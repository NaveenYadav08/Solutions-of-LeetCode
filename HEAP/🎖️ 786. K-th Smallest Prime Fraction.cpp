https://leetcode.com/problems/k-th-smallest-prime-fraction/
786. K-th Smallest Prime Fraction

class Solution {
public:
	vector<int> findCount(vector<int> &arr, double mid) {
		int n = arr.size();
		int num = arr[0];
		int denom = arr[n - 1];

		int i = 0; int cnt = 0;
		for (int j = 1; j < n; j++) {
			while (arr[i] <= mid * arr[j]) i++;
			cnt += i;

			if (i > 0 && arr[i - 1] * denom >= num *  arr[j]) {
				num = arr[i - 1];
				denom = arr[j];
			}
		}

		return {cnt, num, denom};
	}
    
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

		int n = arr.size();
		double low = (arr[0] * 1.0) / arr[n - 1];
		double high = 1;

		if (k == 1) return {arr[0], arr[n - 1]};
		vector<int> ans;

		while (low < high) {
			double mid = (low + high) / 2;
			vector<int> cur = findCount(arr, mid);

			if (cur[0] == k) {
				return {cur[1], cur[2]};
			}

			else if (cur[0] > k) {
				high = mid;
			} else low = mid;
		}

		return {};
	}
};
