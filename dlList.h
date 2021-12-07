#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>
#include "node.cpp"

class dlList{
    private:
    node* head;

    public:
    dlList();
    bool searchList(int key);
    bool insertNode(int key);
    bool deleteNode(int key);
    void displayList();
};
#endif