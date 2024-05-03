// MERGE //
void merge(vector<int>& arr, int s,int mid, int e){
  int l1,l2;
  l1=mid-s+1;
  l2=e-mid;

 vector<int> v1;
 vector<int> v2;

  for(int i=0;i<l1;i++){
    v1.push_back(arr[s+i]);
    }

    for(int i=0;i<l1;i++){
    v2.push_back(arr[mid+1+i]);
    }

  int i=0;
  int j=0;
  int merged_index=s; // putting the sorted values in the same array

  // loop1 - both
  while(i<l1 && j<l2){

   if(v1[i]<=v2[j]){
    arr[merged_index]=v1[i];
    i++;
    merged_index++;}


   else{
    arr[merged_index]=v2[j];
    j++;
    merged_index++;}

  }

  // loop2 - remaining
  while(i<l1){
    arr[merged_index]=v1[i];
    merged_index++;
    i++; 
    }

  // loop3 - remaining
   while(j<l2){
    arr[merged_index]=v2[j];
    merged_index++;
    j++;
    }

}

// MERGESORT //
void mergeSort(vector<int>& v,int s, int e){
    if(s>=e) return;
    if(s<e) 
    {
    int mid=(s+e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,mid,e);
    }
   }

// SORT //
vector<int> sortArray(vector<int>& nums) {
     //quick sort gonna take O(nlog(n)) time complexity:
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
