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
node* reverseDLL(node* head)
{   
    if(head==NULL||head->next==NULL){
        return head;
    } 
    node* back = NULL;
    node* current = head;
    while(current!=NULL){
        back = current->back;
        current->back = current->next;
        current->next=back;
        current=current->back;
    }
    return back->back;
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
    
    node* head = convertArr2DLL(arr);
    cout<<"Initial Doubly LL: ";
    printLL(head);
    
    cout<<endl<<"Doubly LL after reversing it: ";
    head = reverseDLL(head);
    printLL(head);
    return 0;
}

