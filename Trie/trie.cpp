#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie* t[26];
    bool f;
    int ct;

    Trie(){
        for (int i = 0; i < 26; i++)
        {
            t[i]=NULL;
        }
        f=false;
        ct=0;
        
    }

    
};
Trie* root=new Trie();

void insertTrie(string s){
    Trie* temp=root;
    // cout<<temp;
    // for(int i=0;i<26;i++){
    //     cout<<(temp->t[i]==NULL);
    // }
    for(int i=0;i<s.size();i++){
        if(temp->t[s[i]-'a']==NULL){
            temp->t[s[i]-'a']=new Trie();
            if(i==s.size()-1){
                temp->t[s[i]-'a']->f=true;
            }
            temp=temp->t[s[i]-'a'];
        }else{
            if(i==s.size()-1){
                temp->t[s[i]-'a']->f=true;
            }
            temp=temp->t[s[i]-'a'];
        }
    }
}
    bool searchTrie(string s){
        Trie* temp=root;
        int i;
        for(i=0;i<s.size();i++){
            if(temp->t[s[i]-'a']!=NULL){
                temp=temp->t[s[i]-'a'];
            }
            else break;
        }
        if(i==s.size() && temp->f==true){
            return true;
        }
        return false;
    }
bool isPrefix(string s){
    Trie* temp=root;
    int i;
    for(i=0;i<s.size();i++){
        if(temp->t[s[i]-'a']!=NULL){
            temp=temp->t[s[i]-'a'];
        }else break;
    }
    if(i==s.size() ){
        return true;
    }
    return false;
}


// class Trie{
//     public:
//     Trie* t[26];
//     bool f;
//     int ct;

//     Trie(){
//         for (int i = 0; i < 26; i++)
//         {
//             t[i]=NULL;
//         }
//         f=false;
//         ct=0;
        
//     }

    
// };
// Trie* root;
void init(){
    root=new Trie();
}

// void insertTrie(string s){
//     Trie* temp=root;
//     // cout<<temp;
//     // for(int i=0;i<26;i++){
//     //     cout<<(temp->t[i]==NULL);
//     // }
//     for(int i=0;i<s.size();i++){
//         if(temp->t[s[i]-'a']==NULL){
//             temp->t[s[i]-'a']=new Trie();
//             if(i==s.size()-1){
//                 temp->t[s[i]-'a']->f=true;
//             }
//             temp=temp->t[s[i]-'a'];
//         }else{
            
//             temp=temp->t[s[i]-'a'];
            
//         }
//         temp->ct++;
//     }
// }
vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        init();
        for(int i=0;i<n;i++){
            insertTrie(arr[i]);
        }
        vector<string> ans(n,"");
        for(int i=0;i<n;i++){
            Trie* temp=root;
            
            for(auto j:arr[i]){
                //  cout<<j<<temp->ct;
                if(temp->ct==1 ){
                    
                    break;
                }
                else{
                    ans[i]+=j;
                    temp=temp->t[j-'a'];
                }
            }
        }
        return ans;
    }


 bool rec(string s,vector<int> &mem){
     if(s.size()==0) return 1;
     if(mem[s.size()]!=-1) return mem[s.size()];
     string t="";
     bool ans=0;
     for(int i=0;i<s.size();i++){
         t+=s[i];
         
         if(searchTrie(t)){
             ans=ans|rec(s.substr(i+1),mem);
         }
        
     }
     return mem[s.size()]=ans;
 }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        init();
        for(auto i:B){
            insertTrie(i);
        }
        vector<int> mem(A.size()+1,-1);
        bool a= rec(A,mem);
    //   for(auto i:mem){
    //       cout<<i<<" ";
    //   }
       return a;
        
    }

// Phone directory 
    Trie* findPrefix(string s){
    Trie* temp=root;
    int i;
    for(i=0;i<s.size();i++){
        if(temp->t[s[i]-'a']!=NULL){
            temp=temp->t[s[i]-'a'];
        }else break;
    }
    if(i==s.size() ){
        return temp;
    }
    return NULL;
}

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        init();
        for(int i=0;i<n;i++){
            insertTrie(contact[i]);
        }
        string t="";
        vector<vector<string>> aa;
        for(int i=0;i<s.size();i++){
            t+=s[i];
            Trie* ans=findPrefix(t);
            stack<pair<Trie*,string>> q;
            q.push({ans,t});
            vector<string> v;
            while(!q.empty()){
                Trie* t=q.top().first;
                string s2=q.top().second;
                q.pop();
                if(t==NULL ) continue;
              if(t->f==true){
                //   cout<<s2<<" ";
                v.push_back(s2);
              }
              stack<pair<Trie*,string>> temp;
                for(int i=0;i<26;i++){
                    if(t->t[i]!=NULL){
                    char c=('a'+i);
                    temp.push({t->t[i],s2+c});
                    }
                }
                while(!temp.empty()){
                    q.push(temp.top());
                    temp.pop();
                }
            }
            // cout<<"\n";
            if(v.size()==0) v.push_back("0");
            aa.push_back(v);
        }
        return aa;   
    }

int main(){
    insertTrie("apple");
    insertTrie("appss");
    cout<<searchTrie("appss");
    cout<<isPrefix("appl");
    return 0;
}