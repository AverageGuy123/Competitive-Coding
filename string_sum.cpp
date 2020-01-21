#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(string &s){
    for(int i=0; i<s.length(); i++) cout << s[i] << "";
    cout << endl;
}

void recurse(int n, int k, string &s){
    if(n==1) s.push_back('a'+ k - 1);
    else if(k<=26*(n-1)) {s.push_back('a'); recurse(n-1, k-1, s);}
    else {s.push_back('a'+ k-26*(n-1)-1); recurse(n-1, 26*(n-1), s);}
}

int main(){
    int n, k; string s;
    cin >> n >> k;
    recurse(n, k, s);
    print(s);
    return 0;
}