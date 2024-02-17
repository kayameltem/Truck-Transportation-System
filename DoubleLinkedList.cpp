#include "DoubleLinkedList.h"

void DoubleLinkedList::insert(Packages data){
    Node* node = new Node();
    node->item = data;
    node->next = NULL;
    if(head == NULL){
        node->item = data;
        node->prev = NULL;
        head = node;
    }
    else{
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
        node->index = node->prev->index +1;
    }
}
bool DoubleLinkedList::isEmpty(){
    return head == NULL;
}
void DoubleLinkedList::del(int index, Packages& p) {
    if (!isEmpty()) {
        Node *temp = head->next;
        for (; temp != NULL; temp = temp->next) {
            if (temp->index == index) {
                p = temp->item;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                temp->prev->next = temp->next;
                delete temp;
                temp = NULL;
                break;
            }
        }
    }
}
void DoubleLinkedList::delHead(Packages& data){
    if(!isEmpty())
        data = head->item;
    Node *temp = NULL;
    if(head->next != NULL) {
        temp = head->next;
        temp->prev = NULL;
    }
    delete head;
    head= temp;
}