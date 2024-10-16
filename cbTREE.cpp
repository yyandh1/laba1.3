#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

struct CBNode {
    int value;
    CBNode* left;
    CBNode* right;

    CBNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int countNodes(CBNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void InsertCB(CBNode*& root, int value) {
    if (root == nullptr) {
        root = new CBNode(value);
        return;
    }

    // Если есть место в левом поддереве, вставляем туда
    if (root->left == nullptr) {
        root->left = new CBNode(value);
        return;
    } 
    // Если есть место в правом поддереве, вставляем туда
    else if (root->right == nullptr) {
        root->right = new CBNode(value);
        return;
    }
    
    // Если оба поддерева заполнены, рекурсивно пробуем вставить в левое или правое поддерево
    if (countNodes(root->left) <= countNodes(root->right)) {
        InsertCB(root->left, value);
    } else {
        InsertCB(root->right, value);
    }
}


// Остальные функции остаются без изменений
// Удаление узла, поиск минимального/максимального значений, обходы и т.д/

// Поиск минимального значения
int findMin(CBNode* node) {
    if (node == nullptr) return INT_MAX;
    return min(node->value, min(findMin(node->left), findMin(node->right)));
}

// Поиск максимального значения
int findMax(CBNode* node) {
    if (node == nullptr) return INT_MIN;
    return max(node->value, max(findMax(node->left), findMax(node->right)));
}

// Прямой обход (pre-order)
void printPreOrder(CBNode* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// Симметричный обход (in-order)
void printInOrder(CBNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    cout << node->value << " ";
    printInOrder(node->right);
}

// Обратный обход (post-order)
void printPostOrder(CBNode* node) {
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->value << " ";
}

// Запись узлов в файл с отступами
void writeNodeToFile(CBNode* node, ofstream& file, int depth) {
    if (!node) return;

    // Запись левого поддерева
    writeNodeToFile(node->left, file, depth + 1);
    
    // Запись текущего узла с отступами
    file << setw(depth * 4) << ""; // Устанавливаем отступы
    file << node->value << endl; // Записываем значение узла

    // Запись правого поддерева
    writeNodeToFile(node->right, file, depth + 1);
}

void writeToFileCB(CBNode* root, ofstream& file) {
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }

    if (!root) {
        file << "Дерево пусто." << endl;
    } else {
        writeNodeToFile(root, file, 0);
    }
}




// Поиск элемента в дереве
bool SearchCB(CBNode* node, int val) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == val) {
        return true;
    }
    return SearchCB(node->left, val) || SearchCB(node->right, val);
}

// Вспомогательная функция для вывода узлов на текущем уровне
void PrintLevel(CBNode* node, int level) {
    if (node == nullptr) {
        return;
    }
    
    if (level == 1) {
        cout << node->value << " "; // Вывод значения узла
    } else {
        PrintLevel(node->left, level - 1);  // Обход левого поддерева
        PrintLevel(node->right, level - 1); // Обход правого поддерева
    }
}

// Функция для определения высоты дерева
int Height(CBNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(Height(node->left), Height(node->right)) + 1;
}

// Функция для вывода дерева в виде "змейки"
void PrintTreeCB(CBNode* root) {
    int height = Height(root); // Определяем высоту дерева

    for (int i = 1; i <= height; i++) {
        PrintLevel(root, i); // Выводим узлы на текущем уровне
        cout << endl; // Переход на новую строку после каждого уровня
    }
}
// Функция для очистки дерева и освобождения памяти
void clearCB(CBNode*& root) {
    if (root == nullptr) return;

    clearCB(root->left);
    clearCB(root->right);

    delete root;
    root = nullptr; // Устанавливаем указатель в nullptr
}

bool DeleteCB(CBNode*& root, int value) {
    if (root == nullptr) return false;

    if (root->value == value) {
        clearCB(root);
        return true;
    }
    if (DeleteCB(root->left, value) || DeleteCB(root->right, value)) {
        return true;
    }
    return false;
}