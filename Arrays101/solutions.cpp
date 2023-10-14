#include <vector>
#include <unordered_set>


class Solution {

/**
 * Check If N and Its Double Exist
*/
public:
    bool checkIfExist(vector<int>& arr) {
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
public:
    bool validMountainArray(vector<int>& arr) {
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


};