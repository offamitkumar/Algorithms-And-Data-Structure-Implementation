

const int MAXN = (int)1e6+100;
long long factorial[MAXN];
void mod_factorial(int uMOD = (int)1e9+7){
    factorial[0] =1;
    for(int i=1;i <= MAXN; ++i){
        (factorial[i] = factorial[i-1] * i) %= uMOD;
    }
}
