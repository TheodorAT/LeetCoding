#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Max Consecutive Ones
*/
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int counter = 0;
    int maxCount = 0;
    for (int i = 0; i<numsSize; i++) {
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
 * Find Numbers with Even Number of Digits
*/
int findNumbers(int* nums, int numsSize){
    int counter = 0;
    int nrDigits;
    for(int i = 0; i < numsSize; i++) {
        nrDigits = floor(log10(nums[i]))+1;
        if (nrDigits % 2 == 0) {
            counter++;
        }
    }
    return counter;
}

/**
 * Squares of a Sorted Array
*/
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
        
    // Divide the array into two parts, the negative and the positive:
    // Calculate the idx of the last negative number
    int firstPositiveIdx = 0;
    for(firstPositiveIdx = 0; firstPositiveIdx < numsSize; firstPositiveIdx++) {
        if (nums[firstPositiveIdx] >= 0) {
            break;
        }
    }
    
    int idx = 0;
    
    // Use merge sort algorithm to merge the different arrays into new array;
    int temp[numsSize];
    
    // Start off indices on the first positive and last negative:
    int posIdx = firstPositiveIdx;
    int negIdx = firstPositiveIdx - 1;
    int posSquare = 0;
    int negSquare = 0;
    
    while (negIdx >= 0 && posIdx < numsSize) {
        // If the positive numbers square is smaller: 
        posSquare = nums[posIdx] * nums[posIdx];
        negSquare = nums[negIdx] * nums[negIdx];
        
        if (posSquare <= negSquare) {
            temp[idx] = posSquare;
            posIdx++;
        } else {
            temp[idx] = negSquare;
            negIdx--;
        }
        idx++;
    }
    
    // When one of the different parts of the arrays run out of numbers, fill in the rest:
    while(negIdx >= 0) {
        negSquare = nums[negIdx] * nums[negIdx];
        temp[idx] = negSquare;
        negIdx--;
        idx++;
    }
    while(posIdx < numsSize) {
        posSquare = nums[posIdx] * nums[posIdx];
        temp[idx] = posSquare;
        posIdx++;
        idx++;
    }
    
    for(int i = 0; i < numsSize;i++) {
        nums[i] = temp[i];
    }
    return nums;
}

/**
 * Duplicate Zeros
*/
void duplicateZeros(int* arr, int arrSize){    
    int temp[arrSize];
    int shift = 0;
    for(int i = 0; i+shift < arrSize; i++) {   
        if(arr[i] == 0 && i+shift+1 <arrSize) {
            temp[i+shift] = 0;
            temp[i+shift+1] = 0;
            shift++;
        } else {
            temp[i+shift] = arr[i];
        }
    }
    
    for(int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }
}

/**
 * Merge Sorted Array
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0;
    int j = 0;
    int idx = 0;
    int temp[m + n];
    while(i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            temp[idx] = nums1[i];
            i++;
        } else {
            temp[idx] = nums2[j];
            j++;
        }
        idx++;
    }
    while(i < m) {
        temp[idx] = nums1[i];
        i++;
        idx++;
    }
    while(j < n) {
        temp[idx] = nums2[j];
        j++;
        idx++;
    }
    
    for(int i = 0; i < m + n; i++) {
        nums1[i] = temp[i];
    }
}

/**
 * Remove Element
*/
int removeElement(int* nums, int numsSize, int val) {
    int removed = 0;
    for(int i = 0; i + removed < numsSize; i++) {
        if (nums[i] == val) {            
            // Search for the first non-val entry from the back of the array:
            int nonValIdx = numsSize - 1 - removed;
            while(nums[nonValIdx] == val && nonValIdx > i) { // Stop searching 
                nonValIdx--;
                removed++;
            }
            nums[i] = nums[nonValIdx];            
            nums[nonValIdx] = val;
            removed++;
        }
    }
    return numsSize - removed;
}

/**
 * Remove Duplicates from Sorted Array
*/
int removeDuplicates(int* nums, int numsSize){
    int nextIdx = 0;
    int dupesFound = 0;
    for(int i = 1; i < numsSize; i++) {
        
        // Detecting duplicates: 
        if(nums[i] == nums[i-1]) {
            if (dupesFound == 0) { // If the first duplicate:
                nextIdx = i;
            }
            dupesFound++;   
        } else if (dupesFound != 0) { // Detecting a new number after finding the first duplicates:
            nums[nextIdx] = nums[i];
            nextIdx++;
        }
    }
    return numsSize - dupesFound;
}

/**
 * Sort Array By Parity
*/
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int nextEven = 0;
    int temp;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] % 2 == 1) {
            nextEven = i;
            while(nums[nextEven] % 2 == 1 && nextEven < numsSize - 1) {
                nextEven++;
            }
            temp = nums[nextEven];
            nums[nextEven] = nums[i];
            nums[i] = temp;
        }
    }
    return nums;
}