#include <vector>
#include <unordered_set>


class Solution {

/**
 * Check If N and Its Double Exist
*/
public:
    bool checkIfExist(vector<int>& arr) {
        using namespace std;
        unordered_set <int> foundNums;  
        for(int i = 0; i < arr.size(); i++) {
            if (foundNums.contains(arr[i]*2) || (arr[i] % 2 == 0 && foundNums.contains(arr[i]/2))) {
                return true;
            }
            foundNums.insert(arr[i]);
        }
        return false;
    }


    /**
     * Valid Mountain Array
    */
    bool validMountainArray(vector<int>& arr) {
        using namespace std;
        if (arr.size() < 3) {
            return false;
        }
        
        bool goingUp = true;
        
        for(int i = 1; i < arr.size(); i++) {
            // Checking for plateus anywhere
            if (arr[i-1] == arr[i]) {
                return false;
            }            
            // Checking for wrong direction on the way down
            if(!goingUp && arr[i-1] < arr[i]) {
                return false;
            }            
            // Changing directions
            if (goingUp && arr[i-1] > arr[i]) {
                goingUp = false;
                if (i == 1) { // We must go up before going down.
                    return false;
                }
            } 
        }
                
        return !goingUp;
    }


    /**
     * Replace Elements with Greatest Element on Right Side
    */
    vector<int> replaceElements(vector<int>& arr) {
        using namespace std;
        int largestSeen = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        int temp = 0;
        for (int i = arr.size()-2; i >= 0; i--) {
            temp = arr[i];
            arr[i] = largestSeen;            
            if(temp > largestSeen) {                
                largestSeen = temp;
            } 
        }
        return arr;
    }

    /**
     * Remove Duplicates from Sorted Array
    */
    int removeDuplicates(vector<int>& nums) {
        using namespace std;
        int nextIdx = 0;
        int dupesFound = 0;
        for(int i = 1; i < nums.size(); i++) {
        
            // Detecting duplicates: 
            if(nums[i] == nums[i-1]) {
                if (dupesFound == 0) { // If the first duplicate:
                    nextIdx = i;
                }
                dupesFound++;   
            } else if (dupesFound != 0) { // Detecting a new number after finding duplicates:
                nums[nextIdx] = nums[i];
                nextIdx++;
            }
        }
        return nums.size() - dupesFound;
    }


    /**
     * Move Zeroes
    */
    void moveZeroes(vector<int>& nums) {
        using namespace std;
        int zeroPointer = 0; 
        for(int i = 0; i < nums.size(); i++) {
            // Find the first zero in the array
            while (zeroPointer < nums.size() && nums[zeroPointer] != 0) {
                zeroPointer++;
            }
            
            if (zeroPointer < i) {
                nums[zeroPointer] = nums[i];
                nums[i] = 0;
            }
        }
        
    }

    /**
     * Height Checker
    */
    int heightChecker(vector<int>& heights) {
        using namespace std;
        
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        
        int wrongPlaceCounter = 0;
        for(int i = 0; i < heights.size(); i++) {
            if (sorted[i] != heights[i]) {
                wrongPlaceCounter++;
            }
        }
        return wrongPlaceCounter;        
    }


    /**
     * Third Maximum Number
    */
    int thirdMax(vector<int>& nums) {
        using namespace std;
        
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        int uniqueCounter = 0;
        bool hasSeenIntMin = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
                uniqueCounter++;
            } else if (nums[i] > secondMax && nums[i] < firstMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
                uniqueCounter++;
            } else if (nums[i] > thirdMax && nums[i] < secondMax) {
                thirdMax = nums[i];
                uniqueCounter++;
            } else if (nums[i] == INT_MIN && !hasSeenIntMin) {
                uniqueCounter++;
                hasSeenIntMin = true;
            }
        }
        
        if (uniqueCounter > 2) {
            return thirdMax;
        } else {
            return firstMax;
        }
        
    }

    /**
     * Find All Numbers Disappeared in an Array
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        using namespace std; 
        vector<int> result;

        // Placing every int num on index num-1 if possible.
        for(auto& num : nums) {
            // While num is not in the correct position
            while(num != nums[num-1]) {
                // Switch so that that num is in the correct position
                swap(num, nums[num-1]);
            }
        }

        // Counting all of the missing numbers:
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1) {
                result.push_back(i+1);
            }
        }

        return result;
    }

};