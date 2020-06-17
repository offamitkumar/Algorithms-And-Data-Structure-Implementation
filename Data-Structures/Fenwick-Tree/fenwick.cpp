const long long MAXN = 5000100;
const long long MOD = (long long)1e9+7;

vector<long long>ftree(MAXN);
#define MSB(X) ((X)&(-X))

void update(long long a, long long val){
    a+=1;
    while(a<MAXN){
        ftree[a]+=val;
        a+=MSB(a);
    }
    return;
}

long long query(long long a){
    long long sum=ftree[0];
    while(a>0){
        sum+=ftree[a];
        a-=MSB(a);
    }
    return sum;
}

