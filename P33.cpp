#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};
node* insert(node* head,int val){
    node* newE = new node(val);
    if(head == nullptr){
        head = newE;
        return head;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newE;
    return head;
}
node* del(node* head){
    node* slow = head;
    node* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = head;
    node* pre = nullptr;
    while(temp){
        
        if(temp->data == slow->data){
            pre->next = temp->next;
            delete(temp);
            return head;
        }
        pre = temp;
        temp = temp->next;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int n;cin>>n;
    node* head = nullptr;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        head = insert(head,val);
    }
    cout<<"Original Linked List: ";
    print(head);
    cout<<endl<<"Updated Linked List: ";
   head = del(head);
   print(head);
   return 0;
}