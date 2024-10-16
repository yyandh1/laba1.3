#pragma once 
#include <string>
using namespace std;

struct NodeS {
    string data;
    NodeS* next;
};

struct STACK {
    NodeS* head = nullptr;

};

void pushSTACK(STACK* stack, const string& data);
string popSTACK(STACK* stack);
void printSTACK(STACK* stack);
void clearSTACK(STACK* stack);
void writeToFileSTACK(const STACK& stack, const string& filename);