 #include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;



struct segtree{
    struct node{
        node* left =nullptr;
        node* right=nullptr;
        int64_t data;

        node(int v):data(v){}
    };
    using ptr =node*;
    int n;
    ptr root=nullptr;

    segtree(int _n):n(_n) { root =new node(0);}
          
    int64_t get_data(ptr u){
        if(u==nullptr){
            return 0;
        } else{
            return u->data;
        }
    }

    void set(int p, int x){
        root = set(root,1,n,p,x);
    }
    ptr set(ptr u, int l, int r, int p, int x){ // возвращает указатель на новый узел
        if (u==nullptr){
            u=new node(0);
        }
        if(l==r){
            u->data=x;
            return u;
        }
        int m=(l+r)/2;
        if(p<=m){
            u->left=set(u->left, l, m, p, x);
        } else{
            u->right=set(u->right, m+1, r, p, x);
        }
        u->data=max(get_data(u->left),get_data(u->right));
        // cout<<data[id]<<' ';
        return u;
    }

    int64_t get(int ql, int qr){
        return get(root,1, n, ql, qr);
    }

    int64_t get(ptr u, int l, int r, int ql, int qr){
        if(u==nullptr){
            return 0;
        }
        if(ql<= l and r<=qr){
            return u->data;
        }
        int m=(l+r)/2;
        if (qr<=m){
            return get(u->left, l, m, ql, qr);
        }
        if(ql>=m+1){
            return get(u->right, m+1, r, ql, qr);
        }
        // cout<<data[id]<<' ';
        return max(get(u->left, l, m, ql, qr),get(u->right, m+1, r, ql, qr));
    }

};


int main(){
    ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q; // изначально дерево пустое, вводить начальные данные не нужно
    segtree st(n);
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
        } 
    }
    
}

// 10000 12
// 1 100 200
// 2 93 24
// 2 109 5
// 2 150 -4
// 2 66 4
// 1 95 200
// 1 110 200
// 1 150 150
// 1 748 156
// 1 1 747
// 1 555 749
// 1 1 10000
