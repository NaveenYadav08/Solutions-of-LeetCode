// GFG -  https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

// CODE -

class Solution{
public:
	// A comparison function which is used by sort() in printLargest()
	static int myCompare(string X, string Y) {
	    // first append Y at the end of X
	    string XY = X.append(Y);

	    // then append X at the end of Y
	    string YX = Y.append(X);

	    // Now see which of the two formed numbers is greater
	    return XY.compare(YX) > 0 ? 1 : 0;
	}
public:
	// The main function that prints the arrangement with the largest value.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    // Sort the numbers using library sort function. The function uses
	    // our comparison function myCompare() to compare two strings.
	    // See http://www.cplusplus.com/reference/algorithm/sort/ for details
	    sort(arr.begin(), arr.end(), myCompare);

	    string ans;
	    for (int i = 0; i < arr.size(); i++) ans += arr[i];
	    return ans;
	}
};
