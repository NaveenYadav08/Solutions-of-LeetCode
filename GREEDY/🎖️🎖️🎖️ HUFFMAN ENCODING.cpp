https://1drv.ms/u/s!AqxMKPPDP0cpg0mbBIK70ZJ2Fjit?e=OarFlG
Refer to the greedy section of this notebook

CODE 



struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

class Solution
{
	public:
	    void getCodes(struct MinHeapNode* root, string str,vector<pair<char,string>> &res)
        {
            if (!root)
                return;
            if (root->data != '$'){
                res.push_back({root->data,str});
            }
            getCodes(root->left, str + "0",res);
            getCodes(root->right, str + "1",res);
        }
        
        
        
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    struct MinHeapNode *left, *right, *top;
            priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
            
            for (int i = 0; i < N; ++i)
                minHeap.push(new MinHeapNode(S[i], f[i]));
                
            while (minHeap.size() != 1)
            {
                left = minHeap.top();
                minHeap.pop();
                right = minHeap.top();
                minHeap.pop();
                top = new MinHeapNode('$', left->freq + right->freq);
                top->left = left;
                top->right = right;
                minHeap.push(top);
            }
            
            vector<pair<char,string>> res;
            getCodes(minHeap.top(), "",res);
            for(auto x:res)
            cout<<x.first<<" "<<x.second<<endl;
            vector<string> go;
            return go;
		}
};
