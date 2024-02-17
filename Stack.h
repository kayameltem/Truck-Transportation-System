#ifndef ASIGTGUNCEL_STACK_H
#define ASIGTGUNCEL_STACK_H
#include <iostream>

template <typename T>
class Stack {
public:
    Stack(){
        _size = 0;
        _head = NULL;
    }
    ~Stack(){
        ListNode* temp ;
        while(!isEmpty()){
            temp = _head->next;
            delete _head;
            _head = temp;
            _size--;
        }
    }
    bool isEmpty() const{ return _size == 0;}
    int size() const { return _size; }

    //Push: Place item on top of the stack
    void push(const T& newItem){
        ListNode* last = new ListNode();
        last->item = newItem;
        last->next = _head;
        _head = last;
        _size++;
    }
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const{
        if(isEmpty()){
            throw "hata mesajı Stack::getTop()\n";
        }
        stackTop = _head->item;
    }
    //Pop: Remove item from the top of the stack
    void pop(){
        if (isEmpty()){
            std::cout << "hata mesaı Stack::pop()\n";
            return;
        }
        ListNode* temp = _head->next ;
        delete _head;
        _head = temp;
        _size--;

    }
private:
    struct ListNode {
        T item;
        ListNode* next;
    };
    ListNode* _head;
    int _size;
};

#endif //ASIGTGUNCEL_STACK_H
