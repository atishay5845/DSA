#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void insert_b(struct node **head_ref,int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next=*head_ref;
    *head_ref = newnode;
}
void printll(struct node *temp){//temporary pointer
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    struct node *head=NULL;
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>x;
	    insert_b(&head,x);
	}
	printll(head);
	return 0;
}