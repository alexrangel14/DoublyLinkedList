#include <iostream>
#include "dlList.h"

dlList::dlList()
{
    head = NULL;
}
bool dlList::searchList(int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->getData() == key)
        {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}
bool dlList::insertNode(int key)
{
    if (searchList(key))
    {
        std::cout << "Duplicate node" << std::endl;
        return false;
    }
    //Inserting on empty list
    if (head == NULL)
    {
        node *nNode = new node();
        nNode->setData(key);
        nNode->setNext(NULL);
        nNode->setPrev(NULL);
        head = nNode;
        return true;
    }
    //Inserting in occupied list
    node *temp = head;
    while (temp->getNext() != NULL && temp->getNext()->getData() < key)
    {
        temp = temp->getNext();
    }
    //nextHolder can be NULL or another node; whatever is next
    node *nextHolder = temp->getNext();
    //Declare new node to be inserted
    node *nNode = new node();
    nNode->setData(key);
    nNode->setNext(nextHolder);
    nNode->setPrev(temp);

    temp->setNext(nNode);
    //Incase its the last thing in the list
    if (nextHolder != NULL)
    {
        nextHolder->setPrev(nNode);
    }

    return true;
}
bool dlList::deleteNode(int key)
{
    //Confirms that there is a node with that value
    if (!searchList(key))
    {
        std::cout << "Cannot delete node, not in list" << std::endl;
        return false;
    }
    //Find the node with that value
    node *temp = head;
    while (temp->getNext() != NULL && temp->getData() != key)
    {
        temp = temp->getNext();
    }
    //Now at desired node
    //if deleting head
    if (temp->getData() == head->getData())
    {
        //if only thing in list
        if (temp->getNext() == NULL)
        {
            delete head;
            head = NULL;
            return true;
        }
        head = temp->getNext();
        head->setPrev(NULL);

        delete temp;
        temp = NULL;
        return true;
    }
    //if deleting at end of the list
    if (temp->getNext() == NULL)
    {
        node *prevSaver = temp->getPrev();
        prevSaver->setNext(NULL);
        delete temp;
        temp = NULL;
        return true;
    }
    //if deleting middle
    else
    {
        node *nextSaver = temp->getNext();
        node *prevSaver = temp->getPrev();

        //Save connections
        prevSaver->setNext(nextSaver);
        nextSaver->setPrev(prevSaver);

        //delete node
        delete temp;
        temp = NULL;
        return true;
    }
}
void dlList::displayList()
{
    node *temp = head;
    std::cout << "List (going forward):" << std::endl;
    while (temp->getNext() != NULL)
    {
        std::cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    std::cout<<temp->getData()<<std::endl;
    std::cout << "List (going backward):" << std::endl;
    while (temp != NULL)
    {
        std::cout << temp->getData() << " ";
        temp = temp->getPrev();
    }
    std::cout<<std::endl;
}