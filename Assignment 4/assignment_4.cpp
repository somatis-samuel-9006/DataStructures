#include <iostream>
#include "assignment_4.h"
using namespace std;
    
LinkedList::LinkedList(){
    length = 0;     //count of nodes in list
    head = NULL;
}

int LinkedList::get_length(){
    return length;
}

//add a new node at the specified position
void LinkedList::add(int new_value, int new_position){
    if(new_position < 0 ||  new_position > length + 1){        //check for valid position
        cout << "Invalid position\n";
    }else{
        Node *temp = new Node();
        temp->value = new_value;
        temp->next = NULL;

        if(new_position == 0 || (new_position == 1 && head == NULL)){      //insert at head
            temp->next = head;
            head = temp;
            length++;
            return;
        }else{
            Node *current = head;       //current and prev node ptrs and counter for iteration
            Node *previous = NULL;
            int i = 0;

            while(i < new_position){
                previous = current;
                current = current->next;

                if(current == NULL){
                    break;
                }
                i++;
            }
            //now previous is where we want the new node, and current is the node after the new node
            temp->next = current;
            previous->next = temp;
            length++;

        }
    }
}
//remove node at specified position. return its value
int LinkedList::remove(int old_position){
    int result;
    if(old_position < 0 || old_position > length){
        cout << "Invalid Position\n";
    }else if(head == NULL){     //empty list with input of 0
        cout << "Empty List\n";
    }else{
        Node *current = head;
        Node *previous = NULL;
        int i = 0;

        while(i < old_position){
            previous = current;
            current = current->next;

            if(current == NULL){
                break;
            }
            i++;
        }
        result = current->value;
        previous->next = current->next;

        delete current;
        length--;
    }
    return result;
}
//return value of node at specifiec position
int LinkedList::search(int search_position){
    int result;
    if(search_position < 0 || search_position > length){
        cout << "Invalid Position\n";
    }else if(head == NULL){     //empty list with input of 0
        cout << "Empty List\n";
    }else{
        Node *current = head;
        int i = 0;
        while(i < search_position){
            current = current->next;

            if(current == NULL){
                break;
            }
            i++;
        }
        result = current->value;
    }
    return result;         
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
