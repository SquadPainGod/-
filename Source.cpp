#include <iostream>
#include <vector>
#include <Windows.h>
#include <clocale>


using namespace std;

// Функция для обмена двух строк матрицы
void swapRows(vector<vector<int>>& matr, int row1, int row2) {
    for (int j = 0; j < matr[0].size(); j++) {
        swap(matr[row1][j], matr[row2][j]);
    }
}

// Функция для сортировки матрицы по k-му столбцу
void sortmas(int n, int m, vector<vector<int>>& matr, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Сравниваем элементы в k-м столбце
            if (matr[i][k] > matr[j][k]) {
                // Если элемент в первой строке больше, меняем строки местами
                swapRows(matr, i, j);
            }
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matr) {
    for (const auto& row : matr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;

    // Запрос количества строк и столбцов у пользователя
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    // Создание матрицы заданного размера
    vector<vector<int>> matr(n, vector<int>(m));

    // Заполнение матрицы значениями, введенными пользователем
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matr[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    printMatrix(matr);

    int k;
    cout << "Введите индекс столбца для сортировки (начиная с 0): ";
    cin >> k;

    sortmas(n, m, matr, k);

    cout << "\nОтсортированная матрица по " << k << "-му столбцу:" << endl;
    printMatrix(matr);

    return 0;
}