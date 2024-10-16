#include <iostream>
#include <fstream>
#include <iomanip>
#include "HASH.h"

// Конструктор
HASH::HASH() {
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr; // Инициализируем массив нулями
    }
}

// Хеш-функция
int HASH::HASHFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += ch; // Суммируем ASCII значения символов
    }
    return hash % tableSize; // Возвращаем индекс в пределах размера таблицы
}

// Добавление элемента
void HASH::insertHASH(const string& key, const string& value) {
    int index = HASHFunction(key);
    Node* newNode = new Node{key, value, nullptr};

    if (!table[index]) {
        table[index] = newNode; // Если ячейка пуста, добавляем новый узел
    } else {
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                current->value = value; // Обновляем значение, если ключ уже существует
                delete newNode; // Удаляем временный узел
                return;
            }
            if (!current->next) {
                current->next = newNode; // Добавляем новый узел в конец цепочки
                return;
            }
            current = current->next;
        }
    }
}

// Получение значения по ключу
string HASH::getHASH(const string& key) {
    int index = HASHFunction(key);
    Node* current = table[index];
    while (current) {
        if (current->key == key) {
            return current->value; // Возвращаем значение, если ключ найден
        }
        current = current->next;
    }
    return "Ключ не найден"; // Если ключ не найден
}

// Удаление элемента по ключу
void HASH::removeHASH(const string& key) {
    int index = HASHFunction(key);
    Node* current = table[index];
    Node* previous = nullptr;

    while (current) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next; // Удаляем узел из цепочки
            } else {
                table[index] = current->next; // Если это первый узел
            }
            delete current; // Освобождаем память
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Ключ не найден для удаления" << endl; // Если ключ не найден
}

// Вывод всех элементов хеш-таблицы
void HASH::printTableHASH() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i]) {
            Node* current = table[i];
            while (current) {
                cout << "{" << current->key << ": " << current->value << "} ";
                current = current->next;
            }
            cout << endl;
        }
    }
}

// Запись хеш-таблицы в файл
void HASH::writeToFileHASH(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current) {
            file << current->key << " " << current->value << endl;
            current = current->next;
        }
    }

    file.close();
}

// Чтение хеш-таблицы из файла
void HASH::readFromFileHASH(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    clearHASH(); // Очищаем таблицу перед загрузкой новых данных

    string key, value;
    while (file >> key >> value) {
        insertHASH(key, value);
    }

    file.close();
}

// Освобождение памяти вручную
void HASH::clearHASH() {
    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp; // Освобождаем память
        }
        table[i] = nullptr; // Обнуляем указатели
    }
}