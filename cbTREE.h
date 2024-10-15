#pragma once
#include <iostream>
using namespace std;

struct CBNode {
    int data;
    CBNode* left = nullptr;
    CBNode* right = nullptr;
    int balance = 0;
};


void InsertCB(CBNode*& root, int value, int index, int count);
bool SearchCB(CBNode* node, int value);
void PrintTreeCB(CBNode* root, int space = 0);
void writeNodeToFile(CBNode* node, ofstream& file);
void writeToFileCB(CBNode* root, const string& filename);
void readFromFile(CBNode*& root, const string& filename);
void deleteTree(CBNode*& node);