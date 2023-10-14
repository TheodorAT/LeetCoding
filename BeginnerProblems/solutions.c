#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * 1480. Running Sum of 1d Array
 */ 
int* runningSum(int* nums, int numsSize, int* returnSize){
    int sum=0;
    *returnSize=numsSize; //size for the new array to be returned
    for(int i=0;i<numsSize;i++){
        sum=sum+nums[i];
        nums[i]=sum;
    }
    return nums;
}

/**
 * 1672. Richest Customer Wealth
 */ 
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int maxWealth = 0;
    int accountWealth = 0;
    for(int i = 0; i < accountsSize; i++) {
        accountWealth = 0;
        for(int j = 0; j < *accountsColSize; j++) {
            accountWealth += accounts[i][j];
        }
        if(accountWealth>maxWealth) {
            maxWealth = accountWealth;
        }
    }
    return maxWealth;
}

/**
 * 412. Fizz Buzz
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n; // Inform of the return size
    char **result; 
    char str[5]; // At most 5 characters, Fizz \0

    result = malloc(sizeof(*result) * n);
    if (result == NULL) {  // It is best practice to check if malloc returned null
        return result;
    }
    int i;
    for(i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            result[i-1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            result[i-1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            result[i-1] = strdup("Buzz"); // Here we duplicate to avoid memory leak. 
        } else {
            sprintf(str, "%d", i); // Converting i into string.
            result[i-1] = strdup(str); // strdup returning a pointer to a duplicate of the string 
        }
    }
    return result;
}

/**
 * 1342. Number of Steps to Reduce a Number to Zero
*/
int numberOfSteps(int num){
    int steps = 0;
    while (num != 0) {
        steps += 1;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num -= 1;
        }
    }
    return steps;
}

/**
 * 876. Middle of the Linked List
*/

// Definition for singly-linked list node.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * 383. Ransom Note
 */
bool canConstruct(char * ransomNote, char * magazine){
    int map[26] = {0}; // Count characters in array.
    
    while(*ransomNote){ // For every character in ransomnote, add one count in the correct index of the array.
        map[*ransomNote - 'a']++;
        ransomNote++; // Look at the next memory index.
    }
    while(*magazine){ // For every character in magazine, add one count in the correct index of the array.
        map[*magazine - 'a']--;
        magazine++; // Look at the next memory index.
    }
    
    // Check if frequency of any char in ransomNote is greater than in magazine
    for(int i=0; i < 26; i++)
        if (map[i] > 0) return false;
    return true;
}