class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int start = 0;
      int  end = n;
       int mid = start + (end-start)/2;
       int ans = -1;
        
        while(start<=end){
            if(mid*mid == n){
                return mid;
            }
            else if(mid*mid>n){
                end = mid-1;
            }
            else{
                start = mid+1;
                ans = mid;
            }
            mid = start + (end-start)/2;
        }
        return ans;
        
    }
};