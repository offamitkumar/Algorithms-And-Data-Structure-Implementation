const int MAXN = 500
long long dist[MAXN][MAXN];

for(int i=0;i<MAXN;++i){
    for(int j=0;j<MAXN;++j){
        dist[i][j] = INT_MAX;
        // distance of node from itself 
        dist[i][i] = 0;
        dist[j][j] = 0;
    }
}

// input 
for(int i=0;i<m;++i){
    int u,v,w; scanf("%d %d %d",&u,&v,&w);
    dist[u][v] = w;
    // input might say dist[u][u] != 0 , assume that it's not true
    dist[u][u] = 0;
    dist[v][v] = 0;
}
    


// keep the k before i & j : 0 based Indexing 
    for(int k=0;k<n;++k){
        for(int i=0;i<n; ++i){
            for(int j=0;j<n;++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }



// keep the k before i & j : 1 based Indexing 
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n; ++i){
            for(int j=1;j<=n;++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

