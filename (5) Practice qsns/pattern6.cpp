#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    

    for(int i=0;i<n;i++){
       
        int count=65+i;
        for(int j=0;j<n;j++){
           
            cout << char(count) << " ";
            count++;
              
            
        }
        cout<<endl;
    }
}