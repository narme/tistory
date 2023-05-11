#include <iostream>

using namespace std;
typedef int element;

typedef struct Node{
    element data;
    Node* left;
    Node* right;
}Node;

class BinaryTree{
    public:
        BinaryTree();
        ~BinaryTree();

        Node* CreateNode(element data);

        
        int getNodeCount(Node* node);
        int getHeight(Node* node);
        element getData(Node* node);
        bool setData(Node* node, element data);

        void preOrder(Node* node);
        void inOrder(Node* node);
        void postOrder(Node* node);

};
BinaryTree::BinaryTree(){}
BinaryTree::~BinaryTree(){}

Node *BinaryTree::CreateNode(element data){
    Node* newNode = new Node();
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = data;
    return newNode;
}
int BinaryTree::getNodeCount(Node* node){
    int count = 0;
    if(node != nullptr)count = 1 + getNodeCount(node->left) + getNodeCount(node->right);
    return count;
}
int BinaryTree::getHeight(Node* node){
    int height = 0;
    if(node != nullptr)height = 1 + max(getHeight(node->left),getHeight(node->right));
    return height;
}
element BinaryTree::getData(Node* node){
    if(node == nullptr)return -1;
    return node->data;
}
bool BinaryTree::setData(Node* node, element data){
    if(node == nullptr)return false;
    node->data = data;
    return true;
}
void BinaryTree::preOrder(Node* node){
    if(node != nullptr){
        cout << getData(node) << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
void BinaryTree::inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        cout << getData(node) << " ";
        inOrder(node->right);
    }
}

void BinaryTree::postOrder(Node* node){
    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        cout << getData(node) << " ";
    }
}


int main(){
    BinaryTree* tree = new BinaryTree();

    Node* root = tree->CreateNode(1);
    Node* nodeA = tree->CreateNode(2);
    Node* nodeB = tree->CreateNode(3);
    Node* nodeC = tree->CreateNode(4);
    Node* nodeD = tree->CreateNode(5);
    Node* nodeE = tree->CreateNode(6);
    Node* nodeF = tree->CreateNode(7);
    root->left = nodeA;
    root->right = nodeB;
    nodeA->left = nodeC;
    nodeA->right = nodeD;
    nodeB->left = nodeE;
    nodeB->right = nodeF;

    tree->preOrder(root);
    cout << "\n";
    tree->inOrder(root);
    cout << "\n";
    tree->postOrder(root);
    cout << "\n";
}
