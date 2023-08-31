#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

//просто решаем подзадачу

const int INF=1e9+7;

int minimum(int a, int b, int c){
    int mn=min(a,b);
    mn=min(mn, c);
    return mn;
}

int main(){
    int n;
    cin>>n;
    vector <int> step(n+1, INF);
    vector <int> back_step(n+1, -1);
    step[0]=0;
    step[1]=0;
    back_step[1]=1;
    for(int i=1; i<n; ++i){
        int inc, dob, tre;
        inc=i+1;
        dob=i*2;
        tre=i*3;
        if(step[inc]>1+step[i]){
            step[inc]=1+step[i];
            back_step[inc]=i;
        }
        // step[inc]=min(step[inc], 1+step[i]);
        if(dob<=n){
            if(step[dob]>=1+step[i]){
                step[dob]=1+step[i];
                back_step[dob]=i;
            }
        }
        if(tre<=n){
            if(step[tre]>=1+step[i]){
                step[tre]=1+step[i];
                back_step[tre]=i;
            }
        }
    }
    // for(int i=0; i<=n;++i){
    //     cout<<step[i]<<' ';
    // }
    cout<<step[n]<<'\n';
    // cout<<'\n';
    int i=n;
    stack <int> answ;
    answ.push(n);
    while(back_step[i]!=i){
        answ.push(back_step[i]);
        i=back_step[i];
    }
    // answ.push(1);
    cout<<answ.top();
    answ.pop();
    while(answ.empty()==false){
        cout<<' '<<answ.top();
        answ.pop();
    }
}