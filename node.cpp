#include <iostream>
#include "node.h"

node::node()
{
    setNext(NULL);
    setData(-1);
    setPrev(NULL);
}
node *node::getNext()
{
    return this->next;
}

node *node::getPrev()
{
    return this->prev;
}

int node::getData()
{
    return this->data;
}
void node::setData(int data)
{
    this->data = data;
}
void node::setNext(node *nNode)
{
    this->next = nNode;
}
void node::setPrev(node *pNode)
{
    this->prev = pNode;
}