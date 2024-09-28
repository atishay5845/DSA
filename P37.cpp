#include <bits/stdc++.h>
using namespace std;
#define max 30
int main(){
    int n;cin>>n;
    if(n==0){
        cout<<"The STACK is empty";
        return 0;
    }
    if(n>max){
        cout<<"Stack overflow";
        return 0;
    }
    vector<int> s;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        s.push_back(e);
    }
    int x;cin>>x;
    bool found = false;
    for(int i=0;i<n;i++){
        if(s[i]==x){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"Element found";
    }else{
        cout<<"Element not found";
    }
}