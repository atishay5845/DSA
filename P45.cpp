#include <bits/stdc++.h>
using namespace std;

int moveDisks(int n, char source, char aux_pos, char destination) {
    if(n==1){
        cout<<"move disk 1 from rod "<<source<<" to rod "<<destination<<endl;
        return 1;
    }
    int move = moveDisks(n-1,source,destination,aux_pos);
    cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
    move = move+1;
    move = move + moveDisks(n-1,aux_pos,source,destination);
    return move;
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3');
    
    cout << totalMoves << endl;
    return 0;
}