#include <bits/stdc++.h>
using namespace std;
/*
class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack(){
        n=0;
    }
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        if(n==0){
            cout<<"empty"<<endl;
        }
        q1.pop();
        n--;
    }
    int top(){
        if(!q1.empty()){
        return q1.front();
        }
        cout<<"no element ";
        return -1;
    }
    int size(){
        return n;
    }
};*/
class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack(){
        n=0;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        if(n==0){
            n=0;
            return;
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
     void push(int val){
        q1.push(val);
        n++;
     }
    int top(){
        if(q1.empty()){
        return -1;
        }
        while(q1.size()!= 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(ans);
        queue<int> temp=q1;
        q1=q2;
        q2=temp;

        return ans;
    }
    int size(){
        return n;
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size();
    return 0;
}

