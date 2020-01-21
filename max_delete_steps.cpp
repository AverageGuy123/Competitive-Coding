#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(string s){
    for(int i=0; i<s.length(); i++) cout << s[i] << "";
    cout << endl;
}

bool comparator(string s1, string s2){
    if(s1.length()<s2.length()) return true;
    else if(s2.length()<s1.length()) return false;
    else return s1.compare(s2)<0 ? true : false;
}


int main(){
    int n, i=0, j=0, l=-1, m=0;
    scanf("%d\n", &n);
    string s; vector<string>V;
    for(i=0; i<n; i++){
        getline(cin, s);
        V.push_back(s);        
    }
    sort(V.begin(), V.end(), comparator);
    // Map
    map<string, int>M;
    for(i=0; i<n; i++) {
        if(!i || V[i].length()!=l+1) {M[V[i]]=1; l=V[i].length(); continue;}
        for(j=0; j<V[i].length(); j++){
            s=V[i]; s.erase(s.begin()+j);
            if(M.find(s)==M.end()) continue;
            else if(M.find(V[i])==M.end()) M[V[i]]=1+M[s];
            else M[V[i]]=max(M[V[i]], 1+M[s]);
        }
        if(i<n-1 && V[i].length()<V[i+1].length()) l=V[i].length();
        // Update to a new l or don't
        m=max(m, M[V[i]]);
    }
    cout << m << endl;
    return 0;
}
