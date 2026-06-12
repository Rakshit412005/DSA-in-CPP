#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//LeetCode solution for Longest Substring Without Repeating Characters
class Solution {//copy from here
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int n = s.size();
        
        int left = 0;
        int right =0;
        
        int maxlen = 0;
        if(n==0){
            return 0;
        }

        while(right<n){
            if(map.find(s[right])==map.end()){
                map[s[right]]=right;
                right++;
            }
            else{
                left = max(left, map[s[right]]+1 );
                map[s[right]]= right;
                right++;
            }
            maxlen = max(maxlen,right-left);
        }
        return maxlen;  
    }
};