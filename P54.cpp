// sort algorithm
#include <bits/stdc++.h>
using namespace std;
int x=1;
void printarr(vector<string> &arr){
    cout<<"After Iteration "<<x<<": ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    x++;
}
int partition(vector<string> &vec, int low, int high) {
    string pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<string> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);
        printarr(vec);
        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    int n;cin>>n;
    cin.ignore();
    vector<string> vec;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        vec.push_back(str);
    }
    cout<<"Array before sorting: ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout<<endl;
    quickSort(vec, 0, n - 1);
    cout<<"Sorted array: ";
    for (auto i : vec) {
        cout << i << " ";
    }
    return 0;
}
