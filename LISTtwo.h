#include <iostream>
#include <fstream>
#include <string>

struct NodeLT {
    int data;
    NodeLT* next;
    NodeLT* previous;
};

// Функции для работы с двусвязным списком
void addHeadLT(NodeLT*& head, NodeLT*& tail, int value);
void addTailLT(NodeLT*& head, NodeLT*& tail, int value);
void deleteHeadLT(NodeLT*& head, NodeLT*& tail);
void deleteTailLT(NodeLT*& head, NodeLT*& tail);
bool deleteByValueLT(NodeLT*& head, NodeLT*& tail, int value);
NodeLT* searchLT(NodeLT* head, int value);
void printListLT(NodeLT* head);
void clearListLT(NodeLT*& head, NodeLT*& tail);
void writeToFileLT(NodeLT* head, const std::string& filename);
void readFromFileLT(NodeLT*& head, NodeLT*& tail, const std::string& filename);