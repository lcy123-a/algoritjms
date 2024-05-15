#pragma once



template<class type>

class my_stack {
    int top;
    type* my_s;
    int maxsize;
public:
    my_stack():top(-1), maxsize(MAXSIZE) {
        my_s = new type[maxsize];
        if (my_s == NULL) {
            cerr << "动态存储分配失败" << endl;
            exit(1);
        }
    }
    my_stack(int size):top(-1), maxsize(size) {
        my_s = new type[maxsize];
        if (my_s == NULL) {
            cerr << "动态存储分配失败" << endl;
            exit(1);
        }
    }
    ~my_stack() {
        delete[] my_s;
    }
    bool Empty();
    void Push(type tp);
    type Top();
    void Pop();
    int size();
};

template<class type>
bool my_stack<type>::Empty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

template<class type>
type my_stack<type>::Top() {
    if (top != -1) {
        return my_s[top];
    } else {
        cout << "栈空" << endl;
        exit(1);
    }
}

template<class type>
void my_stack<type>::Push(type tp) {
    if (top + 1 < maxsize) {
        my_s[++top] = tp;
    } else {
        cout << "栈满" << endl;
        exit(1);
    }
}

template<class type>
void my_stack<type>::Pop() {
    if (top >= 0) {
        top--;
    } else {
        cout << "栈空" << endl;
        exit(1);
    }
}

template<class type>
int my_stack<type>::size() {
    return top + 1;
}