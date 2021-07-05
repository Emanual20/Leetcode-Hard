class Solution {
public:
    typedef unsigned long ll;
    const int maxn = 1e3 + 10;
    const int MAX_INT = 0x7fffffff;
    int numDistinct(string s, string t) {
        ll dp[maxn][maxn];
        for(int i = 0; i <= s.length(); i++){
            dp[i][t.length()] = 1;
        }
        for(int i = 0; i < t.length(); i++){
            dp[s.length()][i] = 0;
        }
        for(int i = s.length() - 1; i >= 0; i--){
            for(int j = t.length() - 1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};