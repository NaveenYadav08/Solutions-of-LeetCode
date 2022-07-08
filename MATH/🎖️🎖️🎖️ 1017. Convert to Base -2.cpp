https://leetcode.com/problems/convert-to-base-2/

    

class Solution {
public:
	string f(int N){
		if(N==0)return "";
		if(N%2==0)return f(N/-2)+"0";
		return f((N-1)/-2)+"1";
	}
	
	string baseNeg2(int N) {
		if(N==0)return "0";
		return f(N);
	}
};
