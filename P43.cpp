#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    string data;
    int priority;
    node* next;
};
class priorityQ{
    private:
    node* front;
    public:
    priorityQ(){
        front = NULL;
    }
    node* createNode(string v,int p){
        node* newnode = new node();
        newnode->data = v;
        newnode->priority = p;
        newnode->next = NULL;
    }
    void enq(string v,int p){
        node* newnode = createNode(v,p);
        if(front==NULL||front->priority>p){
            newnode->next = front;
            front = newnode;
        }else{
            node* temp = front;
            while(temp->next!=NULL&&temp->next->priority<=p){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        cout<<"Enquequed name in priority queue is "<<v<<" have priority "<<p<<endl;
    }
    void deq(){
        if(front ==NULL){
            cout<<"priority queue underflow"<<endl;
            return;
        }
        cout<<"Name to be dequeued from priority queue is "<<front->data<<endl;
        node* temp = front;
        front = front->next;
        delete temp;
    }
    void display(){
        if(front == NULL){
            cout<<"priority queue underfow"<<endl;
            return;
        }
        node* temp = front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
    }
};
int main(){
    priorityQ pq;
    int n;cin>>n;
    string names[n];;
    int prt[n];
    for(int i=0;i<n;i++){
        cin>>names[i]>>prt[i];
        pq.enq(names[i],prt[i]);
    }
    pq.display();
    pq.deq();
    pq.display();
    
}