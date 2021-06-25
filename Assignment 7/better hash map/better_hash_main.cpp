#include<iostream>
#include<cassert>
#include "better_hash.h"

using namespace std;

//tests values on an empty tree
bool test_empty(){
    hash_table table;
    assert(table.get_load() == ((float)0 / 10));
    assert(table.get_size() == 0);
    assert(table.get_bucket_size() == 10);
    return true;
}

//tests resize capability
bool test_resize(){
    hash_table table(20);
    assert(table.get_load() == ((float)0 / 20));
    assert(table.get_size() == 0);
    assert(table.get_bucket_size() == 20);
    return true;
}

//test add function for each bucket as well as collision handling. Also tests print function and get_ functions
void test_add(){
    hash_table table;
    table.add("a");
    table.add("b");
    table.add("c");
    table.add("d");
    table.add("e");
    table.add("f");
    table.add("g");
    table.add("h");
    table.add("i");
    table.add("j");
    table.add("l");
    table.add("m");
    table.add("n");
    table.add("o");
    table.add("p");
    table.add("q");
    table.add("r");
    table.add("s");
    table.add("t");
    table.add("u");
    table.add("Hello");
    table.add("World");
    cout << "keys(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,Hello,World)" << endl;
    assert(table.get_load() == ((float)22 / 10));       //assert(table.get_load() == 2.2) doesn't work????
    assert(table.get_size() == 22);
    assert(table.get_bucket_size() == 10);
    table.print();
}

//tests remove function for buckets with and without chaining. Also tests print function and get_ functions
void test_remove(){
    hash_table table;
    table.add("a");
    table.add("u");
    table.add("b");
    table.add("c");
    table.add("Hello");
    table.add("World");
    cout << "keys(a,u,b,c,Hello,World)" << endl;
    table.print();
    cout << endl;
    cout << "Removing a, World, and c" << endl;
    table.remove("a");
    table.remove("World");
    table.remove("c");
    assert(table.get_load() == ((float)3 / 10));
    assert(table.get_size() == 3);
    assert(table.get_bucket_size() == 10);
    table.print();
}

//tests search function for values in the map and not in the map
void test_search(){
    hash_table table;
    table.add("a");
    table.add("b");
    table.add("c");
    cout << "keys(a,b,c)" << endl;
    table.print();
    cout << "table.search(a):" << table.search("a") << endl;
    cout << "table.search(hotdogs):" << table.search("hotdogs") << endl;

}

int main(){
    test_empty();
    test_resize();
    cout << "TEST ADD:" << endl;
    test_add();
    cout << endl;
    cout << "TEST REMOVE:" << endl;
    test_remove();
    cout << endl;
    cout << "TEST SEARCH:" << endl;
    test_search();

    return 0;
}