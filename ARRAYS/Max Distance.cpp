//https://www.interviewbit.com/problems/max-distance/
// 




int Solution::maximumGap(const vector<int> &A) {

vector<pair<int,int>>v;
for(int i=0;i<A.size();i++)
{
v.push_back(make_pair(A[i],i));
}
sort(v.begin(),v.end());
int mini=INT_MAX,ans=0;
for(int i=0;i<v.size();i++)
{
//cout<<v[i].first<<endl;

   if(v[i].second<mini)
    {
        mini=v[i].second;
    }
    ans=max(ans,v[i].second-mini);
}
return ans;
}
