https://leetcode.com/problems/design-circular-queue/


622. Design Circular Queue
// add at rear end rear++
// del from front front ++







class MyCircularQueue {
public:
	int *arr;
	int frontIndex;
	int rearIndex;
	int size;
	int capacity;

	MyCircularQueue(int k) {
		arr = new int[k];
		rearIndex = 0;
		frontIndex = -1;
		size = 0;
		capacity = k;        
	}

	bool enQueue(int value) {
		if(size == capacity) {
			return false;
		}
		arr[rearIndex] = value;
		rearIndex = (rearIndex + 1) % capacity ;
		if(frontIndex == -1) {
			frontIndex = 0;
		}
		size++;
		return true;
	}

	bool deQueue() {
		if(isEmpty()) {
			return false;
		}
		frontIndex = (frontIndex + 1) % capacity;
		size--;
		if(size == 0) {
			frontIndex = -1;
			rearIndex = 0;
		}
		return true;        
	}

	int Front() {
		if(isEmpty()) {
			return -1;
		}
		return arr[frontIndex];        
	}

	int Rear() {
		if(isEmpty()) {
			return -1;
		}
		return arr[(rearIndex + capacity - 1) % capacity]; // kyoki mae add krke rear ++ kr deta hu to wo ek pst aage chala jata hae
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		if(size == capacity) {
			return true;
		}
		return false;
	}
};
