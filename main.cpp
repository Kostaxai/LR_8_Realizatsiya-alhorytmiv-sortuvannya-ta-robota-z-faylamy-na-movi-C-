#include <iostream>
#include <fstream>
#include <windows.h>

#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

// виконання завдання 1
void task1() {
    string filename;
    int arr[N];
    int n;
    int k;

    cout << "Введіть ім'я файлу масиву: ";
    cin >> filename;

    cout << "Введіть K: ";
    cin >> k;

    get_mas(filename, arr, n);      // зчитування масиву
    shift_array(arr, n, k);         // зсув елементів вправо

    // запис у файл
    show_mas("array_out_81.txt", arr, n);

    // вивід на консоль
    cout << "Масив після зсуву: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Результат також записано у файл array_out_81.txt\n";
}

// виконання завдання 2
void task2() {
    string filename;
    int matrix[M][NN];
    int m, n;

    cout << "Введіть ім'я файлу матриці: ";
    cin >> filename;

    get_matrix(filename, matrix, m, n);

    int result = find_column(matrix, m, n);

    // вывод на консоль
    cout << "Номер стовпця з однаковою кількістю + та -: " << result << endl;

    // запись в файл
    ofstream fout("matrix_result.txt");
    if (fout) {
        fout << result << endl;
        fout.close();
        cout << "Результат також записано у файл matrix_result.txt\n";
    }
    else {
        cout << "Помилка запису у файл matrix_result.txt\n";
    }
}

// виконання завдання 3
void task3() {
    string filename;
    int arr[N];
    int n;

    cout << "Введіть ім'я файлу масиву: ";
    cin >> filename;

    get_mas(filename, arr, n);

    binary_insertion_sort(arr, n);

    // запис у файл
    show_mas("array_sorted.txt", arr, n);

    // вивід на консоль
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Результат також записано у файл array_sorted.txt\n";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "3 - Завдання 3\n";
        cout << "0 - Вихід\n";

        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        }
    } while (choice != 0);

    return 0;
}
