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
void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    cout<<endl<<"Postorder Traversal on Binary Search Tree: ";
    postorder(root);
    return 0;
}