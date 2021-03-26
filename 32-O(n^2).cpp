// Author: Emanual20
// Date: 3/24/2021
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	int longestValidParentheses(string s) {
		int ret = 0;
		for (int i = 0; i < s.length(); i++) {
			ret = max(ret, calc(s.substr(i, s.length())));
		}
		return ret;
	}
	int calc(string s) {
		int ret = 0, now = 0, tot = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') tot++;
			else if (s[i] == ')') tot--;
			now++;

			if (tot == 0) {
				ret = max(ret, now);
				tot = 0;
			}
			else if (tot < 0) {
				ret = max(ret, now - 1);
				now = 0;
				tot = 0;
			}
		}
		return ret;
	}
};
int main() {
	Solution s;
	string s1;
	s1 = ")()())";
	cout << s.longestValidParentheses(s1) << endl;
	return 0;
}