#ifndef NODE_H
#define NODE_H

class node
{
private:
    int data;
    node *next;
    node *prev;

public:
    node();
    node* getNext();
    node* getPrev();
    int getData();
    void setData(int data);
    void setNext(node* nNode);
    void setPrev(node* pNode);
};
#endif