// Write your code here
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> bfs(int n, int commander, vector<int>&level, vector<int>&count, vector<int>&cummulative, vector<int>&parent, vector<vector<int>>&children){
    // level and count
    queue<int>q;    q.push(commander);  level[commander]=1;
    while(!q.empty()){
        int i=q.front();    q.pop();   count[level[i]]++;
        for(int j=0; j<children[i].size(); j++){
            level[children[i][j]]=level[i]+1;
            q.push(children[i][j]);
        }
    }
    // cummulative
    for(int l=1; l<n+1; l++) cummulative[l]=cummulative[l-1]+count[l];
    // handshakes and fistbumps 
    int fistbumps=0, handshakes=0; 
    for(int i=1; i<n+1; i++) {
        handshakes+=level[i]-1;
        if(i!=commander) fistbumps+=cummulative[level[parent[i]]]-level[i]+1;
    }
    for(int l=1; l<n+1; l++) if(count[l]) fistbumps+=(count[l]*(count[l]-1))/2;
    return make_pair(handshakes, fistbumps);
}

int main(){
    int T, n, commander;
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n;
        vector<int>parent(n+1, 0), level(n+1, 0), count(n+1, 0), cummulative(n+1, 0);
        vector<vector<int>>children(n+1);
        for(int i=1; i<n+1; i++) {
            cin >> parent[i];
            if(parent[i]) children[parent[i]].push_back(i);
            else commander=i;
        }
        pair<int, int>p = bfs(n, commander, level, count, cummulative, parent, children);
        cout  << p.first << " " << p.second << endl;
    }
    return 0;
}
