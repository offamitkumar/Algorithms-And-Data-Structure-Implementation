
long long inverse[MAXN];
void mod_inverse(int uMOD = (int)1e9+7){
    inverse[0] = inverse[1] = 1;
    for ( long long i = 2ll; i < MAXN; i++ ) {
        inverse[i] = inverse[uMOD % i] *  (uMOD - uMOD / i) % uMOD;
    }
}
