#include<bits/stdc++.h>
#include<string>
using namespace std;

// Write a program to reverse an array or string

string reverseWord(string str){
     for(int i=0;i<floor(str.size()/2);i++){
            // cout<<i<<" "<<str[i]<<"\n";
            char p=str[i];
            str[i]=str[str.size()-i-1];
            str[str.size()-i-1]=p;
            
        }
        // return str;
        return str;
}
// Maximum and minimum of an array using minimum number of comparisons

pair<long long, long long> getMinMax(long long a[], int n) {
    
    pair<long long,long long>p={a[0],a[0]};
    
    for(int i=1;i<n;i++){
        if(a[i]>p.second) p.second=a[i];
        if(a[i]<p.first) p.first=a[i];
    }
    
    return (p);
}





// heap and heapify

// heapify
// Kth smallest element
int  heapify( vector<long long> &v,int ind){

    int l=ind*2+1;
    int r=ind*2+2;
    long long temp;
    int tind;
    if(r>=v.size() && l>=v.size()){
        return 0;
    }
    else if(r>=v.size()){
        tind=l;
        temp=v[l];

    }
    else{
    
    if(v[l]<v[r]){
        temp=v[l];
        tind=l;
    }
    else{
        temp=v[r];
        tind=r;

    }
    }
    if(temp<v[ind]){
        // swap
        long long sp=v[ind];
        v[ind]=v[tind];
        v[tind]=sp;
     
       return  heapify(v,tind);
    }
    else{
        return 0;
    }
}

void buildHeap(vector<long long> &v){
    for(int i=v.size()/2-1;i>=0;i--){
        
        heapify(v,i);
    }
    return;
}
int kthSmallestByHeap(int arr[], int l, int r, int k)
    {
       // O(n*log(n))
       vector<long long >v;
       for(int i=l;i<=r;i++){
           v.push_back(arr[i]);
       }
       buildHeap(v);
       for (int  i = 0; i < k-1; i++)
       {
           swap(v[0],v[v.size()-1]);
           v.pop_back();
           heapify(v,0);
       }
        return v[0];
       

    }

    // quick sort partition

int partition(vector<long long >&v,int low,int high ){
    long long pivot=v[high-1];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[high-1],v[i+1]);
    return (i+1);
}

 int kthSmallestByQuickSort(int arr[], int l, int r, int k) { // run time can be O(n^2) in the worst case 
     int low=l;
     vector<long long>v;
     for(int i=l;i<=r;i++){
         v.push_back(arr[i]);
     }
     int high=r+1;
      int ans=partition(v,low,high);
     while (true)
     {  
        // cout<<ans;
        if(ans+1==k){
            return v[k-1];
        } 
        else if(ans+1>k){
            ans=partition(v,low,ans);
        }
        else{
            ans=partition(v,ans,high);
        }
     }
     
     return -1;
 }

 // sort the array of 0,1 and 2 

 void sort012(int a[], int n)
{
    int i=-1;
    for(int j=0;j<n;j++){
        if(a[j]==0){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
                    }
    }
    
    for(int j=i+1;j<n;j++){
        if(a[j]==1){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
                    }
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }

}

// Move all negative numbers to beginning and positive to end with constant extra space

int *rotateSubArray(int arr[], int l, int r){
        int temp = arr[r-1];
        for (int j=r-1;j>=l;j--){
            arr[j] = arr[j-1];
        }
        arr[l] = temp;
        return arr;
 }
        

void segregateElements(int arr[],int n) // maintaining its order
    {
          int i=-1;
    for(int j=0;j<n;j++){
        if(arr[j]>0){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
                    if(j-i>=2){
                        // cout<<(i+1)<<(j+1);
                        rotateSubArray(arr,i+1,j+1);
                    }  
     }
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    }

// Union of two arrays

 int doUnion(int a[], int n, int b[], int m)  {
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]=1;
        }
        for(int i=0;i<m;i++){
            mp[b[i]]=1;
        }
        return mp.size();
    }

    void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int j=n-1;j>=1;j--){
        arr[j]=arr[j-1];
    }
    arr[0]=temp;
}

// kadane's algorithm *************************************************************************
 long long maxSubarraySum(int arr[], int n){ 
        
       long long s=0;
        vector<long long> v;
        long long ma=arr[0];
       for(int i=0;i<n;i++){
           s+=arr[i];
           ma=max(ma,s);
           if(s<0){
               s=0;
           }
       }
    //    cout<<ma;
       return ma;

       
    }

// Minimize the Heights II *******************
    // int getMinDiff(int arr[], int n, int k) {
    //     int ma=arr[0];
    //     int mi=arr[0];
    //     for(int i=0;i<n;i++){
    //         if(arr[i]<mi){
    //             mi=arr[i];
    //         }
    //         if(arr[i]>ma){
    //             ma=arr[i];
    //         }
    //     }
    //     if(ma-mi>=k){
    //         return abs(ma-k-(mi+k));
    //     }
    //     else{
    //         return (ma-mi);
    //     }
    // }
// Minimum number of jumps************

    //  int minJumps(int arr[], int n){
    //     int ct=0;
    //     int i=0;
    //     if(n==1) return 0;
    //     while (i<n)
    //     {
    //         ct++;
    //         if(arr[i]==0){
    //             return -1;
    //         }
    //         if(arr[i]+i>=n-1){
    //             break;
    //         }
    //         int in=-1;
    //         // cout<<arr[i];
    //         int ma=INT_MIN;
    //         for(int j=i+1;j<arr[i]+i+1;j++){
    //             // cout<<(arr[j])<<" ";
    //             if(arr[j]!=0 && arr[j]+j>ma){
    //                 ma=arr[j];
    //                 in=j;
    //             }
    //         }
    //         // cout<<"ma="<<ma;
    //         if(in==-1){
    //             in=i+1;
    //         }
    //         i=in;
    //         // cout<<"mm"<<i<<"kk";
    //     }
        
    //     // cout<<ct;
    //     return ct;
    // }

// 287. Find the Duplicate Number

   int findDuplicate(vector<int>& nums) {
       vector<int>v2;
       for(int i=0;i<nums.size();i++){
           v2.push_back(0);
       }
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                    nums[abs(nums[i])-1]=nums[abs(nums[i])-1]*-1;
            }
           else if(nums[abs(nums[i])-1]>0 && v2[abs(nums[i])-1]==0){
            nums[abs(nums[i])-1]=nums[abs(nums[i])-1]*-1;

            v2[abs(nums[i])-1]=1;
            }
        }
        for(int i=0;i<nums.size();i++){
            // cout<<nums[i]<<"\n";
            if(nums[i]>0 && v2[i]==1){
                return (i+1);
                break;
            }
        }
      return -1;
            }




// Merge Without Extra Space


            	void merge(int arr1[], int arr2[], int n, int m) { // O(n^2) TLE
	
                    // int i=0,j=0,k=0;
                   // using insertion sort
        
                   int j=0,i=0;
                   while (i<n && j<m)
                   {
                       if(arr1[i]<arr2[j]){
                           i++;
                       }
                       else{
                           int temp=arr1[i];
                           arr1[i]=arr2[j];
                           arr2[j]=temp;
                           for(int k=j;k<m-1;k++){
                               if(arr2[k]>arr2[k+1]){
                                   int temp=arr2[k];
                                   arr2[k]=arr2[k+1];

                                   arr2[k+1]=temp;
                               }
                           }
                //            for(int k=0;k<n;k++){
                       
                //            cout<<arr1[k]<<" ";
                       
                //    }
                //    for(int k=0;k<m;k++){
                       
                //            cout<<arr2[k]<<" ";
                       
                //    }
                //    cout<<"\n";
                        //    j++;
                       }
                   }
                //    for(int k=0;k<n;k++){
                       
                //            cout<<arr1[k]<<" ";
                       
                //    }
                //    for(int k=0;k<m;k++){
                       
                //            cout<<arr2[k]<<" ";
                       
                //    }
                   

	}


	    void mergeGap(int arr1[], int arr2[], int n, int m) { // gap method

            int gap=ceil((n+m)/2);
            while (gap>0)
            {
                int i=0,j=gap;
                // cout<<j<<"gap";
                while (j<n+m)
                {
                    // cout<<i<<" "<<j<<"\n";
                    if(i<n && j<n){
                        if(arr1[i]>arr1[j]){
                        int temp=arr1[i];
                            arr1[i]=arr1[j];
                            arr1[j]=temp;}
                        i++;j++;
                    
                }
                else if(i<n && j>=n){
                        if(arr2[j-n]<arr1[i]){
                            int temp=arr1[i];
                            arr1[i]=arr2[j-n];
                            arr2[j-n]=temp;
                        }
                        i++;
                        j++;
                }
                else if(i>=n && j>=n){
                    if(arr2[j-n]<arr2[i-n]){
                    int temp=arr2[i-n];
                            arr2[i-n]=arr2[j-n];
                            arr2[j-n]=temp;
                }
                 i++;
                j++;
                }
               
                }
                if(gap==1) break;
                if(gap%2==0) gap/=2;
                else {gap/=2;gap++;}
             
                
                
            }
             

    }

    // 56. Merge Intervals

bool cmp2(vector<int> &a,vector<int> &b){
    return(a[0]<b[0]);
}
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>>v2;
            sort(intervals.begin(),intervals.end(),cmp2);
            for(int i=0;i<intervals.size()-1;i++){
                if(intervals[i][1]>=intervals[i+1][0]){
                    intervals[i+1][0]=intervals[i][0];
                    intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
                }
                else{
                    v2.push_back(intervals[i]);
                }
            }
            v2.push_back(intervals[intervals.size()-1]);
            // for(int i=0;i<v2.size();i++){
            //     cout<<v2[i][0]<<" "<<v2[i][1]<<"\n";
            // }
            return v2;
    }
//2 6 7 3   3 6 7 2   3 7 6 2  
// 31. Next Permutation

     void nextPermutation(vector<int>& nums) {
         int f=0;
         for(int i=nums.size()-1;i>=1;i--){
             if(nums[i]>nums[i-1]){
                 f=1;
                 int mi=nums[i];
                 int ind=i;
                 for(int j=i;j<nums.size();j++){
                     if(nums[j]>nums[i-1]){
                         if(nums[j]<=mi){
                             mi=nums[j];
                             ind=j;
                         }

                     }
                 }
                 
                 nums[ind]=nums[i-1];
                 nums[i-1]=mi;
               int k=nums.size()-1;
               
               while (i<k)
               {
                   int temp=nums[i];
                   nums[i]=nums[k];
                   nums[k]=temp;
                   i++;
                   k--;
               }
               
                 break;
             }

         }
         if(f==0){
             reverse(nums.begin(),nums.end());
         }
          return;
    }


    // Count Inversions

    bool cmp3(pair<long long,long long>a,pair<long long,long long>b){
        return(a.first<b.first);
    }
    set<pair<long long,long long>> ss;

void merge(long long  arr[],long long l,long long mid,long long r,long long &ct){
    // for(long long i=l;i<r;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"in\n";

    long long a[mid-l+1];
    long long b[r-l+1];
    long long m=0,n=0;
    for(long long i=l;i<mid;i++){
        a[m]=arr[i];
        m++;
    }
    a[m]=LLONG_MAX;
    for(long long i=mid;i<r;i++){
        b[n]=arr[i];
        n++;
    }
    b[n]=LLONG_MAX;
    m=0;
    n=0;
    long long i=l;
    while (m<mid-l+1 && n<r-mid+1)
    {
        if(i==r) break;
       if(a[m]<=b[n]){
           arr[i++]=a[m];
           m++;
           
       }
       else{
            if(m<mid-l){
           ct+=(mid-l-m);
            }
           arr[i++]=b[n++];
        //    cout<<m<<" "<<mid<<"ll\n";
          
       }
    }
    // for(long long i=l;i<r;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"out\n";
    // cout<<ct<<"\n";

}

void devideMerge(long long arr[],long long l,long long r,long long &ct){
    if(r-l>1){
    long long mid=l+(r-l)/2;
    // cout<<mid<<"\n";
    devideMerge(arr,l,mid,ct);
    devideMerge(arr,mid,r,ct);
    merge(arr,l,mid,r,ct);
    }
}
long long int inversionCount(long long arr[], long long N) // devide and conqer
{
    long long ct=0;
    // for(long long i=0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    devideMerge(arr,0,N,ct);
    // for(long long i=0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<ss.size()<<"\n";
        // cout<<ct;
    return ct;
}

// 121. Best Time to Buy and Sell Stock

int maxProfit(vector<int>& prices) {
        int ma=INT_MIN;
        int mi=INT_MAX;
        int ans=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            ma=max(ma,prices[i]);
            ans=max(ans,ma-prices[i]);
        }
        return ans;
    }

// Count pairs with given sum

    int getPairsCount(int arr[], int n, int k) {
        map<int,int> v;
        int ans=0;
        for(int i=0;i<n;i++){
            v[arr[i]-1]=0;
        }
        for(int i=0;i<n;i++){
            
            if(arr[i]<k ){
                if(v.find(k-arr[i]-1)!=v.end()){
                ans+=v[k-arr[i]-1];
                }
                // cout<<i;
            }
            v[arr[i]-1]++;
        }
        return ans;
    }
// Common elements 
  vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int > ans;
            vector<int> v;
            int i=0,j=0,k=0;
            while (i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++;
                }
                else if(A[i]<=B[j] && A[i]<=C[k]){
                    i++;
                }
                else if(B[j]<=A[i] && B[j]<=C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            int p;
            if(ans.size()>0)
            p=ans[0];
            for(int i=1;i<ans.size();i++){
                if(p!=ans[i]){
                    v.push_back(p);
                }
                p=ans[i];
            }
            if(ans.size()==0)
            return v;
            else {
            v.push_back(p);
            return v;
            }
        }

// Rearrange array in alternating positive & negative items with O(1) extra space | Set 1

void rotatevec(vector <int>&v,int l,int r){
    int temp=v[r];
    int i=r;
  while (i>l)
  {
      v[i]=v[i-1];
      i--;
  }
  v[l]=temp;
  
   
}
    void alternatingVector(vector<int> v){
        int i=-1;
        // int alt=0;
        for(int j=0;j<v.size();j++){
            // cout<<i<<" "<<j<<"jjj"<<v[j]<<"\n";

            if(v[j]<0){
                  if(j-i>=2){
                    // cout<<i<<" "<<j<<"\n";
                    rotatevec(v,i+1,j);
                }
                
                i++;
             

            }
            
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        int pt;
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                pt=i;
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            if(i%2==1 && pt<v.size() && v[i]<0){
                rotatevec(v,i,pt);
                pt++;
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }

// Subarray with 0 sum 

bool subArrayExists(int arr[], int n)
    {
        // 4 2 -3 1 6
        // 4 6 3 4 10
        map<int,int> mp;
        int s=0;
        int f=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(mp.find(s)!=mp.end()){
                f=1;
                break;
            }
            mp[s]=1;
        }
        if(f){
            // cout<<"YES"<<"\n";
            return true;
        }
        else{
            // cout<<"NO"<<"\n";
            return false;
        }
    }
// Factorials of large numbers

  vector<int> factorial(int N){
        // 2 4
        // 2 4 * 5
        // 
        vector<int> v1,v2;
        v1.push_back(1);
        for(int i=1;i<=N;i++){
            int p=0;
            // cout<<"i"<<i<<"\n";
            for(auto j:v1){
                // cout<<i<<j<<"\n";
                v2.push_back((i*j+p)%10);
                // v2.push_back((i*j)/10);
                
                    p=((i*j+p)/10);
                                    
               

            }
            while (p>0)
            {
                v2.push_back(p%10);
                p=p/10;
            }
            
                //  for(auto k:v2){
                //     cout<<k<<" ";
                // }
                // cout<<"\n";
            
            v1=v2;
            v2={};
            // break;
        }
        reverse(v1.begin(),v1.end());
        return v1;
    }

// Maximum Product Subarray

long long maxProduct(vector<int> arr, int n) {
    if(n==1){
        return arr[0];
    }
            long long s=0;
            long long fans=LLONG_MIN;
            int p=-1;
            arr.push_back(0);
            for(int i=0;i<=n;i++){
                if(arr[i]==0){
                    int ct=0;
                    long long ans=1;
                    for(int j=p+1;j<i;j++){
                        ans*=arr[j];
                        if(arr[j]<0){
                            
                            ct++;
                        }
                    }
                    // cout<<"ct"<<ct<<ans<<"\n";
                    if(ct%2==0){
                        if(ans>fans){
                            fans=ans;
                        }
                    }
                    else{
                        int f1=0,f2=0;
                        long long ans1=1,ans2=1,ans3=1;

                        for(int j=p+1;j<i;j++){
                            if(arr[j]<0){
                                ans2*=ans3;
                                ans3=1;
                            }
                            ans3*=arr[j];
                            if(f1==1){
                                ans1*=arr[j];
                                // cout<<arr[j];
                            }
                            if(arr[j]<0){
                                f1=1;
                            }
                            
                        }
                        // cout<<ans1<<ans2<<"\n";
                        if(ans2>ans1){
                            ans=ans2;
                        }
                        else{
                            ans=ans1;
                        }
                        if(ans>fans){
                            fans=ans;
                        }
                    }
                    p=i;
                    // cout<<fans<<"kk\n";
                }
                
            }
            // cout<<fans;
            return fans;
	}

// Longest consecutive subsequence

   int findLongestConseqSubseq(int arr[], int N)
    {
        map<int,int> mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]=1;
        }
        int ans=INT_MIN;
        for(int i=0;i<N;i++){
            int a=0;
            int k=0;
            if(mp[arr[i]]==1){
                a=1;
                while (mp.find(arr[i]+a)!=mp.end() && mp[arr[i]+a]==1)
                {
                    mp[arr[i]+a]=2;
                    a++;
                    
                }
                int p=1;
                while (mp.find(arr[i]-p)!=mp.end() && mp[arr[i]-p]==1)
                {
                    a++;
                    mp[arr[i]-p]=2;
                    p++;
                }
                
            }
            ans=max(ans,a);
        }
        // cout<<ans;
        return ans;
    }

// Maximum profit by buying and selling a share at most twice

    int maxTwoShare(vector<int> v){

        vector<int > v1,v2;
        int mi=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<v.size();i++){
            mi=min(mi,v[i]);
            ma=max(ma,v[i]-mi);
            v1.push_back(ma);
        }
        int ma2=INT_MIN;
        ma=INT_MIN;
        for(int i=v.size()-1;i>=0;i--){
            ma2=max(ma2,v[i]);
            ma=max(ma,ma2-v[i]);
            v2.push_back(ma);
        }
        // for(auto i:v1){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for(auto i:v2){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        reverse(v2.begin(),v2.end());
        int ans=INT_MIN;
        for(int i=0;i<v.size()-1;i++){
            ans=max(ans,(v1[i]+v2[i+1]));
        }
    // cout<<ans;
    return ans;

    }

// Array Subset of another array 

    string isSubset(int a1[], int a2[], int n, int m) {
        
        map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[a1[i]]=0;
        }
        n=mp.size(); // reapeted elements
        for(int i=0;i<m;i++){
            mp[a2[i]]=0;
        }
       if(mp.size()==n){
           return "Yes";
       }
       else{
           return "No";
       }

    }

// Triplet Sum in Array

    bool find3Numbers(int A[], int n, int X)
{
    sort(A,A+n);
    int f=0;
    int px=X;
    for(int i=0;i<n;i++){
        X-=A[i];
        if(X<0){
            continue;
        }
        int j=0;
        int k=n-1;
        
        while (j<k)
        {
            int s=0;
            if(j==i) j++;
            if(k==i) k--;
            s+=A[j];
            s+=A[k];
            if(s==X){
                f=1;
                // cout<<A[i]<<A[j]<<A[k]<<"\n";
                j++;
                k--;
                break;
            }
            else if(s<X){
                j++;
            }
            else{
                k--;
            }

        }
        if(f) break;
        X=px;

    }
    return f;
}

// Trapping Rain Water 

 long long trappingWater(int arr[], int n){
       
    vector<int> v1,v2;
    int ma=INT_MIN;
    for(int i=0;i<n;i++){
        ma=max(ma,arr[i]);
        v1.push_back(ma);
    }
    ma=INT_MIN;
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        ma=max(ma,arr[i]);
        v2.push_back(ma);
    }
    reverse(v2.begin(),v2.end());
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1){
            continue;
        }
        long long x=min((v1[i-1]),v2[i+1]);
        if(arr[i]<x)
        ans+=x-arr[i];

        // cout<<x<<ans<<"\n";
        
    }
return ans;

    }

// Chocolate Distribution Problem

    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
        int mi=INT_MAX;
        int j=m;
        while (j<=n)
        {
            int x=(a[j-1]-a[j-m]);
            mi=min(mi,x);
            j++;
        }
        
        return mi;
    
    } 

// Smallest subarray with sum greater than x 

int smallestSubWithSum(int arr[], int n, int x)
    {
        int s=0;
        int mi=INT_MAX;
        int l=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(s>x){
                while (s-arr[l]>x)
                {
                    s-=arr[l];
                    l++;
                }
                
                mi=min(mi,i-l+1);
                // cout<<"mi"<<mi<<" "<<l<<" "<<i<<"\n";

            }
          
        }  
        return mi;
    }


// Three way partitioning

void threeWayPartition(vector<int>array,  int a, int b)
{
    int n=array.size();
    int i=-1;
    for(int j=0;j<n;j++){
        if(array[j]<a){
            i++;
            int temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }
    }
    for(int j=i+1;j<n;j++){
        if(array[j]<=b){
            i++;
            int temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    
}

// Minimum swaps and K together

 int minSwap(int arr[], int n, int k) {

     int ct=0;
     for(int i=0;i<n;i++){
         if(arr[i]<=k){
             ct++;
         }
     }
     int  ct2=0;
     int ma=INT_MIN;
     for(int i=0;i<n;i++){
         if(i<ct){
         if(arr[i]<=k){
             ct2++;
         }
         }
        
         else{
              ma=max(ct2,ma);
              if(arr[i-ct]<=k){
                  ct2--;
              }
              if(arr[i]<=k){
                  ct2++;
              }
         }
     }
     ma=max(ct2,ma);
    //  cout<<ct-ma;
     return (ct-ma);


    }

    // minimum no of operation required to make array palindrome

int minArrayPalindrome(vector<int> v){
    int i=0;
    int j=v.size()-1;
    int sl=0,sr=0;
    int ct=0;
    while (i<j)
    {
        sl+=v[i];
        sr+=v[j];
        if(sl==sr){
            sl=0;
            sr=0;
            i++;
            j--;
        }else if (sl<sr)
        {
            i++;
            ct++;
        }
        else{
            j--;
            ct++;
        }

        
    }
    cout<<ct;
    return ct;
    

}

// Median of two sorted arrays of different sizes in O(log(m+n))

int bsearch(vector<int> & v,vector<int>&v2,int l,int r,int x){
//  cout<<l<<r<<"\n";
 int mid=l+(r-l)/2;
 if(mid==v.size()) return mid-1;
//  else if(mid==-1) return -1;
    if(r-l<=1) {
        // cout<<l<<r<<"\n";
        if(v[mid]<=v2[v2.size()-(mid-(x-v2.size()))-1]){
            // cout<<"m"<<mid;
        return mid;
    }
    else{
       return mid-1;
    }
       
    }
    
    // cout<<mid<<" "<<v2.size()-(mid-(x-v2.size()))-1<<v[mid]<<v2[v2.size()-(mid-(x-v2.size()))-1]<<"\n";
    if(v[mid]<=v2[v2.size()-(mid-(x-v2.size()))-1]){
       return  bsearch(v,v2,mid,r,x);
    }
    else{
       return bsearch(v,v2,l,mid,x);
    }


}

float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    float ans;
    int f=0;
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]!=0) {
            f=1;
            break;
        }
    }
    for(int i=0;i<nums2.size();i++){
        if(nums2[i]!=0) {
            f=1;
            break;
        }
    }
    if(f==0){
        ans=0;
    }
    else{
        if(nums1.size()==0){
            if(nums2.size()%2==0){
                float a=nums2[nums2.size()/2-1];
                float b=nums2[nums2.size()/2];
                ans=(a+b)/2;
            }
            else{
                ans=nums2[nums2.size()/2];
            }
        }
        else if(nums2.size()==0){
             if(nums1.size()%2==0){
                float a=nums1[nums1.size()/2-1];
                float b=nums1[nums1.size()/2];
                ans=(a+b)/2;
            }
            else{
                ans=nums1[nums1.size()/2];
            }
        }
        else{
        if(nums1.size()>nums2.size()){
            if((nums1.size()+nums2.size())%2==1){
                int f=(nums1.size()+nums2.size())/2;
                int ind=bsearch(nums1,nums2,f+1-nums2.size(),nums1.size(),f+1);
                
                if(ind==-1){
                    ans=nums2[f+1-(ind+1)-1];
                }
                else{
                if(nums1[ind]>nums2[f+1-(ind+1)-1]){
                    // cout<<nums1[ind];
                    ans=nums1[ind];

                }
                else{
                    // cout<<nums2[f+1-(ind+1)-1];
                    ans=nums2[f+1-(ind+1)-1];
                }
                }

            }
            else{
                int f=(nums1.size()+nums2.size())/2;
                int ind=bsearch(nums1,nums2,f-nums2.size(),nums1.size(),f);
                float a,b;
                
                if(ind!=-1 && nums1[ind]>nums2[f-(ind+1)-1]){
                    a=nums1[ind];
                }
                else{
                    a=nums2[f-(ind+1)-1];
                }
                 ind=bsearch(nums1,nums2,f+1-nums2.size(),nums1.size(),f+1);
                 if(ind!=-1 &&nums1[ind]>nums2[f+1-(ind+1)-1]){
                    b=nums1[ind];
                }
                else{
                    b=nums2[f+1-(ind+1)-1];
                }
                // cout<<(a)<<" "<<b;
                ans=(a+b)/2;

            
            }
        }
        else{
                 if((nums1.size()+nums2.size())%2==1){
                int f=(nums1.size()+nums2.size())/2;
                int ind=bsearch(nums2,nums1,f+1-nums1.size(),nums2.size(),f+1);
                if(ind!=-1 &&nums2[ind]>nums1[f+1-(ind+1)-1]){
                    // cout<<nums2[ind];
                    ans=nums2[ind];
                }
                else{
                    // cout<<nums1[f+1-(ind+1)-1];
                    ans=nums1[f+1-(ind+1)-1];
                }
            }
            else{
                int f=(nums1.size()+nums2.size())/2;
                int ind=bsearch(nums2,nums1,f-nums1.size(),nums2.size(),f);
                float a,b;
                if(ind!=-1 &&nums2[ind]>nums1[f-(ind+1)-1]){
                    a=nums2[ind];
                }

                else{
                    a=nums1[f-(ind+1)-1];
                }
                // cout<<ind<<"ff";
                 ind=bsearch(nums2,nums1,f+1-nums1.size(),nums1.size(),f+1);
                 if(ind!=-1 &&nums2[ind]>nums1[f+1-(ind+1)-1]){
                    b=nums2[ind];
                }
                else{
                    b=nums1[f+1-(ind+1)-1];
                }
                // cout<<a<<" "<<b;
                if(a==0 && b==0) ans=0;
                else
                ans=(a+b)/2;
            
            }
        }
    }
    }
        return ans;
       

    }





int main(){
    // vector<long long>v={1,3,5,10,6,0,15};
    // int arr[]={9,10,1,2,3,4,8,0,0,0,0,0,0,0,1};
    // minJumps(arr,15);
    // vector<int> v={2,2,2,2,2}; // {-1,-2,-3,4,4}
    // cout<<findDuplicate(v);
//    long long  arr1[] = {468,335,1,170,225,479,359,463,465,206,146,282,328,462,492,496,443,328,437,392,105,403,154,293,383,422,217,219,396,448,227,272,39,370,413,168,300,36,395,204,312,323};
//   int  arr1[] = {48,24,99,51,33,39,29,83,74,72,22,46,40,51,67,37,78,76,26,28,76,25,10,65,64,47,34,88,26,49,86,73,73,36,75,5,26,4,39,99,27,12,97,67,63,15,3,92,90};
// int arr1[]={2,5,5,5,5,10};
// cout<< getPairsCount(arr1,6,10);
// int arr2[] = {0, 2, 6, 8, 9,15,16,17};
// mergeGap(arr1,arr2,7,8);

 vector<int> v={11, 14, 15, 99};
// int a[] = {40,3,2,9};
// findLongestConseqSubseq(a,4);
// alternatingVector(v);
// vector<int> v=factorial(100);
// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
// }
// cout<<"\n";
// maxProduct(v,v.size());

// nextPermutation(v);
// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
// }

// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
// }

// int v[]=  {19,9} ;

// threeWayPartition(v,4,36,72);
vector<int>v1={};
vector<int>v2={0};
cout<<findMedianSortedArrays(v1,v2);

cout<<"\n";
   return 0;
}

