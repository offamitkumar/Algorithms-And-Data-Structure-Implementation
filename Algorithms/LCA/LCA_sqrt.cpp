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
vector<int>depth;
vector<int>parent;
vector<bool>visited;
vector<int>jumping_parent;
const int BLOCK_SIZE = 40;
void dfs(int node , int prev){
    depth[node] = depth[prev]+1;
    visited[node] = true;
    parent[node] = prev;
    if(depth[node]%BLOCK_SIZE == 0){
        jumping_parent[node] = parent[node];
    }else{
        jumping_parent[node] = jumping_parent[prev];
    }
    for(auto&itr:graph[node]){
        if(!visited[itr]){
            dfs(itr , node);
        }
    }
    return;
}

int lca(int u , int v){
    while(u != v){
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

int sq_lca(int u , int v) {
    while(jumping_parent[u] != jumping_parent[v]){
        if(depth[u] > depth[v]){
            u = jumping_parent[u];
        }else if(depth[v] > depth[u]){
            v = jumping_parent[v];
        }
    }
    return lca(u,v);
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
    depth.assign(n+1000,-1);
    parent.assign(n+1000,-1);
    visited.assign(n+1000,false);
    jumping_parent.assign(n+1000,-1);
    for(int i=1;i<=n;++i){
        int child; scanf("%d",&child);
        for(int x,j=0;j<child;++j){
            scanf("%d",&x);
            graph[i].push_back(x);
        }
    }
    // we can do a dfs to find the height or 
    // define the block size manually 
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            dfs(i,0);
        }
    }
    int q; scanf("%d",&q);
    while(q--){
        int u , v; scanf("%d%d",&u,&v);
        printf("%d\n",sq_lca(u,v));
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
