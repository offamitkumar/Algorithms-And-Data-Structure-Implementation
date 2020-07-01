
int n; cin >> n; 
vector<vector<int>>arr(n+1, vector<int>(n+1,INT_MAX));
for(int i=0; i< n;++i){
    for(int j=0;j<n;++j){
        cin >> arr[i][j];
    }
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
// find negative cycle
bool ok = false;
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
            if(arr[k][k]<0 && arr[i][k]!=INT_MAX && arr[k][j] != INT_MAX){
                ok = true;
                goto hell;
            }
        }
    }
}
