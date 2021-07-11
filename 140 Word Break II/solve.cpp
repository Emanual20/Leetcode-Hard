const int maxn = 20 + 10;
class Solution {
public:
    int dp[maxn];
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> vec[maxn];
        map<string, int> dic;
        for (int i = 0; i < wordDict.size(); i++) {
            dic.insert(make_pair(wordDict[i], 1));
        }

        dp[0] = 1; vec[0].push_back("");
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                string tmp = s.substr(j, i - j + 1);
                int jdg = (int)(dp[j] && (dic.find(s.substr(j, i - j + 1)) != dic.end()));
                dp[i+1] = max(dp[i+1], jdg);
                if(jdg){
                    for(int k = 0; k < vec[j].size(); k++){
                        vec[i + 1].push_back(vec[j][k] + s.substr(j, i-j+1) + ((i == s.length() - 1) ? "" : " "));
                    }
                }
            }
        }

        return vec[s.length()];
    }
};