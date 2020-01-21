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

int dfs_visit(int i, int j, int m, int n, int count, vector<vector<int>>&visit, vector<string>&M){
    if(i<0 || i>m-1 || j<0 || j>n-1 || M[i][j]=='P' || visit[i][j]) return -1;
    else if(M[i][j]=='E') return count;
    visit[i][j]=1;
    return max(dfs_visit(i, j+1, m, n, count+1, visit, M), max(dfs_visit(i+1, j, m, n, count+1, visit, M), max(dfs_visit(i-1, j, m, n, count+1, visit, M), dfs_visit(i, j-1, m, n, count+1, visit, M))));
}

void search(int *x, int *y, vector<string> &M){
    for(int i=0; i<M.size(); i++) {
        for(int j=0; j<M[i].length(); j++){
            if(M[i][j]=='R') {*x=i; *y=j;}
        }
    }
}

int main() {
    // Go from R to E, avoid P, unique path and count the steps required
    int m, n, i=0, j=0, x_src=-1, y_src=-1;
    scanf("%d %d\n", &m, &n);
    vector<vector<int>>visit(m, vector<int>(n, 0));
    string s, t; vector<string>M;
    for(i=0; i<m; i++){
        getline(cin, s);
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        M.push_back(s);
    }
    search(&x_src, &y_src, M);
    cout << dfs_visit(x_src, y_src, m, n, 0, visit, M) << endl;
    return 0;
}

