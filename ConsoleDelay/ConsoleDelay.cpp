#include <cstddef>
#include <iostream>
using namespace std;

/// Сбросить флаги ошибок и содержимое буфера потока.
void ignore_all(istream& is)
{
    is.clear();
    is.sync();
    is.ignore(is.rdbuf()->in_avail());
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

        // Выйти, если введён признак конца файла.
        if (cin.eof())
            return EXIT_SUCCESS;

        cout << "\nPress Enter to repeat\n";
        console_delay();
    }
}