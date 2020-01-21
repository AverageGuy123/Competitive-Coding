#include </Library/Developer/CommandLineTools/usr/include/c++/v1/iostream>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/vector>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/cmath>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/string>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/map>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/queue>
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int is_possible(int diff, int k, int n, vector<int>&A){
    int i=0, curr_element=A[0], elements=1;
    for(i=0; i<n; i++){
        if(A[i]-curr_element<diff) continue;
        curr_element=A[i]; elements++;
        if(elements==k) return 1;
    }
    return 0;
}

void binary_search(int lo, int hi, int* max_diff, int k, int n, vector<int>&A){
    if(lo>=hi) return;
    int mid=(lo+hi)/2;
    if(!is_possible(mid, k, n, A)) {binary_search(lo, mid, max_diff, k, n, A); return;}
    *max_diff=max(mid, *max_diff);
    binary_search(mid+1, hi, max_diff, k, n, A);
}

int main() {
    // Maximize the minimum consecutive difference of k elements from an array
    int n, k, lo, hi, max_diff, i;
    cin >> n >> k;
    vector<int>A(n, 0);
    for(i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    lo=0; hi=A[n-1]; max_diff=0;
    binary_search(lo, hi, &max_diff, k, n, A);
    cout << max_diff << endl;
    return 0;
}

