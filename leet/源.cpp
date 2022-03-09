#include<iostream>
#include<vector>
#include<functional>
#include<math.h>
#include<algorithm>
using namespace std;
		class Solution {
		public:
			int maximumRequests(int n, vector<vector<int>>& requests) {
				vector<int>cnt(n);
				int m = requests.size();
				int res = 0;
				function<void(int, int)>dfs = [&](int idx, int ans) {
					if (idx >= m) {
						for (int c : cnt) {
							if (c) {
								return;
							}
						}
						res = max(res, ans);
						return;
					}
					if (ans + m - idx + 1<res) {
						return;
					}
					cnt[requests[idx][0]]--;
					cnt[requests[idx][1]]++;
					dfs(idx + 1, ans + 1);
					cnt[requests[idx][0]]++;
					cnt[requests[idx][1]]--;
					dfs(idx + 1, ans);
				};
				dfs(0, 0);
				return res;
			}
			int nthUglyNumber(int n) {
				vector<int> dp(n + 1);
				dp[1] = 1;
				int p2 = 1, p3 = 1, p5 = 1;
				for (int i = 2; i <= n; i++) {
					int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
					dp[i] = min(min(num2, num3), num5);
					if (dp[i] == num2) {
						p2++;
					}
					if (dp[i] == num3) {
						p3++;
					}
					if (dp[i] == num5) {
						p5++;
					}
				}
				return dp[n];
			}
		};
int main()
{
	int n = 6;
	vector<vector<int>> requests = {
		{0,0},
		{1,1},
		{0,0},
		{2,0},
		{1,1},
		{2,1},
		{2,2},
		{0,1},
		{0,1}
	};
	Solution S;
	S.nthUglyNumber(n);
	return 0;
}