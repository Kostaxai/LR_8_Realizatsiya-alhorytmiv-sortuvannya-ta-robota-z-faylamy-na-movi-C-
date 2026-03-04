#include <iostream>
#include <fstream>
#include "matrix_utils.h"

// ----- Читання матриці з файлу (1-based) -----
void readMatrix1Based(const std::string& filename, int**& mat, int& M, int& N) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Помилка відкриття файлу матриці: " << filename << std::endl;
        mat = nullptr;
        M = N = 0;
        return;
    }

    fin >> M >> N;
    mat = new int* [M + 1]; // строки 1..M
    for (int i = 1; i <= M; ++i) {
        mat[i] = new int[N + 1]; // столбцы 1..N
        for (int j = 1; j <= N; ++j)
            fin >> mat[i][j];
    }
    fin.close();
}

// ----- Пошук останнього збалансованого стовпця (1-based) -----
int findLastBalancedColumn1Based(int** mat, int M, int N) {
    int lastCol = 0;
    for (int j = 1; j <= N; ++j) {
        int pos = 0, neg = 0;
        for (int i = 1; i <= M; ++i) {
            if (mat[i][j] > 0) pos++;
            else if (mat[i][j] < 0) neg++;
        }
        if (pos == neg) lastCol = j; // уже 1-based
    }
    return lastCol;
}

// ----- Допис результату у файл -----
void appendResultToMatrixFile(const std::string& filename, int result) {
    std::ofstream fout(filename, std::ios::app);
    if (!fout.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису результату: " << filename << std::endl;
        return;
    }
    fout << "\nLast balanced column: " << result << std::endl;
    fout.close();
}
