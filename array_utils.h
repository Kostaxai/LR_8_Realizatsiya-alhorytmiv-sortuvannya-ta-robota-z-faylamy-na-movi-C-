#pragma once
#include <string>

// ----- Завдання 1: робота з масивом (1-based індексація) -----
void readArray1Based(const std::string& filename, int*& arr, int& N);
void shiftArray1Based(int* arr, int N, int K);
void writeArray1BasedToFile(const std::string& filename, int* arr, int N);

// ----- Завдання 3: сортування методом двійкових вставок -----
void binaryInsertionSort(int* arr, int N);
void writeSortedArrayToFile(const std::string& filename, int* arr, int N);
