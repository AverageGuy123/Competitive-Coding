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

int main() {
    // Regular Expression Matching
    string s, t="0101";
    getline(cin, s);
    double n=s.length(), m=t.length(), i=0, j=0;
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            // 1st row
            if(i==0){
                if(j==0 && t[i]!=s[j]) dp[i][j]=0;
                else if(j==0) dp[i][j]=1;
                else if(t[i]!=s[j]) dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i][j-1]+1;
            }
            // Other rows
            else if(t[i]!=s[j]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=1+dp[i][j-1];
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}

/*0101000*/
