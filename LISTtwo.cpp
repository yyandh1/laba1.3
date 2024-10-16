#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NodeLT {
    int data;
    NodeLT* next;
    NodeLT* previous;
};

// Добавление элемента в голову списка
// Добавление элемента в голову списка
void addHeadLT(NodeLT*& head, NodeLT*& tail, int value) {
    NodeLT* newNodeLT = new NodeLT;
    newNodeLT->data = value;
    newNodeLT->next = head;
    newNodeLT->previous = nullptr;

    if (head) {
        head->previous = newNodeLT;
    } else {
        tail = newNodeLT; // Если список был пуст, новый узел становится хвостом
    }
    head = newNodeLT;
}

// Добавление элемента в хвост списка
void addTailLT(NodeLT*& head, NodeLT*& tail, int value) {
    NodeLT* newNodeLT = new NodeLT;
    newNodeLT->data = value;
    newNodeLT->next = nullptr;

    if (!head) {
        newNodeLT->previous = nullptr;
        head = newNodeLT;
        tail = newNodeLT; // Если список пуст, новый узел становится и головой, и хвостом
    } else {
        newNodeLT->previous = tail;
        tail->next = newNodeLT;
        tail = newNodeLT; // Обновляем хвост
    }
}

// Удаление элемента с головы списка
void deleteHeadLT(NodeLT*& head, NodeLT*& tail) {
    if (!head) return;
    NodeLT* temp = head;
    head = head->next;
    if (head) {
        head->previous = nullptr;
    } else {
        tail = nullptr; // Если список стал пустым, обнуляем хвост
    }
    delete temp;
}

// Удаление элемента с хвоста списка
void deleteTailLT(NodeLT*& head, NodeLT*& tail) {
    if (!tail) return;
    if (head == tail) {
        delete head; // Если один элемент в списке
        head = nullptr;
        tail = nullptr;
        return;
    }
    NodeLT* temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
}

// Удаление элемента по значению
bool deleteByValueLT(NodeLT*& head, NodeLT*& tail, int value) {
    if (!head) return false;

    if (head->data == value) {
        deleteHeadLT(head, tail);
        return true;
    }

    NodeLT* current = head;
    while (current && current->data != value) {
        current = current->next;
    }

    if (current) {
        if (current->next) {
            current->next->previous = current->previous;
        } else {
            tail = current->previous; // Обновляем хвост, если удаляем последний элемент
        }
        if (current->previous) {
            current->previous->next = current->next;
        }
        delete current;
        return true;
    }

    return false;
}


// Поиск элемента по значению
NodeLT* searchLS(NodeLT* head, int value) {
    NodeLT* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Печать списка
void printListLT(NodeLT* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Освобождение памяти
void clearListLT(NodeLT*& head, NodeLT*& tail) {
    while (head) {
        deleteHeadLT(head, tail);
    }
}

// Функция для записи списка в файл
void writeToFileLT(NodeLT* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeLT* temp = head;
    while (temp) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
}

// Функция для чтения списка из файла
void readFromFileLT(NodeLT*& head, NodeLT*& tail, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearListLT(head, tail); // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;
    while (file >> value) {
        addTailLT(head, tail, value);
        count++;
    }
    if (count > 0) {
        cout << count << " элементов загружено из файла.\n";
    } else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close();
}