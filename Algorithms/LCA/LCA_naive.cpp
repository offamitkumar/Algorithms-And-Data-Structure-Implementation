//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e5+100;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>parent;
vector<int> depth;
void dfs(int node , int dep=0 , int par = -1){
    depth[node] = dep;
    visited[node] = true;
    parent[node] = par;
    for(auto itr:graph[node]){
        if(!visited[itr]){
            dfs(itr,dep+1 , node);
        }
    }
}
int lca(int u , int v){
    while(u!=v){
        if(depth[u] > depth[v]){
            u = parent[u];
        }else if(depth[v] > depth[u]){
            v = parent[v];
        }else{
            u = parent[u];
            v = parent[v];
        }
    }
    return u;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n; scanf("%d",&n);
    graph.resize(n+1000);
    parent.assign(n+1000,-1);
    visited.assign(n+1000,false);
    depth.assign(n+1000,0);
    for(int j=1;j<=n;++j){
        int k; scanf("%d",&k);
        for(int l =0; l<k; ++l ){
            int x; scanf("%d",&x);
            graph[j].push_back(x);
        }
    }
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            dfs(i);
        }
    }
    int q; scanf("%d",&q);
    while(q--){
        int u , v; scanf("%d %d",&u , &v);
        printf("%d\n",lca(u,v));
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
