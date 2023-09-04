#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long long bpow(long long x, long long y){
    int64_t z= 1;
    while (y>0){
        if (y%2==1){
            z=z*x;
        }
        x=x*x;
        y=y/2;
    }
    return z;
}

long long binpow(long long x, long long y){
    int64_t z= 1;
    while (y>0){
        if (y&1){
            z=z*x;
        }
        x=x*x;
        y=y>>1;
    }
    return z;
}


int main(){
    int64_t a,b,p;
    cin>>a>>b;
    p=binpow(a,b);
    cout<<p;

}