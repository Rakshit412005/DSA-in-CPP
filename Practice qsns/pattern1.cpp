#include<iostream>
using namespace std;
int main(){
   int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int count=1;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count<<" ";
            count++;
            j++;
        }
        i++;
        cout<<endl;

    }
    return 0;

}