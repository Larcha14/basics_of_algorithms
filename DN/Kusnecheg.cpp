#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
 
int main(){
    int n,k,s;
    cin>>n>>k;
    vector <int> a(n+1);
    a[0]=1;
    for (int i=1; i<=n;++i){
        for (int j=1; j<=k and i-j>=0;++j){
            a[i]+=a[i-j];
        }
    }
    cout<<a[n];
}