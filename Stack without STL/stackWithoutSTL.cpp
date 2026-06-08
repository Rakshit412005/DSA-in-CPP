#include<iostream>
#include<stack>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    
    public: 
    
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }
    
    void push(int element){
        if((size-top) >= 1){
            top++;
            arr[top] = element;
        }
        
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    
    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    
    void isEmpty(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }
};

int main(){
    Stack st(5);
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.peek();
    st.pop();
    st.peek();
    st.isEmpty();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.isEmpty();
    st.peek();
    return 0;
    
}