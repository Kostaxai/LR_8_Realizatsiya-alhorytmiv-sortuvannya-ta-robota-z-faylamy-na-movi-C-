#include <iostream>
#include <fstream>
#include "array_utils.h"

using namespace std;

// функція зчитування масиву з файлу
void get_mas(string Filename, int mas[N], int& n) {

    ifstream fin(Filename);

    if (!fin) {
        cout << "Помилка відкриття файлу масиву!\n";
        return;
    }

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> mas[i];
    }

    fin.close();
}

// функція запису масиву у файл
void show_mas(string Filename, const int mas[N], const int n) {

    ofstream fout(Filename);

    for (int i = 0; i < n; i++) {
        fout << mas[i] << " ";
    }

    fout.close();
}

// зсув елементів масиву вправо на K позицій
void shift_array(int mas[N], int n, int k) {

    for (int i = n - 1; i >= k; i--) {
        mas[i] = mas[i - k];
    }

    for (int i = 0; i < k; i++) {
        mas[i] = 0;
    }
}

// сортування методом двійкових вставок
void binary_insertion_sort(int mas[N], int n) {

    for (int i = 1; i < n; i++) {

        int key = mas[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {

            int mid = (left + right) / 2;

            if (key < mas[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = i - 1; j >= left; j--) {
            mas[j + 1] = mas[j];
        }

        mas[left] = key;
    }
}
