const int MOD = (int)1e9+7;
int64_t m_pow(int64_t a, int64_t b , int64_t uMOD = (int64_t)1e9+7){
    int64_t res{1ll};
    while(b){
        if(b&1ll){
            (res*=a)%=uMOD;
        }
        (a*=a)%=uMOD;
        b>>=1ll;
    }
    return res;
}
