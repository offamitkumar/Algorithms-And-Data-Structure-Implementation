//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm> 
#include <string> 
//  #include <sstream> 
//  #include <fstream>
//  #include <iomanip> 
#include <chrono> 
#include <numeric>
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
//  #include <unordered_map>
//  #include <unordered_set>
#include <set>
#include <map>
//  #include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//                   TypeInfo ,
//                   null_type ,
//                   less<TypeInfo> ,
//                   rb_tree_tag ,
//                   tree_order_statistics_node_update 
//       > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 

const long long MAXM = (long long)1e5+100;
const long long MAXN = 5000100;
const long long MOD = (long long)1e9+7;

vector<long long>ftree(MAXN);
#define MSB(X) ((X)&(-X))

void update(long long a, long long val){
    a+=1;
    while(a<MAXN){
        ftree[a]+=val;
        a+=MSB(a);
    }
    return;
}

long long query(long long a){
    long long sum=ftree[0];
    while(a>0){
        sum+=ftree[a];
        a-=MSB(a);
    }
    return sum;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m; cin >> n >> m; 
    while(m--){
        char c; cin >> c; 
        if(c=='+'){
            long long a,b; cin >> a >> b;
            update(a , b);
        }else{
            long long a; cin >> a;
            cout << query(a) << '\n'; 
        }
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
