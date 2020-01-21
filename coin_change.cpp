#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, i, j;
    cin >> m >> n;
    vector<int>coins(m, 0);
    for(i=0; i<m; i++) cin >> coins[i];
    // sort(coins.begin(), coins.end());
    // coins.erase(unique(coins.begin(), coins.end()), coins.end());
    vector<vector<int>>ways(n+1, vector<int>(m+1, 0));
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(i<coins[j-1]) ways[i][j]=ways[i][j-1];
            else if(i==coins[j-1]) ways[i][j]=1+ways[i][j-1];
            else ways[i][j]=ways[i][j-1]+ways[i-coins[j-1]][j];
        }
    }
    cout << ways[n][m] << endl;
    return 0;
}