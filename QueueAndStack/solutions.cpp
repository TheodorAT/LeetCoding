/**
 * Design Circular Queue
*/
class MyCircularQueue {
private: 
    vector<int> queue;
    int size;
    int maxSize;
    int head;
    int tail;
    
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        head = 0;
        tail = -1;
        size = 0;
        maxSize = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;        
        }
        // Increase tail by one, and wrap around the array if neccesary.
        tail = (tail + 1) % maxSize;
        queue[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        head = (head + 1) % maxSize;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return queue[head];
    }
    
    int Rear() {
        if(size == 0) {
            return -1;
        }
        return queue[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};


