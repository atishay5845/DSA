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
node* insertBT(node* root,int x){
    if(root==NULL){
        root = new node(x);
        return root;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current = q.front();
        q.pop();
        if(current->left){
            q.push(current->left);
        }else{
            current->left = new node(x);
            return root;
        }
        if(current->right){
            q.push(current->right);
        }else{
            current->right = new node(x);
            return root;
        }
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    int n;cin>>n;
    cout<<"Elements to be inserted in Binary Tree: ";
    for(int i=0;i<n;i++){
        int x;cin>>x;cout<<x<<" ";
        root = insertBT(root,x);
    }
    cout<<endl;
    cout<<"Inorder representation: ";
    inorder(root);
}














