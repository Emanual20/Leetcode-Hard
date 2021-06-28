class Solution {
public:
    struct item {
        int pos;
        int height;
    };
    vector<item> mono_stack;
    vector<int> items_left, items_right;
    void mono_left2right(vector<int>& heights) {
        mono_stack.clear();
        items_left.clear();
        mono_stack.push_back({ -1, -1 });
        for (int i = 0; i < heights.size(); i++) {
            while (mono_stack.back().height >= heights[i]) {
                mono_stack.pop_back();
            }
            items_left.push_back(mono_stack.back().pos);
            mono_stack.push_back({ i, heights[i] });
        }
    }
    void mono_right2left(vector<int>& heights) {
        mono_stack.clear();
        items_right.clear();
        item a; a.pos = heights.size(); a.height = -1;
        mono_stack.push_back(a);
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (mono_stack.back().height >= heights[i]) {
                mono_stack.pop_back();
            }
            items_right.push_back(mono_stack.back().pos);
            mono_stack.push_back({ i, heights[i] });
        }
    }
    int solve(vector<int>& heights) {
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, heights[i] * (items_right[heights.size() - 1 - i] - items_left[i] - 1));
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        mono_left2right(heights);
        mono_right2left(heights);
        return solve(heights);
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int> heights(matrix[0].size(),0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else heights[j] = heights[j] + 1;
                cout<<heights[j]<<" ";
            }
            cout<<endl;
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};