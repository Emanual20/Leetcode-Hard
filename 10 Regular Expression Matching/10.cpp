// Author: Emanual20
// Date: 3/23/2021
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	bool isMatch(string s, string p) {
		int lens = s.length(), lenp = p.length();
		int dp[23][33];
		for (int i = 0; i < lens + 2; i++) {
			for (int j = 0; j < lenp + 2; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i <= lens; i++) {
			for (int j = 0; j <= lenp; j++) {
				if (dp[i][j]) {
					dp[i + 1][j] = dp[i + 1][j] ||
						((i < lens&& j - 1 < lenp && j - 2 >= 0) && (charMatch(s[i], p[j - 2]) && p[j - 1] == '*'));
					dp[i + 1][j + 1] = dp[i + 1][j + 1] ||
						((i < lens&& j < lenp&& j + 1 >= lenp) && charMatch(s[i], p[j])) ||
						((i < lens&& j + 1 < lenp) && (charMatch(s[i], p[j]) && p[j + 1] != '*'));
					dp[i + 1][j + 2] = dp[i + 1][j + 2] ||
						((i < lens&& j + 1 < lenp) && (charMatch(s[i], p[j]) && p[j + 1] == '*'));
					dp[i][j + 2] = dp[i][j + 2] ||
						((j + 1 < lenp) && (p[j + 1] == '*'));
				}
			}
		}
		return dp[lens][lenp];
	}
	bool charMatch(char c1, char c2) {
		return c1 == c2 || c2 == '.';
	}
};
int main() {
	Solution s;
	string s1, s2;
	s1 = "a";
	s2 = "ab*";
	cout << s.isMatch(s1, s2) << endl;
	return 0;
}