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


/**
 * Design Min-Stack
*/
class MinStack {
    
private: 
    struct Node {
        int val;
        int min; 
        Node* next;
        
        Node(int val, int min, Node* next) {
            this->val = val;
            this->min = min;
            this->next = next;
        }
    };
    
    Node* head;
    
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(head == NULL) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, min(val, head->min), head);
        }
    }
    
    void pop() {
        Node* del = head;
        head = head->next;
        delete del;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
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

    /**
     * Perfect Squares
     * Given an integer n, return the least number of perfect square numbers that sum to n.
    */
    int numSquares(int n) {
        using namespace std;
        // Initializing the bfs:
        unordered_set<int> visited;
        queue<int> bfs;
        int start = n;
        bfs.push(n);
        int counter = 0;
        
        // The breadth-first search:
        while(!bfs.empty()) {
            int iterSize = bfs.size();
            for(int i = 0; i < iterSize; i++) {
                int current = bfs.front(); bfs.pop();
                vector<int> nextIntegers = nextInts(current);
                for(int i: nextIntegers) {
                    if(i == 0) {
                        return counter + 1;
                    }
                    if (!visited.contains(i)) {
                        bfs.push(i);
                        visited.insert(i);
                    }
                }
            }
            counter++;
        }
        return counter;
    }
    
    vector<int> nextInts(int current) {
        using namespace std;
        vector<int> result; 
        for(int i = 0; i*i <= current; i++) {
            result.push_back(current - i*i);
        }
        return result;
    }

    /**
     * Valid Parentheses
    */
    bool isValid(string s) {
        using namespace std;
        stack<char> parentheses;
        map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for(char c: s) {
            if(!pairs.contains(c)) {
                parentheses.push(c);  
            } else if (!parentheses.empty() && pairs.find(c)->second == parentheses.top()) {    
                parentheses.pop();
            } else {
                return false;
            } 
        }
        return parentheses.empty();
    }

    /**
     * Daily Temperatures
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        using namespace std;
        int size = temperatures.size();
        vector<int> answer(size, 0);
        
        // Using a monotonic stack to remember the indexes of the days with highest temperatures, in an ascending order.
        stack<int> indexStack;
        for(int i = size - 1; i >= 0; i--) {
            while(!indexStack.empty() && temperatures[indexStack.top()] <= temperatures[i]) {
                indexStack.pop();
            }
            if(!indexStack.empty()) {
                answer[i] = indexStack.top() - i;
            }
            indexStack.push(i);
        }
        return answer;
    }

    /**
     * Evaluate Reverse Polish Notation
    */
   int evalRPN(vector<string>& tokens) {
        using namespace std;
        stack<int> result;
        int a;
        int b;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                a = result.top(); result.pop();
                b = result.top(); result.pop();
                result.push(b + a);
            } else if(tokens[i] == "-") {
                a = result.top(); result.pop();
                b = result.top(); result.pop();
                result.push(b - a);
            } else if(tokens[i] == "*") {
                a = result.top(); result.pop();
                b = result.top(); result.pop();
                result.push(b * a);
            } else if(tokens[i] == "/") {
                a = result.top(); result.pop();
                b = result.top(); result.pop();
                result.push(b / a);
            } else {
                result.push(stoi(tokens[i]));   
            }
        }
        return result.top();
    }

    /**
     * Clone Graph
    */
    Node* cloneGraph(Node* node) {
        using namespace std;
        unordered_map<Node*, Node*> visited;
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0) return new Node(node->val);
        return cloneNode(node, visited);
    }
    
    Node* cloneNode(Node* node, unordered_map<Node*, Node*>& visited) {
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for(Node* neighbor: node->neighbors) {
            if(visited.find(neighbor)==visited.end()) {
                clone->neighbors.push_back(cloneNode(neighbor, visited));
            } else {
                clone->neighbors.push_back(visited[neighbor]);
            }
        }
        return clone;
    }

    /**
     * Target Sum
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetSumWays(nums, target, 0);
    }
    
    int targetSumWays(vector<int>& nums, int target, int curSum) {
        using namespace std;
        if(nums.empty()) {
            if(curSum == target) {
                return 1;
            } 
            return 0;
        }
        int i = nums.back(); nums.pop_back();
        int counter = targetSumWays(nums, target, curSum - i) + targetSumWays(nums, target, curSum + i);
        nums.push_back(i);        
        return counter;
    }

    /**
     * Binary Tree Inorder Traversal - Recursive solution.
    */
    vector<int> inorderTraversal(TreeNode* root) {
        using namespace std;
        vector<int> result;
        inorderTraverse(root, result);
        return result;
    }
    
    void inorderTraverse(TreeNode* head, vector<int>& result) {
        if(head != NULL) {
            inorderTraverse(head->left, result);
            result.push_back(head->val);
            inorderTraverse(head->right, result);
        }
    }

    /**
     * Binary Tree Inorder Traversal - Iterative solution.
    */
    vector<int> inorderTraversal(TreeNode* root) {
        using namespace std;
        vector<int> result;
        TreeNode* cur = root;
        
        stack<TreeNode*> dfs;
        while(!dfs.empty() || cur != NULL) {
            while(cur != NULL) {
                dfs.push(cur);
                cur = cur->left;
            }
            cur = dfs.top(); dfs.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }





};