class Solution {
public:
    
    /**
     * Find Pivot Index
    */
    int pivotIndex(vector<int>& nums) {
        using namespace std;
        int totalSum = 0;
        for(int i : nums) {
            totalSum += i;
        }
        int leftSum = 0;
        int rightSum;
        for(int i = 0;i < nums.size(); i++) {
            rightSum = totalSum - leftSum - nums[i];
            if(rightSum == leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }

    /**
     * Largest Number At Least Twice of Others
    */
    int dominantIndex(vector<int>& nums) {
        using namespace std;
        int largestIdx = 0;
        int secondLargestIdx = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[largestIdx]) {
                secondLargestIdx = largestIdx;
                largestIdx = i;
            } else if (secondLargestIdx == -1 || nums[i] > nums[secondLargestIdx]) {
                secondLargestIdx = i;
            }
        }
        if(nums[largestIdx] >= 2* nums[secondLargestIdx]) {
            return largestIdx;
        } else {
            return -1;
        }
    }

    /**
     * Plus One
    */
    vector<int> plusOne(vector<int>& digits) {        
        using namespace std;
        
        int overLoad = 1;        
        int i = digits.size()-1;
        while(overLoad == 1 && i > -1) {
            if(digits[i] == 9) {
                digits[i] = 0;
                i--;
            } else {
                digits[i] = digits[i] + overLoad;
                overLoad = 0;
            }
        }
        if(i == -1) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }

    /**
     * Diagonal Traverse
    */
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        using namespace std;
        vector<int> diagonalOrder;
        bool isGoingUp = true;
        
        int side = 0;
        int depth = 0;
        int maxSide = mat[0].size();
        int maxDepth = mat.size();
        
        while(depth < maxDepth && side < maxSide) {
            diagonalOrder.push_back(mat[depth][side]);
            if(isGoingUp) {
                if(side == maxSide - 1) {
                    isGoingUp = false;
                    depth++;
                } else if(depth == 0) {
                    isGoingUp = false;
                    side++;
                } else {
                    depth--;
                    side++;
                }
            } else {
                if(depth == maxDepth - 1) {
                    isGoingUp = true;
                    side++;
                } else if (side == 0) {
                    isGoingUp = true;
                    depth++;
                } else {
                    depth++;
                    side--;
                }
            }
        }
        return diagonalOrder;
    }

    /**
     * Spiral Matrix
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        using namespace std;
        int width = 0;
        int depth = 0;

        int minWidth = -1;
        int maxWidth = matrix[0].size();

        int minDepth = -1;
        int maxDepth = matrix.size();

        string dirs[] = {"left", "down", "right", "up"};
        int dir = 0;

        vector<int> spiral;

        while(width > minWidth && width < maxWidth && 
              depth > minDepth && depth < maxDepth) {
            spiral.push_back(matrix[depth][width]);
            if(dirs[dir] == "left") {
                if(width == maxWidth - 1) {
                    depth++;
                    minDepth++;
                    dir++;
                } else {
                    width++;
                }
            } else if(dirs[dir] == "down") {
                if(depth == maxDepth - 1) {
                    width--;
                    maxWidth--;
                    dir++;
                } else {
                    depth++;
                }
            } else if(dirs[dir] == "right") {
                if(width == minWidth + 1) {
                    depth--;
                    maxDepth--;
                    dir++;
                } else {
                    width--;
                }
            } else if (dirs[dir] == "up") {
                if(depth == minDepth + 1) {
                    width++;
                    minWidth++;
                    dir = 0;
                } else {
                    depth--;
                }
            }
        }
        return spiral;
    }

};