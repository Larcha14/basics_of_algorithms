#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct pairu{
    int l;
    int r;
};

bool cmp(pairu a, pairu b){
    if(a.r==b.r){
        return a.l<b.l;
    } else {
        return a.r<b.r;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt;
    cnt=0;
    cin>>n;
    vector <pairu> mass(n);
    for (int i=0; i<n; ++i){
        pairu a;
        cin>>a.l>>a.r;
        mass[i]=a;
    }
    sort(mass.begin(), mass.end(), cmp);
    int r_point=-1;
    // for (int i=0; i<n; ++i){
    //     cout<<mass[i].l<<' '<<mass[i].r<<'\n';
    // }
    for(int i=0; i<n;++i){
        if(mass[i].l>r_point){
            cnt++;
            r_point=mass[i].r;
        }
    }
    cout<<cnt;
}
