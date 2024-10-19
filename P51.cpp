#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int v){
        data = v;
        left = right = NULL;
    }
};
node* insertBST(node* root,int x){
    if(root == NULL){
        root = new node(x);
        return root;
    }
    if(x<root->data){
        root->left = insertBST(root->left,x);
    }else{
        root->right = insertBST(root->right,x);
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    cout<<"Element to be inserted in Binary Search tree: ";
    node* root = NULL;
    for(int i=0;i<n;i++){
        int x;cin>>x;cout<<x<<" ";
        root = insertBST(root,x);
    }
    cout<<endl<<"Inorder Traversal on Binary Search Tree: ";
    inorder(root);
    return 0;
}