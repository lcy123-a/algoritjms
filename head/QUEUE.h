#pragma once
#include "iostream"
#include <stdlib.h>

using namespace std;

#define MAXSIZE 0xffff

template<class type>
class note {
public:
    type data;
    note* next;
    note(type data) : data(data), next(NULL) {}
    ~note() {
        next = NULL;
    }
};

template<class type>
class my_queue {
    note<type>* _front;
    note<type>* _back;
    note<type>* _note;
    int size;
public:
    my_queue():size(-1) {
        _back = _front = NULL;
    }
    ~my_queue() {
        delete _front;
        delete _back;
        delete _note;
        _back = _front = _note = NULL;
    }
    void Push(type data);
    void Pop();
    bool Empty();
    type Front();
    type Back();
    int Size();
};

template<class type>
void my_queue<type>::Push(type data) {
    _note = new note<type>(data);
    _note -> next = NULL;
    if (_front == NULL) {
        _front = _back = _note;
    } else {
        _back -> next = _note;
        _back = _note;
    }
    size++;
}

template<class type>
void my_queue<type>::Pop() {
    if (!Empty()) {
        _note = _front;
        _front = _front -> next;
        delete _note;
        _note = NULL;
        size--;
    } else {
        cout << "队列为空" << endl;
    }
}

template<class type>
bool my_queue<type>::Empty() {
    if (size > -1) {
        return false;
    } else {
        return true;
    }
}


template<class type>
type my_queue<type>::Front() {
    if (!Empty()) {
        return _front -> data;
    } else {
        cout << "队列为空" << endl;
    }
}

template<class type>
type my_queue<type>::Back() {
    if (!Empty()) {
        return _back -> data;
    } else {
        cout << "队列为空" << endl;
    }
}


template<class type>
int my_queue<type>::Size() {
    return size + 1;
}