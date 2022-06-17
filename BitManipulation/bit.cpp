#include<bits/stdc++.h>
using namespace std;

 int setBits(int N) {
        // Write Your Code here
        int ct=0;
        while(N>0){
            ct+=N&1;
            N=N>>1;
        }
        return ct;
    }

 vector<int> singleNumber(vector<int> nums) 
    {
        int ans=0;
        for(auto i: nums){
            ans^=i;
        }
        int rmsb=ans&~(ans-1); // rigth most set bit number 
        int a1=0;
        int a2=0;
        for(auto i:nums){
            if(i&rmsb){
                a1^=i;
            }
            else{
                a2^=i;
            }
        }
        return {min(a1,a2),max(a1,a2)}; 
        
        
    }

        // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int countSetBits(int n)
    {
        int ans=0;
        n++;
        int p=n;
        int i=1;
        while(n>0){
          ans+=(p/(i<<1))*i;
          ans+=(max(0,(p%(i<<1))-i))%i;
          i<<=1;
          n>>=1;
        }
        return ans;
       
        
    }

      // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        return !(n&n-1);
        
    }
     int findPosition(int N) {
        // code here
        int msb=N&~(N-1);
        if(N^msb) return -1;
        return (int)log2(msb)+1;
    }

    long long divide(long long dividend, long long divisor) //O(log(n))
    {
       int ans=0;
       bool sign=(dividend>0 & divisor>0)||(dividend<0 & divisor<0) ;
      
       dividend=abs(dividend);
       divisor=abs(divisor);
       while(dividend>0){
        //   cout<<dividend<<divisor<<" ";
           int t=divisor;
           int ct=-1;
           while(t<=dividend){
               ct++;
               t<<=1;
           }
           if(ct>=0)
           ans+=1<<ct;
        //   cout<<"a"<<ans;
           dividend=dividend-(t>>1);
       }
       if(!sign) ans=-ans;
       return ans;
        //code here
    }
int main(){

    return 0;
}