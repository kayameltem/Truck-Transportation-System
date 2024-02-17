#ifndef ASIGTGUNCEL_QUEUE_H
#define ASIGTGUNCEL_QUEUE_H
#include <iostream>
template<typename T>
class Queue {
    public:
        Queue(){
            _size = 0;
            _lastNode = NULL;
        }
        ~Queue(){
            QueueNode* temp;
            while(!isEmpty()){
                temp = _lastNode->next;
                //delete _lastNode->item;
                delete _lastNode;
                _lastNode = temp;
                _size --;
            }
            _lastNode = NULL;
            delete temp;
            temp = NULL;
        }
        bool isEmpty() const{ return _size == 0;}
        int size() const{return _size; }
        //Enqueue: Items are added to the back of the queue
        void enqueue(const T& newItem){

            QueueNode* last = new QueueNode();
            last->item = newItem;
            last->next = _lastNode;
            _lastNode = last;
            _size ++;
        }
        //Dequeue: Items are removed from the front of the queue
        void dequeue(){
            if (isEmpty()) {
                std::cout << "dequeue hata mesajı\n";
                return;
            }
            QueueNode *temp;
            if (_size == 1) {
                delete _lastNode;
                _lastNode = NULL;
            }
            else {
                QueueNode *next;
                temp = _lastNode;
                while (temp->next->next!= NULL) {
                    temp = temp->next;
                }
                next = temp->next;
                temp->next = NULL;
                delete next;
                next = NULL;
                temp = NULL;
                delete temp;
            }
            _size--;
        }
        //Get Front: Take a look at the first item
        void getFront(T& queueTop) const{
            if(isEmpty()){
                std::cout << "hata mesajı queue::getfront()\n";
                return;
            }
            QueueNode* top = _lastNode;
            while(top->next!= NULL){
                top = top->next;
            }
            queueTop = top->item;
        }
    private:
        struct QueueNode {
            T item;
            QueueNode *next;
        };
        int _size;
        /* to avoid the traversal to the last node,
         an additional pointer to the last node is defined*/
        QueueNode *_lastNode ;
};


#endif //ASIGTGUNCEL_QUEUE_H
