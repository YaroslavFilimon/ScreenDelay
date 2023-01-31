#include <iostream>
using namespace std;

/// Сбросить флаги ошибок и содержимое буфера потока.
void ignore_all(istream& is)
{
    is.clear(); // Сброс ошибок.
    is.sync();  // Синхронизация объекта потока с внешним устройством.
    is.ignore(is.rdbuf()->in_avail()); // Сброс символов уже считанных в буфер потока.
}

/// Задержка экрана = сброс стандартного потока ввода и ожидание следующего символа.
void console_delay()
{
    ignore_all(cin);
    cin.ignore();
}


// Демонстрация.
int main()
{
    while (true)
    {
        cout << "Enter a sequence of integers:\n";
        for (int i; cin >> i;)
            cout << i << ' ';

        cout << "\nPress Enter to repeat\n";
        console_delay();
    }
}