#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;


struct CBNode {
    int value;
    CBNode* left;
    CBNode* right;

    CBNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


// Функция для подсчета количества узлов в дереве
// int countNodes(CBNode* node) {
//     if (node == nullptr) return 0;
//     return 1 + countNodes(node->left) + countNodes(node->right);
// }
int countNodes(CBNode* root) {
    if (root == nullptr)
        return(0);
    return 1 + countNodes (root->left) + countNodes(root->right);
}

void InsertCB(CBNode* root, int value) {
    CBNode* trueRoot = root;
    int currentDeph = trueRoot->value;
    if (pow(2, currentDeph) - 1 != countNodes(root)) {
        while (currentDeph != 2) {
            if (countNodes(root->left) != pow(2, --currentDeph) - 1) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        if (root->left == NULL) {
            root->left = new CBNode(value);
        }
        else {
            root->right = new CBNode(value);
        }
    }
    else {
        currentDeph = trueRoot->value;
        while (currentDeph |= 1){
            root = root->left; 
            currentDeph--;
        }
        root->left = new CBNode(value);
        trueRoot->value++;
    }
}

// Вставка узла в полное двоичное дерево
// void InsertCB(CBNode*& root, int value) {
//     if (root == nullptr) {
//         root = new CBNode(value);
//         return;
//     }

//     // Используем рекурсивную вставку
//     if (countNodes(root->left) <= countNodes(root->right)) {
//         InsertCB(root->left, value);
//     } else {
//         InsertCB(root->right, value);
//     }
// }

// Запись узлов в файл с отступами
void writeNodeToFile(CBNode* node, ofstream& file, int depth) {
    if (!node) return;

    writeNodeToFile(node->left, file, depth + 1);
    
    file << setw(depth * 4) << "";
    file << node->value << endl;

    writeNodeToFile(node->right, file, depth + 1);
}

// Запись всего дерева в файл
void writeToFileCB(CBNode* root, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }

    if (!root) {
        file << "Дерево пусто." << endl;
    } else {
        writeNodeToFile(root, file, 0);
    }
    file.close();
}

// Поиск элемента в дереве
bool SearchCB(CBNode* node, int val) {
    if (node == nullptr) {
        return false;
    }
    if (node-> value == val) {
        return true;
    }
    return SearchCB(node->left, val) || SearchCB(node->right, val);
}

// Функция для вывода дерева
void PrintTreeCB(CBNode* root, int space = 0) {
    if (!root) return;

    // Увеличиваем отступ для следующего уровня
    space += 4;

    // Выводим правое поддерево
    PrintTreeCB (root->right, space);

    // Выводим текущий узел с отступами
    cout<<endl;
    for (int i = 4; i < space; i++)
        cout <<" ";
    cout <<root->value<< "\n";

    // Выводим левое поддерево
    PrintTreeCB (root->left, space);
}