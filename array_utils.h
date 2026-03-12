#pragma once
#include <string>

using namespace std;

const int N = 20; // максимальний розмір масиву

// зчитування масиву з файлу
void get_mas(string Filename, int mas[N], int& n);

// запис масиву у файл
void show_mas(string Filename, const int mas[N], const int n);

// зсув елементів масиву вправо (завдання 1)
void shift_array(int mas[N], int n, int k);

// сортування методом двійкових вставок (завдання 3)
void binary_insertion_sort(int mas[N], int n);
