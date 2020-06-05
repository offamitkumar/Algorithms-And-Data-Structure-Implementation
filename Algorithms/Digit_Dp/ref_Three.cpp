#include <bits/stdc++.h>
using namespace std;
int dp[11][90][90];
char s[150];
vector<int> isprime(101);
void siv(void){
    fill(isprime.begin(),isprime.end(),1);
    isprime.at(0)=isprime.at(1)=0;
    for(int i=2;i<=100;++i){
        if(isprime.at(i)){
            for(int j=i*i;j<=100;j+=i){
                isprime.at(j)=0;
            }
        }
    }
    return;
}
int rec(int digit,int odd ,int even){
    if(digit==0){
        if(even-odd<0){
            return 0;
        }else{
            return isprime.at(even-odd);
        }
    }
    int ans = 0;
    if(dp[digit][odd][even]!=-1){
        return dp[digit][odd][even];
    }else{
        for(int i=0;i<=9;++i){
            if(digit%2==0){
                ans+=rec(digit-1,odd,even+i);
            }else{
                ans+=rec(digit-1,odd+i,even);
            }
        }
    }
    return dp[digit][odd][even]=ans;
}
int query(int x){
    sprintf(s,"%d",x);
    int len = strlen(s);
    memset(dp,-1,sizeof(dp));
    int remain = len;
    int ans = 0;
    int odd = 0;
    int even = 0;
    for(int i=0;i<len;++i){
        int digit = s[i]-'0';
        --remain;
        for(int j=0;j<digit;++j){
            if((len-i)%2==0){
                ans+=rec(remain,odd , even+j);
            }else{
                ans+=rec(remain,odd+j,even);
            }
        }
        if((len-i)%2==0){
            even+=digit;
        }else{
            odd+=digit;
        }
    }
    return ans;
}
void sol(void){
    int a, b;scanf("%d%d",&a,&b);
    cout<<query(b+1)-query(a);
}
int main(void){
    siv();
    int testcase;scanf("%d",&testcase);
    while(testcase--){
        sol();
        cout<<endl;
    }
    return 0;
}
