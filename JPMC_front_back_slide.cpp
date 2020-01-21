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

int main() {
    // maximum out of starting m or last m elements
    int n, m, o, i, j, k, val, sum=0;
    cin >> n >> m >> o;
    vector<int>A(n, 0);
    for(i=0; i<n; i++) cin >> A[i];
    // push
    priority_queue<pair<int, int>>pq;
    for(i=0; i<=min(n-1, m-1); i++) pq.push(make_pair(A[i], -i));
    for(j=n-1; j>=max(0, n-m); j--) pq.push(make_pair(A[j], -j));
    // pop
    while(o){
        val=pq.top().first; k=-pq.top().second; sum+=val; pq.pop();
        cout << val << " " << k << endl;
        if(k<i && i<=min(n-1, j)) {
            pq.push(make_pair(A[i], -i));
            i++;
        }
        if(k>j && j>=max(0, i)) {
            pq.push(make_pair(A[j], -j));
            j--;
        }
        o--;
    }
    cout << sum << endl;
    return 0;
}

