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
    int x;cin>>x;
    node* head = convertArr2DLL(arr);
    cout<<"Initial Doubly LL: ";
    printLL(head);
    
    cout<<endl<<"Doubly LL after inserting a node before head: ";
    head = insertBeforeHead(head,x);
    printLL(head);
    return 0;
}

