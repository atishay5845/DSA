#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    
    node(int d) {
        data = d;
        next = NULL;
    }
};

struct stack {
    node* top;  
    int size;   
    
    
    stack() {
        top = NULL;
        size = 0;
    }

    
    void push(int x) {
        node* element = new node(x);  
        element->next = top;  
        top = element;        
        size++;               
    }

    
    int pop() {
        if (top == NULL) {  
            cout << "Stack underflow" << endl;
            return -1;
        }
        int poppedData = top->data;  
        node* temp = top;            
        top = top->next;             
        delete temp;                
        size--;                     
        return poppedData;          
    }

    int stacktop() {
        if (top == NULL) {  
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;   
    }

  
    void printStack() {
        node* temp = top;
        while (temp != NULL) {  
            cout << temp->data << " ";  
            temp = temp->next;  
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout<<n<<endl;
    int arr[n];  
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
    }
    cout<<"Elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    stack s; 
    
    
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    
    cout << "Elements in the stack (from top to bottom): ";
    s.printStack();

    return 0;
}
