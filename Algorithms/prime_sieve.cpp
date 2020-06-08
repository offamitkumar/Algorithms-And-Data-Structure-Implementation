#include <bits/stdc++.h>
using namespace std;


const int MAXN = (int)1e8+100;
bitset<MAXN>isprime;
int set_primes(const int &n){  // return count of primes till n (inclusive)
    isprime.set();
    isprime[0] = false;
    isprime[1] = false;
    int counter{1};
    for(int i=4;i<=n;i+=2){
        isprime[i] = false;
    }
    long long i;
    for(i = 3; i * i <= n; ++i){
        if(isprime[i]){
            ++counter;
            for(long long j = i*i; j <= n; j+=i){
                isprime[j] = false;
            }
        }
    }
    for(;i<=n;++i){
        counter+=isprime[i];
    }
    return counter;
}



int main(void){
    cout <<  set_primes ( 100000 ) << '\n'; 
    return 0;
}
