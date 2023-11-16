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

class Solution { 
public:
    /**
     * Number of Islands
    */
    int numIslands(vector<vector<char>>& grid) {
        using namespace std;
        int counter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    grid[i][j] = '2';
                    markNeighbours(grid, i, j);
                }
            }
        }
        return counter;
    }
    
    void markNeighbours(vector<vector<char>>& grid, int i, int j) { 
        using namespace std;
        if(i != 0 && grid[i-1][j] == '1') {
            grid[i-1][j] = '2';
            markNeighbours(grid, i-1, j);
        }
        if(i != grid.size()-1 && grid[i+1][j] == '1') {
            grid[i+1][j] = '2';
            markNeighbours(grid, i+1, j);
        }
        if(j != 0 && grid[i][j-1] == '1') {
            grid[i][j-1] = '2';
            markNeighbours(grid, i, j-1);
        }
        if(j != grid[0].size()-1 && grid[i][j+1] == '1') {
            grid[i][j+1] = '2';
            markNeighbours(grid, i, j+1);
        }
    }

    /**
     * Open the Lock
    */
   int openLock(vector<string>& deadends, string target) {
        using namespace std;
        // Storing the deadends and the visited nodes in hashsets:
        unordered_set<string> deadend_set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        
        // Checking for edge cases:
        string start = "0000";
        if(deadend_set.contains(start) || deadend_set.contains(target)) {
            return -1;
        }
        if(target == start) {
            return 0;
        }
        // Initializing the bfs: 
        queue<string> bfs;
        visited.insert("0000");
        bfs.push("0000");     
        int counter = 0;
        
        // Continuing the bfs: 
        while(!bfs.empty()) {
            // For every element in the queue:
            int iterSize = bfs.size();
            for(int i = 0; i < iterSize; i++) { 
                // Getting the next possible nodes: 
                string current = bfs.front(); bfs.pop();
                vector<string> nextNodes = nextStrings(current);
                for(string s: nextNodes) {
                    // For each of the next possible nodes, check for target value: 
                    if(s == target) {
                        return counter + 1;   
                    }
                    // Otherwise, add the node to the queue to be processed in later iterations: 
                    if(!visited.contains(s) && !deadend_set.contains(s)) {
                        bfs.push(s);
                        visited.insert(s);
                    }
                }
            }
            counter++;
        }
        // If we get here, the search failed:
        return -1;
    }

    vector<string> nextStrings(string currentString) {
        using namespace std;
        vector<string> results;
        for(int i = 0; i < 4; i++) {
            int digit = currentString[i] - '0';
            string nextString = currentString;
            nextString[i] = (digit + 1) % 10 + '0';            
            results.push_back(nextString);
            nextString[i] = (digit + 9) % 10 + '0';            
            results.push_back(nextString);            
        }
        return results;
    }

    

};