#include <iostream>

using namespace std;

struct CBNode {
    int value;
    CBNode* left;
    CBNode* right;

    CBNode(int val);
};

// Функции для работы с бинарным деревом
int countNodes(CBNode* root);
void InsertCB(CBNode*& root, int value);
bool DeleteCB(CBNode*& root, int value);
int findMin(CBNode* node);
int findMax(CBNode* node);
void printPreOrder(CBNode* node);
void printInOrder(CBNode* node);
void printPostOrder(CBNode* node);
void writeNodeToFile(CBNode* node, ofstream& file, int depth);
void writeToFileCB(CBNode* root, ofstream& file);
bool SearchCB(CBNode* node, int val);
void PrintTreeCB(CBNode* root);
void clearCB(CBNode*& root);
void PrintLevel(CBNode* node, int level);
int Height(CBNode* node);