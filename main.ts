class binaryNode {
    data : number;
    left : binaryNode | null
    right : binaryNode | null
    constructor(value : number) {
        this.data = value;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    root : binaryNode | null;
    constructor() {
        this.root = null;
    }

    insert(value : number) {
        const newNode : binaryNode = new binaryNode(value);

        if (!this.root)
            this.root = newNode; 
        else 
            this.recursiveInsert(this.root, newNode);
    }

    recursiveInsert(rootNode : binaryNode, newNode : binaryNode) {
        if (newNode.data < rootNode.data) {
            if (!rootNode.left) 
                rootNode.left = newNode;
            else    
                this.recursiveInsert(rootNode.left, newNode);
        } else {
            if (!rootNode.right)
                rootNode.right = newNode
            else 
                this.recursiveInsert(rootNode.right, newNode);
        }
    }

    rootNode() : binaryNode | null {
        return this.root;
    }

    print(root : binaryNode | null) {
        if (root) {
            this.print(root.left);
            console.log(root.data);
            this.print(root.right);
        }
    }
}

const bst : BinarySearchTree = new BinarySearchTree();
[5, 1, 3, 19 ,11, 15].forEach(x => bst.insert(x));
const rootNode : binaryNode | null = bst.rootNode();
bst.print(rootNode);
  
