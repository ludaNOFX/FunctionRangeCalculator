#include <iostream>
#include <iomanip> // Для использования манипуляторов форматирования вывода
#include <limits>  // Для использования numeric_limits

using namespace std;

// Функция для проверки ввода
double getValidInput()
{
    double input_number;
    cout << "Введите значение: ";
    cin >> input_number;

    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите значение повторно: ";
        cin >> input_number;
    }

    return input_number;
}

// Функция проверяет интервалы и деление на 0 и возвращает числовые значения типа int
int check_condition(const double x, const double a, const double b, const double c)
{
    if ((x + c < 0) && (a != 0))
    {
        return 1;
    }
    if ((x + c > 0) && (a == 0))
    {
        if (x == c)
        {
            return -1;
        }
        else
        {
            return 2;
        }
    }
    if (x == 0 || c == 0)
    {
        return -1;
    }
    return 3;
}

// функция которая считает y в зависимости от переменной condition и возвращает bool
bool calculate_value(const double x, const double a, const double b, const double c, double &y, int condition)
{
    switch (condition)
    {
    case 1:
        y = -a * x * x * x - b;
        return true;
    case 2:
        y = (x - a) / (x - c);
        return true;
    case 3:
        y = (x / c) + (c / x);
        return true;
    default:
        return false;
    }
}

// Функция для ввода и проверки диапазона Xнач Xкон: 
void checkRange(double &Xn, double &Xk)
{
    do
    {
        cout << "Введите диапазон Xнач Xкон: " << endl;
        cout << "Xn: ";
        Xn = getValidInput();
        cout << "Xk: ";
        Xk = getValidInput();
        if (Xn >= Xk)
            cout << "Ошибка ввода: Xнач >= Xкон!" << endl;
    } while (Xn >= Xk);
}

// Функция для проверки шага и записи его в переменную dX
double checkStep()
{
    double dX;
    do
    {
        cout << "Введите шаг dX: ";
        dX = getValidInput();
        if (dX <= 0)
            cout << "Ошибка ввода: dX <= 0!" << endl;
    } while (dX <= 0);
    return dX;
}

// Функция для вычисления и вывода значений функции в заданном диапазоне
void calculateAndPrintValues(double Xn, double Xk, double dX, double a, double b, double c)
{
    double x, y;
    x = Xn;
         
    cout << "____________________" << endl
         << "____________________" << endl
         << "   x        F(x)    " << endl
         << "____________________" << endl;
    do
    {
        cout << setw(6) << fixed << setprecision(2) << x << "  ";
        int condition = check_condition(x, a, b, c);
        if (calculate_value(x, a, b, c, y, condition))
            cout << setw(10) << fixed << setprecision(2) << y << endl;
        else
            cout << "не определено" << endl;
        x += dX;
    } while (x <= Xk);  // пока x не привысит значение  Xk тоесть пока x в пределах заданного диапазона
    cout << "____________________" << endl
         << "____________________" << endl;
}

int main()
{
    double Xn, Xk, dX, a, b, c;

    // Запрос ввода параметров a, b, c
    cout << "Введите параметры a, b, c: " << endl;
    cout << "a: "; a = getValidInput();
    
    cout << "b: "; b = getValidInput();
    
    cout << "c: "; c = getValidInput();
    
    // Проверка диапазона Xn Xk
    checkRange(Xn, Xk);

    // Проверка шага dX
    dX = checkStep();

    // Вычисление и вывод значений функции в заданном диапазоне
    calculateAndPrintValues(Xn, Xk, dX, a, b, c);

    return 0;
}
