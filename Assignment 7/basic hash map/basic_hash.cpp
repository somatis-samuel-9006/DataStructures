#include <iostream>
#include <string>
#include <sstream>
#include "basic_hash.h"

using namespace std;

hash_table::hash_table(){
    size = 0;
    capacity = 10;
    load = 0;
    table = new string[capacity];

    //initialize array values
    for(int i = 0; i < capacity; ++i){
        table[i] = "";
    }
}

hash_table::hash_table(int new_capacity){
    size = 0;
    capacity = new_capacity;
    load = 0;
    table = new string[capacity];

    //initialize array values
    for(int i = 0; i < capacity; ++i){
        table[i] = "";
    }
}

int hash_table::get_size(){
    return size;
}

int hash_table::get_capacity(){
    return capacity;
}

float hash_table::get_load(){
    return load;
}

int hash_table::hash(string target){
    int result = 0;
    for(int i = 0; i<target.length(); ++i){
        result += target[i] - 'a';
    }

    result %= capacity;
    return result;
}

//basic way of adding to our hash table, collisions are overwritten
void hash_table::add(string new_value){
    int target_index = hash(new_value);     //hash the key
    if(table[target_index] == ""){
        size++;
        load = (float)size / capacity;
    }
    table[target_index] = new_value;
}

//search for value in bucket, return a remove it if it exists, else return ""
string hash_table::remove(string target){
    int target_index = hash(target);
    string result = "";

    if(table[target_index].compare(target) == 0){
        result = target;
        table[target_index] = "";
        size--;
        load = (float)size / capacity;
    }

    return result;
}

//search for a value and return it if it exists, else return ""
string hash_table::search(string target){
    int target_index = hash(target);
    string result = "";

    if(table[target_index].compare(target) == 0){
        result = target;
    }

    return result;
}

string hash_table::print() {
	stringstream ss;
	ss << "table: [";
	for(int i = 0; i < capacity; ++i) {
		ss << table[i] << ", ";
	}
	ss << "]";
	
	return ss.str();
}