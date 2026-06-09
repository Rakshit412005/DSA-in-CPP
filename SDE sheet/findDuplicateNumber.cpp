#include <iostream>
#include <vector>
using namespace std;

//leetcode solution for find duplicate number problem
class Solution { // copy from here
public:
    int findDuplicate(vector<int>& nums) {
      
      int slow = nums[0];
      int fast = nums[0];

      do{
        slow = nums[slow];
        fast = nums[nums[fast]];
      }while(slow!=fast);

      slow = nums[0];

      while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
      }

      return slow;

    }
};