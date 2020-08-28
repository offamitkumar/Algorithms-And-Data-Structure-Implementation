#define int int64_t
int nCr(int n , int r){
    if(n-r < r){
       r = n-r;
    }
    int a{1}, b{1};
    if(r==0){
        return 1;
    }
    while(r){
        a *= r;
        b *= n;
        int x= __gcd(a,b);
        a/=x;
        b/=x;
        --n;
        --r;
    }
    return b;
}
