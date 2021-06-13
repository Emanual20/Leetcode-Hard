class Solution {
public:
    #define isoffvalid(off, length) ((off) < (length) && (off) >= 0) 
	bool isMatch(string s, string p) {
        const int maxn = 2e3 + 10;
        bool dp[maxn][maxn] = {false};
        dp[0][0] = true;
        int lens = s.length(), lenp = p.length();

        for(int i = 0; i <= lens; i++){
            for(int j = 0; j <= lenp; j++){
                if(dp[i][j]){
                    if(isoffvalid(j, lenp) && p[j] == '*') dp[i][j+1] = true;
                    if(isoffvalid(j-1, lenp) && p[j-1] == '*') dp[i+1][j] = true;
                    if((isoffvalid(i, lens) && isoffvalid(j, lenp)) 
                    && (s[i] == p[j] || p[j] == '?' || p[j] == '*')) dp[i+1][j+1] = true;
                }
            }
        }

        return dp[lens][lenp];
	}
};