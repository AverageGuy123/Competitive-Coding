#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

int main(){
    int n, i=0, j=0, profit=0, max_profit=0;
    cin >> n;
    vector<int>profits(n, 0), deadlines(n, 0);
    vector<pair<int, int>>V;
    for(i=0; i<n; i++) cin >> profits[i];
    for(i=0; i<n; i++) {cin >> deadlines[i]; V.push_back(make_pair(deadlines[i], profits[i]));}
    sort(V.begin(), V.end()); i=0;
    while(i<n){
        j=i; profit=0;
        while(j<n && V[i].first==V[j].first) {profit=max(profit, V[j].second); j++;}
        max_profit+=profit;
        i=j;
    }
    cout << max_profit << endl;
    return 0;
}