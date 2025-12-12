#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insertQuadratic(int key) {
    int index = key % SIZE;

    if(hashTable[index] == -1) {
        hashTable[index] = key;
        return; 
    }

    for(int i = 1; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;

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

    insertQuadratic(25);
    insertQuadratic(35);
    insertQuadratic(45);
    insertQuadratic(20);

    display();
    return 0;
}
