#include <bits/stdc++.h>
using namespace std;
int dp[20][90][90];
char arr[200];
int rec(int digit,int odd , int even){
    if(digit==0){
        return ((even-odd)==1);
    }
    if(dp[digit][odd][even]!=-1){
        return dp[digit][odd][even];
    }
    int ans(0);
    for(int i=0;i<=9;++i){
        if(digit%2==0){
            ans+=rec(digit-1,odd,even+i);
        }else{
            ans+=rec(digit-1,odd+i,even);
        }
    }
    return dp[digit][odd][even]=ans;
}
int query(int x){
    memset(dp,-1,sizeof(dp));
    sprintf(arr,"%d",x);
    int len = strlen(arr);
    int even =0;
    int odd =0;
    int ans =0;
    int remain=len;
    for(int i=0;i<len;++i){
        int digit = arr[i]-'0';
        --remain;
        for(int j=0;j<digit;++j){
            if((len-i)%2==0){
                ans+=rec(remain,odd,even+j);
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
    int testcase;scanf("%d",&testcase);
    while(testcase--){
        sol();
        cout<<endl;
    }
}
