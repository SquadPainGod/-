#include <iostream>
#include <vector>
#include <Windows.h>
#include <clocale>


using namespace std;

// ������� ��� ������ ���� ����� �������
void swapRows(vector<vector<int>>& matr, int row1, int row2) {
    for (int j = 0; j < matr[0].size(); j++) {
        swap(matr[row1][j], matr[row2][j]);
    }
}

// ������� ��� ���������� ������� �� k-�� �������
void sortmas(int n, int m, vector<vector<int>>& matr, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // ���������� �������� � k-� �������
            if (matr[i][k] > matr[j][k]) {
                // ���� ������� � ������ ������ ������, ������ ������ �������
                swapRows(matr, i, j);
            }
        }
    }
}

// ������� ��� ������ �������
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

    // ������ ���������� ����� � �������� � ������������
    cout << "������� ���������� �����: ";
    cin >> n;
    cout << "������� ���������� ��������: ";
    cin >> m;

    // �������� ������� ��������� �������
    vector<vector<int>> matr(n, vector<int>(m));

    // ���������� ������� ����������, ���������� �������������
    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "������� [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matr[i][j];
        }
    }

    cout << "\n�������� �������:" << endl;
    printMatrix(matr);

    int k;
    cout << "������� ������ ������� ��� ���������� (������� � 0): ";
    cin >> k;

    sortmas(n, m, matr, k);

    cout << "\n��������������� ������� �� " << k << "-�� �������:" << endl;
    printMatrix(matr);

    return 0;
}