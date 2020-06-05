#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <memory.h>
#include <cassert>
#define FAST_INPUT_OUTPUT
#define MORE_THAN_ONE_TESTCASE // COMMENT IT
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define vvi vector<vector<int>>
#define viil vector<vector<long long>>
#define mii map<int , int>
#define mll map<long long , long long>
#define msi map<string , i>
#define msl map<string , long long>
#define mci map<char , int >
#define mcl map<char , long long>
#define umii unordered_map<int,int>
#define umll unordered_map<long long ,long long>
#define umsi unordered_map<string , int>
#define umsl map<string , long long> 
#define si set<int>
#define sl set<long long>
#define pii pair<int , int >
#define psi pair<string,int>
#define psl pair<string , long > 
#define pll pair<long long , long long>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpsi vector<psi>
#define vpsl vector<psl>
#define pqi priority_queue<int>
#define pql priority_queue<long long>
#define ub upper_bound
#define lb lower_bound
#define bint long long int
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define iv(v) for(auto &i:v){cin>>i;}
#define ov(v) for(auto i:v){cout<<i<<" ";}cout<<endl;
#define ovn(v) for(auto i:v){cout<<i<<endl;}
#define euv(v) for(auto i:v){cerr<<i<<" ";}cerr<<endl;
#define eovn(v) for(auto i:v){cerr<<i<<endl;}
#define os(s) for(auto itr:s){cout<<itr<<" ";}cout<<endl;
#define osn(s) for(auto itr:s){cout<<itr<<endl;}
#define eos(s) for(auto itr:s){cerr<<itr<<" ";}cerr<<endl;
#define eosn(s) for(auto itr:s){cerr<<itr<<endl;}
#define rep(i,x) for(auto i=0 ; i<x; ++i)
#define repa(i,a,b) for(auto i=a; i<b; ++i)
#define repe(i,x) for(auto i=0; i<=x; ++i)
#define repea(i,a,b) for(auto i=a;i<=b;++i)
#define ef else if
#define wh while
#define el else
#define ivar(x) int x; cin>>x
#define lvar(x) bint x; cin>>x
#define svar(x) string x; cin>>x
#define cvar(x) char x; cin>>x
#define fvar(x) float x; cin>>x
#define dvar(x) double x; cin>>x
#define endl '\n'
using namespace std;
char arr[20];
vi isprime(101);
int dp[15][100];
void siv(void){
    fill(all(isprime),1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i<=100;++i){
        if(isprime[i]){
            for(int j=i*i;j<=100;j+=i){
                isprime[j]=0;
            }
        }
    }
    return;
}
int rec(int digit,int sum){
    if(digit==0){
        return isprime[sum];
    }
    if(dp[digit][sum]!=-1){
        return dp[digit][sum];
    }
    int ans=0;
    for(int i=0;i<=9;++i){
        ans+=rec(digit-1,sum+i);
    }
    return dp[digit][sum]=ans;
}
int query(int x){
    memset(dp,-1,sizeof(dp));
    sprintf(arr,"%d",x);
    int len = strlen(arr);
    int ans{};
    int counter{};
    int remain=len;
    for(int i=0;i<len;++i){
        --remain;
        int digit = arr[i]-'0';
        for(int j=0;j<digit;++j){
            ans+=rec(remain,counter+j);
        }
        counter+=digit;
    }
    return ans;
}
auto SOLUTION_FUNCTION( void ) ->void {
    // your solution goes here 
    ivar(a);ivar(b);
    cout<<query(b+1)-query(a)<<endl;
    return ;
}

int main(void){
#ifdef FAST_INPUT_OUTPUT
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    cout<<fixed;
    cout<<boolalpha;
#endif
#ifdef MY_LOCAL_PROJECT
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int testcase = 1;


#ifdef MORE_THAN_ONE_TESTCASE
    cin>>testcase;
#endif
    siv();
    while(testcase--){
        SOLUTION_FUNCTION();
    }

#ifdef MY_LOCAL_PROJECT
    cout<<"Time : "<<1.0*(double)clock()/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}
