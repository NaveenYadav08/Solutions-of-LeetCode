https://www.interviewbit.com/problems/interview-questions/

int Solution::bulbs(vector<int> &A) {

int state= 0, ans = 0;

		    for (int i = 0;i < A.size();i++) {
			    if (A[i] == state) {
				    ans++;
				    state = 1 - state;
			    }
                
		    }
		    return ans;

}


