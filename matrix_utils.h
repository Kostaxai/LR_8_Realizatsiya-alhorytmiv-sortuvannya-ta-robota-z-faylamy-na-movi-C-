#pragma once
#include <string>

using namespace std;

const int M = 20;
const int NN = 20;

// зчитування матриці з файлу
void get_matrix(string Filename, int mx[M][NN], int& m, int& n);

// пошук стовпця з однаковою кількістю + та -
int find_column(int mx[M][NN], int m, int n);
