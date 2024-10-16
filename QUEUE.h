#pragma once
#include <string>
using namespace std;

struct NodeQ {
    int data;
    NodeQ* next;
};

struct QUEUE {
    NodeQ* head;
    NodeQ* tail;

    QUEUE() : head(nullptr), tail(nullptr) {}
};

void pushQUEUE(QUEUE& queue, int value);
int popQUEUE(QUEUE& queue);
void printQUEUE(const QUEUE& queue);
void clearQUEUE(QUEUE& queue) ;
void writeToFileQUEUE(const QUEUE& queue, const string& filename);
void readFromFileQUEUE(QUEUE& queue, const string& filename);