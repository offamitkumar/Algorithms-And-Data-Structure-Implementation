const int MAXN = 500
long long dist[MAXN][MAXN];
long long n ,m , q , u , v ,w;

for(int i=0;i<MAXN;++i){
    for(int j=0;j<MAXN;++j){
        arr[i][j] = INT_MAX;
        arr[i][i] = 0;
        arr[j][j] = 0;
    }
}

// edge input 
for(int i=0;i<m;++i){
    int u , v, w; scanf("%d %d %d",&u ,&v ,&w);
    arr[u][v] = min(arr[u][v] ,(long long) w);
}

// keep the k before i & j
for(int k=0;k<n;++k){
    for(int i=0;i<n; ++i){
        for(int j=0;j<n;++j){
            if(arr[i][k] != INT_MAX && arr[k][j] != INT_MAX){
                arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
            }
        }
    }
}

// diagonal element will became negative if there 
// exist a negative weight cycle 
// find negative cycle
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
            if(arr[k][k]<0 && arr[i][k]!=INT_MAX && arr[k][j] != INT_MAX){
                arr[i][j] = INT_MIN;
            }
        }
    }
}

while(q--){
    int u , v; scanf("%d %d",&u,&v);
    if(arr[u][v]==INT_MAX){
        puts("Impossible");
    }else if(arr[u][v]==INT_MIN){
        puts("-Infinity");
    }else{
        printf("%lld\n",arr[u][v]);
    }
}
puts("");
}
