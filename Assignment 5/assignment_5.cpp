#include <iostream>
#include <cassert>
#include "assignment_5.h"
using namespace std;



LinkedList::LinkedList(){
    length = 0;     //count of nodes in list
    head = NULL;
    tail = NULL;
}

int LinkedList::get_length(){
    return length;
}

int LinkedList::get_head_value(){
    return head->value;
}

int LinkedList::get_tail_value(){
    return tail->value;
}

//add a new node and value at the appropriate position
void LinkedList::add(int new_value){
    Node *temp = new Node();
    temp->value = new_value;
    temp->next = NULL;

    if(head == NULL){      //first insert
        head = temp;
        tail = temp;
        length++;  
    }
    else if(head->value > temp->value){    //insert new minimum value (at head)
        temp->next = head;
        head = temp;
        length++;
    }
    else{
        Node *current = head;
        Node *previous = NULL;

        while(current->value <= temp->value){
            previous = current;
            current = current->next;

            if(current == NULL){
                break;
            }
        }
        //now current is the node where we want to insert 
        previous->next = temp;
        temp->next = current;

        if(tail->value < temp->value){      //update tail if need be
            tail = temp;
        }
        length++;

    }
}
//remove value, return this value
int LinkedList::remove(int old_value){
    int result;
    if(head == NULL){     //empty list 
        cout << "Empty List\n";
    }
    else if(head->value > old_value || tail->value < old_value){
        cout << "Invalid Position\n";
    }
    else if(head->value == old_value){     //delete at head
        Node *temp = head;
        result = head->value;
        head = head->next;
        delete temp;
        length--;
        return result;
    }
    else{
        Node *current = head;
        Node *previous = NULL;

        while(current->value != old_value){
            previous = current;
            current = current->next;

            if(current == NULL){
                break;
            }
        }
        if(current->next == NULL){      //then the tail is being deleted
            tail = previous;
        }
        result = current->value;
        previous->next = current->next;

        delete current;
        length--;
    }
    return result;
}
//search for value, return its position if it's in the list
int LinkedList::search(int search_value){
    int pos = 0;
    if(head == NULL){     //empty list
        cout << "Empty List\n";
    }
    else{
        Node *current = head;
        while(current->value != search_value){
            current = current->next;

            if(current == NULL){
                cout << "Element not found\n";
                return -1;
            }
            pos++;
        }
    }
    return pos;         
}
//print the nodes and their values in order
void LinkedList::print(){
    if(head == NULL){
        cout<< "Empty List\n";
    }else{
        Node *current = head;
        int count = 0;
        while(current != NULL){
            cout << "Node " << count << ":" << current->value << "\n";
            current = current->next;
            count++;
        }
    }
}

