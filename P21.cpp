#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* insert(Node* head,int v){
    Node* newNode = new Node(v);
    if(head==NULL){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
Node* insertHead(Node* head,int x){
    Node* temp=new Node(x,head);
    return temp;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* head = nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        head = insert(head,value);
    }
    int x;cin>>x;
    cout<<"Created Linked list: ";
    printLL(head);
    cout<<endl<<"Final Linked List: ";
    head= insertHead(head,x);
    printLL(head);
    
}