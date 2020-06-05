// sum of digit between a and b
//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const long long MAXM = (long long)1e5+100;
const long long MAXN = (long long)1e5+100;
const long long MOD = (long long)1e5+100;
long long dp[20][200];
long long solve(string &a ,long long pos, long long sum){
    if(dp[pos][sum] != -1){
        return dp[pos][sum];
    }
    if((long long)a.size() == pos){
        return sum;
    }
    long long max_l = 9;
    long long ans{};
    for(long long i=0;i<=max_l; ++i){
        if(i == a[i]-'0'){
            ans += solve(a , pos+1, sum+i);
        }else{
            ans += solve(a , pos+1, sum+i);
        }
    }
    return dp[pos][sum]= ans;
}
long long sol(long long s){
    string a = to_string(s);
    const long long &n = a.size();
    memset(dp,-1,sizeof(dp));
    long long sum{};
    long long counter = 0;
    for(long long i=0;i<n;++i){
        long long digit = a[i]-'0';
        for(long long j=0;j<digit;++j){
            sum+=solve(a,i+1,counter+j);
        }
        counter+=digit;
    }
    return sum;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    long long t; scanf("%lld",&t);
    while(t--){
        long long a,b;
        cin >> a >> b;
        long long sum{};
        long long temp = a;
        while(temp){
            sum += temp%10ll;
            temp/=10ll;
        }
        printf("%lld\n",sol(b+1ll) - sol(a));
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
