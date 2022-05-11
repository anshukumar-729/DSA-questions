#include<bits/stdc++.h>
using namespace std;


  void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
        
    }

    	int isPalindrome(string S)
	{
	     int f=0;
    for(int i=0;i<(S).size()/2;i++){
        if(S[i]!=S[i-(S).size()-1]){
            f=1;
            break;
        }
    }
    return !f;

	}

bool areRotations(string str1, string str2){
    
    // simply we can check in O(n^2)
    // we use queue for rotating one and checking equality its take time O(n+n)

    queue<char> q1,q2;
    for(auto i:str1){
        q1.push(i);
    }
    for(auto i:str2){
        q2.push(i);
    }
    
    int i=0;
    if(q1.size()!=q2.size()) return false;
    while (i<str1.size())
    {
        cout<<q2.front();
        if(q1==q2){
               return true;
        }
        q2.push(q2.front());
        q2.pop();
        

        i++;
        

    }
    // cout<<i<<"\n";
   return false;
    

    
}

bool validSuffle(string result, string s1,string s2){
    if(result.size()!=(s1.size()+s2.size())) return false;
    sort(result.begin(),result.end());
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int i=0,j=0,k=0;
    // cout<<s1<<"\n";
    // cout<<s2<<"\n";
    // cout<<result<<"\n";
    while (i<s1.size() && j<s2.size())
    {
        // cout<<i<<j<<k;
        if(s1[i]==result[k]){
            i++;
            k++;
        }
        else if(s2[j]==result[k]){
            j++;
            k++;
        }
        else{
            return false;
        }
    }
    // cout<<"pp";
    while (i<s1.size())
    {
        if(s1[i]==result[k]){
            i++;
            k++;
        }
        else{
            return false;
        }
    }
    while (j<s2.size())
    {
        if(s2[j]==result[k]){
            j++;
            k++;
        }
        else{
            return false;
        }
    }
    if(k==result.size()) return true;
    else return false;
    
    
    
}

  string countAndSay(int n) {
      if(n==1) return "1";
        string temp=countAndSay(n-1);
        string ans="";
        char pr=temp[0];
        int ct=1;
        for(int i=1;i<temp.size();i++){
            if(pr==temp[i]){
                ct++;
            }
            else{
                ans+=ct+48;
                ans+=pr;
                pr=temp[i];
                ct=1;
            }
        }
        ans+=ct+48;
        ans+=pr;
        // cout<<ans<<"\n";
        return ans;

    }
   
 string longestPalin (string S) {
        // odd lenght

        int ma=INT_MIN;
        int j,k;
        string ans;
        int ct=1;
        for(int i=0;i<S.size();i++){
            ct=1;
             j=i-1,k=i+1;
            while (j>=0 && k<S.size())
            {
                if( S[j]==S[k]){
                    j--;
                    k++;
                ct+=2;

            }
            else{
                // cout<<ct<<" "<<i<<"\n";
                if(ct>ma){
                    ma=ct;
                    ans=S.substr(j+1,ct);
                }
                
                break;
            }
            
            }
            if(ct>ma){
                    ma=ct;
                    ans=S.substr(j+1,ct);
                }
            
        }
         
                
        for(int i=0;i<S.size()-1;i++){
           ct=0;
             j=i,k=i+1;
            while (j>=0 && k<S.size())
            {
                if( S[j]==S[k]){
                    j--;
                    k++;
                ct+=2;

            }
            else{
                // cout<<ct;
               if(ct>ma){
                    ma=ct;
                    ans=S.substr(j+1,ct);
                   
                }
                 break;
            }
            
            }
            
             if(ct>ma){
                    ma=ct;
                    ans=S.substr(j+1,ct);
                }
        }
        
        return ans;
    }


int LongestRepeatingSubsequence(string str){
    int n=str.size();
		   int A[n+1][n+1];
           for(int i=0;i<n+1;i++){
               for(int j=0;j<n+1;j++){
                   if(i==0 || j==0){
                       A[i][j]=0;
                   }
                   else{
                       if(str[i-1]==str[j-1] && i!=j){
                           A[i][j]=A[i-1][j-1]+1;
                       }
                       else{
                           A[i][j]=max(A[i-1][j],A[i][j-1]);
                       }
                   }
               }
           }
		    return A[n][n];
		}

void printSubsequence(string input, string output,vector<string> &v){ //O(2^n) simple way how to generate all 2^n choices
    if(input.empty()){
    v.push_back(output);
    cout<<output<<" ";
    return;
    }
   
        printSubsequence(input.substr(1),output+input[0],v);
        printSubsequence(input.substr(1),output,v);

    

}

// all permutaion in lexicographical order

string nextPermutation(string s){
    string temp="";
    int f=-1;
    for(int i=s.size()-1;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            if(s[j]<s[i]){
                swap(s[i],s[j]);
                f=j;
                break;
            }
        }
        if(f!=-1) break;
    }
    if(f==-1){
        sort(s.begin(),s.end());
        return s;
    }
    for(int i=f+1;i<s.size();i++){
        temp+=s[i];
    }
    sort(temp.begin(),temp.end());
    int k=0;
    for(int i=f+1;i<s.size();i++){
        s[i]=temp[k++];
    }
    return s;

}
vector<string>find_permutation(string S)
		{
            vector<string> ans;
            // cout<<S;
               
		    sort(S.begin(),S.end());
             ans.push_back(S);
            string temp=nextPermutation(S);
            while (temp!=S)
            {
                // cout<<temp;
                ans.push_back(temp);
                temp=nextPermutation(temp);
            }
            
    return ans;
		}
    // maximum balanced binary substring
        int maxSubStr(string str, int n){
            int ct=0;
            int ans=0;
            for(int i=0;i<n;i++){
                if(str[i]=='1') ct++;
                else ct--;
                if(ct==0) ans++;
            }
            return ans;
        }

    // awesome recursion + memoization implementation

        int rec(vector<int> &v,int k,int i,int w,vector<vector<int>> &mem){
            cout<<i<<" "<<w<<"\n";
            if(i==v.size()) return 0;
            else if(mem[i][w]!=-1) return mem[i][w];
            if(w+v[i]<=k){
                if(w==0){
                    return mem[i][w]=rec(v,k,i+1,(i==v.size()-1)?w+v[i]:w+v[i]+1,mem);
                }

            return mem[i][w]=min((k-w+1)*(k-w+1)+rec(v,k,i,0,mem),rec(v,k,i+1,(i==v.size()-1)?w+v[i]:w+v[i]+1,mem));
            }
            else
            return mem[i][w]=(k-w+1)*(k-w+1)+rec(v,k,i,0,mem);
        }

          int solveWordWrap(vector<int>nums, int k) 
    { 
        // cout<<rec(nums,k,0,0);
        vector<vector<int>> mem;
    for(int i=0;i<nums.size();i++){
        vector<int > temp;
        for(int j=0;j<=k+1;j++){
            temp.push_back(-1);
        }
        mem.push_back(temp);
        temp.clear();
    }
        return rec(nums,k,0,0,mem);
    } 

    int lcs(string s,string t,vector<vector<int>> &mem,int n,int m){
        
        // if(t.size()==0 || s.size()==0) return 0;
        if(t.size()==0 ) return s.size();
        if(s.size()==0) return t.size();
        else if((mem[n-s.size()][m-t.size()])!=-1) return mem[n-s.size()][m-t.size()];
        if(s[0]==t[0]) return mem[n-s.size()][m-t.size()]=(lcs(s.substr(1),t.substr(1),mem,n,m));
        else{
            return mem[n-s.size()][m-t.size()]=1+min(lcs(s.substr(1),t,mem,n,m),min(lcs(s,t.substr(1),mem,n,m),lcs(s.substr(1),t.substr(1),mem,n,m)));
        }
    }

    int editDistance(string s, string t) {
        vector<vector<int>> mem(s.size(),vector<int> (t.size(),-1));
        int ct=lcs(s,t,mem,s.size(),t.size());
        // cout<<ct;
       
        
        return ct;
    }

 vector<int> nextPermutation(int N, vector<int> arr){
    int ind1=-1;
       for(int i=N-1;i>=1;i--){
           if(arr[i]>arr[i-1]){
               ind1=i-1;
               break;
           }
       }
       if(ind1==-1){
           reverse(arr.begin(),arr.end());
           return arr;
       }
       int mi=INT_MAX;
       int ind2=N;
       for(int i=ind1+1;i<N;i++){
           if(arr[i]<mi && arr[i]>=arr[ind1]){
               mi=arr[i];
               ind2=i;
           }
       }
       swap(arr[ind1],arr[ind2]);
       ind2=N-1;
       int n=ind2-ind1;
       for(int i=ind1+1;i<ind1+1+n/2;i++){
           swap(arr[i],arr[ind2-(i-ind1-1)]);
       }
       return arr;
    }

//Function to check if brackets are balanced or not.
    int val(char ch){
        if(ch=='('){
            return 1;
        }
        else if(ch=='{'){
            return 2;
        }
        else if(ch=='['){
            return 3;
        }
        else if(ch==')'){
            return -1;
        }
        else if(ch=='}'){
            return -2;
        }
        else{
            return -3;
        }
    }

     bool ispar(string x)
    {
        stack<int> st;
        int f=0;
        for(int i=0;i<x.size();i++){
            if(val(x[i]>0)){
                st.push(val(x[i]));
            }
            else{
                if(st.empty()){
                    f=1;
                    break;
                }
                else{
                    int t=st.top();
                    if(t*-1==val(x[i])){
                        st.pop();
                    }
                    else{
                        f=1;
                        break;
                    }
                }
            }
        }
        if(f || !st.empty()){
            return false;
        }
        else{
            return true;
        }
    }

bool part1(string A,unordered_set<string> &st,string pr,vector<vector<int>> &mem,int n){
    if(A.empty()){
        if(st.find(pr)!=st.end()){
            return 1;
        }
        else return 0;
    }
    if(mem[n-A.size()][pr.size()]!=-1) return mem[n-A.size()][pr.size()];
    if(st.find(pr)!=st.end()){
        return mem[n-A.size()][pr.size()]=(part1(A.substr(1),st,pr+A[0],mem,n)+part1(A,st,"",mem,n));

    }
    else{
       
            return mem[n-A.size()][pr.size()]=part1(A.substr(1),st,pr+A[0],mem,n);
       
    }
}   

 int wordBreak(string A, vector<string> &B) {
       unordered_set<string> st;
       vector<vector<int>> mem(A.size(),vector<int>(A.size()+1,-1));

       for(auto i:B){
           st.insert(i);
       }
       return part1(A,st,"",mem,A.size());
    }

long long hash1(string x){
    long long ans=0;
    int p=0;
    for(int i=x.size()-1;i>=0;i--){
        ans+=(long long)(abs((x[i]-96))*(long long)(pow(2,p)));
        ans=ans%1000000007;
        p++;
    }
    return ans;
}
vector<int> rabinKarpAlgorithm(string s, string pt){ // uses hash function to reduce checking
    vector<int> ans;
    long long h=hash1(pt);
    string temp=s.substr(0,pt.size());
    long long pr;
    pr=hash1(s.substr(0,pt.size()));
    for(int i=pt.size();i<s.size();i++){
        if(pr==h ){
            if(pt==temp)
            ans.push_back(i-pt.size());
        }
        pr-=(abs((s[i-pt.size()]-96))*(long long)(pow(2,pt.size()-1)));
        pr*=2;
        pr+=s[i]-96;
        temp=temp.substr(1);
        temp+=s[i];
    }
    if(pr==h ){
            if(pt==temp)
            ans.push_back(s.size()-pt.size());
        }
        return ans;

}

// longest suffix prefix same reduce choices using hash

long long pow2(int n,int p){
    long long ans=1;
    while (p>0)
    {
        ans*=n;
        p--;
        ans%=1000000007;
    }
        return ans;
}
    // good hashing is very powerfull!
	int lps(string s) {
        long long h=0;
        int p=0;
        long long mod=1000000007;
        int k=1;
        long long l=h,r=h;
        int f=0;
        long long ans=0;
        long long pw=1;
        while (k<s.size())
        {
           l=((l*31)%mod+(s[k-1]-96))%mod;
           r=(r+(((s[s.size()-k]-96))*(pw))%mod)%mod;
           pw*=31;
           pw%=mod;
        //   cout<<l<<" "<<r<<"\n";
            if(l==r){
                // for(int i=0;i<k;i++){
                //     if(s[i]!=s[s.size()-k+i]){
                //         f=1;
                //     }
                // }
                if(f==0){
                    ans=k;
                }
                else{
                    f=0;
                }
            }
            k++;

        }
        
	   return ans;
	}

    // C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
string numericKey(string s){
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
                   string ans="";
                   for(int i=0;i<s.size();i++){
                       if(s[i]==' ') ans+='0';
                       else
                       ans+=(str[s[i]-97]);
                   }
                   return ans;
}

// minimum number of reversal to make balanced paranthesis

int countRev (string s)
{
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty() || (!st.empty() && st.top()=='}')){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
    }
    int ans=0;
    if(st.size()%2==1){
        return -1;
    }
    else{
        
        while (!st.empty())
        {
            if(st.top()=='{') ans++;
            st.pop();
            if(st.top()=='}') ans++;
            st.pop();
        }
        
    }
    return ans;
}

//Count Palindromic Subsequences correct but tle in gfg at tc 102/105

int palindromes(string s,int i,int j,int k,vector<vector<long long>> &mem){
    // cout<<j<<" "<<k<<"\n";
    if(j>k) return 0;
    if(j==k) return 1;
    if(mem[j][k]!=-1) return mem[j][k];
    
    // cout<<j<<"f "<<k<<"\n";
    if(s[j]==s[k]) return mem[j][k]=(1+palindromes(s,i,j+1,k,mem)%1000000007+palindromes(s,i,j,k-1,mem)%1000000007)%1000000007;
    else return mem[j][k]=((palindromes(s,i,j+1,k,mem)%1000000007+ palindromes(s,i,j,k-1,mem)%1000000007+1000000007-palindromes(s,i,j+1,k-1,mem)%1000000007))%1000000007;
}

long long int  countPS(string str)
    {
    //    cout<<palindromes(str,2,1,3);
    long long mod=1000000007;
    long long ans=0;
    vector<vector<long long>> mem(str.size(),vector<long long>(str.size(),-1));
    // for(int i=0;i<str.size();i++){
    //     ans+=1+palindromes(str,i,i-1,i+1,mem);
    //     ans%=mod;
    // }
    // for(int i=0;i<str.size()-1;i++){
    //     ans+=palindromes(str,0,i,i+1,mem);
    //     ans%=mod;
    // }
    ans=palindromes(str,0,0,str.size()-1,mem);
    return ans;
       
    }
    // // correct by gfg
    // const long long int mod = 1000000007;
    // long long int add(long long int x, long long int y) {
    //     return ((x % mod) + (y % mod)) % mod;
    // }
    // long long int sub(long long int x, long long int y) {
    //     return ((x % mod) - (y % mod) + mod) % mod;
    // }
    // long long int  countPS(string str)
    // {
    //     long long int  N = str.length();

    //     // create a 2D array to store the count of palindromic
    //     // subsequence
    //     long long int  cps[N + 1][N + 1];
    //     memset(cps, 0 , sizeof(cps));

    //     // palindromic subsequence of length 1
    //     for (long long int  i = 0; i < N; i++)
    //         cps[i][i] = 1;

    //     // check subsequence of length L is palindrome or not
    //     for (long long int  L = 2; L <= N; L++)
    //     {
    //         for (long long int  i = 0; i <= N - L; i++)
    //         {
    //             long long int  k = L + i - 1;
    //             if (str[i] == str[k])
    //                 cps[i][k] = add(cps[i][k - 1] , add(cps[i + 1][k] , 1LL)) % mod;
    //             else
    //                 cps[i][k] = add(cps[i][k - 1] , sub(cps[i + 1][k] , cps[i + 1][k - 1])) % mod;
    //         }
    //     }

    //     // return total palindromic subsequence
    //     return cps[0][N - 1] % mod;
    // }

   // find-count-number-given-string-present-2d-character-array

    bool isup(int n,int m,int i,int j){
        if(i>0) return true;
        else return false;
    }
    bool isdown(int n,int m,int i,int j){
        if(i<n-1) return true;
        else return false;
    }
    bool isleft(int n,int m,int i,int j){
        if(j>0) return true;
        else return false;
    }
    bool isright(int n,int m,int i,int j){
        if(j<m-1) return true;
        else return false;
    }
    void oneInternalSearch(vector<string> &vs,vector<vector<int>> isTraverse,pair<int,int> p,string s,int k,int &ans){

        // cout<<k<<p.first<<p.second<<"\n";
        
        if(s[k]==vs[p.first][p.second]){
            // k++;
        if(k==s.size()-1 ) {
            // isTraverse[p.first][p.second]=1;
            ans++;
            return;
        }
        // isTraverse[p.first][p.second]=1;
        if(isup(vs.size(),vs[0].size(),p.first,p.second) && !isTraverse[p.first-1][p.second]){
            p.first--;
            oneInternalSearch(vs,isTraverse,p,s,k+1,ans);
            p.first++;
        }
        if(isdown(vs.size(),vs[0].size(),p.first,p.second) && !isTraverse[p.first+1][p.second]){
            p.first++;
            oneInternalSearch(vs,isTraverse,p,s,k+1,ans);
            p.first--;
        }
        if(isleft(vs.size(),vs[0].size(),p.first,p.second) && !isTraverse[p.first][p.second-1]){
            p.second--;
            oneInternalSearch(vs,isTraverse,p,s,k+1,ans);
            p.second++;
        }
        if(isup(vs.size(),vs[0].size(),p.first,p.second) && !isTraverse[p.first][p.second+1]){
            p.second++;
            oneInternalSearch(vs,isTraverse,p,s,k+1,ans);
            p.second--;
        }
        }
        else{
            return;
        }

    }

    int internaSearch(vector<string> vs,string s){
        vector<pair<int,int>> vp;
        for(int i=0;i<vs.size();i++){
            for(int j=0;j<vs[0].size();j++){
                if(vs[i][j]==s[0]){
                    vp.push_back({i,j});
                }
            }
        }
        int ans=0;
        int ct=0;
        vector<vector<int>> isTraverse(vs.size(),vector<int>(vs[0].size(),0));
        for(auto i:vp){
            oneInternalSearch(vs,isTraverse,i,s,0,ans);
            // cout<<ans<<"\n";
            ct+=ans;
            // cout<<ans<<"\n";
            ans=ans&0;
        }
        return ct;

    }
// correct in one attempt
  
   void serachCharByChar(vector<vector<char>> &vc,int i ,int j,string s,int k,int &ans,vector<int> dir){
        if(vc[i][j]==s[k]){
            if(k==s.size()-1){
                ans=ans|1;
                return;
            }
            if(dir[0]==1){
                if(isup(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i-1,j,s,k+1,ans,{1,0,0,0,0,0,0,0});
                }
            }
            if(dir[1]==1){
                if(isup(vc.size(),vc[0].size(),i,j) && isright(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i-1,j+1,s,k+1,ans,{0,1,0,0,0,0,0,0});
                }
            }
            if(dir[2]==1){
                if(isright(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i,j+1,s,k+1,ans,{0,0,1,0,0,0,0,0});
                }
            }
            if(dir[3]==1){
                if(isright(vc.size(),vc[0].size(),i,j) && isdown(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i+1,j+1,s,k+1,ans,{0,0,0,1,0,0,0,0});
                }
            }
            if(dir[4]==1){
                if(isdown(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i+1,j,s,k+1,ans,{0,0,0,0,1,0,0,0});
                }
            }
            if(dir[5]==1){
                if(isdown(vc.size(),vc[0].size(),i,j)&&isleft(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i+1,j-1,s,k+1,ans,{0,0,0,0,0,1,0,0});
                }
            }
            if(dir[6]==1){
                if(isleft(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i,j-1,s,k+1,ans,{0,0,0,0,0,0,1,0});
                }
            }
            if(dir[7]==1){
                if(isup(vc.size(),vc[0].size(),i,j) && isleft(vc.size(),vc[0].size(),i,j)){
                    serachCharByChar(vc,i-1,j-1,s,k+1,ans,{0,0,0,0,0,0,0,1});
                }
            }
        }
        else{
            return;
        }
    }
    	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
            vector<vector<int>> a;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    int ans=0;
                    serachCharByChar(grid,i,j,word,0,ans,{1,1,1,1,1,1,1,1});
                    if(ans) a.push_back({i,j});
                }
            }
            return a;
	}


// kmp(Knuth–Morris–Pratt algorithm) algorithm for pattern matching O(m+n)
// longest prefix suffix table for pattern using kmp algo**************************
// awesome algo for lps***************
vector<int> lpsTable(string pt){
    vector<int> lps(pt.size(),0);
    int k=1;
    for(int i=1;i<pt.size();i++){
        k=i;
        while (k>0)
        {
            // cout<<k<<" ";
            if(pt[lps[k-1]]==pt[i]){
                    lps[i]=lps[k-1]+1;
                    
                    break;
                 }
            k=lps[k-1];
        
        }
        
        
        
    }
    return lps;
}

// using lps for word matching
vector<int> matchWord(string text,string pt){
    vector<int> lps=lpsTable(pt);
    vector<int> ans;
    int j=0;
    for(int i=0;i<text.size();i++){
        // cout<<j<<" ";
        if(text[i]!=pt[j])  j=lps[j-1];
        if(text[i]==pt[j]){
            j++;
            if(j==pt.size()){
                ans.push_back(i-j+1);
                // break;
            }
        }
        
           
        
    }
    if(ans.size()==0) ans.push_back(-1);
    return ans;
}

// Boyer Moore Algorithm for Pattern Searching
// uses mad match table
map<char,int> badMatchTable(string pt){
    map<char,int> mp;
    for(int i=0;i<pt.size();i++){
        mp[pt[i]]=pt.size()-i-1;
    }
    mp[pt[pt.size()-1]]=pt.size();
    return mp;
}

vector<int> boyerMooreAlgo(string text,string pt){
    map<char,int> mp=badMatchTable(pt);
    vector<int > ans;
    int i=pt.size()-1;
    int j=pt.size()-1;
    while (i<text.size())
    {
        // cout<<i<<" "<<j<<"\n";
        if(text[i]==pt[j]){
            i--;
            j--;
            if(j==-1){
                ans.push_back(i+1);
                i+=pt.size()+1;
                j=pt.size()-1;
            }
        }
        else{
            i+=(pt.size()-j-1);
            if(mp.find(text[i])!=mp.end()){
                i+=mp[text[i]];
                
                
            }
            else{
                i+=pt.size();
            }
            j=pt.size()-1;
        }
    }
    return ans;
    
}

  int romanToDecimal(string &str) {
        map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        int i=str.size()-1;
        while(i>=1){
               if(mp[str[i]]>mp[str[i-1]]){
                   ans+=mp[str[i]];
                   ans-=mp[str[i-1]];
                   i-=2;
               }
               else{
                   ans+=mp[str[i]];
                   i--;
               }
               
        }
        if(i==0) ans+=mp[str[i]];
        return ans;
        
    }
string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int k=0;
        char pr;
        while (true)
        {
            if(strs[0].size()>k)
            pr=strs[0][k];
            else
            return ans;
            for(int i=1;i<strs.size();i++){
            if(k<strs[i].size()){
                if(strs[i][k]!=pr) return ans;
            }
            else return ans;
            }
            ans+=pr;
            k++;
        }
        return ans;
        
    }

    int minFlips (string S)
{
    int ct1=0,ct2=0;
    for(int i=0;i<S.size();i++){
        if(i%2==0){
            if(S[i]=='1') ct1++;
            else ct2++;
        }
        else{
            if(S[i]=='0') ct1++;
            else ct2++;
        }
    }
    return min(ct1,ct2);
}

// to make balance parantehsis

int minimumNumberOfSwaps(string S){
       int ct=0;
       vector<int> v1,v2;
       for(int i=0;i<S.size();i++){
           if(S[i]=='[') v1.push_back(i);
           
       }
       int f=0;
       int ind=0;
       int j=0;
       for(int i=0;i<S.size();i++){
           if(S[i]=='['){
               j++;
               ind++;
           }
           else{
               j--;
           
           if(j<0){
               if(i<v1[ind]){
           ct+=(v1[ind]-i);
           
           swap(S[i],S[v1[ind]]);
           ind++;
           j=1;
            
           }
          
           }
           }
       }

        return ct;
        

    }

int lcsreccursion(int x, int y, string s1, string s2,vector<vector<int>> &mem){
     if(x==0 || y==0 ) return 0;
     if(mem[x][y]!=-1) return mem[x][y];
        if(s1[s1.size()-x]==s2[s2.size()-y]){
            return mem[x][y]=1+(lcsreccursion(x-1,y-1,s1,s2,mem));

        }
        else{
            return mem[x][y]=max(lcsreccursion(x-1,y,s1,s2,mem),lcsreccursion(x,y-1,s1,s2,mem));
        }
}
  int lcs(int x, int y, string s1, string s2)
    {

vector<vector<int>> mem(x+1,vector<int>(y+1,-1));
return lcsreccursion(x,y,s1,s2,mem);
       
    }

     vector<string> genIp(string &s) { // don't know what is ip 
         
         int n=s.size();
         vector<string> ans;
         for(int i=1;i<n-1;i++){
             for(int j=i+1;j<n-1;j++){
                 for(int k=j+1;k<n-1;k++){
                     string s2="";
                     for(int p=0;p<n;p++){
                         if(p+1==i|| p+1==j|| p+1==k){
                             s2+=s[p];
                             s2+='.';
                         }
                         else{
                             s2+=s[p];
                         }
                     }
                     ans.push_back(s);
                 }
             }
         }
         return ans;

    }

 //sliding window
 //Smallest distinct window
  int findSubString(string str)
    {
        map<char,int> mp;
        int mi=INT_MAX;
        int a1,a2;
        for(int i=0;i<str.size();i++){
            mp[str[i]]=1;
        }
        int ct=mp.size();
           int i=0;
           int j=0;
           while (i<str.size())
           {
               if(mp[str[i]]==1) {
                   mp[str[i]]--;
                   ct--;
               }
               else{
                   mp[str[i]]--;
               }
               i++;
               if(ct==0){
                   while (ct==0)
                   {
                       if(i-j<mi){
                           mi=i-j;
                           a1=j;
                           a2=i;
                       }
                        if(mp[str[j]]==0){
                            mp[str[j]]++;
                            ct++;
                        }   
                        else mp[str[j]]++;
                        j++;
                   }
                   
               }
           }
        //   cout<< str.substr(a1,(a2-a1));
           return (a2-a1);
           
    }

    //Minimum characters to be added at front to make string palindrome
    // using hashing

    int vall(char ch){
        return ch-96;                   
    }
        long long mod=1000000007;
        int minChar(string str){
        
        long long h1=vall(str[0]);
        long long h2=vall(str[1]);
        int ans=1;
        int i=0;
        int j=1;
        while (j<str.size())
        {
            cout<<h1<<" "<<h2<<"\n";
            if(h1==h2) ans=(j)+1;
            i++;
            j++;
            h1+=(vall(str[i])*pow2(31,i));
            h1%=mod;
            h2*=31;
            h2%=mod;
            h2+=vall(str[j]);
            h2%=mod;
        }
        if(h1==h2) ans=j+1;

        return str.size()-ans;
        
    }

    // using lps table kmp algorithm**********
     int minChar2(string str){
         string s2=str;
         reverse(s2.begin(),s2.end());
         str+='0';
         str+=s2;
         vector<int> v=lpsTable(str);
         return str.size()-v[v.size()-1];
     }

// Print Anagrams Together
// using hashing
 vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<int,vector<string>> mp;
        long long mod=1000000007;
        for(int i=0;i<string_list.size();i++){
            string temp=string_list[i];
            sort(temp.begin(),temp.end());
            long long pw=31;
            long long h=0;
            for(int j=0;j<temp.size();j++){
                h*=pw;
                h%=mod;
                h+=(temp[j]-96);
                h%=mod;
            }
            mp[h].push_back(string_list[i]);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            vector<string> temp;
            for(auto j:i.second){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }

  string smallestWindow (string s, string p)
    {
        map<char,long long> mp;
        for(auto &i: s){
            mp[i]=0;
        }
        long long te=mp.size();
        for(auto &i: p){
            mp[i]=0;
        }
        if(mp.size()>te) return "-1";
        
        long long ct=0;
        long long a1,a2;
        long long mi=INT_MAX;
        for(auto &i: p){
            if(mp[i]==0) ct++;
            mp[i]++;
        }
        long long i=0;
        long long j=0;
        while (j<s.size())
        {
            // cout<<j<<"\n";
            if(mp[s[j]]==1){
                mp[s[j]]--;
                ct--;
            }
            else mp[s[j]]--;
            j++;
            if(ct==0){
                while (ct==0)
                {
                    // cout<<i<<" ";
                    if(j-i<mi){
                        mi=j-i;
                        a1=i;
                        a2=j;

                    }
                    if(mp[s[i]]==0){
                        mp[s[i]]++;
                        ct++;
                    }
                    else mp[s[i]]++;
                    i++;
                }
                
            }
        }
        if(mi==INT_MAX) return "-1";
        return s.substr(a1,a2-a1);
    }   


// Recursively remove all adjacent duplicates
     string rremove(string s){
         if(s.size()==0) return "";
         char pr=s[0];
         int ind =0;
         vector<pair<int,int>> vp;
         
        for(int i=1;i<s.size();i++){
            if(s[i]==pr){
               
             
            }
            else{
                vp.push_back({ind,i});
                ind=i;
                pr=s[i];
            }
        }
        vp.push_back({ind,s.size()});
        string s2="";
        bool f=0;
        for(auto &i:vp){
            if(i.second-i.first==1){
               s2+=s[i.first];
            }
            else{
                f=1;
            }
        }
        if(f==0) return s2;
        return rremove(s2);
    }
int matchWord2(string a,string b){
    int i=0;
    int j=0;
    for(int i=0;i<a.size()-b.size()+1;i++){
        bool f=0;
        for(int j=0;j<b.size();j++){
            if(b[j]!='?' && a[i+j]!=b[j]){
                f=1;
                break;
            }
        }
        if(f==0) return i;
    }
    return -1;
}
// wildcard matching
bool recMatch(string a,string b,int i,int j){ // accepted :)p[]
    // cout<<i<<j;
    if(a.size()==i+1 && a[i]=='*') return true;
    
    string temp="";
    int ind=i-1;
    for(int k=i;k<a.size();k++){
        ind=k;
        if(a[k]!='*'){
            temp+=a[k];
        }
        else break;
    }
    int r=-1;
    if(ind==a.size()-1){
         if(i==0) {
                 r=matchWord2(b,temp);
            if(r==0 && b.size()==temp.size()) return true;
            else return false;
            }
        if(a[ind]=='*'){
            if(j<b.size())
            r=matchWord2(b.substr(j),temp);
            if(r!=-1) return true;
            else return false;
        }
        else{
           
            if(j<=(b.size()-temp.size()))
            r=matchWord2(b.substr(b.size()-temp.size(),temp.size()),temp);
            if(r!=-1) return true;
            else return false;
        }
    }
    if(j<b.size())
    r=matchWord2(b.substr(j),temp);
    else return false;
    // cout<<r;
    if(i==0){
        
        if(r==0){
            return recMatch(a,b,ind+1,r+temp.size());
        }
        else return false;
    }
    else{
        if(r!=-1){
            return recMatch(a,b,ind+1,r+temp.size());
        }
        else{
            return false;
        }
    }
    
}

bool regexMatch(string s1,string s2){

   return recMatch(s1,s2,0,0);
}

// Function to find Number of customers who could not get a computer
int countCustomers(vector<int> &arr, int k)
{
    map<int,int> mp;
    string s="";
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]=0;
    }
	
    for(int i=0;i<arr.size();i++){
        if(mp[arr[i]]%2==0){
			s+='(';
			mp[arr[i]]++;
		}
		else{
			s+=')';
			mp[arr[i]]--;
		}
    }
    int ct=0;
    int p=0;
	cout<<s<<"\n";
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') p++;
        else p--;
        if(s[i]=='(' && p>k) ct++;
    }
// 	cout<<ct<<"\n";
    return ct;
}

// The transfigure spell can be used to pick any one character from the DNA string, remove it and insert it in the beginning. 
     int transfigure (string A, string B)
    {
        if(A.size()!=B.size()) return -1;
    	int ct=0;
    	int s=0;
    	 map<char,int> mp;
    	 int j=A.size()-1;
        for(int i=0;i<A.size();i++){
            mp[A[i]]=0;
            mp[B[i]]=0;
        }
        for(int i=0;i<A.size();i++){
             
            s+=A[i];
            s-=B[i];
            if(A[A.size()-1-i]==B[j]){
                j--;
            }
            else{
                mp[A[A.size()-1-i]]++;
                ct++;
            }
        }
        if(s!=0) return -1;
       
       
        
       
        
      
        bool f=0;
        while(j>=0){
           
                mp[B[j]]--;
                if(mp[B[j]]<0) return -1;
            
            j--;
        }
       return ct;
        

    }
    void makesentense(vector<vector<string>>&list, vector<vector<string>> &ans,int i,vector<string> temp){
        if(i==list.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<list[i].size();j++){
            temp.push_back(list[i][j]);
            makesentense(list,ans,i+1,temp);
            temp.pop_back();
        }
    }

 vector<vector<string>> sentences(vector<vector<string>>&list){
     vector<vector<string>> ans;
       makesentense(list,ans,0,{});
       return ans;
    }


int main(){
    string s1="abcde";
    string s2="deabc";
    string r="aabbddeecc";
    // cout<<validSuffle(r,s1,s2);
    // cout<<longestPalin("aaaabbaa");
    vector<string> v2;
    // printSubsequence("aabc","",v);
    // find_permutation("ABC");
    // cout<<maxSubStr("001101010011",12);
    
    // cout<<solveWordWrap({3,2,2},4);
    // editDistance("ecfbefdcfca","badfcbebbf");
    // vector<int> v=rabinKarpAlgorithm("abcdabcabcabceabc","abc");
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    // cout<<lps("aaaa");
    // cout<<numericKey("anshu kumar");
    // cout<<countPS("mbcgepnkdqemhmkuqosgeonbcrphobcmbhrgppkfpdqckigsomktpsurknsospighufulqijcupisnuqcqfpuckrndmqeeklqfcrfnemeghmnlunlpslncqllmbebnoudihgpigrfbrqbcurmqnfroheqltkbnpocousjepehgppmblodppsqrglprtekmsqlqekhjseotocgkfcrkssmmenhitupdcoujscnetbrrcdoctqdfssupfnuolrobckseuromqsuoctmnbudnthrctndtrnietrkqbropugptpuhclftohuendhhnpnhqqkmksigbcrtrtjtmhonnumnnupgtntdhefushmrshselrdfqnoddmqqhjrjtknmokrlgdrcomnbjdlcothrhgsljreflusnnnrkckstoluhduguicfomgjkorgmujoonekscbikeshbqfqfrbcmspqphujltqebostmbkunhhhqmdqdqmfsbekeonmsiqsbomhmrtnqtmutrbmrlthhieihqjebklckemustsufbqmbjcqdtkdjscmdsrkkqdfojplektrsinjfbhmfoumqirfehdhgdkejefupstmhqesqobcqftpgbrckqrjqdosfjschbhbuobhriguipdkeeggbtecsqheelrqiqfdokqhrdsdcifnkulloeckeghochpdfjpqesqmqsngcbpngjurdsbhtsilkoiglbgmofnjuojtgjqnpgobmfehjnqbfmternugrhbnrgqusloiuusqogtqsclesqsmhjghqdtqkgikghflotgfmkdngklcorqlegpdidptohlgnnnflhtcmpcehogooflhujpichtknfqicpkjmgjjdnmtsprcueeolruiqjpeldelnukfitfgqsdejupshdtebtqfrqbtuttkldbuupidurhimnrmpdfjtbuinfchjormhissgpdbisugtrqqdiqekpnicpej");
    // vector<string> vs={ "BBABBM",
    //                    "CBMBBA",
    //                    "IBABBG",
    //                    "GOZCII",
    //                    "ABBBGC",
    //                    "MCIGAM" };
    //                    cout<<internaSearch(vs,"MAGIC");

    // vector<int> vp=boyerMooreAlgo("ababcdecabcde","abcde");
    // for(auto i:vp){
    //     cout<<i<<"\n";
    // }
    // cout<<minChar("aacecaaaa");
    // cout<<smallestWindow("wsuhvkglogyqzsnhojwlmddiwrrwdvztkuprtifvpecugmrihaspzzylndnrmdulylswdvdahdzyzmrnwfiqhovjffyxbmldaznlkxvqtzywaxwrkupvucod","ezqaocnqiovkiosoaqyijhqnidoxdwovyvyjfjurah");
    // cout<<matchWord2("abcd","");
    cout<<regexMatch("ab*","aab");
    return 0;
}
