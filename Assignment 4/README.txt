#include <iostream>
#include "assignment_4.h"
using namespace std;
    								COST:
LinkedList::LinkedList(){						1
    length = 0;     							1
    head = NULL;							1
}

int LinkedList::get_length(){					1
    return length;							1
}

void LinkedList::add(int new_value, int new_position){			1
    if(new_position < 0 ||  new_position > length + 1){        		1
        cout << "Invalid position\n";					1
    }else{								1
        Node *temp = new Node();					1
        temp->value = new_value;					1
        temp->next = NULL;						1

        if(new_position == 0 || (new_position == 1 && head == NULL)){    	1
            temp->next = head;					1
            head = temp;						1
            length++;							1
            return;							1
        }else{							1
            Node *current = head;       					1
            Node *previous = NULL;					1
            int i = 0;							1

            while(i < new_position){					n+1
                previous = current;					n
                current = current->next;					n

                if(current == NULL){					n
                    break;						n
                }
                i++;							n
            }
         
            temp->next = current;					1
            previous->next = temp;					1
            length++;							1

        }
    }
}

int LinkedList::remove(int old_position){				1
    int result;							1
    if(old_position < 0 || old_position > length){				1
        cout << "Invalid Position\n";					1
    }else if(head == NULL){     					1
        cout << "Empty List\n";					1
    }else{								1
        Node *current = head;						1
        Node *previous = NULL;					1
        int i = 0;							1

        while(i < old_position){					n+1
            previous = current;						n
            current = current->next;					n

            if(current == NULL){					n
                break;							n
            }
            i++;							n
        }
        result = current->value;					1
        previous->next = current->next;				1

        delete current;						1
        length--;							1
    }
    return result;							1
}

int LinkedList::search(int search_position){				1
    int result;							1
    if(search_position < 0 || search_position > length){			1
        cout << "Invalid Position\n";					1
    }else if(head == NULL){     					1
        cout << "Empty List\n";					1
    }else{								1
        Node *current = head;						1
        int i = 0;							1
        while(i < search_position){					n+1
            current = current->next;					n

            if(current == NULL){					n
                break;							n
            }
            i++;							n
        }
        result = current->value;					1
    }
    return result;							1         
}

void LinkedList::print(){						1
    if(head == NULL){						1
        cout<< "Empty List\n";						1
    }else{								1
        Node *current = head;						1
        int count = 0;						1
        while(current != NULL){					n+1
            cout << "Node " << count << ":" << current->value << "\n";		n
            current = current->next;					n
            count++;							n
        }
    }
}

OVERALL:
The overall time complexity for each of these methods is linear time, O(n).
