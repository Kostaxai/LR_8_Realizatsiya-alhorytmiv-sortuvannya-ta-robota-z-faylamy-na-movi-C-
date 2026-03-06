#include <iostream>
#include <fstream>
#include "matrix_utils.h"

using namespace std;

// зчитування матриці з файлу
void get_matrix(string Filename, int mx[M][NN], int& m, int& n) {

    ifstream fin(Filename);

    if (!fin) {
        cout << "Помилка відкриття файлу матриці!\n";
        return;
    }

    fin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> mx[i][j];
        }
    }

    fin.close();
}

// пошук останнього стовпця
int find_column(int mx[M][NN], int m, int n) {

    int result = 0;

    for (int j = 0; j < n; j++) {

        int pos = 0;
        int neg = 0;

        for (int i = 0; i < m; i++) {

            if (mx[i][j] > 0)
                pos++;

            if (mx[i][j] < 0)
                neg++;
        }

        if (pos == neg && pos != 0) {
            result = j + 1;
        }
    }

    return result;
}
