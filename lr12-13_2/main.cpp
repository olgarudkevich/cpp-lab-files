#include <iostream>
#include <fstream>

using namespace std;

int main() {

    const int n = 5;
    int a[n][n];
    int sum = 0;

    ifstream inputFile;
    inputFile.open("matrix.txt");

    if (!inputFile) {
        cerr << "Помилка: Не вдалося відкрити файл matrix.txt для читання." << endl;
        return 1;
    }

    cout << "Зчитую елементи матриці 5x5 з файлу matrix.txt..." << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> a[i][j];
        }
    }

    inputFile.close();

    cout << "\nЗчитана матриця:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > 0) {
                sum += a[i][j];
            }
        }
    }

    cout << "\nСума додатних елементів над головною діагоналлю = " << sum << endl;

    ofstream outputFile;
    outputFile.open("result.txt");

    if (!outputFile) {
        cerr << "Помилка: Не вдалося відкрити файл result.txt для запису." << endl;
        return 1;
    }

    outputFile << "Сума додатних елементів над головною діагоналлю = " << sum << endl;
    
    outputFile.close();

    cout << "Результат також записано у файл result.txt." << endl;

    return 0;
}