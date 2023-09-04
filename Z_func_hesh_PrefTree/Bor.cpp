#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
#include <string>
#include <map>
using namespace std;

struct trie{
    using dict = map<char, int>;

    struct node{
        dict go;
        int end=0;
    };
    int create_node(){
        data.push_back(node());
        return data.size()-1;
    }
    vector <node> data;

    trie(){
        create_node();
    }
    bool can_go(int u, char c){
        return data[u].go.count(c);
    }
    int go(int u, char c){
        return data[u].go[c];
    }
    void insert(const string &s){
        int u=0;
        for (int i=0; i<s.size(); ++i){
            if(!can_go(u, s[i])){
                data[u].go[s[i]]=create_node();
            }
            u = go(u,s[i]);
        }
        ++data[u].end;
    }
    
    int count(const string &s){
        int u=0;
        for (int i=0; i<s.size(); ++i){
            if(!can_go(u, s[i])){
                return 0;
            }
            u = go(u,s[i]);
        }
        return data[u].end;
    }

    void erase(const string &s){
        int u=0;
        for (int i=0; i<s.size(); ++i){
            u = go(u,s[i]);
        }
        --data[u].end;
    }

};

int main(){
    trie t;
    string s;
    // cin>>s;

    t.insert("abac");
    t.insert("abca");
    t.insert("ababa");
    cout<<t.count("ab")<<endl;
    cout<<t.count("abab")<<endl;
    cout<<t.count("ababa")<<endl;

}