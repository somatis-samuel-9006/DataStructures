#include <string>
using namespace std;

class hash_table{
    public:
        hash_table();
        hash_table(int new_capacity);
        void add(string new_value);
        string remove(string target);
        string search(string target);
        int get_size();
        int get_capacity();
        float get_load();
        string print();
    private:
        int size;
        int capacity;
        float load;
        string *table;
        int hash(string target);
};