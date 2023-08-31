#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    cin>>n;
    vector <int> first_sub(n+1);
    for(int i=1; i<=n;++i){
        cin>>first_sub[i];
    }
    cin>>m;
    vector <int> second_sub(m+1);
    for(int i=1; i<=m;++i){
        cin>>second_sub[i];
    }
    vector <vector <int> > state(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m;++j){
            if(first_sub[i]==second_sub[j]){
                state[i][j]=state[i-1][j-1]+1;
            } else{
                state[i][j]=max(state[i-1][j], state[i][j-1]);
            }
        }
    }
    // for(int i=0; i<=n; ++i){
    //     for(int j=0; j<=m;++j){
    //         cout<<state[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<state[n][m];
}