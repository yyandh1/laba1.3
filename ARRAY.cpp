#include <iostream>
#include <fstream> // Добавляем этот заголовок

using namespace std;

// Структура для массива
struct ARRAY {
    int* data;       // Указатель на массив
    int size;        // Текущий размер массива
    int capacity;    // Максимальная вместимость массива
};

// Инициализация массива с заданной емкостью
void ARRAYinit(ARRAY& arr, int cap) {
    arr.data = new int[cap];
    arr.size = 0;
    arr.capacity = cap;
}

// Освобождение памяти
void ARRAYdestroy(ARRAY& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

// Добавление элемента в конец массива
void ARRAYappend(ARRAY& arr, int value) {
    if (arr.size >= arr.capacity) {
        // Увеличение емкости массива
        arr.capacity *= 2;
        int* newData = new int[arr.capacity];
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    arr.data[arr.size++] = value;
}

// Вставка элемента по индексу
void ARRAYinsert(ARRAY& arr, int index, int value) {
    if (index < 0 || index > arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    if (arr.size >= arr.capacity) {
        arr.capacity *= 2;
        int* newData = new int[arr.capacity];
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    for (int i = arr.size; i > index; --i) {
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[index] = value;
    arr.size++;
}

// Получение элемента по индексу
int ARRAYget(const ARRAY& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return -1;
    }
    return arr.data[index];
}

// Удаление элемента по индексу
void ARRAYremove(ARRAY& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    for (int i = index; i < arr.size - 1; ++i) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}

// Замена элемента по индексу
void ARRAYreplace(ARRAY& arr, int index, int value) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    arr.data[index] = value;
}

// Получение длины массива
int ARRAYlength(const ARRAY& arr) {
    return arr.size;
}

// Вывод элементов массива
void printARRAY(const ARRAY& arr) {
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

// Запись элементов массива в файл
void writeToFileARRAY(const ARRAY& arr, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return;
    }
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl;
    }
    file.close();
    cout << "Данные успешно записаны в файл: " << filename << endl;
}
