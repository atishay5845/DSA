#include <bits/stdc++.h>
using namespace std;


void insert_max_heap(int heap[],int x,int &size){
    heap[size] = x;
    size++;
    int i = size-1;
    while(i!=0&&heap[(i-1)/2]<heap[i]){
        swap(heap[i],heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
void print(int heap[],int n){
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;cin>>n;
    int size = 0;
    int heap[100];
    for(int i=0;i<n;i++){
        cin>>heap[i];
    }
    cout<<"Array elements: ";
    print(heap,n);
    for(int i=0;i<n;i++){
        insert_max_heap(heap,heap[i],size);
    }
    cout<<"Array after inserting in max heap: ";
    print(heap,size);
    
}