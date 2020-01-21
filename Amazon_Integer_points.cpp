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

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int boundary_integrals(pair<int, int>p, pair<int, int>q){
    if(p.first==q.first) return abs(p.second-q.second)-1;
    else if(p.second==q.second) return abs(p.first-q.first)-1;
    else return gcd(abs(p.first-q.first), abs(p.second-q.second))-1;
}

int double_area_triangle(pair<int, int>p, pair<int, int>q, pair<int, int>r){
    int x1=p.first, x2=q.first, x3=r.first, y1=p.second, y2=q.second, y3=r.second;
    return x1*abs(y2-y3) + x2*abs(y3-y1) + x3*abs(y1-y2);
}

int main() {
    // Number of integral points inside a triangle
    int x1, x2, x3, y1, y2, y3, double_area, boundary_points, inside_points;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    pair<int, int>p = make_pair(x1, y1), q = make_pair(x2, y2), r = make_pair(x3, y3);
    boundary_points = boundary_integrals(p, q) + boundary_integrals(q, r) + boundary_integrals(r, p) + 3;
    double_area = double_area_triangle(p, q, r);
    // cout << boundary_points << " " << double_area << endl;
    inside_points = (double_area-boundary_points+2)/2;
    cout << inside_points << endl;
    return 0;
}

