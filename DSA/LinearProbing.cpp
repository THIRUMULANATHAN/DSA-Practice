#include <iostream>
#define size 30
int hashTable[size];

void init() {
    for(int i=0; i<size; i++) hashTable[i] = -1;
}

int hashFunction(int val) { 
    return val%size;
}

void insert(int key) {
    int index = hashFunction(key);
    if(hashTable[index] == -1) {
        hashTable[index] = key;
        return;
    }

    for(int i=0; i<size; i++) { 
        int newIndex = (index + i) % size;
        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }

    std :: cout << "Hash table is full!\n";
}

void display() {
    for(int i=0; i<size; i++) {
        if(hashTable[i] != -1)
            std :: cout << i << " -> " << hashTable[i] << "\n";
    }
}

int main() {
    init();
    int n, x;
    std :: cout << "Enter size : "; 
    std :: cin >> n;
    for(int i=0; i<n; i++) {
        std :: cin >> x;
        insert(x);
    }

    display();

    return 0;
}