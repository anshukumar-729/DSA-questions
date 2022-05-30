#include<bits/stdc++.h>
using namespace std;
// Rat in a Maze Problem - I 
 void rec(vector<vector<int>> v,int n,int i,int j,vector<string> &ans,string s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        v[i][j]=0;
        if(i!=0 && v[i-1][j]!=0){
            rec(v,n,i-1,j,ans,s+'U');
        }
        if(i!=n-1 && v[i+1][j]!=0){
            rec(v,n,i+1,j,ans,s+'D');
        }
        if(j!=0 && v[i][j-1]!=0){
            rec(v,n,i,j-1,ans,s+'L');
        }
        if(j!=n-1 && v[i][j+1]!=0){
            rec(v,n,i,j+1,ans,s+'R');
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        if(m[0][0]==0) return ans;
        rec(m,n,0,0,ans,"");
        return ans;
    }

// N-Queen Problem 

     void rec(int n,int j,map<int,bool> mp,map<int,bool> mp1,map<int,bool> mp2,vector<int> v,vector<vector<int>> &ans){
            if(j==n ){
                ans.push_back(v);
                return;
            }
            int f=0;
            for(int i=0;i<n;i++){
                if(mp[i]!=1 && mp1[j-i]!=1 && mp2[j-(n-i-1)]!=1){
                    f=1;
                    mp[i]=1;
                    mp1[j-i]=1;
                    mp2[j-(n-i-1)]=1;
                    v.push_back(i+1);
                    rec(n,j+1,mp,mp1,mp2,v,ans);
                    v.pop_back();
                    mp[i]=0;
                    mp1[j-i]=0;
                    mp2[j-(n-i-1)]=0;
                    
                }
            }
            if(f==0) return;
        
        
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        map<int,bool> mp1,mp2,mp;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            mp[i]=0;
        }
        for(int i=-n+1;i<n;i++){
            mp1[i]=0;
        }
        for(int i=-n+1;i<n;i++){
            mp2[i]=0;
        }
        
        rec(n,0,mp,mp1,mp2,{},ans);
        return ans;
        
        
    }

// Word Break - Part 2 

     void rec(int n,int i,unordered_set<string> &st,string s,string s2,string ans,vector<string>&aa){
        for(int j=i;j<n;j++){
        s2+=s[j];
        if(st.find(s2)!=st.end()){
            if(j==n-1){
                ans+=s2;
                aa.push_back(ans);
                return;
            }
            string temp=ans;
            ans+=s2;
            ans+=' ';
            rec(n-j-1,0,st,s.substr(j+1,n-j-1),"",ans,aa);
            ans=temp;
        }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> aa;
        unordered_set<string> st;
        for(auto i:dict){
            st.insert(i);
        }
        rec(s.size(),0,st,s,"","",aa);
        return aa;
    }


 void rec2(string s,int i,int k,int l,int r,string t,unordered_set<string> &ans){
         if(i==s.size()){
             if(k==0){
                 ans.insert(t);
             }
             return;
         }
         if(s[i]!='('){
             if(s[i]==')') r++;
             if(l>=r)
             rec2(s,i+1,k,l,r,t+s[i],ans);
         }
         else if(k>0){
             rec2(s,i+1,k,l,r,t,ans);
             rec2(s,i+1,k-1,l+1,r,t+'(',ans);
         }
         else{
             rec2(s,i+1,k,l,r,t,ans);
         }
     }
    
    // 301. Remove Invalid Parentheses

    void rec(string s,int i,string ts,int l,int r,unordered_set<string> &ans){
        cout<<ts<<l<<r<<i;
       
        if(l>=r){
             if(i==s.size()){
           rec2(ts,0,r,0,0,"",ans);
            return;
        }
            ts+=s[i];
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')') r++;
            // cout<<"here"<<l<<r;
            rec(s,i+1,ts,l,r,ans);
        }
        else{
            int j=0;
            string tts="";
            while(j<ts.size()){
                if(ts[j]==')'){
                    string ttts=tts;
                    tts+=ts.substr(j+1);
                    rec(s,i,tts,l,r-1,ans);
                    tts=ttts;
                    
                    
                }
                tts+=ts[j];
                j++;
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        rec(s,0,"",0,0,st);
        vector<string> ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }

     //Function to find a solved Sudoku. 
    bool fit(int grid[9][9],int i,int k){
        int f=0;
        for(int p=0;p<9;p++){
            if(grid[i/9][p]==k){
                f=1;
                break;
            }
            if(grid[p][i%9]==k){
                f=1;
                break;
            }
        }
        for(int p=((i/9)/3)*3;p<((i/9)/3)*3+3;p++){
            for(int q=((i%9)/3)*3;q<((i%9)/3)*3+3;q++){
                if(grid[p][q]==k){
                    f=1;
                    break;
                }
            }
        }
        return !f;
        
    }
      void  recSudoku(int grid[9][9],int i,bool &ans){
            if(i==81){
                ans=1;
                
            }
            if(grid[i/9][i%9]==0){
                for(int k=1;k<=9;k++){
                    if(fit(grid,i,k)){
                        grid[i/9][i%9]=k;
                        recSudoku(grid,i+1,ans);
                        if(!ans)
                        grid[i/9][i%9]=0;
                    }
                }
            }else{
                recSudoku(grid,i+1,ans);
            }
        }
    
    bool SolveSudoku(int grid[9][9])  
    { 
        // Your code here
        bool ans=0;
        recSudoku(grid,0,ans);
        return ans;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[9][9]) 
    {
        // Your code here 
          bool ans=0;
        recSudoku(grid,0,ans);
        // return ans;
        if(ans){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<grid[i][j]<<" ";
                }
            }
            // cout<<"\n";
        }
    }

   // Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool rec(bool graph[101][101],int i,map<int,pair<bool ,int>> &mp,int m,int n){
    if(i==n) return 1;
    for(int k=0;k<m;k++){
        // if(mem[{i,k}]!=-1) return mem[{i,k}];
        int f=0;
        for(int p=0;p<n;p++){
            if(graph[i][p]==1 && mp[p].first==1 && mp[p].second==k){
                f=1;
                break;
            }
        }
        if(f==0){
            bool aa=1;
            mp[i].first=1;
            mp[i].second=k;
            // if(mem[{i,k}]!=-1) return mem[{i,k}];
            int f3=0;
            
                    
            aa=rec(graph,i+1,mp,m,n);
                 
            
            if(aa) {
                return 1;
            }
            mp[i].first=0;
            mp[i].second=-1;
        }
    }
    
    return 0;
   
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    bool aa=1;
     map<int,pair<bool,int>>mp;
        for(int j=0;j<n;j++) mp[j]={0,-1};
  
     aa=rec(graph,0,mp,m,n);
        return aa;
    }

// Find all possible palindromic partitions of a String 
     bool ispalindrome(string s){
      int i=0;int j=s.size()-1;
      while(i<j){
          if(s[i]!=s[j]){
              return false;
          }
          i++;
          j--;
      }
      return true;
  }
  
    void rec(string ts,vector<string> v, vector<vector<string>>&ans){
        string tts="";
        for(int i=0;i<ts.size();i++){
            tts+=ts[i];
            if(ispalindrome(tts)){
                v.push_back(tts);
                if(i==ts.size()-1){
                    ans.push_back(v);
                    return;
                }
                rec(ts.substr(i+1),v,ans);
                v.pop_back();
            }
        }
        
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        rec(S,{},ans);
        return ans;
        
    }

// Partition Equal Subset Sum 
    bool rec(int arr[],int i,int s,int s2,int n,vector<vector<int>> &mem){
        if(i==n){
            return (s==s2);
        }
        if(mem[i][s]!=-1) return mem[i][s];
        if(s==s2){
            return mem[i][s]=1;
        }
        else if(s<s2){
            bool a=rec(arr,i+1,s+arr[i],s2-arr[i],n,mem);
            bool b=rec(arr,i+1,s,s2,n,mem);
            return mem[i][s]=a||b;
        }
        else return mem[i][s]=0;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
         
        
        int s2=0;
        for(int i=0;i<N;i++){
            s2+=arr[i];
        }
       vector<vector<int>> mem(N+1,vector<int>(s2+1,-1));
        return (rec(arr,0,0,s2,N,mem));
    }

// The Knight’s tour problem

  void  rec(vector<vector<int>> & mat,int i,int j,int n,int &f2){
        if(f2==1) return;
        int p=mat[i][j];
        int f=0;
        vector<pair<int,int>> v={{2,1},{2,-1},{-2,1},{-2,-1}};
        for(int k=0;k<4;k++){
           
            i+=v[k].first;
            j+=v[k].second;
            
            if(i>=0 && i<n && j>=0 && j<n && mat[i][j]==-1) {
                f=1;
                 mat[i][j]=p+1;
            rec(mat,i,j,n,f2);
             if(f2==1) return;
             mat[i][j]=-1;
            }
            if(f2==1) return;
            i-=v[k].first;
            j-=v[k].second;
            
            j+=v[k].first;
            i+=v[k].second;
            
           if(i>=0 && i<n && j>=0 && j<n && mat[i][j]==-1) {
               f=1;
            mat[i][j]=p+1;
            rec(mat,i,j,n,f2);
             if(f2==1) return;
               mat[i][j]=-1;
            }
            if(f2==1) return;
            
            j-=v[k].first;
            i-=v[k].second;
        }
        if(f==0){
            if(p==n*n-1){
                f2=1;
            }
        }
        
    }

    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
   void rec(vector<int> & v, int i,int s,int t,vector<int> v2,vector<vector<int>> &ans,vector<vector<int>> &mem){
       
        if(s==t && i==v.size()){
            ans.push_back(v2);
            return;
        }
        else if(s>t){
            return;
        }
        if(i==v.size()) return;
        if(s+v[i]==s){
            rec(v,i+1,s,t,v2,ans,mem);
           
        }
        else{
            v2.push_back(v[i]);
           
            rec(v,i,s+v[i],t,v2,ans,mem);
            v2.pop_back();
            
            rec(v,i+1,s,t,v2,ans,mem);
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        A.push_back(0);
        sort(A.begin(),A.end());
        vector<vector<int>> mem(100,vector<int>(B+1,-1));
        vector<int> v;
        int p=-1;
        for(int i=0;i<A.size();i++){
            if(p!=A[i]){
                v.push_back(A[i]);
            }
            p=A[i];
        }
        rec(v,0,0,B,{},ans,mem);
        vector<vector<int>> aa;
        
        return ans;
    }

     //Function to find the largest number after k swaps.
    
    void rec(string s,int i,int k,string &ans){
        if(k==0|| i==s.size()){
            // cout<<s<<"p";
            ans=max(ans,s);
            return;
        }
        char ma='0';
        for(int p=i+1;p<s.size();p++){
            // cout<<s[i];
              ma=max(ma,s[p]);
         }
        // cout<<ma;
        if(ma>s[i]){
            for(int p=i+1;p<s.size();p++){
                if(s[p]==ma){
                    swap(s[p],s[i]);
                    // cout<<s;
                    rec(s,i+1,k-1,ans);
                    swap(s[p],s[i]);
                    
                }
            }
        }
        else{
            rec(s,i+1,k,ans);
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans="0";
       rec(str,0,k,ans);
       return ans;
    }

// Partition array to K subsets 
    void  rec(vector<int>a,vector<int>s,int i,int j,int n,int k,int s2,vector<int> vis,bool &ans){
    
     if(j==k){
         ans=1;
         return;
     }
     if(s[j]==s2){
         rec(a,s,0,j+1,n,k,s2,vis,ans);
     }
     else if(s[j]<s2 && vis[i]==0 && i<n){
          if(i==n) return;
         s[j]+=a[i];
         vis[i]=1;
        rec(a,s,i+1,j,n,k,s2,vis,ans);
        vis[i]=0;
        s[j]-=a[i];
        rec(a,s,i+1,j,n,k,s2,vis,ans);
     }
     else {
          if(i==n) return;
         rec(a,s,i+1,j,n,k,s2,vis,ans);
     }
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<int> s(k,0);
         vector<int > aa;
         vector<int> vis(n,0);
         int s2=0;
         for(int i=0;i<n;i++){ aa.push_back(a[i]);
            s2+=a[i];
         }
        //  for(int i=0;i<k;i++) cout<<s[i];
         bool ans=0;
         if(s2%k==0){
             s2=s2/k;
         rec(aa,s,0,0,n,k,s2,vis,ans);
         }
         return ans;
         
         
    }
int main(){
    int N=8;
     vector<vector<int>> mat(N,vector<int>(N,-1));
	    int f2=0;
	    mat[0][0]=0;
	    rec(mat,0,0,N,f2);
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cout<<mat[i][j]<<" ";
	        }
	        cout<<"\n";
	    }
    return 0;
}