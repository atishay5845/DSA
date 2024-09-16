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
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* move = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        move->next=temp;
        move=temp;
    }
    return head;
}
Node* reverseLL(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* newhead=reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Node* head= convertArr2LL(a);
    cout<<"Created Linked list: ";
    printLL(head);
    
    head = reverseLL(head);
    cout<<endl<<"Reversed Linked List: ";
    printLL(head);
}