#include<bits/stdc++.h>
using namespace std;


    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp (pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int p=-1;
        int ct=0;
        for(int i=0;i<n;i++){
            if(p<vp[i].first){
                ct++;
                 p=vp[i].second;
            }
           
        }
        return ct;
    }

    // Job Sequencing Problem 
     //Function to find the maximum profit and the number of jobs done.
  struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
       unordered_map<int,multiset<int>> mp;
       int ma=INT_MIN;
       for(int i=0;i<n;i++){
           ma=max(ma,arr[i].dead);
           mp[arr[i].dead].insert(arr[i].profit);
       }
       int ct=0;
       int p=0;
    //   cout<<ma;
       for(int i=ma;i>=1;i--){
           int ma2=INT_MIN;
           multiset<int>::iterator it2;
           int k;
           for(int j=i;j<=ma ;j++){
               if(mp.find(j)!=mp.end()){
                    if(mp[j].size()!=0){
                        auto it =mp[j].end();
                        it--;
                        if(ma2<*it){
                            ma2=*it;
                            it2=it;
                            k=j;
                        }
                    }   
               }
           }
           if(ma2!=INT_MIN){
               mp[k].erase(it2);
               ct++;
               p+=ma2;
           }
        //   cout<<p<<" ";
       }
       return {ct,p};
    } 
// Water Connection Problem 
 vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        unordered_map<int,int> mp,mp2;
        for(int i=0;i<p;i++){
            mp[a[i]]=i;
        }
        for(int i=0;i<p;i++){
            mp2[b[i]]=i;
        }
        int i=0;
        vector<int> v2;
        for(int i=1;i<=n;i++){
            if(mp2.find(i)==mp2.end()){
                v2.push_back(i);
            }
        }
        vector<vector<int>> ans;
        i=0;
        while(i<v2.size()){
            
            int mi=INT_MAX;
            int k=v2[i];
            while(mp.find(k)!=mp.end()){
                mi=min(mi,d[mp[k]]);
                k=b[mp[k]];
                
            }
            if(k!=v2[i]){
                ans.push_back({v2[i],k,mi});
                // amp[k]= {i,mi};   
            }
            i++;
        }
       
        return ans;
    }

    // Fractional Knapsack 
struct Item{
    int value;
    int weight;
};
     static bool cmp(Item a,Item b){
        return ((a.value/(float)a.weight)>(b.value/(float)b.weight));
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    //   sort(arr,arr+n,cmp);
    // vector<Item> v;
    // for(int i=0;i<n;i++){
    //     v.push_back(arr[i]);
    // }
    // struct cmp;
    sort(arr,arr+n,cmp);
      double p=0;
      int i=0;
      W=(double)W;
      while(W>0 && i<n){
          if(arr[i].weight<=W){
              p+=arr[i].value;
              W-=arr[i].weight;
          }
          else{
            //   cout<<p;
              p+=(arr[i].value*(W/(float)arr[i].weight));
            //   cout<<p;
              break;
          }
          i++;
      }
      return p;
    }

     string chooseandswap(string a){
        // Code Here
        unordered_set<char> st;
        char d='z'+1;
        pair<char,int> c;
        c={'0',INT_MAX};
        int f=0;
        stack<pair<char,int>> s;
        for(int i=0;i<a.size();i++){
            if(s.empty()){
                s.push({a[i],i});
                st.insert(a[i]);
            }
            else{
                if(st.find(a[i])==st.end()){
                    st.insert(a[i]);
                    while(!s.empty() && s.top().first>a[i]){
                      if(c.second>s.top().second){
                         c=s.top();
                      }
                        d=min(d,a[i]);
                        s.pop();
                    }
                   
                    s.push({a[i],i});
                }
            }
            
        }
        // cout<<c.first<<d<<"\n";
        for(int i=0;i<a.size();i++){
            if(a[i]==c.first){
                a[i]='0';
            }
           
        }
         for(int i=0;i<a.size();i++){
            if(a[i]==d){
                a[i]=c.first;
            }
           
        }
         for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                a[i]=d;
            }
           
        }
        return a;
    }
     //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second) return a.first>b.first;
        return a.second<b.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int ct=0;
    	vector<pair<int,int>> vp;
    	for(int i=0;i<n;i++)
    	{
    	    vp.push_back({arr[i],dep[i]});
    	}
    	sort(vp.begin(),vp.end(),cmp);
    	multiset<int> v;
    	v.insert(INT_MIN);
    	v.insert(INT_MAX);
    // 	for(int i=0;i<n;i++){
    // 	    cout<<vp[i].second;
    // 	}
    	int k=0;
    	for(int i=0;i<n;i++){
    	    auto it=v.lower_bound(vp[i].first);
    	   // cout<<*it<<" ";
    	    it--;
    	    if((*it)==INT_MIN){
    	        v.insert(vp[i].second);
    	    }
    	    else{
    	        v.erase(it);
    	        v.insert(vp[i].second);
    	    }
    	   
    	}
    	return v.size()-2;
    }

       static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
        
    }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({price[i],i+1});
            
        }
        sort(vp.begin(),vp.end(),cmp);
        int ct=0;
        for(int i=0;i<n;i++){
            if(vp[i].first*vp[i].second<=k){
                k-=vp[i].first*vp[i].second;
                ct+=vp[i].second;
            }
            else{
                ct+=(k/vp[i].first);
                break;
            }
        }
        return ct;
    }

     int minimumCostOfBreaking(vector<int> X, vector<int>Y, int M, int N){
        //Write your code here
        int s=0;
        // cout<<N<<M;
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        int i=0;
        int j=0;
        int p=1;
        int q=1;
       
        while(i<M && j<N){
            if(X[i]<Y[j]){
                // cout<<Y[j]<<q;
                s+=Y[j]*q;
                j++;
                p++;
                
            }
            else{
                s+=X[i]*p;
                // cout<<X[i]<<p;
                i++;
                q++;   
            }
        }
        while(i<M){
            s+=X[i]*p;
            i++;
            q++;
        }
        while(j<N){
            s+=Y[j]*q;
            j++;
            p++;
        }
        return s;
    }

    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int> vc(C,-1);
        
        int ct=0;
        for(int i=0;i<N;i++){
            int f=0;
               for(int j=0;j<C;j++){
                   if(vc[j]==pages[i]){
                       f=1;
                       for(int k=j;k>0;k--){
                           swap(vc[k],vc[k-1]);
                       }
                   }
               }
               if(f==0){
                   ct++;
                    for(int k=C-1;k>0;k--){
                           swap(vc[k],vc[k-1]);
                       }
                       vc[0]=pages[i];
               }
        }
        return ct;
    }
// K Centers Problem 
     int rec(int n,int i,int k,vector<vector<int>> & mat,vector<int> v){
        if(i>=n){
            if(k!=0) return INT_MAX;
            int ma=INT_MIN;
            for(int i=0;i<n;i++){
                int mi=INT_MAX;
                for(int j=0;j<v.size();j++){
                    mi=min(mi,mat[i][v[j]]);
                }
                ma=max(ma,mi);
            }
            return ma;
        }
        if(k>0){
            v.push_back(i);
            int a=rec(n,i+1,k-1,mat,v);
            v.pop_back();
            int b=rec(n,i+1,k,mat,v);
            // cout<<a<<" "<<b<<"\n";
            return min(a,b);
        }
        else{
           return  rec(n,i+1,k,mat,v);
        }
    }
    
    int selectKcities(int n, int k, vector<vector<int>>& mat){
        
        return rec(n,0,k,mat,{});
    }

// The task is to find the smallest number with given sum of digits as S and number of digits as D.
     string smallestNumber(int S, int D){
        // code here 
        string ans="";
        S--;
        while(S>0){
            int r;
            if(S>=9){
                r=9;
            }
            else r=S;
            ans+=r+'0';
            S-=9;
        }
        while(ans.size()<D){
            ans+='0';
        }
        if(ans.size()>D || ans[ans.size()-1]=='9'){
            return "-1";
        }
        else{
            reverse(ans.begin(),ans.end());
            ans[0]++;
           
        }
         return ans;
    }
// Find Maximum Equal sum of Three Stacks 
int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int i=0,j=0,k=0;
        int s1=0,s2=0,s3=0;
        for(int i=0;i<N1;i++) s1+=S1[i];
        for(int i=0;i<N2;i++) s2+=S2[i];
        for(int i=0;i<N3;i++) s3+=S3[i];
        while(i<N1 && j<N2 && k<N3){
            // cout<<s1<<","<<s2<<","<<s3<<" ";
            if(s1==s2 && s1==s3){
                return s1;
            }
            if(s1>=s2 && s1>=s3){
                s1-=S1[i];
                i++;
            }
            else if(s2>=s1 && s2>=s3){
                s2-=S2[j];
                j++;
            }
            else{
                s3-=S3[k];
                k++;
            }
        }
        // cout<<"-1";
        return 0;
    }
int main(){


    return 0;
}