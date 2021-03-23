// Author: Emanual20
// Date: 3/23/2021
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		int is_odd = (len1 + len2) % 2, goal_index = (len1 + len2 + 1) / 2;
		int l1 = 0, r1 = len1 - 1, l2 = 0, r2 = len2 - 1;
		while (goal_index > 1) {
			int tmp1 = (l1 + goal_index / 2 - 1) >= len1 ? 0x7fffffff : nums1[l1 + goal_index / 2 - 1],
				tmp2 = (l2 + goal_index / 2 - 1) >= len2 ? 0x7fffffff : nums2[l2 + goal_index / 2 - 1];
			if (tmp1 > tmp2) {
				l2 += goal_index / 2;
			}
			else {
				l1 += goal_index / 2;
			}
			goal_index -= goal_index / 2;
		}
		if (is_odd) {
			return min(l1 >= len1 ? 0x7fffffff : nums1[l1], l2 >= len2 ? 0x7fffffff : nums2[l2]);
		}
		else {
			int tmp = min(l1 >= len1 ? 0x7fffffff : nums1[l1], l2 >= len2 ? 0x7fffffff : nums2[l2]);
			if (tmp == (l1 >= len1 ? 0x7fffffff : nums1[l1])) l1++;
			else l2++;
			return (tmp + min(l1 >= len1 ? 0x7fffffff : nums1[l1], l2 >= len2 ? 0x7fffffff : nums2[l2])) / 2.0;
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