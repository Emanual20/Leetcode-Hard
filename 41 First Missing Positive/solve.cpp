class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] <= 0){
                nums[i] = len + 1;
            }
        }

        for(int i = 0; i < len; i++){
            if(abs(nums[i]) <= len){
                if(nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            }
        }

        for(int i = 0; i < len; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return len + 1;
    }
};