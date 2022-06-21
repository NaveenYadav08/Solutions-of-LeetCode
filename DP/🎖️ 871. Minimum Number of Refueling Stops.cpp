https://leetcode.com/problems/minimum-number-of-refueling-stops/


class Solution {
public:
	// A FABULOUS GREEDY QUESTION - CODEFORCES LEVEL
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
		int dis = startFuel;
		int ans = 0;
		for (int i = 0; i < stations.size(); i++) {
			if (dis >= target) return ans;
			int x = stations[i][0], fuel = stations[i][1];
			while (dis < x && !pq.empty()) {
				int mx = pq.top();
				pq.pop();
				dis += mx;
				ans++;
			}
			if (dis < x) return -1;
			pq.push(fuel);
		}
		while (dis < target && !pq.empty()) {
				int mx = pq.top();
				pq.pop();
				dis += mx;
				ans++;
			}
		return dis < target ? -1: ans;
    }
};
