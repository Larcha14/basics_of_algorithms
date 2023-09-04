#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

const int64_t MOD =1e9+7;
const int N=1e5;
int64_t fact[N+1];
int64_t inv_fact[N+1];

long long binpow(long long x, long long y){
    int64_t z= 1;
    while (y>0){
        if (y&1){
            z=(z*x)%MOD;
        }
        x=(x*x)%MOD;
        y=y>>1;
    }
    return z;
}


int64_t inverse(int64_t x){
    return binpow(x, MOD - 2);
}

void precalc(){
    fact[1]=1;
    for (int i=2;i<=N; ++i){
            fact[i]=(fact[i-1]*i)%MOD;
    }
    for (int i=1;i<=N; ++i){
            inv_fact[i]=inverse(fact[i]);
    }

}

int main(){
    precalc();
}