#include<bits/stdc++.h>
using namespace std;

// Coin Change 
// memoization
  long long int rec(int s[],int i,int n,int sum,vector<vector<long long int>> &mem){
      if(i==n){
          if(sum==0) return 1;
          return 0;
      }
      if(mem[i][sum]!=-1) return mem[i][sum];
      if(sum>=s[i]){
          return mem[i][sum]=rec(s,i,n,sum-s[i],mem)+rec(s,i+1,n,sum,mem);
      }
      else{
          return mem[i][sum]=rec(s,i+1,n,sum,mem);
      }
  }
    long long int countm(int S[], int m, int n) {

        // code here.
        vector<vector<long long int>> mem(m+1,vector<long long int>(n+1,-1));
        return rec(S,0,m,n,mem);
    }

//tabulation
    long long int count(int S[], int m, int n) {

       long long int dp[m+1][n+1];
      
       for(int i=m;i>=0;i--){
           for(int j=0;j<=n;j++){
               if(i==m){
                   if(j==0) dp[i][j]=1;
                   else dp[i][j]=0;
               }else{
                   if(j>=S[i]){
                       dp[i][j]=dp[i][j-S[i]]+dp[i+1][j];
                   }else{
                       dp[i][j]=dp[i+1][j];
                   }
                   
               }
           }
       }
       return dp[0][n];
    }

    //Function to return max value that can be put in knapsack of capacity W.
    // memoization
    int rec(int wt[],int i,int w,int val[],int v,int n,vector<vector<int>> &mem){
        if(i==n){
            return 0;
            
        }
        if(mem[i][w]!=-1) return mem[i][w];
        if(w>=wt[i]){
            return mem[i][w]=max(rec(wt,i+1,w,val,v,n,mem),val[i]+rec(wt,i+1,w-wt[i],val,v,n,mem));
        }
        else{
            return mem[i][w]=rec(wt,i+1,w,val,v,n,mem);
        }
    }
    
    int knapSackm(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> mem(n+1,vector<int>(W+1,-1));
       return rec(wt,0,W,val,0,n,mem);
       
    }
    // tabulation

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      int dp[n+1][W+1];
      for(int i=n;i>=0;i--){
          for(int j=0;j<=W;j++){
              if(i==n){
                  dp[i][j]=0;
              }
              else{
                  if(j>=wt[i])
                  dp[i][j]=max(dp[i+1][j],val[i]+dp[i+1][j-wt[i]]);
                  else
                  dp[i][j]=dp[i+1][j];
              }
          }
      }
      return dp[0][W];
       
    }

    // nCr
    // mem
     long long rec(int n,int r,vector<vector<int>> &mem){
        if(n<r) return 0;
        if(r==0) return 1;
        if(mem[n][r]!=-1) return mem[n][r];
        return mem[n][r]=(rec(n-1,r,mem)+rec(n-1,r-1,mem))%1000000007;
    }
    int nCrm(int n, int r){
        vector<vector<int>> mem(n+1,vector<int>(r+1,-1));
        return rec(n,r,mem);
    }
    //tabulation
     int nCr(int n, int r){
        long long dp[n+1][r+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
                if(i<j) dp[i][j]=0;
                else if(j==0) dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%1000000007;
            }
        }
        return dp[n][r];
    }
    //MCM mem
    int rec(int arr[],int i,int j,vector<vector<int>> &mem){
        if(i==j) return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        int mi=INT_MAX;
        for(int k=i;k<j;k++){
            mi=min(mi,((arr[i-1])*arr[k]*arr[j])+rec(arr,i,k,mem)+rec(arr,k+1,j,mem));
        }
        return mem[i][j]=mi;
    }

    int matrixMultiplicationm(int N, int arr[])
    {
        // code here
        vector<vector<int>> mem(N,vector<int>(N,-1));
        return rec(arr,1,N-1,mem);
        
    }

    //tabulation
   int matrixMultiplication(int N, int arr[])
    {
        int dp[N+1][N+1];
        for(int i=N-1;i>0;i--){
            for(int j=1;j<N;j++){
                if(i==j) dp[i][j]=0;
                else{
                    int ans=INT_MAX;
                    for(int k=i;k<j;k++){
                        ans=min(ans,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[1][N-1];
    }


    int lcs(string s,string t,int i,int j,vector<vector<int>> &mem){
        if(i==s.size() || j==t.size()) return max(s.size()-i,t.size()-j);
        if(mem[i][j]!=-1) return mem[i][j];
        if(s[i]==t[j]){
            return mem[i][j]=lcs(s,t,i+1,j+1,mem);
        }
        else{
            return mem[i][j]=1+min(lcs(s,t,i,j+1,mem),min(lcs(s,t,i+1,j,mem),lcs(s,t,i+1,j+1,mem)));
        }
    }
    int editDistancem(string s, string t) {
        vector<vector<int>> mem(s.size(),vector<int>(t.size(),-1));
      int lcsl= lcs(s,t,0,0,mem);
    //   cout<<lcsl;
      return lcsl;
    }

    int editDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
       int dp[n+1][m+1];
       for(int i=n;i>=0;i--){
           for(int j=m;j>=0;j--){
               if(i==n || j==m){
                   dp[i][j]=max(n-i,m-j);
               }
               else{
                   if(s[i]==t[j]){
                       dp[i][j]=dp[i+1][j+1];
                   }
                   else{
                       dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                   }
               }
           }
       }
       return dp[0][0];
    }


     int equalPartition(int N, int arr[])
    {
       int s=0;
       for(int i=0;i<N;i++){
           s+=arr[i];
       }
       if(s%2==1) return 0;
       s=s/2;
       int dp[N+1][s+1];
       for(int i=N;i>=0;i--){
           for(int j=0;j<=s;j++){
               if(i==N){
                   if(j==0) dp[i][j]=1;
                   else dp[i][j]=0;
               }
               else{
                   if(j>=arr[i]){
                       dp[i][j]=dp[i+1][j-arr[i]]||dp[i+1][j];
                   }
                   else{
                       dp[i][j]=dp[i+1][j];
                   }
               }
           }
           
       }
       return dp[0][s];
    }

     int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n+1][m+1];
        for(int j=m;j>=0;j--){
            for(int i=n;i>=0;i--){
                if(j==m || i==n){
                    dp[i][j]=0;
                }
                else if(j==m-1){
                    dp[i][j]=M[i][j];
                }
                else{
                    int ans=INT_MIN;
                    ans=max(ans,dp[i][j+1]);
                    if(i!=0){
                        ans=max(ans,dp[i-1][j+1]);
                    }
                    if(i!=n-1){
                        ans=max(ans,dp[i+1][j+1]);
                    }
                    dp[i][j]=M[i][j]+ans;
                }
            }
        }
       
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }

// Painting the Fence 
     long long countWays(int n, int k){
        // code here
        long long mod=1000000007;
        int s=2;
        long long  dp[n+1][s+1];
        for(int i=n;i>=0;i--){
            for(int j=s;j>=0;j--){
                if(i==n){
                    dp[i][j]=1;
                }
                else if(j==2){
                    dp[i][j]=(k*dp[i+1][j-1])%mod ;
                }
                else if(j==1){
                    dp[i][j]=(((k-1)*dp[i+1][j])%mod+dp[i+1][j-1])%mod;
                }
                else{
                    dp[i][j]=((k-1)*dp[i+1][1])%mod;
                }
                
            }
        }
       
        return dp[0][s];
    }

     //Function to find the maximum number of cuts.
    //  Maximize The Cut Segments 
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int wt[]={x,y,z};
        int dp[4][n+1];
        for(int i=3;i>=0;i--){
            for(int j=0;j<=n;j++){
                if(i==3){
                    if(j==0) dp[i][j]=0;
                    else
                    dp[i][j]=INT_MIN;
                }
                else{
                    if(j>=wt[i]){
                        dp[i][j]=max(1+dp[i][j-wt[i]],dp[i+1][j]);
                    }
                    else{
                        dp[i][j]=dp[i+1][j];
                    }
                }
            }
        }
        if(dp[0][n]<0) return 0;
        return dp[0][n];
    }

      //Function to find the length of longest common subsequence in two strings.
  
  int lcs(int x, int y, string s1, string s2)
    {
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m) {
                    dp[i][j]=0;
                }
                else{
                    if(s1[i]==s2[j]){
                        dp[i][j]=1+dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
                }
            }
        }
        return dp[0][0];
    }

    int longestSubsequence(int n, int a[]) // longest increasing subsequence
    {
       // your code here
        int dp[n+1];
        for(int i=n;i>=0;i--){
             if(i==n) dp[i]=0;
             else{
             int ma=INT_MIN;
            for(int j=i;j<=n;j++){
               
               
                if(a[i]<a[j]) ma=max(ma,dp[j]+1);
                
            }
                if(ma==INT_MIN) dp[i]=1;
                else dp[i]=ma;
                // cout<<i<<dp[i];
             }
            
        }
    int ans=INT_MIN;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
    }


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[(n1+1)*100+n2+1][n3+1];
    for(int i=n1;i>=0;i--){
        for(int j=n2;j>=0;j--){
            for(int k=n3;k>=0;k--){
                
                if(i==n1 || j==n2 || k==n3){
                    dp[i*100+j][k]=0;
                }
                else{
                    if(A[i]==B[j] && B[j]==C[k]){
                        dp[i*100+j][k]=1+dp[(i+1)*100+j+1][k+1];
                    }
                    else if(A[i]==B[j]){
                        dp[i*100+j][k]=max(dp[(i+1)*100+j+1][k],dp[i*100+j][k+1]);
                    }
                    else if(B[j]==C[k]){
                     dp[i*100+j][k]=max(dp[(i)*100+j+1][k+1],dp[(i+1)*100+j][k]);   
                    }
                    else{
                        dp[i*100+j][k]=max(dp[i*100+j][k+1],max(dp[(i+1)*100+j][k],dp[i*100+j+1][k]));
                    }
                }
            }
        }
        
    }
    return dp[0][0];
}
// Maximum sum increasing subsequence 
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n+1];
	    for(int i=n;i>=0;i--){
	        if(i==n) dp[i]=0;
	        else{
	            int ma=INT_MIN;
	            for(int j=i+1;j<=n;j++){
	                if(arr[i]<arr[j])
	                ma=max(ma,arr[i]+dp[j]);
	            }
	            if(ma==INT_MIN) dp[i]=arr[i];
	            else dp[i]=ma;
	        }
	    }
	    int ans=INT_MIN;
	    for(int i=0;i<=n;i++){
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}  
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int rec(int n,int k,vector<vector<int>> &mem){
        if(n==1 || k==1) return k;
        if(mem[n][k]!=-1) return mem[n][k];
        int mi=1000000;
        for(int i=1;i<=k;i++){
            mi=min(mi,1+max(rec(n,k-i,mem),rec(n-1,i-1,mem)));
        }
        if(mi==1000000){
             return mem[n][k]=0;
        }
        return mem[n][k]=mi;
    }
    
  
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> mem(n+1,vector<int>(k+1,-1));
        return rec(n,k,mem);
        
        
    }

      int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i<=1 || j<=1) dp[i][j]= j;
                else{
                    int mi=INT_MAX;
                    for(int p=1;p<=j;p++){
                        mi=min(mi,1+max(dp[i-1][p-1],dp[i][j-p]));
                    }
                    if(mi==INT_MAX) dp[i][j]=0;
                    else dp[i][j]=mi;
                }
            }
            
        }
        return dp[n][k];
        
    }

     int maxmat(vector<int> &a){
        int n=a.size();
        // for(auto i:a) cout<<i<<" ";
        // cout<<"\n";
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> q;
        for(int i=n-1;i>=0;i--){
            if(q.empty()){
                q.push(i);
            }                           
                                            
            else{
                while(!q.empty() && a[q.top()]>a[i]){
                    left[q.top()]=i;
                    q.pop();
                }
                q.push(i);
            }
        }
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++){
            if(q.empty()){
                q.push(i);
            }
            else{
                while(!q.empty() && a[q.top()]>a[i]){
                    right[q.top()]=i;
                    q.pop();
                }
                q.push(i);
            }
        }
        // for(auto i:left) cout<<i<<" ";
        // cout<<"\n";
        // for(auto i:right) cout<<i<<" ";
        // cout<<"\n";
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int mi=min(right[i]-left[i]-1,a[i]);
            ans=max(ans,mi);
        }
        return ans;
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<int> a(m,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) a[j]++;
                else a[j]=0;
            }
            ans=max(ans,maxmat(a));
            
        }
        return ans;
        
    }
    
     int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here  
        sort(arr,arr+N,greater<int>());
        int ans=0;
        int p=-1;
        for(int i=0;i<N;i++){
            if(p==-1){
                p=arr[i];
            }
            else if(p-arr[i]<K){
                ans+=p+arr[i];
                p=-1;
                
            }
            else{
                // ans+=p+pr;
                p=arr[i];
            }
        }
        return ans;
        
    }

// Minimum cost to fill given weight in a bag 
    	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[N+1][W+1];
        for(int i=N;i>=0;i--){
            for(int j=0;j<=W;j++){
                if(j==0) dp[i][j]=0;
                else if(i==N){
                    if(j==0) dp[i][j]=0;
                    else dp[i][j]=1000000;
                }
                else{
                    if(j>=(i+1) && cost[i]!=-1){
                        dp[i][j]=min(cost[i]+dp[i][j-(i+1)],dp[i+1][j]);
                    }
                    else{
                        dp[i][j]=dp[i+1][j];
                    }
                }
            }
        }
       
        if(dp[0][W]>=1000000) return -1;
        return dp[0][W];
	} 


 int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        multiset<int> ms;
        int ma=1;
        int i=-1;
        int n=a.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(ms.empty()){
                ms.insert(a[i]);
            }else {
                int m1=(*ms.rbegin());
                int m2=(*ms.begin());
                // cout<<m1<<m2;
                if(m1-m2<=k){
                    int s2=ms.size();
                    // cout<<s2<<" ";
                    ma=max(ma,s2);
                    ms.insert(a[i]);
                }
                else{
                    while((*ms.rbegin())-(*ms.begin())>k){
                        ms.erase(ms.begin());
                    }
                    ms.insert(a[i]);
                }
            }
        }
         int m1=(*ms.rbegin());
                int m2=(*ms.begin());
        if(m1-m2<=k){
                    int s2=ms.size();
                    
                    ma=max(ma,s2);
                   
                }
        return n-ma;
    }

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m){
                    dp[i][j]=0;
                }
                else{
                    if(S1[i]==S2[j]){
                        if(S1[i+1]==S2[j+1]){
                        dp[i][j]=1+dp[i+1][j+1];
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
                }
            }
        }
        int ma=INT_MIN;
        
            for(int j=0;j<=m;j++){
                ma=max(ma,dp[0][j]);
                
            }
            for(int i=0;i<=n;i++){
                ma=max(ma,dp[i][0]);
            }
          
        return ma;
    }
    long long int countBT(int h) { 
        // code here
        long long m=1000000007;
        long long ans=0;
        long long  dp[h+1];
        for(int i=0;i<=h;i++){
            if(i<=1) dp[i]= 1LL;
            else{
                dp[i]=((dp[i-1]*dp[i-1])%m+(dp[i-2]*dp[i-1])%m+(dp[i-1]*dp[i-2])%m)%m;
            }
        }
        return dp[h];
        
        
    }
    int smallestSumSubarray(vector<int>& a){ //**kadane's algorithm
      //Code here
      int mi=INT_MAX;
      int s=0;
      for(int i=0;i<a.size();i++){
          s+=a[i];
          mi=min(mi,s);
          if(s>0){
              s=0;
          }
      }
      return mi;
  }

   int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        for(int i=N;i>=0;i--){
            for(int j=0;j<=W;j++){
                if(i==N){
                    dp[i][j]=0;
                }
                else{
                    if(j>=wt[i]){
                        dp[i][j]=max(val[i]+dp[i][j-wt[i]],dp[i+1][j]);
                    }
                    else{
                        dp[i][j]=dp[i+1][j];
                    }
                }
            }
        }
        return max(0,dp[0][W]);
    }
    int wordBreak(string A, vector<string> &B) {
      
      set<string> st;
       int n=A.size();
      bool ss[n+1][n+1];
      for(auto &i:B){
          st.insert(i);
      }
      for(int i=0;i<n;i++){
          string temp="";
          for(int j=i;j<n;j++){
              temp+=A[j];
              if(st.find(temp)!=st.end()){
                  ss[i][j]=1;
              }
              else{
                  ss[i][j]=0;
              }
          }
      }
     
      int dp[n+1][n+1];
      for(int i=n;i>=0;i--){
          for(int j=n;j>=i;j--){
              if(i==n && j==n){
                  dp[i][j]=1;
              }
              else if(j==n){
                  dp[i][j]=0;
              }
              else{
                  if(ss[i][j]){
                      dp[i][j]=dp[i][j+1]||dp[j+1][j+1];
                  }
                  else{
                      dp[i][j]=dp[i][j+1];
                  }
              }
          }
      }
      return dp[0][0];
    }

 int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        int dp[n+1][n+1];
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==n || j==n){
                    dp[i][j]=0;
                }
                else
                {
                    if(A[i]==A[n-j-1]){
                        dp[i][j]=1+(dp[i+1][j+1]);
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
                }
            }
        }
        return dp[0][0];
    }

     string longestPalindrome(string s) {
        
    int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n;i++){
            int ll=i;
            int rr=i;
            while(ll>=0 && rr<n && s[ll]==s[rr]){
               
                if(rr-ll>r-l){
                    r=rr;
                    l=ll;
                }
                 ll--;
                rr++;
            }
        }
        for(int i=0;i<n-1;i++){
            int ll=i;
            int rr=i+1;
            while(ll>=0 && rr<n && s[ll]==s[rr]){
                
                if(rr-ll>r-l){
                    r=rr;
                    l=ll;
                }
                ll--;
                rr++;
            }
        }
        return s.substr(l,r-l+1);
    
    }

    	int AlternatingaMaxLength(vector<int>&nums){//********* Unique Approach
		    // Code here
		   int mi=1;
		   int ma=1;
		   for(int i=1;i<nums.size();i++){
		        if(nums[i-1]<nums[i]){
		            ma=mi+1;
		        }   
		        else if(nums[i-1]>nums[i]){
		            mi=ma+1;
		        }
		   }
		   return max(mi,ma);
		}

        	int findWinner(int N, int X, int Y) //*****Analysis
	{
		// Your code goes here
		bool dp[N+1];
		for(int i=0;i<=N;i++){
		    if(i==0){
		        dp[i]=false;
		    }
		    else if(i==1){
		        dp[i]=true;
		    }
		    else if(i>=1 && dp[i-1]==false){
		        dp[i]=true;
		    }
		    else if(i>=X && dp[i-X]==false){
		        dp[i]=true;
		    }
		    else if(i>=Y && dp[i-Y]==false){
		        dp[i]=true;
		    }
		    else {
		        dp[i]=false;
		    }
		    
		}
		return dp[N]?1:0;
	
	}

// Buy and Sell a Share at most twice 
int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    int l[n];
    int r[n];
    int mi=INT_MAX;
    int ma=INT_MIN;
    for(int i=0;i<n;i++){
        mi=min(mi,price[i]);
        ma=max(ma,price[i]-mi);
        l[i]=ma;
    }
    mi=INT_MIN;
    ma=INT_MIN;
    for(int i=n-1;i>=0;i--){
        mi=max(mi,price[i]);
        ma=max(ma,mi-price[i]);
        r[i]=ma;
    }
    int ans=INT_MIN;
    for(int i=1;i<n;i++){
        ans=max(ans,l[i-1]+r[i]);
    }
    return ans;
}

// Optimal Strategy For A Game 
 long long  rec(int a[],int n,int i,int j,vector<vector<long long>>&mem){
        if(i>=j) return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        return mem[i][j]=max(a[i]+min(rec(a,n,i+2,j,mem),rec(a,n,i+1,j-1,mem)),a[j]+min(rec(a,n,i+1,j-1,mem),rec(a,n,i,j-2,mem)));
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> mem(n,vector<long long>(n,-1));
        return rec(arr,n,0,n-1,mem);
    }

    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<vector<bool>> p(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && str[l]==str[r]){
                p[l][r]=1;
                l--;
                r++;
            }
        }
        for(int i=0;i<n-1;i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<n && str[l]==str[r]){
                p[l][r]=1;
                l--;
                r++;
            }
        }
        int dp[n+1][n+1];
        for(int i=n;i>=0;i--){
            for(int j=n;j>=i;j--){
                if(j==n){
                    if(i==n) {
                        dp[i][j]=-1;
                    }else{
                        dp[i][j]=1000000;
                    }
                }else{
                    if(p[i][j]){
                        dp[i][j]=min(1+dp[j+1][j+1],dp[i][j+1]);
                    }
                    else{
                        dp[i][j]=dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }

    	long long getCount(int N)
	{
		// Your code goes here
		long long dp[N+1][10];
		for(int i=0;i<=N;i++){
		    for(int j=0;j<=9;j++){
		        if(i==0){
		            dp[i][j]=0;
		        }
		        else if(i==1){
		            dp[i][j]=1;
		        }
		        else{
		            long long ct=0;
		            if(j==0){
		                ct+=dp[i-1][8];
		                ct+=dp[i-1][j];
		                
		            }
		            else if(j==1){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][2];
		                ct+=dp[i-1][4];
		                
		            }
		            else if(j==2){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][1];
		                ct+=dp[i-1][3];
		                ct+=dp[i-1][5];
		                
		            }
		            else if(j==3){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][2];
		                ct+=dp[i-1][6];
		                
		            }
		             else if(j==4){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][1];
		                ct+=dp[i-1][7];
		                ct+=dp[i-1][5];
		                
		            }
		             else if(j==5){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][2];
		                ct+=dp[i-1][8];
		                ct+=dp[i-1][4];
		                ct+=dp[i-1][6];
		                
		            }
		             else if(j==6){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][5];
		                ct+=dp[i-1][3];
		                ct+=dp[i-1][9];
		                
		            }
		             else if(j==7){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][4];
		                ct+=dp[i-1][8];
		                
		            }
		             else if(j==8){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][5];
		                ct+=dp[i-1][0];
		                ct+=dp[i-1][7];
		                ct+=dp[i-1][9];
		                
		            }
		             else if(j==9){
		                ct+=dp[i-1][j];
		                ct+=dp[i-1][8];
		                ct+=dp[i-1][6];
		                
		            }
		            dp[i][j]=ct;
		        }
		    }
		}
		long long ans=0;
		for(int i=0;i<=9;i++){
		    ans+=dp[N][i];
		}
		return ans;
	}

// Boolean Parenthesization 
int m=1003;
    pair<int,int> rec(string s,int i,int j,vector<vector<pair<int,int>>> &mem){
        
        if(j==i) {
            if(s[i]=='T') return {1,0};
            return {0,1};
        }
        if(mem[i][j].first!=-1) return mem[i][j];
        pair<int,int> ans={0,0};
        for(int k=i+2;k<=j;k+=2){
            pair<int,int>p1,p2;
            p1=rec(s,i,k-2,mem);
            p2=rec(s,k,j,mem);
            if(s[k-1]=='|'){
                ans.first+=(p1.first*p2.first)%m+p1.first*p2.second%m+p1.second*p2.first%m;
                ans.second+=p1.second*p2.second%m;
            }
            else if(s[k-1]=='&'){
                ans.first+=(p1.first*p2.first)%m;
                ans.second+=p1.second*p2.second%m+p1.first*p2.second%m+p1.second*p2.first%m;
            }
            else if(s[k-1]=='^'){
                ans.first+=p1.first*p2.second%m+p1.second*p2.first%m;
                ans.second+=p1.second*p2.second%m+p1.first*p2.first%m;
            }
            
        }
        // cout<<i<<j<<ans.first<<ans.second<<" ";
        
        return mem[i][j]=(ans);
    }

    int countWays(int N, string S){
        // code here
        vector<vector<pair<int,int>>> mem(N,vector<pair<int,int>>(N,{-1,-1}));
        return rec(S,0,N-1,mem).first%1003;
        
    }

    int m=1003;
  

    int countWays(int N, string S){ //*** Only care about direction of traverse in table to convert mem to dp
        // code here
        int m=1003;
        vector<vector<pair<int,int>>> dp(N+1,vector<pair<int,int>>(N+1,{0,0}));
        for(int i=N;i>=0;i--){
            for(int j=0;j<=N;j++){
                if(i==j){
                    if(S[i]=='T'){
                        dp[i][j]={1,0};
                        }
                        else{
                           dp[i][j]= {0,1};
                        }
                }
                else{
                    for(int k=i+2;k<=j;k+=2){
                       if(S[k-1]=='|'){
                        dp[i][j].first+=(dp[i][k-2].first*dp[k][j].first)%m+dp[i][k-2].first*dp[k][j].second%m+dp[i][k-2].second*dp[k][j].first%m;
                        dp[i][j].second+=dp[i][k-2].second*dp[k][j].second%m;
                        }
                        else if(S[k-1]=='&'){
                            dp[i][j].first+=(dp[i][k-2].first*dp[k][j].first)%m;
                            dp[i][j].second+=dp[i][k-2].second*dp[k][j].second%m+dp[i][k-2].first*dp[k][j].second%m+dp[i][k-2].second*dp[k][j].first%m;
                        }
                        else if(S[k-1]=='^'){
                            dp[i][j].first+=dp[i][k-2].first*dp[k][j].second%m+dp[i][k-2].second*dp[k][j].first%m;
                            dp[i][j].second+=dp[i][k-2].second*dp[k][j].second%m+dp[i][k-2].first*dp[k][j].first%m;
                        }
                    }
                    
                 }
                //  cout<<i<<j<<dp[i][j].first<<dp[i][j].second<<" ";
            }
        }
        return dp[0][N-1].first%m;
    }
    // Maximum sum Rectangle 
     int maxSub(int a[],int n){//** kadane's algo
      int ans=INT_MIN;
      int s=0;
      for(int i=0;i<n;i++){
          s+=a[i];
          ans=max(ans,s);
          if(s<0){
              s=0;
          }
      }
      return ans;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int a[C];
        int ans=INT_MIN;
        for(int i=0;i<C;i++) a[i]=0;
        for(int i=0;i<R;i++){
            for(int i=0;i<C;i++) a[i]=0;
             for(int j=i;j<R;j++){
                 for(int k=0;k<C;k++){
                     a[k]+=M[j][k];
                 }
                 int x=maxSub(a,C);
                //  cout<<x<<" ";
                 ans=max(ans,x);
                 
             }   
        }
        return ans;
    }

    // Largest rectangular sub-matrix whose sum is 0 

pair<int,int> find(vector<int> &v){
      unordered_map<int,pair<int,int>> mp;
      int s=0;
      mp[0]={0,-1};
      for(int i=0;i<v.size();i++){
          s+=v[i];
          if(mp.find(s)==mp.end()){
              mp[s]={i+1,-1};
          }
          else{
              mp[s].second=i;
          }
      }
      int ma=0;
      int l=-1,r=-1;
      for(auto i:mp){
        //   cout<<i.first<<" "<<i.second.first<<" "<<i.second.second;
        if(i.second.second!=-1 && i.second.second-i.second.first+1>ma){
            ma=i.second.second-i.second.first+1;
            l=i.second.first;
            r=i.second.second;
        }   
      }
      return {l,r};
      
  }
  
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n=a.size();
      int m=a[0].size();
      int ans=-1;
      int x1,y1,x2,y2;
      for(int i=0;i<n;i++){
           vector<int> v(m,0);
          for(int j=i;j<n;j++){
             
              for(int k=0;k<m;k++){
                  v[k]+=a[j][k];
              }
              pair<int,int> a=find(v);
              
              int l=a.first;
              int r=a.second;
            //   cout<<l<<r<<"\n";
              if(l!=-1){
                  if((r-l+1)*(j-i+1)==ans){
                      if(x2-x1<r-l){
                           x1=l;
                            x2=r;
                            y1=i;
                            y2=j;
                      }
                  }
                else if((r-l+1)*(j-i+1)>ans){
                    ans=(r-l+1)*(j-i+1);
                    x1=l;
                    x2=r;
                    y1=i;
                    y2=j;
                }   
              }
          }
      }
    //   cout<<x1<<x2<<y1<<y2<<"\n";
    
      vector<vector<int>> vv;
      if(ans!=-1){
          for(int i=y1;i<=y2;i++){
              vector<int> temp;
              for(int j=x1;j<=x2;j++){
                  temp.push_back(a[i][j]);
              }
              vv.push_back(temp);
          }
      }
      return vv;
  }

// Maximum Profit 
  int rec(int a[],int i,int n,int k,vector<vector<int>> &mem){
      
          if(i==n || k==0) return 0;
         
      if(mem[i][k]!=-1)return mem[i][k];
      if(k>0){
          int mi=INT_MAX;
          int ma=INT_MIN;
          int ans=INT_MIN;
          for(int p=i;p<n;p++){
              mi=min(mi,a[p]);
              ma=max(a[p]-mi,ma);
              ans=max(ans,ma+rec(a,p+1,n,k-1,mem));
              
          }
          return mem[i][k]=ans;
      }
  }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> mem(N+1,vector<int>(K+1,-1));
        return rec(A,0,N,K,mem);
        
    }

       /*You are required to complete this method */
    //    Interleaved Strings 
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.size();
        int m=B.size();
        int s=C.size();
        if(n+m!=s) return 0;
        int dp[n+1][m+1];
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m){
                    dp[i][j]=1;
                }
                else{
                    if(i<n && j<m && C[s-(n-i)-(m-j)]==A[i] && C[s-(n-i)-(m-j)]==B[j]){
                        dp[i][j]=(dp[i+1][j]||dp[i][j+1]);
                    }
                    else if(i<n && C[s-(n-i)-(m-j)]==A[i]){
                        dp[i][j]=dp[i+1][j];
                    }
                    else if(j<m && C[s-(n-i)-(m-j)]==B[j]){
                        dp[i][j]=dp[i][j+1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                // cout<<i<<j<<dp[i][j]<<" ";
            }
            
        }
        return dp[0][0];
    }

int main(){

    return 0;
}