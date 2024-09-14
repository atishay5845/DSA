#include <bits/stdc++.h>
using namespace std;
 
class node{
    public:
    int data;
    node* next;
    node* back;
    public:
    node(int data1,node* next1,node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
node* convertArr2DLL(vector<int> &arr){
    node* head= new node(arr[0]);
    node* prev = head;
    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node* insertBeforeHead(node* head,int v){
    node* newhead=new node(v,head,nullptr);
    head->back=newhead;
    return newhead;
}

node* insertBeforekthelement(node* head,int k,int v){
    if(k==1){
        return insertBeforeHead(head,v);
    }
    node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(k==cnt){
            break;
        }
        temp=temp->next;
    }
    node* prev = temp->back;
    node* newnode = new node(v,temp,prev);
    prev->next=newnode;
    temp->back = newnode;
    return head;
}
void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k,v;cin>>k>>v;
    node* head = convertArr2DLL(arr);
    cout<<"Initial Doubly LL: ";
    printLL(head);
    
    cout<<endl<<"Doubly LL after inserting a node before head: ";
    head = insertBeforekthelement(head,k,v);
    printLL(head);
    return 0;
}

