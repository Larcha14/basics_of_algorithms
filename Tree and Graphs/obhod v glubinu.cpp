#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

using graphs = vector< vector<int> >;
#define s 12;
#define f 14;

bool dfs(int u, const graphs &g, vector<int> &color, vector <int> &path, vector<int> &cycle ){
    if(color[u]==2){
        return false;
    }
    path.push_back(u);
    color[u]=1;
    for(int v : g[u]){
        if(color[v]==1){

        }
    }
    color[u]=2;
}

int main(){
    int n, m;
    int u, v;
    int start =s;
    int finish =f;
    cin >>n>>m;
    graphs g(n);
    for (int i=0; i<m; ++i){
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector <int> color(n, 0);
    vector <int> cycle;
    vector <int> path;
    queue <int> q;

    q.push(start);
    while(!q.empty()){
        int u2=q.front();
        q.pop();
        for (int v2 : g[u2]){
            if (step[v2]==-1){
                step[v2]=step[u2]+1;
                back[v2]=u2;
                q.push(v2);

            }
        }
    }
    vector <int> pass;
    int u3=finish;
    while(back[u3]!=u3){
        pass.push_back(u3);
        u=back[u3];

    }
    pass.push_back(u3);
    reverse(pass.begin(), pass.end());
    cout<<pass.size()<<endl;
    for (int elem: pass){
        cout<<elem+1<<' ';
    }

}

// 3 3 3
// 1 2
// 2 3
// 3 1

// ansv 2 1 0  

// 3 1 1
// 1 2

// ansv 0 1 -1 