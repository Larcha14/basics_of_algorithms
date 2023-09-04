#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include<set>
using namespace std;

const int64_t INF = 1e18;
vector<int64_t> r;
vector<int64_t> c;
vector<vector<int64_t> > memo;

int64_t solve(int i, int j){
    if (memo[i][j] < INF){
        return memo[i][j];
    }
    int64_t res =INF;
    for (int k=i; k<=j-1; ++k){
        int64_t matr_l = solve(i, k);
        int64_t matr_r = solve(k+1, j);
        res = min(res, matr_l+matr_r+r[i]*c[k]*c[j]);
    }
    memo[i][j]= res;
    return memo[i][j]; 
}
 
 int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    r.resize(n);
    c.resize(n);
    for (int i=0; i<n; ++i){
        cin>>r[i]>>c[i];

    }
    memo.resize(n, vector<int64_t>(n,INF));
    for (int i=0; i<n; ++i){
        memo[i][i]=0;
    }
    int64_t ans = solve(0,n-1);
    
    cout<<ans<<endl;
 }