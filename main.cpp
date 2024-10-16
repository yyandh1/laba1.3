#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "ARRAY.h"
#include "cbTREE.h"
#include "HASH.h"
#include "LISTone.h"
#include "LISTtwo.h"
#include "QUEUE.h"
#include "STACK.h"

void handleARRAYCommands(ARRAY& arr) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        // Приводим команду к нижнему регистру
        for (auto &c : command) c = tolower(c);

        if (command == "append") {
            int value;
            cin >> value;

            bool exists = false;
            for (int i = 0; i < arr.size; ++i) {
                if (arr.data[i] == value) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                ARRAYappend(arr, value);
                writeToFileARRAY(arr, "ARRAY.txt");
            } else {
                cout << "Значение уже существует." << endl;
            }
        } else if (command == "ainsert") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index <= ARRAYlength(arr)) {
                ARRAYinsert(arr, index, value);
                writeToFileARRAY(arr, "ARRAY.txt");
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        } else if (command == "aget") {
            int index;
            cin >> index;
            if (index >= 0 && index < ARRAYlength(arr)) {
                cout << "Элемент по индексу " << index << ": " << ARRAYget(arr, index) << endl;
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        } else if (command == "aremov") {
            int index;
            cin >> index;
            if (index >= 0 && index < ARRAYlength(arr)) {
                ARRAYremove(arr, index);
                writeToFileARRAY(arr, "ARRAY.txt");
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        } else if (command == "areplace") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index < ARRAYlength(arr)) {
                ARRAYreplace(arr, index, value);
                writeToFileARRAY(arr, "ARRAY.txt");
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        } else if (command == "asize") {
            cout << "Длина массива: " << ARRAYlength(arr) << endl;
        } else if (command == "print") {
            printARRAY(arr);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Неизвестная команда." << endl;
        }
    }
}


// Обработчик команд для дерева
void handleCBCommands(CBNode*& root) {
    string command;

    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "CBINSERT") {
            int val;
            cout << "Введите значение: ";
            cin >> val;

            // Вставка узла
            InsertCB(root, val);

            // Запись дерева в файл
            writeToFileCB(root, "CB.txt");

            cout << "Значение " << val << " вставлено." << endl;
        } else if (command == "CBSEARCH") {
            int val;
            cout << "Введите значение для поиска: ";
            cin >> val;
            if (SearchCB(root, val)) {
                cout << "Значение " << val << " найдено." << endl;
            } else {
                cout << "Значение " << val << " не найдено." << endl;
            }
        } else if (command == "PRINT") {
            cout << "Дерево:" << endl;
            PrintTreeCB(root);
        } else if (command == "EXIT") {
            break;
        } else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleHASHCommands(HASH& HASHTable) {

    string command;
    while (true) {
         cout << ">> ";
        cin >> command;

        if (command == "HINSERT") {
            string key, value;

            cin >> key;
            cin >> value;
            HASHTable.insertHASH(key, value);
            HASHTable.writeToFileHASH("HASH.txt");
        }
        else if (command == "HGET") {
            string key;

            cin >> key;
            string result = HASHTable.getHASH(key);
            if (!result.empty()) {
                cout << "Значение: " << result << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "HREMOVE") {
            string key;
            cin >> key;
            HASHTable.removeHASH(key);
            HASHTable.writeToFileHASH("HASH.txt");
        }
        else if (command == "HPRINT") {
            cout << "Хеш-таблица:" << endl;
            HASHTable.printTableHASH();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleListONECommands(NodeLO*& list, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LOADDHEAD") {
            int value;
            cin >> value;
            addHeadLO(list, value);
            writeToFileLO(list, filename);
        }
        else if (command == "LOADDTAIL") {
            int value;
            cin >> value;
            addTailLO(list, value);
            writeToFileLO(list, filename);
        }
        else if (command == "LODELHEAD") {
            if (list) {
                deleteHeadLO(list);
                writeToFileLO(list, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELTAIL") {
            if (list) {
                deleteTailLO(list);
                writeToFileLO(list, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELVAL") {
            int value;
            cin >> value;
            if (deleteByValueLO(list, value)) {
                writeToFileLO(list, filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOSEARCH") {
            int value;
            cin >> value;
            if (searchLO(list, value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOPRINT") {
            cout << "Список: ";
            printListLO(list);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleLISTtwoCommands(NodeLT*& head, NodeLT*& tail, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LTADDHEAD") {
            int value;
            cin >> value;
            addHeadLT(head, tail, value);
            writeToFileLT(head, filename);
        }
        else if (command == "LTADDTAIL") {
            int value;
            cin >> value;
            addTailLT(head, tail, value);
            writeToFileLT(head, filename);
        }
        else if (command == "LSDELHEAD") {
            if (head) {
                deleteHeadLT(head, tail);
                writeToFileLT(head, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LTDELTAIL") {
            if (tail) {
                deleteTailLT(head, tail);
                writeToFileLT(head, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LTDELVAL") {
            int value;
            cin >> value;
            if (deleteByValueLT(head, tail, value)) {
                writeToFileLT(head, filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LTSEARCH") {
            int value;
            cin >> value;
            if (searchLT(head, value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LTPRINT") {
            cout << "Список: ";
            printListLT(head);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}



void handleSTACKCommands(STACK& stack) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "SPUSH") {
            string value;
            cin >> value;
            pushSTACK(&stack, value);
            writeToFileSTACK(stack, "STACK.txt");
        }
        else if (command == "SPOP") {
            string value = popSTACK(&stack);
            if (!value.empty()) {
                writeToFileSTACK(stack, "STACK.txt");
            }
            else {
                cout << "Стек пуст." << endl;
            }
        }
        else if (command == "SPRINT") {
            cout << "Стек: ";
            printSTACK(&stack);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleQUEUECommands(QUEUE& queue) {

    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "QPUSH") {
            int value;
            cin >> value;
            pushQUEUE(queue, value);
            writeToFileQUEUE(queue, "QUEUE.txt");
        }
        else if (command == "QPOP") {
            int value = popQUEUE(queue);
            if (value != -1) {
                writeToFileQUEUE(queue, "QUEUE.txt");
            }
            else {
                cout << "Очередь пуста." << endl;
            }
        }
        else if (command == "QPRINT") {
            cout << "Очередь: ";
            printQUEUE(queue);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}


int main() {
    system("chcp 65001");

   ARRAY arr; // Теперь используем структуру Array вместо указателя
    ARRAYinit(arr, 10); // Инициализация массива с начальной емкостью 10
    CBNode* root = nullptr;
    HASH HASHTable;
    NodeLO* list = nullptr;
    NodeLT* list2 = nullptr;
    QUEUE queue;
    STACK stack;

    while (true) {
        string command;
        cout << ">> ";
        cin >> command;

        if (command == "ARRAY") {
            handleARRAYCommands(arr); // Передаем массив по ссылке
        }
        else if (command == "AVL") {
            handleCBCommands(root);
        }
        else if (command == "HASH") {
            handleHASHCommands(HASHTable);
        }
        else if (command == "LO") {
            handleListONECommands(list, "LISTONE.txt");
        }
        else if (command == "LT") {
            handleLISTtwoCommands(list2, "LISTTWO.txt");
        }
        else if (command == "QUEUE") {
            handleQUEUECommands(queue);
        }
        else if (command == "STACK") {
            handleSTACKCommands(stack);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда. Попробуйте снова." << endl;
        }
    }

    // Очистка памяти
    ARRAYdestroy(arr); // Освобождаем память массива
    clearCB(root);
    HASHTable.clearHASH();
    clearListLO(list);
    clearListLT(list2);
    clearQUEUE(queue);
    clearSTACK(&stack);

    return 0;
}