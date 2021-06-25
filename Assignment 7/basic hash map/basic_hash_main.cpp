#include<iostream>
#include "basic_hash.h"

using namespace std;

int main(){
    cout <<"what"<<endl;
    hash_table hash;
    hash.add("a");
    hash.add("b");
    hash.add("c");
    cout << hash.get_size() <<endl;
    cout << hash.get_load() <<endl;
    cout << hash.get_capacity() <<endl;
    cout << hash.print()<<endl;
    hash.remove("b");
    cout << hash.get_size() <<endl;
    cout << hash.get_load() <<endl;
    cout << hash.get_capacity() <<endl;
    cout << hash.print()<<endl;
    hash.add("abcde");
    cout << hash.get_size() <<endl;
    cout << hash.get_load() <<endl;
    cout << hash.get_capacity() <<endl;
    cout << hash.print()<<endl;
    cout << "hash.search(c):"<<hash.search("c")<<endl;
    cout << "hash.search(dogs):"<<hash.search("dogs")<<endl;



    return 0;
}
