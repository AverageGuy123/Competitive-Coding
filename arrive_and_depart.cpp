#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, count=0;
    cin >> n;
    vector<int>arrival(n, 0), duration(n, 0), departure(n, 0);
    vector<pair<int, int>>v;
    for(i=0; i<n; i++) cin >> arrival[i];
    for(i=0; i<n; i++) {
        cin >> duration[i]; 
        departure[i]=arrival[i]+duration[i];
        v.push_back(make_pair(arrival[i], departure[i]));
    }
    sort(v.begin(), v.end());
    stack<pair<int, int>>s;
    for(i=0; i<n; i++){
        if(s.empty() || s.top().second<=v[i].first) s.push(v[i]);
        else if(v[i].second<s.top().second) {s.pop(); s.push(v[i]);}
        else continue;
    }
    while(!s.empty()) {s.pop(); count++;}
    cout << count << endl;
    return 0;
}