https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#


class Solution
{
    public:
    double median;
    
    //using two priority queues.
    priority_queue<int> max; 
	priority_queue<int, vector<int>, greater<int> > min;
		
	//Function to insert heap.
    void insertHeap(int &x)
    {
        //inserting the element.
    	if (max.empty() or max.top()>x) 
    		max.push(x);
    
    	else
    		min.push(x);
    		
    	//calling function to balance heaps.
    	balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
    	if (abs(max.size() - min.size()) > 1) 
    	{
    	    //if size of max queue is greater than min queue, we pop top 
    	    //element from max queue and push it in min queue.
    		if (max.size() > min.size())
    		{
    			min.push(max.top());
    			max.pop();
    		}
    		//else we pop top element from min queue and push it in max queue.
    		else
    		{
    			max.push(min.top());
    			min.pop();
    		}
    	}
    }
    
    //Function to return Median.
    double getMedian()
    {
        //if total size is even.
    	if (max.size() == min.size())
    	{
    	    //we store the sum of top elements of both priority
    	    //queues and divide it by 2.
    		median = (max.top() + min.top());
    		median /= 2;
    	}
    	//else the total size is odd.
    	else 
    	{
    	    //if min queue is empty or max queue is bigger than min queue,
    	    //we store top element of max queue in median else we store
    	    //top element of min queue.
    		if (min.size()>max.size())
    			median = min.top();
    		else
    			median = max.top();
    	}
    	
    	//returning the median.
    	return median;
    }
};
