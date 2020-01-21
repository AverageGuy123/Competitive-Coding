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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void dfs_visit(int i, int n, int k, vector<int>&visit, vector<vector<int>>&adj_list){
    if(i<1 || i>n || visit[i]) return;
    visit[i]=k;
    for(int j=0; j<adj_list[i].size(); j++) dfs_visit(adj_list[i][j], n, k, visit, adj_list);
    return;
}

void dfs(int n, vector<int>&visit, vector<vector<int>>&adj_list){
    int component=0;
    for(int i=1; i<n+1; i++){
        if(visit[i]) continue;
        component++; dfs_visit(i, n, component, visit, adj_list);
    }
    return;
}

int main() {
    int n, threshold, queries, i, j;
    cin >> n >> threshold >> queries;
    vector<int>sources(queries, 0), destinations(queries, 0), cities(n+1, 0);
    for(i=0; i<queries; i++) cin >> sources[i];
    cin >> queries;
    for(i=0; i<queries; i++) cin >> destinations[i];
    // Create edges efficiently
    vector<vector<int>>adj_list(n+1); vector<int>visit(n+1, 0);
    for(i=threshold+1; i<n+1; i++){
        for(j=2*i; j<n+1; j+=i){
            if(gcd(i, j)<=threshold) continue;
            adj_list[i].push_back(j);
            adj_list[j].push_back(i);
        }
    }
    dfs(n, visit, adj_list);
    for(i=0; i<queries; i++){
        if(visit[sources[i]]==visit[destinations[i]]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

/*
 6
 1
 4
 1
 2
 4
 6
 4
 3
 3
 3
 4
 */
