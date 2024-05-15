#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "iostream"
#include <string.h>

using namespace std;


/*typedef struct pair {
    int key;            // 构建一个键，充当哈希地址的求解
    char element[20];   // 数据类型
}DATA, *LPDATA;

typedef struct hashTable {
    LPDATA* table;
    int divisor;
    int curSize;
}HASH, *LPHASH;


LPHASH createHashTable(int p) {
    LPHASH hash = (LPHASH)malloc(sizeof(HASH));
    assert(hash);
    hash->curSize = 0;
    hash->divisor = p;
    hash->table = (LPDATA*)malloc(sizeof(LPDATA) * hash->divisor);
    assert(hash->table);
    for (int i = 0; i < hash->divisor; i++) {
        hash->table[i] = NULL;
    }
    return hash;
}


int search(LPHASH hash, int key) {
    int pos = key % hash->divisor;
    int curPos = pos;
    do {
        if (hash->table[curPos] == NULL || hash->table[curPos]->key == key) {
            return curPos;
        }
        curPos = (curPos + 1) % hash->divisor;
    }while(curPos != pos);
    return curPos;
}


void insertData(LPHASH hash, DATA data) {
    int pos = search(hash, data.key);
    if (hash->table[pos] == NULL) {
        hash->table[pos] = (LPDATA)malloc(sizeof(DATA));
        assert(hash->table[pos]);
        memcpy(hash->table[pos], &data, sizeof(DATA));
        hash->curSize++;
    } else {
        if (hash->table[pos]->key == data.key) {
            strcpy(hash->table[pos]->element, data.element);
        }
        else {
            cout << "hash表满了，无法插入" << endl;
            return;
        }
    }
}

void printHash(LPHASH hash) {
    for (int i = 0; i < hash->divisor; ++i) {
        if (hash->table[i] == NULL) {
            cout << "NULL" << endl;
        }
        else {
            cout << hash->table[i]->key << " " << hash->table[i]->element << endl;
        }
    }
}*/


