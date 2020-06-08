#include <bits/stdc++.h>
using namespace std;
int main(void){
    array<int , 10 > catalan;
    const int n = 9; // don't go with c++ if n is high , use python implementation 
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i<=n; ++i){
        catalan[i] = 0;
        for(int j=0;j<i; ++j){
            catalan[i] += ( catalan[j] * catalan[i-j-1] ); 
        }
    }
    for(auto&itr:catalan){
        cout << (&itr - &catalan[0]) <<" : " << itr << '\n'; 
    }
    return 0;
}
