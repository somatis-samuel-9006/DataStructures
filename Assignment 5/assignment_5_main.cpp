#include <iostream>
#include <cassert>
#include "assignment_5.h"
using namespace std;

//test functionality of add and get_length and print
void test_add(){
    LinkedList list;
    list.add(0);
    list.add(1);
    list.add(5);
    list.add(4);
    list.add(0);
    cout << "Expected order: 0, 0, 1, 4, 5\nActual order:\n";
    list.print();
    assert(list.get_length() == 5);
    assert(list.get_head_value() == 0);
    assert(list.get_tail_value() == 5);
}

//test remove functionality
void test_remove(){
    LinkedList list;
    list.add(0);
    list.add(4);
    list.add(5);
    list.remove(4);
    cout << "Expected order: 0, 5\nActual order:\n";
    list.print();
    assert(list.get_length() == 2);
    assert(list.get_head_value() == 0);
    assert(list.get_tail_value() == 5);
}

//test search functionality
void test_search(){
    LinkedList list;
    list.add(4);
    list.add(11);
    list.add(2);
    assert(list.search(4) == 1);
    assert(list.search(11) == 2);
    assert(list.search(2) == 0);
    cout << "Expected order of positions for values 4, 11, 2:120\nActual order:\n";
    cout << list.search(4) << list.search(11) << list.search(2);
}
int main(){
    cout << "ADD\n";
    test_add();
    cout << "\n";
    cout << "REMOVE\n";
    test_remove();
    cout << "\n";
    cout << "SEARCH\n";
    test_search();
    return 0;
}