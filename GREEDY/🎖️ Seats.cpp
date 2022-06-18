https://www.youtube.com/watch?v=SK2ypa7poKg
https://www.interviewbit.com/problems/seats/


int Solution::seats(string A) {
    
        vector<int> arr;
        for(int i = 0 ; i<A.length();i++){
            if(A[i]=='x'){
                arr.push_back(i);
            }
        }
        int ans = 0 ;
        int mid = arr.size()/2;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i<arr.size();i++){
            start = arr[i];
            end =  arr[mid]-mid + i; // i act as how many filled , ABS bcz mid ke right mae 
            cout<<arr[mid]<<endl;
            ans= (ans+abs(end-start))%10000003;
        }
        return ans%10000003;
}
