
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {

    vector<int>dist(n+3 , 1000000);
    dist[s] = 0;
    int m = edges.size();
    bool relaxed = true;
    for(int i=0; i<=n && relaxed; ++i){
        relaxed = false;
        for(int j=0;j<m;++j){
            const int &start = edges[j][0];
            const int &end = edges[j][1];
            const int &weight = edges[j][2];
            if(dist[end] > dist[start] + weight){
                relaxed = true;
                dist[end] = dist[start] + weight;
            }
            if(dist[start] > dist[end] + weight){
                relaxed = true;
                dist[start] = dist[end] + weight;
            }
        }
    }
    

    // extracting the distance of all other nodes 
    // except the root node 
    vector<int>ans;
    for(int i=1;i<=n;++i){
        if(i == s)continue;
        if(dist[i]==1000000){
            dist[i] = -1; // not reachable 
        }
        ans.push_back(dist[i]);
    }
    return ans;
}
