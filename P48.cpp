// You are using GCC
#include <bits/stdc++.h>
using namespace std;

int moveDisks(int n, char s, char a, char d) {
    if(n==1){
        cout<<"move disk 1 from rod "<<s<<" to rod "<<d<<endl;
        return 1;
    }
    int move = moveDisks(n-1,s,d,a);
    cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
    move = move+1;
    move = move + moveDisks(n-1,a,s,d);
    return move;
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3');
    
    cout << totalMoves << endl;
    return 0;
}