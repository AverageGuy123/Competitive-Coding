#include </Library/Developer/CommandLineTools/usr/include/c++/v1/iostream>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/vector>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/cmath>
#include </Library/Developer/CommandLineTools/usr/include/c++/v1/string>
//#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&A){
    for(int i=0; i<A.size(); i++) cout << A[i] << " ";
    cout << endl;
}

int main() {
    string s1, s2;
    getline(cin, s1); getline(cin, s2);
    double n1=s1.length(), n2=s2.length(), i=0, count=0;
    vector<int>counts(26, 0);
    for(i=0; i<n1; i++) counts[s1[i]-'a']++;
    for(i=0; i<n2; i++) {
        counts[s2[i]-'a']--;
        if(counts[s2[i]-'a']<0) count++;
    }
    cout << count << endl;
    return 0;
}
