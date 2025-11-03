#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("number.txt");

    if (!inputFile) {
        cerr << "Помилка: Не вдалося відкрити файл number.txt" << endl;
        return 1;
    }

    int number;
    long long sumOfSquares = 0;

    cout << "Зчитуємо числа з файлу number.txt..." << endl;

    while (inputFile >> number) {
        if (number < 0) {
            sumOfSquares += (long long)number * number;
        }
    }

    inputFile.close();

    cout << "Сума квадратів від'ємних чисел: " << sumOfSquares << endl;

    return 0;
}