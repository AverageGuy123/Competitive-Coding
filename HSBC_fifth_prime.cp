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

int is_prime(int n){
    if(n<=1) return 0;
    else if(n<=3) return 1;
    else if(n%2==0 || n%3==0) return 0;
    for(int i=5; i*i<=n; i+=6){
        if(n%i==0 || n%(i+2)==0) return 0;
    }
    return 1;
}

void print(vector<pair<int, int>>&A){
    for(int i=0; i<A.size(); i++) cout << A[i].first << "," << A[i].second << " ";
    cout << endl;
}

int main() {
    // 5th closest prime number to a given number
    int n, lefts=0, left_number, rights=0, right_number, i;
    cin >> n; left_number=n-1; right_number=n;
    // top 5 left and top 5 right
    vector<int>numbers;
    while(lefts<5) {
        if(is_prime(left_number)) {lefts++; numbers.push_back(left_number);}
        left_number--;
    }
    while(rights<5){
        if(is_prime(right_number)) {rights++; numbers.push_back(right_number);}
        right_number++;
    }
    vector<pair<int, int>>V;
    for(i=0; i<numbers.size(); i++) V.push_back(make_pair(abs(numbers[i]-n), -numbers[i]));
    sort(V.begin(), V.end());
    // print(V);
    cout << -V[4].second << endl;
    return 0;
}

