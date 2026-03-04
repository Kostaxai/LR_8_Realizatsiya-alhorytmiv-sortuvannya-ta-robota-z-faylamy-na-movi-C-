#pragma once

// ----- Функції для роботи з двовимірними масивами (матрицею) -----
void readMatrix1Based(const std::string& filename, int**& mat, int& M, int& N);
int findLastBalancedColumn1Based(int** mat, int M, int N);
void appendResultToMatrixFile(const std::string& filename, int result);
