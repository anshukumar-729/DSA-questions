#include <bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    int* stack;
    int topPointer;
    public:
        Stack(int size=40){
            size=size;
            topPointer=-1;
            stack = new int[size];
        }
        void pop();
        int top();
        void push(int data);
        bool isEmpty();
        bool isFull();
};
bool Stack::isEmpty(){
   return topPointer==-1;
}
bool Stack::isFull(){
    return topPointer==size-1;
}
int Stack::top(){
    if(!isEmpty())
    return stack[topPointer];
    cout<<"underflow\n";
    return -1;
}
void Stack::pop(){
    if(!isEmpty()){
    topPointer=-1;
    return;
    }
    cout<<"underflow\n";
}
void Stack::push(int data){
    if(!isFull()){
    topPointer++;
    stack[topPointer]=data;
    return;
    }
    cout<<"overflow\n";
}

class Queue{
    int frontPointer;
    int rearPointer;
    int* queue;
    int size;

    Queue(int size=40){
        size=size;
        rearPointer=-1;
        frontPointer=-1;
        queue = new int [size];
    }
    bool isFull();
    bool isEmpty();
    void push(int data);
    int front();
    void pop();
};
bool Queue::isFull(){
    return rearPointer==size;
}
bool Queue::isEmpty(){
    return rearPointer==-1||frontPointer==rearPointer;
}
void Queue::push(int data){
    if(!isFull()){
        if(isEmpty()){
            rearPointer++;
            frontPointer++;
        }
        queue[rearPointer]=data;
        rearPointer++;
    }
    else{
        cout<<"overflow\n";
    }
}
void Queue::pop(){
    if(!isEmpty()){
        frontPointer++;
    }
    else{
        cout<<"underflow\n";
    }
}
int Queue::front(){
    if(!isEmpty()){
        return queue[frontPointer];
    }
    else{
        cout<<"underflow\n";
        return -1;
    }
}
 //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        stack<long long> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
        // Your code here
    }

     //Function to find if there is a celebrity in the party or not.*******unique approach
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==0 && M[b][a]==1){
                st.push(a);
            }
            else if(M[a][b]==1 && M[b][a]==0){
                st.push(b);
            }
        }
        if(st.empty()){
            return -1;
        }
        int d=st.top();
        int f=0;
        for(int i=0;i<n;i++){
            if(i==d) continue;
            if(M[d][i]==1 || M[i][d]==0){
                f=1;
                break;
            }
        }
        if(f){
            return -1;
        }
        return d;
    }

// Overlapping Intervals 
    static  bool  cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
  }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end(),cmp);
         vector<vector<int>> ans;
         pair<int,int> p={intervals[0][0],intervals[0][1]};
         for(int i=1;i<intervals.size();i++){
             if(intervals[i][0]<=p.second){
                 p.second=max(p.second,intervals[i][1]);
             }
             else{
                 ans.push_back({p.first,p.second});
                 p.first=intervals[i][0];
                 p.second=intervals[i][1];
             }
         }
         ans.push_back({p.first,p.second});
         return ans;
    }
    
    // Valid Substring 
     int findMaxLen(string s) {
        int l=0;
        int r=0;
        stack<int> st;
        int ct=0;
        int ma=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
                l++;
            }
            else{
               if(st.empty() || s[st.top()]==')'){
                   st.push(i);
                   r++;
               }
               else{
                   st.pop();
                   l--;
               }
            }
        }
        // code here
        int p=s.size();
        while(!st.empty()){
            // cout<<p;
            ma=max(ma,p-st.top()-1);
            p=st.top();
            st.pop();
        }
        // cout<<p;
        if(p>ma){
            ma=p;
        }
        return ma;
    }

int main(){
    
    Stack s1;
    s1.push(3);
    cout<<s1.top()<<"\n";
    s1.pop();
    s1.pop();
    return 0;
}
