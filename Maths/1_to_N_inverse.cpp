/*Inverse 1 to N {{{*/
int inverse[MAXN];
void mod_inverse(int uMOD = (int)1e9+7){
    inverse[0] = inverse[1] = 1;
    for ( int i = 2ll; i < MAXN; i++ ) {
        inverse[i] = inverse[uMOD % i] *  (uMOD - uMOD / i) % uMOD;
    }
}
/*}}}*/
