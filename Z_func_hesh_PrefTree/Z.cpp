#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

vector <int> z_func(const string & s){
    int n=s.size();
    vector <int> z(n);
    z[0]=n;
    int l=0;
    int r=0;
    for (int i=1; i<n; ++i){
        if (i<r){
            z[i]=min(z[i-l], r-i);
        }
        while (i+z[i]<n and s[z[i]]==s[i+z[i]]){
            ++z[i]; 
        }
        if(i+z[i]>r){
            l=i;
            r=z[i];
        }
    }
    return z;
}
 

 int main(){
    string s;
    vector<int> z=z_func(s);
 }