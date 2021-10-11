#include <iostream>
#include <string>
#include <vector>
using String = std::string;


template <typename T> // too lazy to write std::cout everytime :omegalul:
void log(T val) {
    std::cout << val << std::endl;
}

//    A binary tree
//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//     / \    /   
//    5   9  17 
// elements with lower value goes to left branch while elements with greater value goes to right branch

struct Node {
    int data;
    Node * left = NULL;
    Node * right = NULL;
};


class BinarySearchTree {
    private:
        Node * root; // aka the top most element of the tree
    private:
        void recursiveInsert(Node * rootNode, Node * newNode); // this function is not to be explicitly used outside the class
    public:
        BinarySearchTree() {
            root = NULL; // initialize an empty tree
        }
        void insert(int x); // inserts a new element to the tree (uses recursiveInsert to determine the position)
        void print(Node * node); // prints all elements in the tree in order fashion 
        Node * rootNode(); // returns the root node (to be used in print function)
};

int main() {
    BinarySearchTree bst;
    std::vector<int> el = {15, 10, 25, 7, 13, 22, 27, 5, 9, 17};
    for (auto i : el)
        bst.insert(i);
    Node * root = bst.rootNode();
    bst.print(root);

    return 0;
}

void BinarySearchTree::insert(int x) {
    Node * newNode = new Node(); // create new node
    newNode -> data = x; // set the value
    if (root == NULL) { // if its an empty tree, this node becomes the first member aka the root
        root = newNode;
        log("inserted node");
        return;
    }

    // if tree is not empty use recursiveInsert to find the viable position to insert node        
    recursiveInsert(root, newNode);
}

void BinarySearchTree::recursiveInsert(Node * rootNode, Node * newNode) {
    if (newNode -> data < rootNode -> data) { // if node to insert has a value less than the parent node
        if (rootNode->left == NULL) { // if parent node has no left element, the newnode becomes the left element
            rootNode->left = newNode;
            return;
        } else 
            recursiveInsert(rootNode->left, newNode); // if parent node has a node on the left, initiate recursion
    } else {
        if (rootNode->right == NULL) { // do the same thing for right node if the value is greater than parent noe
            rootNode->right = newNode;
            return;
        } else 
            recursiveInsert(rootNode->right, newNode);
    }
}

/**
 * print starts from root, ie pass in the root variable to initiate print
 */
void BinarySearchTree::print(Node * node) {
    if  (node != NULL) {
        print(node -> left); // print order is -> left value -> parent value -> right value
        log(node -> data);
        print(node -> right);
    }
}

Node * BinarySearchTree::rootNode() {
    return root;
}

// void log(auto string) {
//     std::cout << string << std::endl;
// }