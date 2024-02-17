#ifndef ASIGTGUNCEL_DOUBLELINKEDLIST_H
#define ASIGTGUNCEL_DOUBLELINKEDLIST_H
#include "Packages.h"

class DoubleLinkedList {
    private:
        struct Node {
            Packages item;
            Node* next;
            Node* prev;
            int index = -1;
        };
        Node* head;
    public:
        void insert(Packages data);  //inserts from tail.
        bool isEmpty();
        void del(int index, Packages& p); //deletes package at the given index.
        void delHead(Packages& data); //deletes package from head.
};

#endif //ASIGTGUNCEL_DOUBLELINKEDLIST_H
