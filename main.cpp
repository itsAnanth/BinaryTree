#include <iostream>
#include <string>
#include <vector>
using String = std::string;

//    A binary tree
//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//     / \    /   
//    5   9  17 

/**
 * a single Node 
 *      data
 *      /  \
 *    left right
 *    node  node
 */
struct Node {
    int data;
    Node * left = NULL;
    Node * right = NULL;
};

void log(auto string); // too lazy to use std::cout lol

class BinarySearchTree {
    private:
        Node * root;
    public:
        BinarySearchTree() {
            root = NULL;
        }
        void insert(int x);
        void recursiveInsert(Node * rootNode, Node * newNode);
        void print(Node * node);
        Node * rootNode();
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
    Node * newNode = new Node();
    newNode -> data = x;
    if (root == NULL) {
        root = newNode;
        log("inserted node");
        return;
    }
        
    recursiveInsert(root, newNode);
}

void BinarySearchTree::recursiveInsert(Node * rootNode, Node * newNode) {
    if (newNode -> data < rootNode -> data) {
        if (rootNode->left == NULL) {
            rootNode->left = newNode;
            return;
        } else 
            recursiveInsert(rootNode->left, newNode);
    } else {
        if (rootNode->right == NULL) {
            rootNode->right = newNode;
            return;
        } else 
            recursiveInsert(rootNode->right, newNode);
    }
}

void BinarySearchTree::print(Node * node) {
    if  (node != NULL) {
        print(node -> left);
        log(node -> data);
        print(node -> right);
    }
}

Node * BinarySearchTree::rootNode() {
    return root;
}

void log(auto string) {
    std::cout << string << std::endl;
}