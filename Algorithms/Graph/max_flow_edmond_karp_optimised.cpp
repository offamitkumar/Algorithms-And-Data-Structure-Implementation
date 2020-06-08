#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int64_t ,
        null_type ,
        less<int64_t> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 505
int64_t capacity[MAXN][MAXN];
int64_t temp_capacity[MAXN][MAXN];
int64_t n;
vector<int64_t>parent(MAXN);
//vector<bool>visited(MAXN);
bitset<MAXN>visited;
bool bfs(int64_t s , int64_t t){
    fill(parent.begin() , parent.end() , -1);
//    fill(visited.begin() , visited.end() , false);
    visited.reset();
    queue<int64_t>q;
    q.push(s);
    bool is_path_found = false;
    while(q.empty()==false and is_path_found == false){
        int64_t current_node = q.front();
  //      visited[current_node] = true;
        visited.set(current_node);
        q.pop();
        for(int64_t i=0;i<n;++i){
            if(capacity[current_node][i]>0 && !visited[i]){
//                visited.at(i)=true;
                visited.set(i);
                parent[i] = current_node;
                if(i == t){
                    return true;
                }
                q.push(i);
            }
        }
    }
    return false;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int64_t m, s, t; cin >> n >> m >> s >> t;
    memset(capacity , 0, sizeof(capacity));
    for(int64_t u,v,c,i=0;i<m; ++i){
        cin >> u >> v >> c;
        capacity[u][v] = c;
        temp_capacity[u][v] = c;
    }
    int64_t max_flow = 0;
//    map<pair<int64_t,int64_t>,int64_t>edge_participated;
    vector<tuple<int,int,int>>edge_participated;
    while(bfs(s , t)){
        int64_t v = t;
        int64_t flow = numeric_limits<int64_t>::max();
        while(v != s){
            int64_t u = parent[v];
            flow = min(flow , capacity[u][v]);
            v = u;
        }
        v = t;
        max_flow += flow;
        while( v != s ) {
            int64_t u = parent[v];
            capacity[u][v]-=flow;
            capacity[v][u]+=flow;
            v = u;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(temp_capacity[i][j] && capacity[i][j]<temp_capacity[i][j]){
                edge_participated.push_back(make_tuple(i,j,temp_capacity[i][j]-capacity[i][j]));
            }
        }
    }
    cout<<n<<' '<<max_flow<<' '<<edge_participated.size()<<'\n';
    for(auto&itr:edge_participated){
        int a,b,c;
        tie(a,b,c) = itr;
        cout<<a<<' '<<b<<' '<<c<<'\n';
//        cout<<get<1>(itr)<<' '<<get<2>(itr)<<' '<<get<3>(itr)<<'\n';
    }
    return 0;
}
