#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include<set>
using namespace std;
 
int main(){
    int n,k,l;
    cin>>n>>k>>l;
    set<int> m;
    for (int i=0; i<l;++i){
        int x;
        cin>>x;
        m.insert(x);
    }
    vector <int> a(n+1);
    a[0]=1;
    for (int i=1; i<=n;++i){
        if (m.count(i)){
            continue;
        }
        for (int j=1; j<=k and i-j>=0;++j){
            a[i]+=a[i-j];
        }
    }
    cout<<a[n];
}
//пропуск определенных клеток