#include<iostream>
#include<string>
using namespace std;

char bag[100];
//marbles in the bag
int amount = 0;
//representation of a marble
const char marble = 'M';

//Put a 'M' at the next non-empty index
void addMarble(){
    if(amount >= 99){
        cout << "Can't add marble, bag is full\n";
    } else{
        cout << "adding a marble to the bag\n";
        bag[amount] = marble; //amount is the index
        amount++;
    }
}

//Make the last index filled null/empty
void popMarble(){
    if(amount <= 0){
        cout << "Can't add marble. There are no marbles in the bag\n";
    } else{
        cout << "taking a marble out of the bag\n";
        bag[amount - 1] = '\0'; //space is empty now, pop last marble added, which is located at amount - 1
        amount--;
    }
}

//Print how many marbles are in the bag
void getAmount(){
    cout << "There are " << amount << " marbles in the bag\n";
}

//Test for trying to add more marbles than can fit in the bag
void testTooMuch(){
    int oldAmount = amount; //variable to store the old amount to revert back
    amount = 99;
    getAmount();
    cout << "Amount set to 99. Attempting to put a 100'th marble in the bag\n";
    addMarble();
    amount = oldAmount;
    
}

//Print out a visual representation of the bag(array)
void printBag(){
    cout << "Printing bag\n[";
    for(int i = 0; bag[i] == 'M'; i++){
        cout << bag[i] << ",";
    }
    cout << "]\n";
}

//Test bags functionality by calling all helper functions. "Driver file"
int main(){
    getAmount();
    popMarble();
    addMarble();
    getAmount();
    addMarble();
    getAmount();
    addMarble();
    getAmount();
    printBag();
    popMarble();
    getAmount();
    printBag();
    testTooMuch();
    
    return 0;
}

