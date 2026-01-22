#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
  
  int firstOcc(vector<int>& arr, int x, int length){
      
      int s = 0;
      int e = length - 1;
      int mid = (s+e)/2;
      int ans = -1;
      while(s<=e){
          if(arr[mid]==x){
              ans = mid;
              e = mid-1;
          }
          else if(arr[mid]>x){
              e=mid-1;
          }
          else{
              s=mid+1;
          }
          mid = (s+e)/2;
      }
      return ans;
  }
  
    int lastOcc(vector<int>& arr, int x, int length){
      
      int s = 0;
      int e = length - 1;
      int mid = (s+e)/2;
      int ans = -1;
      while(s<=e){
          if(arr[mid]==x){
              ans = mid;
              s = mid+1;
          }
          else if(arr[mid]>x){
              e=mid-1;
          }
          else{
              s=mid+1;
          }
          mid = (s+e)/2;
      }
      return ans;
  }
  
    vector<int> find(vector<int>& arr, int x) {
        // code here
      int length = arr.size();
      int FirstOcc = firstOcc(arr,x,length);
      int LastOcc = lastOcc(arr,x,length);
       vector<int> result;
        result.push_back(FirstOcc);
        result.push_back(LastOcc);
        return result;
    }
};