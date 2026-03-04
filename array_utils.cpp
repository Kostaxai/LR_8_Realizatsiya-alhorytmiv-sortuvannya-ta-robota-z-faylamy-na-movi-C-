#include <iostream>
#include <fstream>
#include "array_utils.h"

// ----- Завдання 1: Читання масиву з файлу (1-based) -----
void readArray1Based(const std::string& filename, int*& arr, int& N) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Помилка відкриття файлу масиву: " << filename << std::endl;
        arr = nullptr;
        N = 0;
        return;
    }

    fin >> N;
    arr = new int[N + 1]; // arr[1..N], arr[0] не використовується
    for (int i = 1; i <= N; ++i) {
        fin >> arr[i];
    }
    fin.close();
}

// ----- Завдання 1: Зсув масиву вправо на K позицій (1-based) -----
void shiftArray1Based(int* arr, int N, int K) {
    for (int i = N; i >= K + 1; --i) {
        arr[i] = arr[i - K];
    }
    for (int i = 1; i <= K; ++i) {
        arr[i] = 0;
    }
}

// ----- Завдання 1: Запис масиву у файл (1-based) -----
void writeArray1BasedToFile(const std::string& filename, int* arr, int N) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису масиву: " << filename << std::endl;
        return;
    }
    for (int i = 1; i <= N; ++i) {
        fout << arr[i] << " ";
    }
    fout.close();
}

// ----- Завдання 3: Бінарний пошук для вставки -----
int binarySearch(int* arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// ----- Завдання 3: Сортування методом двійкових вставок -----
void binaryInsertionSort(int* arr, int N) {
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = binarySearch(arr, key, 0, i - 1);
        int k = i - 1;
        while (k >= j) {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[j] = key;
    }
}

// ----- Запис відсортованого масиву у файл -----
void writeSortedArrayToFile(const std::string& filename, int* arr, int N) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису відсортованого масиву: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < N; ++i)
        fout << arr[i] << " ";
    fout.close();
}
