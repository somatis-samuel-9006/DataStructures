#include<iostream>
#include "queue.h"
using namespace std;


class Queue{
    private:
        int length;     //current length of queue
        Node *head;
        Node *tail;
    
    public:
        Queue(){        //constructor
            length = 0;
            head = NULL;
            tail = NULL;
        }
        //Push a new node with a given value to the back of the queue.
        void push(int new_value){
           Node *new_node = new Node();     //create new node
           new_node->value = new_value;
           new_node->next = NULL;

           if(head == NULL){
               head = new_node;
               tail = new_node;
               length++;
           }
           else{
               tail->next = new_node;       //if head already full, current is tail. so set tail->next to new node.
               tail = new_node;
               length++;
           }
        }
        //Remove the head and return its value
        int pop(){
            int result;
            if(head == NULL && tail == NULL){
                cout << "Empty queue";
            } else if(head == tail && head != NULL){        // one element
                result = head->value;
                head = tail = NULL;
                length--;
            } else{                         //multi elements
                result = head->value;
                Node *temp = head;
                head = head->next;
                length--;

                delete temp;
            }
            return result;
        }
        //Display the value of the head
        int peek(){
            return head->value;
        }
        //Display the value of each node in order
        void print_queue(){
            Node *current = head;
            while(current != NULL){
                cout << current->value << "\n";
                current = current->next;
            }
        }

};

int main(){
    Queue queue;
    queue.push(2);
    queue.push(3);
    queue.push(5);
    queue.push(55);
    queue.push(4);
    cout << queue.peek() << "\n";
    queue.print_queue();
    queue.pop();
    queue.pop();
    cout << queue.peek() << "\n";
    queue.print_queue();

    return 0;
}