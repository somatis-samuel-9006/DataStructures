using namespace std;

typedef struct node{
    int value;
    node *next;     //next pointer
}Node;

class LinkedList{
    private:
        int length;
        Node *head;
        Node *tail;

    public:
        LinkedList();
        int get_length();
        int get_head_value();
        int get_tail_value();
        void add(int new_value);
        int remove(int old_value);
        int search(int search_value);
        void print();
};