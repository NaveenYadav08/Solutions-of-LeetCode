https://1drv.ms/u/s!AqxMKPPDP0cpg0mbBIK70ZJ2Fjit?e=OarFlG
Refer to the greedy section of this notebook

CODE 
To build the Huffman Tree:

Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. 
The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
Create a new internal node with a frequency equal to the sum of the two nodes frequencies. 
Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps #2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete. 














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
            vector<string> go;
            getCodes(minHeap.top(), "",res);
            for(auto x:res)
            { cout<<x.first<<" "<<x.second<<endl;
            go.push_back(x.second);}
            return go;
			
		}
};
