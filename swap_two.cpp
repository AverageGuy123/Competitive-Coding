#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(string &s){
    for(int i=0; i<s.length(); i++) cout << s[i] << "";
    cout << endl;
}

int main(){
    string s;
    getline(cin, s);
    int n=s.length(), i=0;
    for(i=0; i<n; i++){
        if((s[i]-'0')%2 || s[i]>=s[n-1]) continue;
        iter_swap(s.begin()+i, s.begin()+n-1); break;
    }
    if(i!=n) {print(s); return 0;}
    for(i=n-1; i>-1; i--) {
        if((s[i]-'0')%2) continue;
        iter_swap(s.begin()+i, s.begin()+n-1); break;
    }
    if(i==-1) s="-1";
    print(s);
    return 0;
}