#py version of my cpp binary tree kekw

class Node:
    def __init__(self, value):
        self.right = None
        self.left = None
        self.data = value
    
class BinarySearchTree:
    def __init__(self) -> None:
        self.root = None
    def getRootNode(self):
        return self.root
    def insert(self, value):
        newNode = Node(value)
        if not self.root:
            self.root = newNode
        else:
            self.recursiveInsert(self.root, newNode)
    def recursiveInsert(self, rootNode, newNode):
        if newNode.data < rootNode.data:
            if not rootNode.left:
                rootNode.left = newNode
            else:
                self.recursiveInsert(rootNode.left, newNode)
        else :
            if not rootNode.right:
                rootNode.right = newNode
            else:
                self.recursiveInsert(rootNode.right, newNode)
    def print(self, node):
        if not not node:
            self.print(node.left)
            print(node.data)
            self.print(node.right)
            
bst = BinarySearchTree()
bst.insert(5)
bst.insert(1)
bst.insert(10)
treeroot = bst.getRootNode()
bst.print(treeroot)
