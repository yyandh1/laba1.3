#pragma once
#include <iostream>
using namespace std;

struct CBNode {
    int data;
    CBNode* left = nullptr;
    CBNode* right = nullptr;
    int balance = 0;
};

int HeightCB(CBNode* root);
void SetBalanceCB(CBNode* root);
void TurnRightCB(CBNode*& root) ;
void TurnLeftCB(CBNode*& root);
void InsertCB(CBNode*& root, int key);
bool SearchCB(CBNode* root, int key);
CBNode* MinValueCBNode(CBNode* AVLNode);
void DeleteCBNode(CBNode*& root, int key);
void InOrderCB(CBNode* root);
void PrintTreeCB(CBNode* root, int space = 0);
void writeNodeToFile(CBNode* node, ofstream& file, int depth);
void writeToFileCB(CBNode* root, ofstream& file);
void readFromFileCB(CBNode*& root, ifstream& file);
void clearCB(CBNode*& root);