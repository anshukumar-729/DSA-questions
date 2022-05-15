#include <bits/stdc++.h>
using namespace std;

long long max(long long a,long long b){
    if(a>b) return a;
    else return b;
}
long long min(long long a,long long b){
    if(a<b) return a;
    else return b;
}
vector<int> find(int arr[], int n , int x )
{
    int l=0;
    int r=n-1;
    int ans1,ans2;
    while (r-l>1)
    {
        int m=(r-l)/2+l;
        if(arr[m]>=x){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    if(arr[l]==x) ans1=l;
    else if(arr[r]==x) ans1=r;
    else ans1=-1;
    l=0;
    r=n-1;
    while (r-l>1)
    {
        int m=(r-l)/2+l;
        if(arr[m]<=x){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    if(arr[r]==x) ans2=r;
    else if(arr[l]==x) ans2=l;
    else ans2=-1;
    return {ans1,ans2};


}
	vector<int> valueEqualToIndex(int arr[], int n) {  // 1 2 3 3 5 5
	 vector<int> ans;
     for(int i=0;i<n;i++){
         if(arr[i]==i) ans.push_back(i);
     }
     return ans;
	}

// 33. Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while (r-l>1)
        {
            int m=(r-l)/2+l;
            if(nums[m]>=nums[0]  ){
               l=m;
                
            }
            else{
                r=m-1;
            }
        }
        int mid;
        if(r+1<nums.size() && nums[r]>nums[r+1]){
            mid=r;
        }
        else if(l+1<nums.size() && nums[l]>nums[l+1]){
            mid=l;
        }
        else{
            mid=-1;
        }
        if(mid==-1){
            l=0;
            r=nums.size()-1;
        }
        else if(nums[0]<=target){
            l=0;
            r=mid;
        }
        else{
            l=mid+1;
            r=nums.size()-1;
        }
        while (r-l>1)
        {
            int m=(r-l)/2+l;
            if(nums[m]>=target){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        if(nums[l]==target) return l;
        else if(nums[r]==target) return r;
        else return -1;
        
        
    }

// Find square root of number upto given precision using binary search
#include <string> // fully not correct kisi ka sahi nahi hai pure intrenet par <','>
#include<iostream>
using namespace std;
float sqrtBinarySearch(int num, int p) {
   int left = 0, right = num;
   int mid;
   float res;
   while (left <= right) {
      mid = (left + right) / 2;
      if (mid * mid == num) {
         res = mid;
         break;
      }
      if (mid * mid < num) {
         left = mid + 1;
         res = mid;
      } else {
         right = mid - 1;
      }
   }
   float incr = 0.1;
   for (int i = 0; i < p; i++) {
      while (res * res <= num) {
         res += incr;
      }
      res -= incr;
      incr /= 10;
   }
   return res;
}


// Maximum and minimum of an array using minimum number of comparisons but this is in O(nlog(n)) :{

 pair<int,int> maxMinPair(vector<int> & v ,int i,int j){
    if(j-i==1) return {v[i],v[i]};
    else if(j-i==2) return {min(v[i],v[i+1]),max(v[i],v[i+1])};
    int mid=(j-i)/2+i;
    pair<int ,int> a=maxMinPair(v,i,mid);
    pair<int ,int> b=maxMinPair(v,mid,j);
    return {min(a.first,b.first),max(a.second,b.second)};
}

// Optimum location of point to minimize total distance  hard question wrong in decimal point 
float distance2(vector<pair<int,int>> &vp,int a,int b,int c,float x){
    float ans=0;
    for(int i=0;i<vp.size();i++){
        float x1=vp[i].first;
        float y1=vp[i].second;
        float x2=x;
        float y2=(-1*a*x-c)/b;
        float temp;
        temp=sqrt((y2-y1)*(y2-y1)+((x2-x1)*(x2-x1)));
        ans+=temp;
    }
    return ans;
}

pair<float,float> perpendiCular(pair<float,float> p,float a,float b,float c){ // y=mx+c  y=a/bx+c by=ax+bc
    // cout<<(b*(b*p.first-a*p.second)- a*c)/(a*a+b*b)<<" "<<(a*(-1*b*p.first+a*p.second)- b*c)/(a*a+b*b)<<"\n";
    return {(b*(b*p.first-a*p.second)- a*c)/(a*a+b*b),(a*(-1*b*p.first+a*p.second)- b*c)/(a*a+b*b)};

}

 double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    vector<pair<float,pair<float,float>>> vp;
        for(int i=0;i<p.size();i++){
            pair<float,float> pp=perpendiCular(p[i],get<0>(l),get<1>(l),get<2>(l));
            vp.push_back({pp.first,{pp.second,i}});
        }
        sort(vp.begin(),vp.end());
        float lt=vp[0].first;
        float rt=vp[vp.size()-1].first;
        // cout<<lt<<" "<<rt<<"\n";
        while ((rt-lt)>0.00001)
        {
            // cout<<lt<<"\n";
            float m=(rt-lt)/2+lt;
            float aa=distance2(p,get<0>(l),get<1>(l),get<2>(l),m);
            float bb=distance2(p,get<0>(l),get<1>(l),get<2>(l),m+0.00001);
            // cout<<aa<<" "<<bb<<"\n";
            // lt+=0.01;
            if(aa>=bb){
                lt=m;
            }
            else{
                rt=m-0.00001;
            }

        }
        return min(distance2(p,get<0>(l),get<1>(l),get<2>(l),lt),distance2(p,get<0>(l),get<1>(l),get<2>(l),rt));

        

    }

    // x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n){
        if(arr[i]==x) return i;
        if(abs(arr[i]-x)>k) {
            i+=(abs(arr[i]-x)/k);
        }
        else i+=1;
    }
    return -1;
}    	
// Find Pair Given Difference 

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    for(int i=0;i<size-1;i++){
        int x;
        
        x=n+arr[i];
        
        int l=i+1;
        int r=size-1;
        // cout<<i<<"k"<<x<<"\n";
        while (r-l>1)
        {
            
            int m=(r-l)/2+l;
            // cout<<arr[m]<<"\n";
            if(arr[m]>=x){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        if(arr[l]==x || arr[r]==x) return 1;
        x=n-arr[i];
        if(x<0) continue;
         l=i+1;
         r=size-1;
        // cout<<i<<"k"<<x<<"\n";
        while (r-l>1)
        {
            
            int m=(r-l)/2+l;
            // cout<<arr[m]<<"\n";
            if(arr[m]>=x){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        if(arr[l]==x || arr[r]==x) return 1;
        
    }
    // cout<<"not";
    return 0;
    
}

 // arr[] : int input array of integers
    // k : the quadruple sum required
  vector<vector<int> > fourSum(vector<int> &arr, int p) {
        int n=arr.size();
        set<vector<int>> ans;
        sort(arr.begin(),arr.end(),greater<int>());
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    int x=(p-(arr[i]+arr[j]+arr[k]));
                    // cout<<x<<"\n";
                    // if(x<0) continue;
                    int l=k+1;
                    if(l>=n) continue;
                    int r=n-1;
                    // cout<<l<<r<<"\n";
                    while (r-l>1)
                    {
                        int m=(r-l)/2+l;
                        // cout<<"y"<<m;
                        if(arr[m]<=x){
                            r=m;
                        }
                        else{
                            l=m+1;
                        }
                    }
                    if(arr[l]==x){
                        ans.insert({arr[l],arr[k],arr[j],arr[i]});
                        // cout<<i<<j<<k<<l<<"\n";
                        // cout<<arr[l]<<"\n";
                    }
                    else if(arr[r]==x){
                        ans.insert({arr[r],arr[k],arr[j],arr[i]});
                        // cout<<i<<j<<k<<r<<"\n";
                        // cout<<arr[r]<<"\n";
                    }

                    
                }
            }
        }
        vector<vector<int>> v;
        for(auto i:ans){
            v.push_back(i);
        }
        return v;
    }

    //Function to find the maximum money the thief can get. no two consecutive

    int maxSumRec(vector<int> &v,int i,vector<int> &mem){
        if(i>=v.size()) return 0;
        if(mem[i]!=-1) return mem[i];
        return mem[i]=max(maxSumRec(v,i+1,mem),v[i]+maxSumRec(v,i+2,mem));
    }

    int FindMaxSum(int arr[], int n)
    {
        vector<int> mem(n,-1);
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(arr[i]);
        }
       return maxSumRec(v,0,mem);

    }

   	long long countTriplets(long long arr[], int n, long long sum)
	{
        sort(arr,arr+n);
        long long ct=0;
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
	    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=sum-(arr[i]+arr[j]);
                int l=j+1;
                if(l>=n) continue;
                int r=n-1;
                // cout<<x<<"\n";
                while (r-l>1)
                {
                    int m=(r-l)/2+l;
                    if(arr[m]<x){
                        l=m;
                    }
                    else{
                        r=m-1;
                    }
                }
                if(r>=l && arr[r]<x){
                    ct+=(r-j);
                    // cout<<arr[i]<<arr[j]<<arr[r]<<"\n";
                }
                else if(arr[l]<x){
                    ct+=(l-j);
                    // cout<<arr[i]<<arr[j]<<arr[r]<<"\n";
                } 

                
            }
        }
        return ct;
	}
    // Merge Without Extra Space 
		  void merge(int arr1[], int arr2[], int n, int m) { // gap method

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

// by insertion sort method O(n^2)

 void merge2(int arr1[], int arr2[], int n, int m) {
     int i=0;
     int j=0;
     while (i<n)
     {
         if(arr1[i]>arr2[j]){
             swap(arr1[i],arr2[j]);
             int k=j;
             while (k+1<m && arr2[k]>arr2[k+1])
             {
                 swap(arr2[k],arr2[k+1]);
                 k++;
             }
             
             
         }
         i++;
     }
     
 }

 //Function to count subarrays with sum equal to 0.
    long long  findSubarray(vector<long long > arr, int n ) {
        long long ct=0;
        vector<long long> sum(n+1,0);
        map<long long,int> mp;
        for(int i=0;i<n;i++){
           sum[i+1]=sum[i]+arr[i];
           mp[sum[i]]++;
        }
        mp[sum[n]]++;
        for(auto &i:mp){
            int g=i.second;
            ct+=((g*(g+1))/2);
        }

        return ct;
    }
 string increamentDecreamentPattern(string s){
    //  vector<int> v;
     int temp=1;
     for(auto i:s){
         if(i=='D') temp++;
     }
     
     int ct=0;
     string ans="";
     int mi=temp;
     int ma=temp+1;
     ans+=(to_string(mi--));
     for(auto i:s){
         if(i=='D'){
             ans+=(to_string(mi--));
         }
         else{
             ans+=to_string(ma++);
         }
         if(mi<0 || ma>10) return "-1";
        
     }

 return ans;
 }

  // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long> v;
        long long ans=1;
        int f=0;
        for(int i=0;i<n;i++){
            if(f==0){
                if(nums[i]!=0){
                    ans*=nums[i];
                }
                else{
                    f=1;
                    
                }
            }
            else{
                ans*=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(f==1){
                if(nums[i]!=0){
                    v.push_back(0);
                }
                else{
                    v.push_back(ans);
                }
            }
            else{
            v.push_back(ans/nums[i]);
            }
        }
        return v;
    }
    int setBitCount(int n){
        int ct1=__builtin_popcount(n);
          
          
           return ct1;
          
    }
    void mergeInSetBit(vector<int> &arr,int i,int m,int j,map<int,int> &mp){
        vector<int> v;
        int p=i;
        int q=m;
        while (p<m && q<j)
        {
            if(mp[arr[q]]>mp[arr[p]]){
                v.push_back(arr[q++]);
            }
            else{
                v.push_back(arr[p++]);
            }
        }
        while (p<m)
        {
            v.push_back(arr[p++]);
        }
        while (q<j)
        {
            v.push_back(arr[q++]);
        }
        p=0;
        for(int k=i;k<j;k++){
            arr[k]=v[p++];
        }
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        
    }
   void mergeSortBySetBit(vector<int> &arr,int i,int j,map<int,int> &mp){
       if(j-i<=1) return;
       
       int m=(j-i)/2+i;
       mergeSortBySetBit(arr,i,m,mp);
       mergeSortBySetBit(arr,m,j,mp);
       mergeInSetBit(arr,i,m,j,mp);

   }
 // TLE due to tight bound O(nlog(n))
    void sortBySetBitCount(int arrr[], int n)
    {
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(arrr[i]);
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=setBitCount(arr[i]);
        }
        mergeSortBySetBit(arr,0,n,mp);
        for(int i=0;i<n;i++){
            arrr[i]=(arr[i]);
        }
    }

    // built in
     static bool cmp4(int a,int b){
        
          return (__builtin_popcount(b)<__builtin_popcount(a));
    }
   
    void sortBySetBitCount2(int arr[], int n)
    {
       
       stable_sort(arr,arr+n,cmp4);

    }


    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int ct=0;int n=nums.size();
        vector<int> v=nums;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[v[i]]=i;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=v[i]){
                ct++;
                swap(v[i],v[mp[nums[i]]]);
            }
        }
        return ct;
	}


   int kthElement(int arr1[], int arr2[], int n, int mm, int k)
    {
        long long  l=1;
        long long r=INT_MAX-1;
        
        while (r-l>1)
        {
            // cout<<l<<" "<<r<<"  ";
            long long m=(r-l)/2+l;
            int l1=0;
            int r1=n-1;
            int ct=0;
            // cout<<m<<" ";
            while (r1-l1>1)
            {
                int m1=(r1-l1)/2+l1;
                if(arr1[m1]>m){ // right baised
                    r1=m1-1;
                }
                else{
                    l1=m1;
                }
              
            }
              if(arr1[r1]<=m) ct+=r1+1;
                else if(arr1[l1]<=m) ct+=l1+1;
                // cout<<ct<<" ";
            int l2=0;
            int r2=mm-1;
            while (r2-l2>1)
            {
                int m1=(r2-l2)/2+l2;
                if(arr2[m1]>m){
                    r2=m1-1;
                }
                else{
                    l2=m1;
                }
               
            }
            
             if(arr2[r2]<=m) ct+=r2+1;
                else if(arr2[l2]<=m) ct+=l2+1;
            
            if(ct<k){ // left biased
                l=m+1;
            }
            else{
                r=m;
            }
            
            
        }
        // cout<<l<<r;
        int m=l;
         int l1=0;
            int r1=n-1;
            int ct=0;
            // cout<<m<<" ";
            while (r1-l1>1)
            {
                int m1=(r1-l1)/2+l1;
                if(arr1[m1]>m){
                    r1=m1-1;
                }
                else{
                    l1=m1;
                }
              
            }
              if(arr1[r1]<=m) ct+=r1+1;
                else if(arr1[l1]<=m) ct+=l1+1;
                // cout<<ct<<" ";
            int l2=0;
            int r2=mm-1;
            while (r2-l2>1)
            {
                int m1=(r2-l2)/2+l2;
                if(arr2[m1]>m){
                    r2=m1-1;
                }
                else{
                    l2=m1;
                }
               
            }
            
             if(arr2[r2]<=m) ct+=r2+1;
                else if(arr2[l2]<=m) ct+=l2+1;
            if(ct>=k) return l; // > for repeated elements;
        return r;


        

    }

    int funcIsFit(vector<long long> &v,int m,int k){
        int n=v.size();
        int ct=k-1;
           int i=0;
           while (ct>0)
           {
               int l1=i;
               int r1=n-1;
               while (r1-l1>1)
               {
                   int m1=(r1-l1)/2+l1;
                   if((v[m1]-v[i])<m){
                       l1=m1+1;
                   }
                   else{
                       r1=m1;
                   }
               }
               if((v[l1]-v[i])>=m){
                   ct--;
                   i=l1;
               }
               else if((v[r1]-v[i])>=m){
                   ct--;
                   i=r1;
               }
               else{
                   break;
               }
           }
           return ct;
    }

   int aggresiveCows(vector<long long >&v,int k){
       sort(v.begin(),v.end());
       int n=v.size();
       int l=0;
       int r=(v[v.size()-1]-v[0]);
       while (r-l>1)
       {
           int m=(r-l)/2+l;
           int ct=funcIsFit(v,m,k);
           if(ct!=0){
               r=m-1;
           }
           else l=m;
           

       }
       int ct=funcIsFit(v,r,k);
       if(ct==0) return r;
       else{
           ct=funcIsFit(v,l,k);
           if(ct==0) return l;
           else return 0;
       }
    }

     //Function to find minimum number of pages. HARD gfg************

    int isFitPages(int A[],int N,int m,int M){
         int ct=M;
            int i=0;
            while (ct>0)
            {
                int j=i;
                int temp=0;
                // cout<<i<<j<<"\n";
                while (j<N && temp+A[j]<=m)
                {
                    
                    temp+=A[j];
                    // cout<<j<<" "<<A[j]<<" "<<temp<<" ";
                    j++;
                    
                }
                // cout<<i<<j<<"\n";
                
                
                 if(j==i && j==N){
                    ct=-2;
                    break;
                }
               else  if(i==j&& j<N){
                    ct=-1;
                    break;
                }
               
                else {
                    ct--;
                    i=j;
                    if(j==N && ct==0 ) break;
                    
                }
            }
            if(i==N)
            return ct;
            else return -1;
     }
    int findPages(int A[], int N, int M) 
    {
        int sum=0;
        int ma=INT_MIN;
        for(int i=0;i<N;i++){
            ma=max(ma,A[i]);
            sum+=A[i];
        }
        int l=ma;
        int r=sum;
        while (r-l>1)
        {
            int m=(r-l)/2+l;
            int ct=isFitPages(A,N,m,M);
            // cout<<m<<" "<<ct<<"\n";
            if(ct==-1){
                l=m+1;
            }
            else{
                r=m;
            }            
        }
        int ct=isFitPages(A,N,l,M);
        // cout<<l<<" "<<ct<<"\n";
        if(ct==0 || ct==-2) return l;
        else {
            ct=isFitPages(A,N,r,M);
            // cout<<r<<" "<<ct<<"\n";
            if(ct==0|| ct==-2) return r;
            else return -1;
        }

        

    }

    long long cuttingWood(vector<long long> &v,long long m){
        long long s=0;
        for(long long i=0;i<v.size();i++){
            if(v[i]>m)
            s+=(v[i]-m);
        }
        return s;
    }


    // EKO - Eko  wood cutting maxmimum heigth blade
    long long minimumHeightBlade(vector<long long> &v,long long k){
        long long n=v.size();
        long long ma=LLONG_MIN;
        for(long long i=0;i<n;i++){
            ma=max(ma,v[i]);
        }
        long long l=0;
        long long r=ma;
        while (r-l>1)
        {
            long long m=(r-l)/2+l;
            long long ct=cuttingWood(v,m);
            if(ct<k){
                r=m-1;
            }
            else{
                l=m;
            }
        }
        if(cuttingWood(v,r)>=k) return r;
        else if(cuttingWood(v,l)>=k) return l;
        else return -1;
        

    }

   int maxValueJob(vector<vector<int>> &v,int i,int k,vector<int> &mem){
        if(i==v.size()) return 0;
        if(mem[i]!=-1) return mem[i];
        int l=i;
        int r=v.size()-1;
       int ans=-1;
        while (r-l>1)
        {
            int m=(r-l)/2+l;
            if(v[m][0]<k){
                l=m+1;
            }
            else{
                r=m;
            }
           
        }
         if(v[l][0]>=k) ans=l;
            else if(v[r][0]>=k) ans=r;
        // cout<<i<<ans;
        if(ans==-1){
            return 0;
        }
        return max(maxValueJob(v,ans+1,v[ans][0],mem),v[ans][2]+maxValueJob(v,ans+1,v[ans][1],mem));
    }
	/* The Job class have three public member variables, start, finish, and profit. */

static	bool comp(vector<int> a,vector<int>b){
		if(a[0]==b[0]){
			return a[2]>b[2];
		}
		else return a[0]<b[0];
	}
	int findMaxProfit(vector<vector<int>> v)
	{
		
		
		sort(v.begin(),v.end(),comp);
		 vector<int> mem(v.size(),-1);
		     return maxValueJob(v,0,0,mem);

		
	}

    // Smallest factorial number with atleast n trailing 0
int noOfZeroes(int n){
    int p=5;int ct=0;
    while (p<=n)
    {
        ct+=(n/p);
        p*=5;
    }
    return ct;
    
}

int findNum(int n)
        {
            int l=1;
            int r=n*5;
            while (r-l>1)
            {
                int m=(r-l)/2+l;
                if(noOfZeroes(m)<n){
                    l=m+1;
                }
                else{
                    r=m;
                }


            }
            if(noOfZeroes(l)>=n) return l;
            else if(noOfZeroes(r)>=n) return r;
            else return -1;            
        }


// The Painter's Partition Problem-II  Hard gfg********** repeated concept of binary search

    int paintersFit(int arr[],int n,long long m,int k){
        int i=0;
        int ct=k;
        while (ct>0)
        {
            long long temp=0;
            while (i<n && temp+arr[i]<=m)
            {
                temp+=arr[i];
                i++;
            }
            ct--;
            
            if(ct==0 && i<n) {
                ct=-1;
                break;
            }
            if(i==n) break;
               
        }
        // cout<<"bb"<<i<<ct<<"\n";
        return ct;
        
    }

    long long minTime(int arr[], int n, int k)
     {
        //  for(int i=0;i<n;i++){
        //      cout<<arr[i]<<" ";
        //  }
        //  cout<<"\n";
        int ma=INT_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            ma=max(ma,arr[i]);
            sum+=arr[i];
        }   
        long long l=ma;
        long long r=sum;
        while (r-l>1)
        {
            long long m=(r-l)/2+l;
            long long ct=paintersFit(arr,n,m,k);
            // cout<<m<<" "<<ct<<"\n";
            if(ct==-1){
                l=m+1;
            }
            else{
                r=m;
            }


        }
        if(paintersFit(arr,n,l,k)!=-1) return l;
        else if(paintersFit(arr,n,r,k)!=-1) return r;
        else return -1;
        
    }


// PRATA - Roti Prata these all question are based on binary search on answer

int noOfParathaInTime(int arr[],int n,int m){
    int ans=0;
    for(int i=0;i<n;i++){
        int l=(sqrt((m*2)/arr[i]));
        if(l*(l+1)<=(m*2)/arr[i]) ans+=l;
        else ans+=l-1;
    }
    return ans;
}

int minTimeParatha(int arr[],int n,int p){
    int ma=INT_MIN;
    for(int i=0;i<n;i++){
        ma=max(ma,arr[i]);
    }
    int l=0;
    int r=ma*((p*(p+1))/2);
    while (r-l>1)
    {
        int m=(r-l)/2+l;
        int ct=noOfParathaInTime(arr,n,m);
        // cout<<m<<ct<<"\n";
        if(ct<p){
            l=m+1;
        }
        else{
            r=m;
        }

    }
    if(noOfParathaInTime(arr,n,l)>=p) return l;
    else if(noOfParathaInTime(arr,n,r)>=p) return r;
    else return -1;
    

}

// ANARC05B - The Double HeLiX
#include <bits/stdc++.h>
using namespace std;
int maxSumInHelix(int a[],int b[],int n,int m,int i,int j,int p,vector<int> &v1,vector<int> &v2,vector<vector<int>> &mem){
    if(i>=n || j>=m) return 0;
    if(p==0){
        if(mem[0][i]!=-1) return mem[0][i];
        if(v1[i]==-1){
            return mem[0][i]=(a[i]+maxSumInHelix(a,b,n,m,i+1,j,p,v1,v2,mem));
        }
        else{
            return mem[0][i]=max(a[i]+maxSumInHelix(a,b,n,m,i+1,j,p,v1,v2,mem),b[v1[i]]+maxSumInHelix(a,b,n,m,i,v1[i]+1,1,v1,v2,mem));
        }
    }
    else{
        if(mem[1][j]!=-1) return mem[1][j];
        if(v2[j]==-1){
            return mem[1][j]=(b[j]+maxSumInHelix(a,b,n,m,i,j+1,p,v1,v2,mem));
        }
        else{
            return mem[1][j]=max(b[j]+maxSumInHelix(a,b,n,m,i,j+1,p,v1,v2,mem),a[v2[j]]+maxSumInHelix(a,b,n,m,v2[j]+1,j,0,v1,v2,mem));
        }
    }
}

int doubleHelixMax(int a[], int b[],int n,int m){
    vector<int> v1(n,-1);
    vector<int> v2(m,-1);
    for(int i=0;i<n;i++){
        int l=0;
        int r=m-1;
        while (r-l>1)
        {
            int mid=(r-l)/2+l;
            if(b[mid]<a[i]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        if(b[l]==a[i]){
            v1[i]=l;
            v2[l]=i;
        }
        else if(b[r]==a[i]){
            v1[i]=r;
            v2[r]=i;
        }
        
    }
    vector<vector<int>> mem;
    vector<int> m1(n,-1);
    vector<int> m2(m,-1);
    mem.push_back(m1);
    mem.push_back(m2);
    // if(a[0]>b[0])
    int aa=maxSumInHelix(a,b,n,m,0,0,1,v1,v2,mem);
    mem.clear();
     mem.push_back(m1);
    mem.push_back(m2);
    int bb=maxSumInHelix(a,b,n,m,0,0,0,v1,v2,mem);
    // cout<<aa<<bb<<"\n";
   return max( aa,bb);

}

  // arr[]: Input Array
    // N : Size of the Array arr[]
    // Inversion count
 
void merge(long long  arr[],long long l,long long mid,long long r,long long &ct){
   
   vector<long long > v;
   int i=l;
   int j=mid;
   while (i<mid && j<r)
   {
       if(arr[i]>arr[j]){
           v.push_back(arr[j++]);
           ct+=(mid-i);
       }
       else{
           v.push_back(arr[i++]);
       }
   }
   while (i<mid)
   {
       v.push_back(arr[i++]);
   }
   while (j<r)
   {
       v.push_back(arr[j++]);
   }
   
   int k=l;
   for(auto &m:v){
       arr[k++]=m;
   }
   
   

}

void devideMerge(long long arr[],long long l,long long r,long long &ct){
    if(r-l==1) return;
    long long mid=l+(r-l)/2;
    // cout<<mid<<"\n";
    devideMerge(arr,l,mid,ct);
    devideMerge(arr,mid,r,ct);
    merge(arr,l,mid,r,ct);
    
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

// quick sort 

int  quickPartition(int a[],int i, int j){
    int p=i;
    int temp=a[p];
    int l=i;
    int r=i+1;
    while (r<j)
    {
       if(a[r]<temp){
           l++;
           swap(a[l],a[r]);
       }
       r++;
    }
    swap(a[p],a[l]);
    //  for(int i=0;i<8;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    return l;

    
}

void quickSortRec(int a[],int n,int i,int j){
    if(j-i<=1) return;
    int p=quickPartition(a,i,j);
    // int p=(j+i)/2;
    quickSortRec(a,n,i,p);
    quickSortRec(a,n,p+1,j);

}

void quickSort(int a[],int n){
    quickSortRec(a,n,0,n);
}


int main(){
    // int arr[]={0,1,2,3,5,5};
    // valueEqualToIndex(arr,6);
    // vector<long long> v={1,4,7,8,9};
    // for(int i=0;i<1000000;i++){
    //     v.push_back(i);
    // }
    // cout<<func("IDIDI");
    // cout<<search(v,0);
    // cout<<setprecision(3)<<sqrtBinarySearch(16,2);
    // cout<<maxMinPair(v,0,v.size()).first;
    // // cout<<maxMinPair(v,0,v.size()).second;
    // int t;
    // // cin>>t;
    // t=1;
    // while (true)
    // {

    //     int n,m;
    //     cin>>n;
    //     if(n==0) break;
    //     int a[n];
    //     for(int i=0;i<n;i++){
    //         cin>>a[i];
    //     }
    //     cin>>m;
    //     int b[m];
    //     for(int i=0;i<m;i++){
    //         cin>>b[i];
    //     }
    //     cout<<doubleHelixMax(a,b,n,m)<<"\n";
    //     // t--;
    // }
    // cout<<funcIsFit(v,3,3);  
    
    // vector<int> mem(2,-1);
    // vector<vector<int>> v={{0,6,60},{7,8,10}};
    // cout<<maxValueJob(v,0,0,mem);
    // int arr[]={5,10,30,20,15};
    // cout<<minTime(arr,5,3);
    int a[]={6,3,8,0,10,5,4,7};
    quickSort(a,8);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }

    
    return 0;
}