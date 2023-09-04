#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

const int64_t INF = 1e18;

struct wedge{
    int u, v;
    int64_t w;
};

using weight_graphs = vector< vector<wedge> >;
using item = pair<int64_t, int>;

int main(){
    int n, m, start, finish;
    int u, v;
    int64_t w;
    cin >>n>>m>>start;
    weight_graphs g(n);
    --start;
    for (int i=0; i<m; ++i){
        cin>>u>>v>>w;
        g[u-1].push_back({u-1, v-1, w});
    }
    int flag =1;
    vector <int64_t> d(n, INF);
    vector <int64_t> back(n, -1);
    vector <int> visited(n, 0);
    vector <int> pass;
    // slow
    // d[start]=0;
    // back[start]=start;  
    // for (int i=0; i<n; ++i){
    //     int mnid =-1;
    //     int64_t val= INF;
    //     for (int j=0; j<n;++j){
    //         if(visited[j]==0 and d[j]<val){
    //             mnid=j;
    //             val = d[j];
    //         }
    //     }
    //     u = mnid;
    //     visited[u]=1;
    //     for (int j=0; j<n; ++j){
    //         for (int y=0; y<g[j].size();++y){
    //             v= g[j][y].v;
    //             w=g[j][y].w;
    //             if (d[v]>d[u]+w){
    //                 d[v]=d[u]+w;
    //                 back[v]=u;
    //             }
    //         }
    //     }

    // }


    // fast
    set<item> pq;
    d[start]=0;
    back[start]=start;   
    for (int i=0; i<n; ++i){
        pq.insert({d[i], i});
    }
    while (!pq.empty()){
        item el = *pq. begin();
        pq. erase(pq.begin());
        u = el.second;
        visited[u]=1;
        for (int j=0; j<n; ++j){
            if(visited[j]==1){
                continue;
            }
            for (int y=0; y<g[j].size();++y){
                v= g[j][y].v;
                w=g[j][y].w;
                if (d[v]>d[u]+w){
                    pq.erase({d[v], v});
                    d[v]=d[u]+w;
                    back[v]=u;
                    pq.insert({d[v], v});
                }
            }
        }


    }
    for (int64_t i=0; i<n;++i){
        cout<<d[i]<<' ';
    }
    int f=finish;
    while(back[u]!=f){
        pass.push_back(f);
        u=back[u];
    }
    pass.push_back(u);
    reverse(pass.begin(), pass.end());
}