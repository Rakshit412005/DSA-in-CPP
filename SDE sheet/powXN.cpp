#include<iostream>
using namespace std;

//leetcode solution for pow(x,n) using recursion and divide and conquer approach
class Solution {//copy from here
public:

    double solve(double x, int n){
        if(n==0){
            return 1.0;
        }

        double half = solve(x,n/2);

        if(n%2 == 0){
            return half*half;
        }
        else{
            return x*half*half;
        }   
    }

    double myPow(double x, int n) {
       
        long long N = n;

                if(N < 0){
                    x = 1/x;
                    N = -N;
                }

                return solve(x, N); 
    }
};