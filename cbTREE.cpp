#include <iostream>
#include <fstream>

using namespace std;

struct CompleteBinaryTreeNode {
    int data;
    CompleteBinaryTreeNode* left;
    CompleteBinaryTreeNode* right;

    CompleteBinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Вставка узла в полное двоичное дерево
void InsertCB(CompleteBinaryTreeNode*& root, int value, int index, int count) {
    if (root == nullptr) {
        if (index < count) {
            root = new CompleteBinaryTreeNode(value);
        }
        return;
    }
    InsertCB(root->left, value, 2 * index + 1, count);
    InsertCB(root->right, value, 2 * index + 2, count);
}

// Симметричный обход дерева
void inorderTraversal(CompleteBinaryTreeNode* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

// Очистка дерева
void deleteTree(CompleteBinaryTreeNode*& node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

// Запись узлов дерева в файл
void writeNodeToFile(CompleteBinaryTreeNode* node, ofstream& file) {
    if (!node) return;
    writeNodeToFile(node->left, file);
    file << node->data << endl; // Записываем значение узла
    writeNodeToFile(node->right, file);
}

// Чтение узлов дерева из файла
void readFromFile(CompleteBinaryTreeNode*& root, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }
    int value;
    while (file >> value) {
        static int count = 0;
        InsertCB(root, value, count, count);
        count++;
    }
    file.close();
}

// Запись дерева в файл
void writeToFileCB(CompleteBinaryTreeNode* root, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    writeNodeToFile(root, file);
    file.close();
}

// Поиск элемента в дереве
bool SearchCB(CompleteBinaryTreeNode* node, int value) {
    if (node == nullptr) {
        return false; // Элемент не найден
    }
    if (node->data == value) {
        return true; // Элемент найден
    }
    // Рекурсивный поиск в левом и правом поддереве
    return SearchCB(node->left, value) || SearchCB(node->right, value);
}
// Вывод дерева
// Вывод дерева в виде структуры
void PrintTreeCB(CompleteBinaryTreeNode* root, int space = 0) {
    if (root == nullptr) return;

    space += 10;

    PrintTreeCB(root->right, space);

    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    PrintTreeCB(root->left, space);
}