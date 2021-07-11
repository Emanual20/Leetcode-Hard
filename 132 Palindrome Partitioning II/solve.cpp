class Solution {
public:
    const int inf = 0x7fffffff;
    int minCut(string s) {
        const int maxn = 2e3 + 10;
        int dp[maxn][maxn] = {0}, DP[maxn] = {0};
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(i >= j) dp[i][j] = 1;
            }
        }
        for(int i = 1; i < s.length(); i++){
            for(int j = 0; i + j < s.length(); j++){
                dp[j][i+j] = dp[j+1][i+j-1] && (s[j] == s[i+j]);
            }
        }

        for(int i = 0; i < s.length(); i++){
            DP[i] = inf;
        }

        for(int i = 0; i < s.length(); i++){
            if(dp[0][i]){
                DP[i] = 0;
            }
            else{
                for(int j = 1; j <= i; j++){
                    if(dp[j][i]){
                        DP[i] = min(DP[i], DP[j-1] + 1);
                    }
                }
            }
        }

        return DP[s.length() - 1];
    }
};