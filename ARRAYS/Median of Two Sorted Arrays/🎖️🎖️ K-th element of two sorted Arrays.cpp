https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1



https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

🎖️🎖️K-th element of two sorted Arrays.cpp

class Solution{
    public:
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)return kthElement(arr2,arr1,m,n,k);
        // I have to take something from arrr1
        // I cant take all element from arr1
        // THIS IS TO AVOID EDGE CASE where i pick more ele than size of arry
        
        //https://youtu.be/nv7F4PiLUzo?t=1329  
        // watch at this time for edge case
        int low=max(0,k-m),high=min(k,n);
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=k-cut1;
            int l1= cut1==0 ? INT_MIN : arr1[cut1-1];
            int l2= cut2==0 ? INT_MIN : arr2[cut2-1];
            int r1= cut1==n ? INT_MAX : arr1[cut1];
            int r2= cut2==m ? INT_MAX : arr2[cut2];
            if(l1<=r2 and l2<=r1) return max(l1,l2);
            else if(l1>r2) high=cut1-1;
            else low= cut1 +1;
        }
        return 1;
    }
};
