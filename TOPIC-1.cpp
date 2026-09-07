#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void preorder(Node* root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int size(Node* root){
    if(root==NULL)return 0;
    return 1+size(root->left)+size(root->right);
}

int sum(Node* root){
    if(root==NULL)return 0;
    return root->val+sum(root->left)+sum(root->right);
}

int height(Node* root){
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}

int maxValue(Node* root){
    if(root==NULL)return INT_MIN;
    return max(root->val,max(maxValue(root->left),maxValue(root->right)));
}

int minValue(Node* root){
    if(root==NULL)return INT_MAX;
    return min(root->val,min(minValue(root->left),minValue(root->right)));
}

int leafNodes(Node* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    return leafNodes(root->left)+leafNodes(root->right);
}

int main(){

    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=g;

    cout<<"Preorder: ";
    preorder(a);

    cout<<"\nInorder: ";
    inorder(a);

    cout<<"\nPostorder: ";
    postorder(a);

    cout<<"\nSize: "<<size(a);
    cout<<"\nSum: "<<sum(a);
    cout<<"\nHeight: "<<height(a);
    cout<<"\nMax value: "<<maxValue(a);
    cout<<"\nMin value: "<<minValue(a);
    cout<<"\nLeaf nodes: "<<leafNodes(a);

}