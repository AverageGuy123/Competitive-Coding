#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int seconds(int h, int m, int s){
    return h*3600+m*60+s;
}

int difference(int h1, int m1, int s1, int h2, int m2, int s2){
    int secs1=seconds(h1, m1, s1), secs2=seconds(h2, m2, s2);
    if(secs1>=secs2) return secs1-secs2;
    else return difference(24, 0, 0, h2, m2, s2) + difference(h1, m1, s1, 0, 0, 0);
}

int main(){
    string S1, S2;
    getline(cin, S1); getline(cin, S2);
    int h1=10*(S1[0]-'0')+(S1[1]-'0'), m1=10*(S1[3]-'0')+(S1[4]-'0'), s1=10*(S1[6]-'0')+(S1[7]-'0'),
        h2=10*(S2[0]-'0')+(S2[1]-'0'), m2=10*(S2[3]-'0')+(S2[4]-'0'), s2=10*(S2[6]-'0')+(S2[7]-'0'),
        s_diff=difference(h1, m1, s1, h2, m2, s2), m_diff=s_diff/60, h_diff=s_diff/3600;
    // hour diff
    if(h_diff>1) {cout << to_string(h_diff) << " hours ago" << endl; return 0;}
    else if(h_diff==1) {cout << "1 hour ago" << endl; return 0;}
    // min diff
    if(m_diff>1) {cout << to_string(m_diff) << " minutes ago" << endl; return 0;}
    else if(m_diff==1) {cout << "1 minute ago" << endl; return 0;}
    // sec diff
    if(s_diff>1) {cout << to_string(s_diff) << " seconds ago" << endl; return 0;}
    else if(s_diff==1) {cout << "1 second ago" << endl; return 0;}
    return 0;
}