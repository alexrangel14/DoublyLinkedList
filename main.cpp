#include <iostream>
#include "dlList.cpp"

int main(){
    dlList list;
    //insert nodes
    for (int i=0;i<10;i++){
        list.insertNode(i);
    }
    //display nodes
    list.displayList();
    //delete nodes
    for (int i=0;i<10;i++){
        list.deleteNode(i);
    }
}