#include <iostream>
using namespace std;

#define SIZE 10
#define PRIME 7

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int h1(int key) { return key % SIZE; }
int h2(int key) { return PRIME - (key % PRIME); }

void insertDoubleHash(int key) {
    int index = h1(key);

    if(hashTable[index] == -1) { 
        hashTable[index] = key;
        return;
    }

    int step = h2(key);

    for(int i = 1; i < SIZE; i++) { 
        int newIndex = (index + i * step) % SIZE;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }

    cout << "Hash table full!\n";
}

void display() {
    for (int i = 0; i < SIZE; i++)
        cout << i << " → " << hashTable[i] << endl;
}

int main() {
    init();

    insertDoubleHash(10);
    insertDoubleHash(20);
    insertDoubleHash(30);
    insertDoubleHash(40);

    display();
    return 0;
}
