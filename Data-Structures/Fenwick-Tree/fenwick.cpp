


vector<int64_t>ftree(MAXN);
#define MSB(X) ((X)&(-X))

void update(int64_t a, int64_t val){
    a+=1ll;
    while(a<MAXN){
        ftree[a]+=val;
        a+=MSB(a);
    }
    return;
}

int64_t query(int64_t a){
    int64_t sum=ftree[0];
    while(a>0){
        sum+=ftree[a];
        a-=MSB(a);
    }
    return sum;
}



