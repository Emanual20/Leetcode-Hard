class Solution {
public:
    bool isinline(vector<int> p1, vector<int> p2, vector<int> p3){
        return 1ll * (p2[0] - p1[0]) * p3[1] == 1ll * p3[0] * (p2[1] - p1[1]) + (p2[0] * p1[1] - p1[0] * p2[1]);
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) return points.size();
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int now = 0;
                for(int k = 0; k < points.size(); k++){
                    now += isinline(points[i], points[j], points[k]);
                }
                ans = max(ans, now);
            }
        }
        return ans;
    }
};