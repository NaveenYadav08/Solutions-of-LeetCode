https://leetcode.com/problems/restore-ip-addresses/


class Solution {
public:
vector<string> ans;

void helper(string tmp, int i, int count, string& s)
{
    if(i==s.size() and count==4)
    {   string aa=tmp;
        aa.pop_back();
        ans.push_back(aa);
        return;
    }

    if(i>=s.size() or count>=4) {
        //cout<<tmp<<endl;
    return;}

    for(int len=1; len<=3 and (i+len)<=s.size(); len++)
    {
        string tk = s.substr(i,len);
        int tolo = stoi(tk);
        if(tolo>255 or tolo<0 or (tk.size()>1 and tk[0]=='0')) return;
        tmp+=tk;
        tmp+='.';
        helper(tmp,i+tk.size(),count+1,s);
        int N=tk.size();
        N++;
        while(N--)
        {
            tmp.pop_back();
        }
        
        

    }
}

vector<string> restoreIpAddresses(string ip) {
    int n=ip.size();
    ans.clear();
    if(n>12 or n<4) return ans;
    helper("",0,0, ip);
    return ans;
}
};


