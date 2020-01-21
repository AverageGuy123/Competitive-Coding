#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

int level_max_side(int n, vector<int>&A){
    int i=0, max_side=0; stack<int>S;
    vector<int>sides(n, 0);
    for(i=0; i<n; i++){
        while(!S.empty() && A[i]<=A[S.top()]){
            sides[S.top()]+=i-S.top();
            S.pop();
        }
        if(!S.empty()) sides[i]+=i-S.top()-1;
        else sides[i]+=i;
        S.push(i);
    }
    while(!S.empty()){
        sides[S.top()]+=n-S.top();
        S.pop();
    }
    for(i=0; i<n; i++) max_side=max(max_side, min(A[i], sides[i]));
    return max_side;
}

void histogram(vector<vector<int>>&M, vector<vector<int>>&H){
    int m=M.size(), n=M[0].size(), i=0, j=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(!i || !M[i][j]) H[i][j]=M[i][j];
            else H[i][j]=M[i][j]+H[i-1][j];
        }
    }
}

int main(){
    int m, n, i, j, max_side=0;
    cin >> m >> n;
    vector<vector<int>>M(m, vector<int>(n, 0)), H(m, vector<int>(n, 0));
    for(i=0; i<m; i++){
        for(j=0; j<n; j++) cin >> M[i][j];
    }
    histogram(M, H);
    for(i=0; i<m; i++) max_side = max(max_side, level_max_side(n, H[i]));
    cout << max_side << endl;
    return 0;
}