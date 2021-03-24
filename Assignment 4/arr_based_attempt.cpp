#include <iostream>
using namespace std;

//THIS IS JUST AN ATTEMPT AT THE ARRAY BASED LIST AS PER ASSIGNMENT INSTRUCTIONS. THE "MAIN" PORTION OF MY ASSIGNMENT IS THE LINKED LIST VERSION

class array_list{
    private:
        int list[10];
        int length;     //#of current items
    
    public:
        array_list();
        void add(int new_value, int new_position);
        int remove(int old_position);
        int search(int search_position);
        void print();

};

array_list::array_list(){
    length = 0;
}

//is possible to chop certain values out of the array
void array_list::add(int new_value, int new_position){
    if(new_position < 0 || new_position > 9){
        cout << "Invalid Position\n";
    }else if(length == 10){
        cout << "List full\n";
    }else{
        for(int i = (length-1); i >= new_position; i--){
            list[i+1] = list[i];
        }
        list[new_position] = new_value;
        length++;
    }
}

int array_list::remove(int old_position){
    int result;
    if(old_position < 0 || old_position > 9){
        cout << "Invalid position\n";
    }else{
        result = list[old_position];
        for(int i = old_position; i <= length; i++){
            list[i] = list[i+1];
        }
    }
    length--;
    return result;
}

int array_list::search(int search_position){
    if(search_position < 0 || search_position > 9){
        cout << "Invalid Position\n";
    }else if(search_position > (length - 1)){
        cout << "Space Empty\n";
    }
    return list[search_position];
}

void array_list::print(){
    for(int i = 0; i<length; i++){
        cout << list[i] << "\n";
    }
}

int main(){
    array_list arr;
    arr.add(0,0);
    arr.add(1,1);
    arr.add(2,2);
    arr.add(3,3);
    arr.add(4,1);
    cout << "value of element 1: " << arr.search(1);
    cout << "\n";
    arr.print();
    arr.remove(1);
    cout << "\n";
    arr.print();
}