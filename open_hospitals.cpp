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

void dfs_visit(int i, int V, vector<int>&visit, vector<int>&color, vector<vector<int>>&adj_list){
    if(i<1 || i>V || visit[i]) return;
    int j=0, color1=0, color2=0, color3=0;
    // visit
    visit[i]=1;
    for(j=0; j<adj_list[i].size(); j++){
        if(visit[adj_list[i][j]]) continue;
        dfs_visit(adj_list[i][j], V, visit, color, adj_list);
    }
    // color
    for(j=0; j<adj_list[i].size(); j++){
        if(color[adj_list[i][j]]==1) color1++;
        else if(color[adj_list[i][j]]==2) color2++;
        else if(color[adj_list[i][j]]==3) color3++;
    }
    // leaf node
    if(!color1 && !color2 && !color3) color[i]=1;
    // essential node
    else if(color1!=0 || (color1==0 && color2==0)) color[i]=2;
    // non-essential node
    else if(color2) color[i]=3;
    return;
}

int main() {
    // your code goes here
    int V, E, e, v1, v2, i, hospitals=0;
    cin >> V >> E;
    vector<vector<int>>adj_list(V+1); vector<int>visit(V+1, 0), color(V+1,0);
    for(e=0; e<E; e++){
        cin >> v1 >> v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    dfs_visit(1, V, visit, color, adj_list);
    for(i=1; i<V+1; i++) if(color[i]==2) hospitals++;
    cout << hospitals << endl;
    return 0;
}

/*
 12 11
 1 11
 1 2
 6 7
 1 6
 1 12
 2 3
 11 10
 12 9
 4 5
 12 8
 6 4
 */
