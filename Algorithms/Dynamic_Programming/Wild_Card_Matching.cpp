class Solution {
public:
    bool isMatch(string s, string p) {
        int row = s.size();
        int col = p.size();
        vector<vector<bool>>dp(row+1,vector<bool>(col+1,false));
        dp[0][0]=true;
        for(int i=1;i<=col;++i){
            if(p[i-1]=='*'){
                dp[0][i] = dp[0][i-1];
            }else{
                dp[0][i] = false;
            }
        }
        for(int i=1;i<=row;++i){
            for(int j=1;j<=col;++j){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[row][col];
    }
};
