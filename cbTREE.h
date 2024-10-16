#include <iostream>
#include <fstream>

using namespace std;

struct CBNode {
    int value;
    CBNode* left;
    CBNode* right;

    CBNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функции для работы с полным двоичным деревом
void InsertCB(CBNode* root, int value);
void writeToFileCB(CBNode* root, const string& filename);
void writeNodeToFile(CBNode* node, ofstream& file, int depth);
bool SearchCB(CBNode* node, int value);
void PrintTreeCB(CBNode* root, int space = 0);
