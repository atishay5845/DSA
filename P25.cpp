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
node* deleteHead(node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    node* prev = head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
node* deleteTail(node* head){
    node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node* newtail=tail->back;
    newtail->next = nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}
node* deletekthelement(node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    node* knode = head;
    while(knode!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }else{
            knode=knode->next;
        }
    }
    node* prev = knode->back;
    node* front = knode->next;
    if(prev==NULL&&front==NULL){
        return NULL;
    }else if(prev==NULL){
        return deleteHead(head);
    }else if(front==NULL){
        return deleteTail(head);
    }else{
        prev->next=front;
        front->back=prev;
        delete knode;
        return head;
    }
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
    int k;cin>>k;
    node* head = convertArr2DLL(arr);
    cout<<"Initial Doubly LL: ";
    printLL(head);
    
    cout<<endl<<"Doubly LL after deleting kth element: ";
    head = deletekthelement(head,k);
    printLL(head);
    return 0;
}

