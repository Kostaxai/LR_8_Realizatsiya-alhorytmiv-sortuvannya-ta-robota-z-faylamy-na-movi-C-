#include <iostream>
#include <windows.h>
#include "array_utils.h"
#include "matrix_utils.h"

int main() {
    // Встановлюємо UTF-8 для консолі
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ----- Завдання 1: Масив зсуву (1-based індексація) -----
    int* array1 = nullptr;
    int N1 = 0;
    std::string arrayFile;
    std::cout << "Введіть ім'я файлу масиву: ";
    std::cin >> arrayFile;

    readArray1Based(arrayFile, array1, N1);

    if (array1 != nullptr) {
        int K;
        std::cout << "Введіть K для зсуву масиву: ";
        std::cin >> K;

        shiftArray1Based(array1, N1, K);
        writeArray1BasedToFile("array_out_81.txt", array1, N1);

        std::cout << "Масив після зсуву: ";
        for (int i = 1; i <= N1; ++i) std::cout << array1[i] << " ";
        std::cout << std::endl;

        delete[] array1;
    }

    // ----- Завдання 2: Матриця -----
    int** matrix = nullptr;
    int M = 0, Nmatr = 0;
    std::string matrixFile;
    std::cout << "Введіть ім'я файлу матриці: ";
    std::cin >> matrixFile;

    readMatrix1Based(matrixFile, matrix, M, Nmatr);

    if (matrix != nullptr) {
        int lastCol = findLastBalancedColumn1Based(matrix, M, Nmatr);
        appendResultToMatrixFile(matrixFile, lastCol);

        std::cout << "Останній збалансований стовпець: " << lastCol << std::endl;

        for (int i = 1; i <= M; ++i) delete[] matrix[i];
        delete[] matrix;
    }

    // ----- Завдання 3: Сортування методом двійкових вставок -----
    int demoArray[7] = { 12, 5, -3, 7, 0, 4, 9 };
    int demoN = 7;

    // Запис початкового демонстраційного масиву у файл
    writeSortedArrayToFile("demo_array.txt", demoArray, demoN);

    // Сортування методом двійкових вставок
    binaryInsertionSort(demoArray, demoN);

    // Запис відсортованого масиву у файл
    writeSortedArrayToFile("demo_array_sorted.txt", demoArray, demoN);

    std::cout << "Відсортований масив методом двійкових вставок: ";
    for (int i = 0; i < demoN; ++i) std::cout << demoArray[i] << " ";
    std::cout << std::endl;

    return 0;
}
