#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
node* createBinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node* temp = new node(x);
    cout<<"Enter the left child of "<<x<<":";
    temp->left = createBinaryTree();
    cout<<"Enter the right child of "<<x<<":";
    temp->right = createBinaryTree();
    return temp;
}
int main(){
    cout<<"Enter the root node: ";
    node* root;
    root = createBinaryTree();
}
