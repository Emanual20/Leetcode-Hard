class Solution {
public:
    int tot;
    string ans;
    void dfs(int now, int goal, int k, vector<int>& isused, string& now_str){
        if(now == goal) {
            tot++;
        }
        if(tot == k) {
            ans = now_str;
            return;
        }
        for(int i = 0; i < isused.size(); i++){
            if(!isused[i]){
                isused[i] = 1;
                now_str += char(i + '1');
                dfs(now+1, goal, k, isused, now_str);
                if(tot == k){
                    return;
                }
                now_str = now_str.substr(0, now_str.length() - 1);
                isused[i] = 0;
            }
        }
    }
    string getPermutation(int n, int k) {
        tot = 0;
        vector<int> isused;
        for(int i=0;i<n;i++){
            isused.push_back(0);
        }
        string str = "";
    
        int mult = 1;
        for(int i = 2; i < n; i++) mult*=i;
        int first_ch = ceil(k * 1.0 / mult);
        str += char(first_ch + '0');
        isused[first_ch - 1] = 1;
        dfs(1, n, k - mult * (first_ch - 1), isused, str);

        // dfs(0, n, k, isused, str);
        return ans;
    }
};