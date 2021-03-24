#include <iostream>
#include <cassert>
#include "assignment_4.h"

using namespace std;

//test functionality of add and get_length and print
void test_add(){
    LinkedList list;
    list.add(1,0);
    list.add(2,1);
    list.add(3,1);
    assert(list.get_length() == 3);
    list.print();
}
//test remove functionality
void test_remove(){
    LinkedList list;
    list.add(1,0);
    list.add(2,1);
    list.add(3,2);
    assert(list.remove(1) == 2);
    assert(list.get_length() == 2);
    list.print();
}

//test search functionality
void test_search(){
    LinkedList list;
    list.add(1,0);
    list.add(2,1);
    list.add(3,2);
    assert(list.search(0) == 1);
    cout << "Value of node 0 is 1";
}

//test error handling for bad values
void test_error_msg(){
    LinkedList list;
    cout << "Testing error messages:\n";
    cout<<"list.add(3,10): ";
    list.add(3,10);
    cout << "list.remove(0): ";
    list.remove(0);
    cout << "list.remove(3): ";
    list.remove(3);
    cout<< "list.search(0): ";
    list.search(0);
    cout << "list.search(3): ";
    list.search(3);
    cout << "print() while empty: "; 
    list.print();
}
 int main(){
    cout << "ADD: \n";
    test_add();
    cout << "\n";
    cout << "REMOVE: \n";
    test_remove();
    cout << "\n";
    cout << "SEARCH: \n";
    test_search();
    cout << "\n";
    cout << "\n";
    cout << "ERROR MESSAGES: \n";
    test_error_msg();
    return 0;
}
