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

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

void create(int n, vector<int>&B, vector<vector<int>>&V){
    double zeros=V[0].size(), ones=V[1].size(), twos=V[2].size(), flag=0;
    if((zeros==0 && ones!=0 && twos!=0) || (zeros>ones+twos+1)) {B.push_back(-1); return;}
    flag=0;
    while(zeros>1 && ones){
        if(flag==0) {B.push_back(V[0][V[0].size()-1]); V[0].pop_back(); zeros--; flag=1;}
        else {B.push_back(V[1][V[1].size()-1]); V[1].pop_back(); ones--; flag=0;}
    }
    while(ones) {B.push_back(V[1][V[1].size()-1]); V[1].pop_back(); ones--;}
    B.push_back(V[0][V[0].size()-1]); V[0].pop_back(); zeros--;
    flag=2;
    while(zeros and twos){
        if(flag==0) {B.push_back(V[0][V[0].size()-1]); V[0].pop_back(); zeros--; flag=2;}
        else {B.push_back(V[2][V[2].size()-1]); V[2].pop_back(); twos--; flag=0;}
    }
    while(twos) {B.push_back(V[2][V[2].size()-1]); V[2].pop_back(); twos--;}
    if(zeros) {B.push_back(V[0][V[0].size()-1]); V[0].pop_back(); zeros--;}
    return;
}

int main() {
    // your code goes here
    int n, T, t, i;
    cin >> T;
    for(t=0; t<T; t++){
        cin >> n;
        vector<int>A(n, 0), B; vector<vector<int>>V(3);
        for(i=0; i<n; i++){
            cin >> A[i];
            if(A[i]%3==0) V[0].push_back(A[i]);
            else if(A[i]%3==1) V[1].push_back(A[i]);
            else V[2].push_back(A[i]);
        }
        create(n, B, V);
        print(B);
    }
    return 0;
}

