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

    /**
     * Pascal's Triangle
    */
   vector<vector<int>> generate(int numRows) {
        using namespace std;
        vector<vector<int>> pascals;
        pascals.push_back({1});

        vector<int> prevRow;
        vector<int> nextRow;
        
        for(int i = 1;i < numRows; i++) {
            nextRow = {1};
            prevRow = pascals[i-1];
            for(int j = 1; j < i; j++) {
                int sum = prevRow[j-1] + prevRow[j];
                nextRow.push_back(sum);
            }
            nextRow.push_back(1);
            pascals.push_back(nextRow);
        }
        return pascals;
    }

    /**
     * Add Binary
    */
    string addBinary(string a, string b) {
        using namespace std;
        string result = "";
        int sum;
        int overLoad = 0;
        int indexA = a.size()-1;
        int indexB = b.size()-1;
        
        while(indexA >= 0 || indexB >= 0) {
            sum = overLoad;
            if(indexA >= 0) {
                sum += a[indexA] - '0';
                indexA--;                
            }
            if(indexB >= 0) {
                sum += b[indexB] - '0';
                indexB--;                
            }
            if(sum > 1) {
                sum = sum % 2;
                overLoad = 1;
            } else {
                overLoad = 0;
            }
            result = to_string(sum) + result;
        }
        
        if(overLoad != 0) {
            result = "1" + result;
        }
        return result;
    }

    /**
     * Implement strStr()
    */
    int strStr(string haystack, string needle) {
        using namespace std;
        int haySize = haystack.size();
        int needleSize = needle.size();
        bool match = true;
        
        for(int i = 0; i <= haySize-needleSize; i++) {
            match = true;
            for(int j = 0; j < needleSize && match; j++) {
                if(needle[j] != haystack[i+j]) {
                    match = false;
                }
            }   
            if(match) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Longest Common Prefix
    */
    string longestCommonPrefix(vector<string>& strs) {
        using namespace std;
        string prefix = "";
        int index = 0;
        bool search = true;
        
        while(index < strs[0].size() && search) {
            char match = strs[0][index];
            for(int i = 1; i < strs.size(); i++) {
                if(index >= strs[i].size() || strs[i][index] != match) {
                    search = false;
                    break;
                }
            }
            if(search) {
                prefix = prefix + match;
            }
            index++;
        }
        return prefix;
    }

    /**
     * Reverse String
    */
    void reverseString(vector<char>& s) {
        using namespace std;
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    /**
     * Array Partition I
    */
    int arrayPairSum(vector<int>& nums) {
        using namespace std;
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }

    /**
     * Two Sum II - Input array is sorted
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        using namespace std;
        int index1 = 0;
        int index2 = numbers.size() - 1;
        int sum = target - 1;
        vector<int> result;
        
        while(index1 < index2 && sum != target) {
            sum = numbers[index1] + numbers[index2];
            if(sum == target) {
                result.push_back(index1 + 1);
                result.push_back(index2 + 1);
                return result;
            } else if (sum < target) {
                index1++;
            } else {
                index2--;
            }
        }
        return result;
    }

    /**
     * Remove Element
    */
    int removeElement(vector<int>& nums, int val) {
        using namespace std;
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

    /**
     * Max Consecutive Ones
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        using namespace std;
        int counter = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                counter++;
                if(counter > maxCount) {
                    maxCount = counter;
                }
            } else {
                counter = 0;
            }
        }
        return maxCount; 
    }

    /**
     * Minimum Size Subarray Sum
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        using namespace std;
        int minLength = INT_MAX;
        int fastIdx = 0;
        int slowIdx = 0;
        int sum = 0;
        while(fastIdx < nums.size()) {
            sum += nums[fastIdx];
            fastIdx++;
            while(sum >= target) {
                minLength = min(minLength, fastIdx - slowIdx);
                sum -= nums[slowIdx];
                slowIdx++;
            }
        }
        if(minLength == INT_MAX) {
            return 0;
        } else {
            return minLength;        
        }
    }

    /**
     * Rotate Array
    */
    void rotate(vector<int>& nums, int k) {
        using namespace std;
        k = k % nums.size();
        // Reverse the last k numbers: 
        reverse(nums.end() - k, nums.end());
        // Reversing the rest of the numbers: 
        reverse(nums.begin(), nums.end() - k);
        // Reversing the whole array: 
        reverse(nums.begin(), nums.end());
    }

    /**
     * Pascal's Triangle II
    */
    vector<int> getRow(int rowIndex) {
        using namespace std;
        if(rowIndex == 0) {
            return {1};
        }
        vector<int> row = {1};
        vector<int> prevRow = {1};
        int sum;
        for(int i = 0; i <= rowIndex; i++) {
            row = {1};
            for(int j = 1; j < i; j++) {
                sum = prevRow[j - 1] + prevRow[j];
                row.push_back(sum);
            }
            row.push_back(1);
            prevRow = row;
        }
        return row;
    }

    /**
     * Reverse Words in a String
    */
    string reverseWords(string s) {
        #include <regex>
        using namespace std;
        s.push_back(' ');
        reverse(s.begin(), s.end());
        s.push_back(' ');
        int startWord = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + startWord, s.begin() + i);
                startWord = i + 1;
            }
        }
        regex space_dupes("\\s+");
        s = regex_replace(s, space_dupes, " ");
        s.erase(s.end() - 1);
        s.erase(s.begin());
        return s;
    }

    /**
     * Reverse Words in a String III
    */
    string reverseWords(string s) {
        using namespace std;
        s.push_back(' ');
        int startWord = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + startWord, s.begin() + i);
                startWord = i + 1;
            }
        }
        s.erase(s.end() - 1);
        return s;
    }


};