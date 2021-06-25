#include <iostream>
#include <string>
#include <vector>
#include "better_hash.h"

using namespace std;

hash_table::hash_table(){
    size = 0;
    bucket_size = 10;
    load = 0;
    table = new vector<string>[bucket_size];
}

hash_table::hash_table(int new_buck_size){
    size = 0;
    bucket_size = new_buck_size;
    load = 0;
    table = new vector<string>[bucket_size];
}

int hash_table::get_size(){
    return size;
}

int hash_table::get_bucket_size(){
    return bucket_size;
}

float hash_table::get_load(){
    return load;
}

int hash_table::hash(string target){
    int result = 0;
    for(int i = 0; i<target.length(); ++i){
        result += target[i] - 'a';
    }

    result %= bucket_size;
    return result;
}

//basic way of adding to our hash table, collisions are overwritten
void hash_table::add(string new_value){
    int target_index = hash(new_value);     //hash the key
    table[target_index].push_back(new_value);   //push the new value to the back of the linked list
    size++;
    load = (float)size / bucket_size;
}

//search for value in bucket, return a remove it if it exists, else return ""
string hash_table::remove(string target){
    int target_index = hash(target);
    string result = "";

    vector<string>::iterator i;     //iterator of vector of strings
    for(i = table[target_index].begin(); i != table[target_index].end(); ++i){     //Loop over entire vector with iterator
        if(*i == target){
            break;
        }
    }
    if(i != table[target_index].end()){     //vector.end() points to theoretical element after the last element in vector (NULL?)
        result = *i;
        table[target_index].erase(i);
        size--;
        load = (float)size / bucket_size;
    }

    return result;
}

//same as remove function, just don't remove the value if it's found
string hash_table::search(string target){
    int target_index = hash(target);
    string result = "";

    vector<string>::iterator i;     //iterator of vector of strings
    for(i = table[target_index].begin(); i != table[target_index].end(); ++i){     //Loop over entire vector with iterator
        if(*i == target){
            break;
        }
    }
    if(i != table[target_index].end()){     //vector.end() points to theoretical element after the last element in vector (NULL?)
        result = *i;
    }
    else{
        result = "String not found";
    }

    return result;
}


void hash_table::print(){
    for(int i = 0; i<bucket_size; ++i){
        cout << i<<": ";
        for(auto j = table[i].begin(); j != table[i].end(); ++j){       //auto will evaluate to iterator over string vector
            cout <<"->" << *j;
        }
        cout <<endl;
    }

}
