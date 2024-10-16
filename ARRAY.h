#include <iostream>
using namespace std;

// Структура для массива
struct ARRAY {
    int* data;       // Указатель на массив
    int size;        // Текущий размер массива
    int capacity;    // Максимальная вместимость массива
};


void ARRAYinit(ARRAY& arr, int cap);
void ARRAYdestroy(ARRAY& arr);
void ARRAYappend(ARRAY& arr, int value);
void ARRAYinsert(ARRAY& arr, int index, int value);
int ARRAYget(const ARRAY& arr, int index);
void ARRAYremove(ARRAY& arr, int index);
void ARRAYreplace(ARRAY& arr, int index, int value);
int ARRAYlength(const ARRAY& arr);
void printARRAY(const ARRAY& arr);
void writeToFileARRAY(const ARRAY& arr, const string& filename);