#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
};

class HASH {
public:
    static const int tableSize = 10;
    Node* table[tableSize];

    HASH();
    void insertHASH(const string& key, const string& value);
    string getHASH(const string& key);
    void removeHASH(const string& key);
    void printTableHASH();
    void writeToFileHASH(const string& filename);
    void readFromFileHASH(const string& filename);
    void clearHASH();

private:
    int HASHFunction(const string& key); // Объявление хеш-функции
};