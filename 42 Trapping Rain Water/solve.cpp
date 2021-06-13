class Solution {
public:
    
    int trap(vector<int>& height) {
        const int maxn = 3e4 + 10;
        int l_max[maxn] = {0}, r_max[maxn] = {0};
        long long ans = 0;

        int tmp = 0;
        for(int i = 0; i < height.size(); i++){
            l_max[i] = tmp;
            tmp = max(tmp, height[i]);
        }

        tmp = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            r_max[i] = tmp;
            tmp = max(tmp, height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            ans += max(min(l_max[i], r_max[i]) - height[i], 0);
        }

        return ans;
    }
};