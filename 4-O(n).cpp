// Author: Emanual20
// Date: 3/23/2021
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        nums1.push_back(0x7fffffff); nums2.push_back(0x7fffffff);
        if ((l1 + l2) % 2) {
            double now = 0;
            int r = (l1 + l2) / 2 + 1, p1 = 0, p2 = 0;
            for (int i = 0; i < r; i++) {
                double exp = min(nums1[p1], nums2[p2]);
                if (nums1[p1] == exp) p1++;               
                else if (nums2[p2] == exp) p2++;              
                now = exp;
            }
            return now;
        }
        else {
            double now = 0;
            int r = (l1 + l2) / 2 + 1, p1 = 0, p2 = 0;
            for (int i = 0; i < r; i++) {
                double exp = min(nums1[p1], nums2[p2]);
                if (i == r - 2 || i == r - 1) now += exp;
                if (nums1[p1] == exp) p1++;
                else if (nums2[p2] == exp) p2++;
            }
            return now / 2;
        }
    }
};
int main() {
    Solution s;
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    cout << s.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}