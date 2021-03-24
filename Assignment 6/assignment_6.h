using namespace std;

typedef struct node{
    int value;
    node *left;
    node *right;
    node *parent;
}Node;

class binaryTree{
    private:
        Node *root;
        Node* add(int new_value, Node *leaf);
        Node* get_min(Node *leaf);
        Node* Remove(int old_value, Node *leaf);
        void inorder(Node *leaf);
        void preorder(Node *leaf);
        void postorder(Node *leaf);

    public:
        binaryTree();
        void insert(int new_value);
        void remove(int old_value);
        void print_inorder();
        void print_preorder();
        void print_postorder();
};


        

