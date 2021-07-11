class Solution {
public:
    int candy(vector<int>& ratings) {
        const int maxn = 2e4 + 10;
        int left[maxn], right[maxn], ans = 0;
        for(int i = 0; i < ratings.size(); i++){
            if(i>0 && ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else left[i] = 1;
        }

        for(int i = ratings.size() - 1; i >= 0; i--){
            if(i<ratings.size()-1 && ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;
            }
            else right[i] = 1;
        }

        for(int i = 0; i < ratings.size(); i++){
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};