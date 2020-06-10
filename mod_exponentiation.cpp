const int MOD = (int)1e9+7;
long long m_pow(long long a, long long b){
    long long res{1ll};
    while(b){
        if(b&1ll){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b>>=1ll;
    }
    return res;
}
