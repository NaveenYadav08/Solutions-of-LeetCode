https://leetcode.com/problems/minimum-number-of-refueling-stops/

 https://youtu.be/4RgqAQFr9WQ?t=75

DP solution-
For input :
120
10
[[10,60],[20,20],[30,30],[60,40]]

Filling of DP - 
// i 
// dp array
0
10   70   0   0   0   
1
10   70   90   0   0   
10   70   90   0   0   
2
10   70   90   120   0   
10   70   100   120   0   
10   70   100   120   0   
3
10   70   100   120   160   
10   70   100   140   160   
10   70   110   140   160   
10   70   110   140   160   




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
			if (dis < x and pq.empty()) return -1;
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
