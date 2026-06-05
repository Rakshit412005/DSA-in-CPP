// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    vector<int>v1(n1),v2(n2);
    
    for(int i =0; i<n1;i++){
        v1[i] = arr[start+i];
    }
    
    for(int j = 0; j<n2; j++){
        v2[j] = arr[mid+1+j];
    }
    
    int k = start;
    int m = 0;
    int n = 0;
    
    while(m < n1 && n < n2){
        if(v1[m] <= v2[n]){
            arr[k] = v1[m];
            m++;
        }
        else{
            arr[k] = v2[n];
            n++;
        }
        k++;
    }
    
    while(m<n1){
        arr[k] = v1[m];
        m++;
        k++;
    }
    
    while(n<n2){
        arr[k] = v2[n];
        n++;
        k++;
    }
}

void mergeSort(vector<int>&arr, int start, int end){
    
    if(start>=end){
        return;
    }
    
    int mid = start + (end-start)/2;
    
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}



int main() {
   vector<int>arr = {5,4,3,2,1};
   int n = arr.size();
   
   int start = 0;
   int end = n-1;
   
   mergeSort(arr,start,end);
   
   for(int i =0; i< n; i++){
       cout<<arr[i]<<"\t";
   }

    return 0;
}