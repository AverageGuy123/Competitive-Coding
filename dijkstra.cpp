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

// Dijkstra implementation using priority_queue
int main() {
    int V, E, e, v1, v2, weight, distance;
    cin >> V >> E;
    vector<int>Distances(V, INT_MAX), Flags(V, 0);
    vector<vector<int>>Edges(V); map<pair<int, int>, int>Weights;
    for(e=0; e<E; e++){
        cin >> v1 >> v2 >> weight;
        // undirected
        Edges[v1].push_back(v2); Edges[v2].push_back(v1);
        Weights[make_pair(v1, v2)]=weight; Weights[make_pair(v2, v1)]=weight;
    }
    // Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    Distances[0]=0; pair<int, int>p=make_pair(Distances[0], 0); pq.push(p);
    while(!pq.empty()){
        p=pq.top(); pq.pop();
        v1=p.second; distance=p.first; Flags[v1]=1;
        for(int i=0; i<Edges[v1].size(); i++){
            v2=Edges[v1][i]; weight=Weights[make_pair(v1, v2)];
            if(Flags[v2] || Distances[v2]<=distance+weight) continue;
            // Push this neighbor
            Distances[v2]=distance+weight;
            p=make_pair(Distances[v2], v2); pq.push(p);
        }
    }
    // Distances
    for(int i=0; i<V; i++) cout << Distances[i] << " ";
    cout << endl;
    return 0;
}
