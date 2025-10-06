#include <windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість елементів масиву n: ";
    cin >> n;

    int arr[100]; // максимум 100 елементів
    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Знаходження середнього арифметичного від’ємних елементів
    int countNeg = 0;
    double sumNeg = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            sumNeg += arr[i];
            countNeg++;
        }
    }

    if (countNeg > 0) {
        double avgNeg = sumNeg / countNeg;
        cout << "\nСереднє арифметичне від’ємних елементів: " << avgNeg << endl;
    }
    else {
        cout << "\nУ масиві немає від’ємних елементів.\n";
    }

    // Сортування методом обміну (bubble sort) за спаданням
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // міняємо місцями, якщо попередній менший
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nМасив після сортування за спаданням:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}