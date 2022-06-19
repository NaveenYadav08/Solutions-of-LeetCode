https://leetcode.com/problems/k-th-smallest-prime-fraction/
786. K-th Smallest Prime Fraction

https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/1678746/C%2B%2B-Binary-Search-With-detailed-explanation

findCount(arr, target) : this returns the number of fractions in the array, which have a value less than or equal to target
						 also this function returns the numerator and the denominator of the fraction that is closest to target (it might be equal as well)



for now, just assume this function is already implemented

now all the fractions under consideration lie between arr[0] / arr[n-1] and 1

the approach is to apply binary search on this range

what to search for? Ans : find the value of target, such that the number of fractions which are less than or equal to target are exactly equal to K
when you find such a target, return the fraction which is supplied by this findCount() function

now mid = (low + high)/2;

vector<int> cur = findCount(arr, mid);
cur[0] gives the number of fractions whose values are less than or equal to mid
in case cur[0] == 0, means we have found the answer

when cur[0] > k, it means that we are too far ahead, so move to the left portion
when cur[0] < k, it means that we are too left, so move to the right portion

implemeting findCount(arr, target)

we use two pointer method to do this

treat each element as a fixed denominator , and find the largest i, such that arr[i] / arr[j] <= target
and after finding this i, to your answer, add all the numbers from 0 to i
(because all the numbers are sorted, so all the numbers till i, when treated as numerator (and arr[j] as the fixed denominator),
will always be less than target)

[1, 3, 5, 7, 11, 13 , 17] (try out on this array)

  
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

		while (low <= high) {
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
