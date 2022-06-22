https://leetcode.com/problems/iterator-for-combination/


class CombinationIterator {
public:
    vector<string>v;
    int index=0;
    
    // s index
    void comb(string&st,string c,int l,int s){
        if(c.size()==l) {
            v.push_back(c);
            return;
        }
        for(int i=s;i<st.size();i++) {
            c.push_back(st[i]);
            comb(st,c,l,i+1);
            c.pop_back();
        }
    }
    
    CombinationIterator(string ch, int l) {
        comb(ch,"",l,0);
    }
    
    string next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index<v.size();
    }
};
