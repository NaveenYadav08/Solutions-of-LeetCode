// LINK  https://leetcode.com/problems/maximum-product-subarray/

// left side se check krna
// right side sae check krna 


// code 
class Solution {
public:
    int maxProduct(vector<int>& nums) {

int max_prod = INT_MIN;
int tmp_prod = 1;

        // from left side
for(int i=0; i<nums.size(); i++){
	tmp_prod *= nums[i];
	max_prod = max(max_prod, tmp_prod);
	if(tmp_prod==0){
		tmp_prod=1;
	}
}

tmp_prod = 1;

        // from right side
for(int i=nums.size()-1; i>=0; i--){
	tmp_prod *= nums[i];
	max_prod = max(max_prod, tmp_prod);
	if(tmp_prod==0){
		tmp_prod=1;
	}
}

return max_prod; 
    }
};
