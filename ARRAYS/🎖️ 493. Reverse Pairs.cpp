https://leetcode.com/problems/reverse-pairs/description/
// modifaction of count inversion 


class Solution {
public:
    int count = 0;
    void mergeSortedArrays(int ll, int mid, int ul, vector<int>& nums){
        int i = 0, j = 0, k = ll;
        vector<int> lft(nums.begin() + ll, nums.begin() + mid + 1); 
        vector<int> rgt(nums.begin() + mid + 1, nums.begin() + ul + 1);
        int s1 = lft.size(), s2 = rgt.size();

        //Code to compare the conditions for reverse pairs
        while(i < s1 && j < s2){
            if(lft[i] <= 2 * (long)rgt[j])
                i++;
            else{
                count += s1 - i;
                j++;
            }
        }

        //Code for merging the two sorted arrays
        i = 0, j = 0;
        while(i < s1 && j < s2){
            if(lft[i] <= rgt[j])
                nums[k++] = lft[i++];
            else
                nums[k++] = rgt[j++];
        }
        while(i < s1)
            nums[k++] = lft[i++];
        while(j < s2)
            nums[k++] = rgt[j++];
    }

    void mergeSort(int ll, int ul, vector<int>& nums){
        if(ll == ul)
            return ;
        int mid = (ll + ul) >> 1;
        mergeSort(ll, mid, nums);
        mergeSort(mid + 1, ul, nums);
        mergeSortedArrays(ll, mid, ul, nums);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        return count;
    }
};
