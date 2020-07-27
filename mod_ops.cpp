// Mod Operations /*{{{*/

void check2(int64_t &a){
    if(a<0){
        a = (a+MOD+MOD)%MOD;
    }
}

void check1(int64_t &a, int64_t &b){
    a%=MOD;
    b%=MOD;
    check2(a);
    check2(b);
}

int64_t mul(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a*b)%MOD;
    check2(temp);
    return temp;
}

int64_t add(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a+b)%MOD;
    check2(temp);
    return temp;
}

int64_t sub(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a-b)%MOD;
    check2(temp);
    return temp;
}

int64_t inverse(int64_t a, int64_t uMOD = (int64_t)1e9+7ll) { 
    int64_t m0 = uMOD; 
    int64_t y = 0ll, x = 1ll; 
    if (uMOD == 1ll) return 0ll; 
    while (a > 1ll) { 
        int64_t q = a / uMOD; 
        int64_t t = uMOD; 
        uMOD = a % uMOD, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
} 

int64_t div(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (mul(a,inverse(b,MOD)))%MOD;
    check2(temp);
    return temp;
}


/*}}}*/
