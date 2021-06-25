#include <string>
#include <vector>
using namespace std;

class hash_table{
    public:
        hash_table();
        hash_table(int new_buck_size);
        void add(string new_value);
        string remove(string target);
        string search(string target);
        int get_size();
        int get_bucket_size();
        float get_load();
        void print();

    private:
        int size;
        int bucket_size;
        float load;
        vector<string> *table;
        int hash(string target);

};