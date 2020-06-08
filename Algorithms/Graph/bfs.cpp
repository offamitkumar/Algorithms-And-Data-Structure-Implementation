
/*
 *  n -> total nodes ( 1 based indexing )
 *  m -> total edges 
 *  s -> source 
 *
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int>visited_time(n+1 , 100000);
    vector<vector<int>>graph(n+1);
    for(auto&itr:edges){
        graph[itr[0]].push_back(itr[1]);
        graph[itr[1]].push_back(itr[0]);
    }
    visited_time[s] = 0;
    queue<int>q; q.push(s);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto&itr:graph[node]){
            if(visited_time[itr] == 100000){
                q.push(itr);
                visited_time[itr] = visited_time[node]+1;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;++i){
        if(i==s){
            continue;
        }
        if(visited_time[i] == 100000){
            visited_time[i] = -1;
        }
        ans.push_back(visited_time[i]);
    }
    return ans;
}
