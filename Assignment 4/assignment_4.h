
typedef struct node{
    int value;
    node *next;     //next pointer
}Node;

class LinkedList{
    private:
        int length;
        Node *head;

    public:
        LinkedList();
        int get_length();
        void add(int new_value, int new_position);
        int remove(int old_position);
        int search(int search_position);
        void print();
};