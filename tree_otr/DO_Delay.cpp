#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct segtree{
    int n;
    vector<int64_t> data, delay;
    segtree( const vector<int64_t>&a):n(a.size()), data(4*n), delay(4*n) {build(1, 1, n, a);}
    segtree(int _n):n(_n), data(4* n), delay(4*n) {
          
    }
    void build(int id, int l, int r, const vector<int64_t> &a){
        if (l==r){
            data[id]=a[l-1];
            return;
        }
        int m=(l+r)/2;
        build(id*2, l, m, a);
        build(id*2+1, m+1, r, a);
        data[id]=max(data[id*2], data[id*2 +1]);  // создание дерев
    }

    void push(int64_t id){
        if(delay[id]==0){
            return;
        }
        if (id*2<4*n){
            delay[id*2]+=delay[id];
        }
        if(id*2 +1<4*n){
            delay[id*2 +1]+=delay[id];
        }
        data[id]+=delay[id];
        delay[id]=0;
    }

    void set(int p, int x){
        set(1,1,n,p,x);
    }
    void set(int id, int l, int r, int p, int x){
        if(l==r){
            data[id]=x;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if(p<=m){
            set(id*2, l, m, p, x);
        } else{
            set(id*2 +1, m+1, r, p, x);
        }
        data[id]=max(data[id*2],data[id*2 +1]);
        // cout<<data[id]<<' ';
    }

    int64_t get(int ql, int qr){
        return get(1,1, n, ql, qr);
    }

    int64_t get(int id, int l, int r, int ql, int qr){
        if(ql<= l and r<=qr){
            return data[id];
        }
        push(id);
        int m=(l+r)/2;
        if (qr<=m){
            return get(id*2, l, m, ql, qr);
        }
        if(ql>=m+1){
            return get(id*2 +1, m+1, r, ql, qr);
        }
        // cout<<data[id]<<' ';
        return max(get(id*2, l, m, ql, qr),get(id*2 +1, m+1, r, ql, qr));
    }

    void update(int l, int r, int64_t x){
        update(1,1,n,l,r,x);
    }

    void update(int id, int l, int r, int ql, int qr, int64_t x){
        if(ql>r or qr<l){
            return;
        }
        if(ql<= l and r<=qr){
            delay[id]+=x;
            push(id);
            return;
        }
        int m= (l+r)/2;
        update(id*2, l, m, ql, qr, x);
        update(id*2 +1, m+1, r, ql, qr, x);
        data[id]=max(data[id*2], data[id*2 +1]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int64_t> a(n);
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
    segtree st(a);
    // cout<<'\n';
    int q;
    cin>>q;
    while (q--)    {
        int t; 
        cin>>t;
        if(t==1){
            int l, r;
            cin>>l>>r;
            cout<<st.get(l,r)<<'\n';
        } else if(t==2){
            int64_t x, y;
            cin>>x>>y;
            st.set(x, y);
        } else if(t==3){
            int l,r;
            int64_t x;
            cin>>l>>r>>x;
            st.update(l,r,x);
        }
    }
    
}

// 16
// 6 1 7 2 9 2 3 6 8 5 7 3 8 2 3 4
// 11
// 1 1 16
// 2 8 13
// 1 5 9
// 1 10 14
// 3 4 7 5
// 1 1 16
// 3 5 10 -3
// 1 9 13
// 2 1 -5
// 2 5 3
// 1 2 6