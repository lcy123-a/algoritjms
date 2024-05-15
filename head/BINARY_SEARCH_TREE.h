#pragma once

#include "iostream"
#include "vector"

using namespace std;

struct node {
    int data;       // 数据域
    node* lchild;   // 指针域：左孩子
    node* rchild;   // 指针域：右孩子
};

// 创建新节点   
node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = nullptr;
    return Node;
}

// 二叉查找树的查找操作
bool search(node* root, const int& val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    else if (root->data > val) 
        search(root->lchild, val);
    else
        search(root->rchild, val); 
}

// 二叉查找树的插入操作
void insert(node* root, const int& val) {
    if (root == nullptr) 
        root = newNode(val);
    
    if (root->data == val) return;
    else if (root->data > val) insert(root->lchild, val);
    else insert(root->rchild, val);
}

// 二叉查找树的建立
node* create(vector<int>& data) {
    node* root = nullptr;
    for (auto& iter : data) insert(root, iter);
    return root;
}

// 二叉查找树的删除
/*
	为保证删除某一个节点之后仍然为一个二叉查找树，
	一种方法是，找到删除节点的左子树中的最大值，替换掉删除的节点
	另一种方法是，找到删除节点的右子树中的最小值，替换掉删除的节点
	替换的方法是进行删除节点的递归操作
*/

// 传入的是左孩子节点，找到左子树中的最大值，
node* GetLeftMax(node* root) {
    while (root != nullptr) root = root->rchild;
    return root;
}

// 传入的是右孩子节点，找到右子树中的最小值，
node* GetRightMin(node* root) {
    while (root != nullptr) root = root->lchild;
    return root;
}

// 二叉查找树的删除操作
void deleteNode(node* &root, int& val) {
    if (root == nullptr) return; 
    if (root->data > val) deleteNode(root->lchild, val);
    else if (root->data < val)  deleteNode(root->rchild, val);
    else {
        if (root->lchild == nullptr && root->rchild == nullptr) {
            delete root;    // 释放内存
            root = nullptr; // 指针置空
        } else if (root->lchild != nullptr) {
            node* pre = GetLeftMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        } else if (root->rchild != nullptr) {
            node* post = GetRightMin(root->rchild);
            root->data = post->data;
            deleteNode(root->rchild, post->data);
        }
    }
}