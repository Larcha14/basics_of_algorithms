#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

//просто решаем подзадачу


int minimum(int a, int b, int c){
    int mn=min(a,b);
    mn=min(mn, c);
    return mn;
}

int main(){
    int n;
    cin>>n;
    vector <int> change(n+1);
    change[0]=0;
    change[1]=1;
    change[2]=2;
    change[3]=1;
    change[4]=1;
    for(int i=5; i<=n; ++i){
        change[i]=1+minimum(change[i-1], change[i-3], change[i-4]);
    }
    // for(int i=0; i<)
    cout<<change[n];

}