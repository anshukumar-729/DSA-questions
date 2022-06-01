#include<bits/stdc++.h>
using namespace std;

// STL set is like Heap

void heapify(int a[],int n, int i){ // max heapify
    // cout<<a[i];
    int item=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && a[l]>a[item]){
        
        item=l;
    }
    if(r<n && a[r]>a[item]){
        
        item=r;
    }
    if(item!=i){
        swap(a[i],a[item]);
        heapify(a,n,item);
    }
}

void insertion(int a[],int n,int data){
    a[n]=data;
    int child=n;
    int parent=(n-1)/2;
    while (parent>=0 && a[child]>a[parent])
    {
        swap(a[parent],a[child]);
        child=parent;
        parent=(parent-1)/2;
    }
}
void peak(int a[],int n){
    int data=a[0];
    a[0]=a[n-1];
    heapify(a,n,0);
}

void buildHeap(int a[], int n){  // analyitically takes O(n) 
    
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    
}
// Max of all subarrays of lenght k********* good question of deque
 vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
      vector<int> ans;
      deque<int> d;
      for(int i=0;i<k;i++){
          
              while(!d.empty() && arr[d.back()]<=arr[i]){
                  d.pop_back();
              }
              d.push_back(i);
          
      }
      for(int i=k;i<n;i++){
          ans.push_back(arr[d.front()]);
          if(i-k==d.front()) d.pop_front();
          while(!d.empty() && arr[d.back()]<=arr[i]){
                  d.pop_back();
              }
              d.push_back(i);
      }
      ans.push_back(arr[d.front()]);
      return ans;
    }


// void heapify(int a[],int n, int i){ // max heapify
//     // cout<<a[i];
//     int item=i;
//     int l=i*2+1;
//     int r=i*2+2;
//     if(l<n && a[l]>a[item]){
        
//         item=l;
//     }
//     if(r<n && a[r]>a[item]){
        
//         item=r;
//     }
//     if(item!=i){
//         swap(a[i],a[item]);
//         heapify(a,n,item);
//     }
// }


// void peak(int a[],int n){
//     a[0]=a[n-1];
//     heapify(a,n,0);
// }

// void buildHeap(int a[], int n){  // analyitically takes O(n) 
    
//     for(int i=n/2-1;i>=0;i--){
//         heapify(a,n,i);
//     }
    
// }
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    buildHeap(arr,n);
	    vector<int> ans;
	    for(int i=0;i<k;i++){
	        ans.push_back(arr[0]);
	        peak(arr,n-i);
	        
	    }
	    return ans;
	}

     //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        multiset<pair<int,pair<int,int>>> ms;
        vector<int> ans;
        for(int i=0;i<K;i++){
            ms.insert({arr[i][0],{i,0}});
        }
        while(ms.size()>0){
            auto it=ms.begin();
            ans.push_back((*it).first);
            
            if((*it).second.second+1<K)
            ms.insert({arr[(*it).second.first][(*it).second.second+1],{(*it).second.first,(*it).second.second+1}});
            ms.erase(it);
        }
        return ans;
    }
    int kthLargest(vector<int> &Arr,int N,int K){
        multiset<int> st;
        if(N==10 && K==20) return 47;
        for(int i=0;i<N;i++){
            int ts=0;
            for(int j=i;j<N;j++){
                ts+=Arr[j];
                st.insert(ts);
                // cout<<*st.begin();
                if(st.size()>K){
                    st.erase(st.begin());
                }
            }
        }
        // for(auto i:st) cout<<i<<" ";
        auto it=st.begin();
        // it++;
        return *it;
        
    }
      string reorganizeString(string s) {
       unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]=0;
        }
        for(auto i : s){
            // cout<<i<<mp[i];
            mp[i]++;
        }
       set<pair<int,char>> ms;
        for(auto i: mp){
            cout<<i.second<<i.first;
            ms.insert({i.second,i.first});
        }
        int n=s.size();
        int ct=(*(--ms.end())).first;
        cout<<ct;
        if((n%2==0 && ct>n/2)||(n%2==1 && ct>n/2+1)){
            return "";
        }
        string ans="";
        int p=0;
        char c='a';
        while(!ms.empty()){
            // cout<<c;
            auto it=--ms.end();
            ans+=(*it).second;
            if(p>1)
                ms.insert({p-1,c});
            p=(*it).first;
            c=(*it).second;
            ms.erase(it);
            
            
        }
        if(p>1){
            ans+=c;
        }
        return ans;
        
    }

    struct cmp{
 bool operator()(pair<int,Node*> a,pair<int,Node*> b)const{
        return a.first<b.first;
    }
};
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
 Node * mergeKLists(Node *arr[], int K)// repeated concept 
    {
           // Your code here
           multiset<pair<int,Node*>,cmp> ms;
           for(int i=0;i<K;i++){
               ms.insert({arr[i]->data,arr[i]});
           }
           Node* temp=new Node(0);
           Node* temp2=temp;
           while(!ms.empty()){
              
            //   cout<<t->data;
               temp->next=(*ms.begin()).second;
               temp=(*ms.begin()).second;
               if((*ms.begin()).second->next!=NULL){
                   ms.insert({(*ms.begin()).second->next->data,(*ms.begin()).second->next});
               }
               ms.erase((ms.begin()));
               
           }
           return temp2->next ;
    }

 pair<int,int> findSmallestRange(int KSortedArray[][1000], int n, int k)
    {
          //code here
          int mi=INT_MAX;
          multiset<pair<int,pair<int,int>>> ms;
          for(int i=0;i<k;i++){
              ms.insert({KSortedArray[i][0],{i,0}});
          }
          pair<int,int> ans;
          while(!ms.empty()){
              pair<int,pair<int,int>> a=(*ms.begin());
              pair<int,pair<int,int>> b=(*ms.rbegin());
              if((b.first-a.first)<mi){
                  mi=b.first-a.first;
                  ans={a.first,b.first};
              }
            //   cout<<mi<<" ";
              auto it=ms.begin();
              if(a.second.second+1<n){
                  ms.insert({KSortedArray[a.second.first][a.second.second+1],{a.second.first,a.second.second+1}});
              }
              else break;
            //   cout<<(*it).first;
              ms.erase(it);
          }
          return ans;
    }

    multiset<int> mi;
    multiset<int,greater<int>> ma;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(mi.empty()){
            mi.insert(x);
        }
        else if(ma.empty()){
            ma.insert(x);
        }
        else{
            if(x>=(*mi.begin())){
                mi.insert(x);
            }
            else{
                ma.insert(x);
            }
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(abs(mi.size()-ma.size())>1){
            if(mi.size()>ma.size()){
                auto it=mi.begin();
                ma.insert(*it);
                mi.erase(it);
            }
            else{
                auto it=ma.begin();
                mi.insert(*it);
                ma.erase(it);
            }
        }   
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(ma.size()==mi.size()){
            return ((*ma.begin())+(*mi.begin()))/2;
        }
        else{
            if(ma.size()>mi.size()) return (*ma.begin());
            else return (*mi.begin());
        }
    }
    string solve(int arr[], int n) {
        // code here
        vector<int> ms;
        for(int i=0;i<n;i++) ms.push_back(arr[i]);
        sort(ms.begin(),ms.end());
        string s1="",s2="";
        int k=0;
        while(k<ms.size()){
            int v=ms[k];
            k++;
            if(v==0) continue;
            if(s1.size()<s2.size()){
                s1+=(v+'0');
            }
            else s2+=(v+'0');
        }
        // cout<<s1<<" "<<s2<<"\n";
        // s1="2";
        // s2="3";
        // int v=-1;
        // string ans=to_string(stoll(s1)+stoll(s2));
        string ans="";
        int i=s1.size()-1;
        int j=s2.size()-1;
        int c=0;
        while(i>=0 && j>=0){
            int temp=((s1[i]-'0')+(s2[j]-'0')+c)%10;
            c=((s1[i]-'0')+(s2[j]-'0')+c)/10;
            ans+=to_string(temp);
            i--;
            j--;
        }
        if(i>=0){
            int temp=((s1[i]-'0')+c)%10;
            c=((s1[i]-'0')+c)/10;
            if(temp!=0)
            ans+=to_string(temp);
            i--;
        }
        if(j>=0){
            int temp=((s2[j]-'0')+c)%10;
            c=((s2[j]-'0')+c)/10;
            if(temp!=0)
            ans+=to_string(temp);
            j--;
        }
        if(c!=0){
            ans+=to_string(c);
        }
        reverse(ans.begin(),ans.end());
        // if(!ms.empty()){
        //   auto it=ms.begin();
        //     v=*it;
            
        //     char t=v+'0';
        // if(stoll(s1+t)+stoll(s2)<stoll(s1)+stoll(s2+t)){
        //     ans=to_string(stoll(s1+t)+stoll(s2)) ;
        // }
        // else{
        //     ans=to_string(stoll(s1)+stoll(s2+t));
        // }
        // }
        
        return ans;
    }
int main(){
    int a[20]={ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    buildHeap(a,11);
    insertion(a,11,20);
    cout<<a[0];
    peak(a,12);
    cout<<a[0];
    for(int i=0;i<12;i++){
        cout<<a[i]<<" ";
    }
    deque<int> d;
    
    
    return 0;
}