#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include<set>
using namespace std;
 
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    int n,k,l;
    cin>>n>>k;
    vector <int> c(n+1);
    vector <int> a(n+1, INF);
    for (int i=1; i<n;++i){
            cin>>c[i];
    
    }
    a[0]=0;
    for (int i=1; i<=n;++i){
        for (int j=1; j<=k and i-j>=0;++j){
            a[i]=min(a[i], a[i-j]);
        }
        a[i]+=c[i];
    }
    cout<<a[n]<<endl;
    vector<int> pass;
    int u=n;
    while (a[u]!=u){
        pass.push_back(u);
        u=a[u];
    }
    pass.push_back(u);
    reverse(pass.begin(), pass.end());
    for (int elem : pass){
        cout<<elem<<' ';
    }


}
//стоимость посещения клетки