#include<iostream>
using namespace std;
void pairSum(int arr[], int sum,int length){
    cout<<length<<endl;
    
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            if(arr[i]!=arr[j] && arr[i]+arr[j]== sum){
                cout<<arr[i]<<" "<<arr[j];
            }
        }
        cout<<endl;
    }
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int length= sizeof(arr)/sizeof(int);
    pairSum(arr,6,length);
    
    return 0;
}