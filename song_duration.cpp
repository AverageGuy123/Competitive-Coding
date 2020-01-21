#include </Library/Developer/CommandLineTools/usr/include/c++/v1/iostream>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/vector>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/cmath>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/string>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/map>
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    // Songs Durations
    int n, i, count=0;
    cin >> n;
    vector<int>A(n, 0);
    for(i=0; i<n; i++) cin >> A[i];
    map<int, int>M;
    // 2Sum
    for(i=0; i<n; i++){
        if(M.find(60-A[i])!=M.end()) count+=M[60-A[i]];
        if(M.find(A[i])==M.end()) M[A[i]]=1;
        else M[A[i]]++;
        // cout << A[i] << " " << M[A[i]] << endl;
    }
    cout << count << endl;
    return 0;
}
/*
 6
 5 10 50 10 50 55 --> 5
 */
