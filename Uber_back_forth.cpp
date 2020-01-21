#include </Library/Developer/CommandLineTools/usr/include/c++/v1/iostream>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/numeric>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/vector>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/cmath>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/string>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/map>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/queue>
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

int recurse(int r1, int r2, int c1, int n, vector<vector<int>>&A, vector<vector<vector<int>>>&dp){
    int c2=r1+c1-r2, coins=0;
    // base cases
    if(r1<0 || r1>n-1 || r2<0 || r2>n-1 || c1<0 || c1>n-1 || c2<0 || c2>n-1 ||
       A[r1][c1]==-1 || A[r2][c2]==-1) return INT_MIN;
    else if(r1==n-1 && c1==n-1) return A[r1][c1];
    else if(dp[r1][c1][r2]!=0) return dp[r1][c1][r2];
    // code starts
    if(r1==r2) coins=A[r1][c1];
    else coins=A[r1][c1]+A[r2][c2];
    coins+=max({recurse(r1+1, r2+1, c1, n, A, dp), recurse(r1+1, r2, c1, n, A, dp),
                recurse(r1, r2+1, c1+1, n, A, dp), recurse(r1, r2, c1+1, n, A, dp)});
    dp[r1][c1][r2]=coins;
    return coins;
}

int main() {
    // your code goes here
    int n, i, j;
    cin >> n;
    vector<vector<int>>A(n, vector<int>(n, 0));
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) cin >> A[i][j];
    }
    cout << max(0, recurse(0, 0, 0, n, A, dp)) << endl;
    return 0;
}

