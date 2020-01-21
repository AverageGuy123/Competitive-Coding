#include </Library/Developer/CommandLineTools/usr/include/c++/v1/iostream>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/vector>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/cmath>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/string>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/deque>
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

int main() {
    int n, k, i;
    cin >> n >> k;
    vector<int>A(n, 0), B;
    for(i=0; i<n; i++) cin >> A[i];
    deque<int>dq;
    for(i=0; i<k; i++) {
        while(!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    B.push_back(A[dq.front()]);
    for(i=k; i<n; i++){
        while(!dq.empty() && i-k+1>dq.front()) dq.pop_front();
        while(!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
        B.push_back(A[dq.front()]);
    }
    print(B);
    cout << *max_element(B.begin(), B.end()) << endl;
    return 0;
}
