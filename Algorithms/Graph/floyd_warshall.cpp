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
    }
    

    // keep the k before i & j
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n; ++i){
            for(int j=1;j<=n;++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
     // query section 
    scanf("%d",&m);
    while(m--){
        int a,b; scanf("%d %d",&a,&b);
        printf("%lld\n",(dist[a][b]==INT_MAX) ? -1ll : dist[a][b]);
    }
