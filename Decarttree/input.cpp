#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

mt19937 rng(time(NULL)); // - генератор случайных чисел

struct treap_node {
    treap_node* left;
    treap_node* right;
    int x;
    int64_t y;

    treap_node(int _x) : x(_x){
        left =nullptr;
        right =nullptr;
        y =rng(); //y - рандом
    }
};

using treap = treap_node*;

void split(treap t, int x0, treap & t1, treap & t2){
    if(t==nullptr){
        t1=nullptr;
        t2=nullptr;
    }
    if(x0> t->x){
        split(t->right, x0, t->right, t2);
        t1=t;
    } else{
        split(t->right, x0, t1, t->left);
        t2=t;
    }

}

treap merge(treap t1, treap t2){
    if (t1==nullptr){
        retrun t2;
    }
    if(t2==nullptr){
        return t1;
    }
    if(t1->y >t2->y){
        t1->right = merge(t1->right, t2);
        return t1;
    } else{
        t2->left=merge(t1, t2->left);
        return t2;
    }
}

void print_t(treap t, int h){
    if(t==nullptr){
        return;
    }
    print_t(t->left, h+1);
    for(int i=0; i<4*h, ++i){
        cout<<' ';
    }
    cout<<t->x<<endl;
    print_t(t->right, h+1);
}

int main(){
    ios::sync_with_stdio(false);
    treap t =nullptr;
    for(int i=1; i<20; ++i){
        treap m= new treap_node(i);
        c=merge(t, m);
    }
    print_t(t);
    int q;
    cin>>q;
    whilr(q--){
        string s;
        cin>>s;
        int x;
        cin>>x;
        treap l =nullptr, m= nullptr, r= nullptr;
        if(s=="insert"){
            split(t, x,l,r);
            m=new treap_node(x);
            t=merge(merge(l,m), r);
            cout<<"Querry\n";
            print(t);
            cout<<endl;
        }
    }

}