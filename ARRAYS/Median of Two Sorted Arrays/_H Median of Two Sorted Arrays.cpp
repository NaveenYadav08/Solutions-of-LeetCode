Leetcode -  https://leetcode.com/problems/median-of-two-sorted-arrays/
https://www.youtube.com/watch?v=NTop3VTjmxk
CODE - 
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int m=nums1.size();
     int n=nums2.size();
    if(m>n)return findMedianSortedArrays(nums2,nums1);
    int s=(m+n+1)/2;
 int l=0,h=m,cut1,cut2,l1,l2,r1,r2;
    double median;
    while(l<=h)
    {
        
        cut1=(l+h)/2;
        cut2=(s-cut1);
        l1=(cut1==0) ? -99999999 : nums1[cut1-1];
        l2=(cut2==0) ? -99999999 : nums2[cut2-1];
        r1=(cut1==m) ? 999999999 : nums1[cut1];
        r2=(cut2==n) ? 999999999 : nums2[cut2];
        cout<<l1<<" "<<l2<< " "<<r1<<" "<<r2<<endl;
        if(l1<=r2 && l2<=r1)
        {
            if((m+n)%2==0) median= (double)( max(l1,l2)+ min(r1,r2) )/2.0;
            else median= max(l1,l2);
            return median;
        }
        else
        {
            if(l1>r2  ) h=cut1-1;
            else if(r1<l2)l=cut1+1;
            
        }
        
        
                    

    }
   return 0.0;
}
};
