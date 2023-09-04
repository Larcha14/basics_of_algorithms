#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include<set>
using namespace std;

using pii = pair<int, int>;
const int INF = 1e9;

 int main(){
    ios::sync_with_stdio(false);
    int n, W;
    cin>>n>>W;
    vector<int> w(n);
    vector<int> c(n);
    for (int i=0; i<n; ++i){
        cin>>w[i]>>c[i];
    }
    // vector<vector<int> > dp(n+1, vector<int>(W+1, -INF));
    // for (int i=0; i<=n; ++i){
    //     dp[i][0]=0;
    // }
    // for (int i=0; i<=W; ++i){
    //     dp[0][i]=0;
    // }
    vector<int> dp_prev(W+1,0);
    vector<int> dp_next(W+1,0);
    for (int i=1; i<=n; ++i){
        dp_next.assign(W+1,0);
        for (int j=1; j<=W; ++j){
            dp_next[j]=dp_prev[j];
            // dp[i][j]=dp[i-1][j];
            if (w[i-1]<=j){
                dp_next[j]= max(dp_next[j], dp_prev[j-w[i-1]]+c[i-1]);
            //     dp[i][j]= max(dp[i][j], dp[i-1][j-w[i-1]]+c[i-1]);

            }
        }
        swap(dp_next, dp_prev);
    }
    cout<<dp_prev[W]<<endl;
 }
