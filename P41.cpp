
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int v){
        data = v;
        next = nullptr;
    }
};
node* front = nullptr;
node* rear = nullptr;
class que{
    public:
    void enq(int v){
        node* newnode = new node(v);
        newnode->data = v;
        newnode->next = nullptr;
        if(rear==nullptr){
            front = rear = newnode;
        }else{
            rear->next = newnode;
            rear = newnode;
        }
        cout<<"Enqueued value: "<<v<<endl;
    }
    void deq(){
        
        if(front == nullptr){
            cout<<"underflow"<<endl;
            return;
        }else{
            cout<<"Value to be Dequeued present on front: "<<front->data<<endl;
            node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void display(){
        if(front==nullptr){
            cout<<"underflow";
            return;
        }else{
        node* temp = front;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        }
    }
};
int main(){
    que q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enq(x);
    }
    cout<<"Queue: ";
    q.display();
    cout<<endl;
    q.deq();
    cout<<"Queue after deleting one element: ";
    q.display();
}