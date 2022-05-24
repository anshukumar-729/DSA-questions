#include <bits/stdc++.h> 
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }

};

 //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* temp=q.front();
           
            q.pop();
             if(temp==NULL) continue;
            ans.push_back(temp->data);
            q.push(temp->left);
            q.push(temp->right);
        }
        return ans;
    }


    vector<int> reverseLevelOrder(Node *root)
    {
        vector<int> ans;
         queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
           
            q.pop();
             if(temp==NULL) continue;
            ans.push_back(temp->data);
            q.push(temp->right);
            q.push(temp->left);

        }
        reverse(ans.begin(),ans.end());
        return ans;

    }

    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        queue<pair<Node*,int>> qp;
        qp.push({node,1});
        int ma=-1;
        while (!qp.empty())
        {
            Node* temp=qp.front().first;
            int size=qp.front().second;
            qp.pop();
            if(temp==NULL) continue;
            ma=max(ma,size);
            qp.push({temp->left,size+1});
            qp.push({temp->right,size+1});

        }
        return ma;
        
    }

    // Function to return the diameter of a Binary Tree.

    int traverseRec(Node* node,int &ma){
        if(node==NULL) return 0;
        int a=traverseRec(node->left,ma);
        int b=traverseRec(node->right,ma);
        ma=max(ma,1+a+b);
        return 1+max(a,b);
    }
int diameter(struct Node* root) {
  int ma=-1;
  int h=traverseRec(root,ma);
//   cout<<h<<ma;
return ma;
}

// inorder recursively;
void inOrder(Node* node,vector<int> &v){
		if(node==NULL) return;
		inOrder(node->left,v);
		v.push_back(node->data);
		inOrder(node->right,v);
	}

	vector<int> findInorderTraversal(Node* root)
	{
		vector<int> v;
		inOrder(root,v);
		return v;
	}

    	vector<int> findInorderTraversalIteratively(Node* root) // nice method***********
	{
		vector<int> v;
		std::stack<Node*>st ;
		while(root!=NULL || !st.empty()){
			if(root!=NULL){
				st.push(root);
				root=root->left;
			}
			else{
				Node* temp=st.top();
				st.pop();
				v.push_back(temp->data);
				root=temp->right;
				
			}
		}
		return v;
	}

// preOrder recursively
    	void preOrder(Node* node,vector<int> &v){
		if(node==NULL) return;
			v.push_back(node->data);
		preOrder(node->left,v);
	
		preOrder(node->right,v);
	}

	vector<int> findPreorderTraversal(Node* root)
	{
		vector<int> v;
		preOrder(root,v);
		return v;
	}

    vector<int> findPreorderTraversalIteratively(Node* root){
        vector<int> v;
        stack<Node*> st;
        while (!st.empty()|| root!=NULL)
        {
            if(root!=NULL){
                v.push_back(root->data);
                st.push(root);
                root=root->left;
            }
            else{
                Node* temp=st.top();
                st.pop();
                root=temp->right;
            }
        }
        return v;
        
    }

// postOrder recursively
    	void postOrder(Node* node,vector<int> &v){
		if(node==NULL) return;
			
		postOrder(node->left,v);
	
		postOrder(node->right,v);
        v.push_back(node->data);
	}

	vector<int> findpostOrderTraversal(Node* root)
	{
		vector<int> v;
		postOrder(root,v);
		return v;
	}

    vector<int> findPostorderTraversalIteratively(Node* root){ //********little different
        vector<int> v;
        stack<Node*> st;
        stack<int> ans;
        if(root==NULL) return v;
        st.push(root);
        while (!st.empty())
        {

            Node* temp=st.top();
            st.pop();
            ans.push(temp->data);
           if(temp->left!=NULL) st.push(temp->left);
           if(temp->right!=NULL) st.push(temp->right);


        }
                   while (!ans.empty())
           {
               int temp=ans.top();
               ans.pop();
               v.push_back(temp);
           }
           
       
        return v;
        
    }


//Function to return a list containing elements of left view of the binary tree.

vector<int> leftView(Node *root)
{
    vector<int> v;
    unordered_set<int> st;
   queue<pair<Node*,int>> q;
   q.push({root,1});
   while(!q.empty()){
       Node* temp=q.front().first;
       int s=q.front().second;
        q.pop();
       if(temp==NULL) continue;
       if(st.find(s)==st.end()){
           v.push_back(temp->data);
           st.insert(s);
       }
      q.push({temp->left,s+1});
      q.push({temp->right,s+1});
       
       
       
   }
    return v;
}

vector <int> bottomView(Node *root) {
        vector<int> v;
    map<int,Node*> mp;
   queue<pair<Node*,int>> q;
   q.push({root,0});
   while(!q.empty()){
       Node* temp=q.front().first;
       int s=q.front().second;
        q.pop();
       if(temp==NULL) continue;
       mp[s]=temp;
      q.push({temp->left,s-1});
      q.push({temp->right,s+1});
       
       
       
   }
   for(auto &i:mp){
       v.push_back(i.second->data);
   }
    return v;
    }

  vector<int> rightView(Node *root)
    {
       vector<int> v;
       queue<pair<Node*,int>> q;
       q.push({root,1});
       unordered_set<int> st;
       while(!q.empty()){
           Node* temp=q.front().first;
           int s=q.front().second;
           q.pop();
           if(temp==NULL) continue;
           if(st.find(s)==st.end()){
               v.push_back(temp->data);
               st.insert(s);
               
           }
           q.push({temp->right,s+1});
           q.push({temp->left,s+1});
           
           
       }
       return v;
    }

     //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void inOrder(Node* node,int s,int h,unordered_map<int,pair<Node*,int>> &mp,unordered_map<Node*,int> &mp2){
		if(node==NULL) return;
		inOrder(node->left,s-1,h+1,mp,mp2);
	    mp2[node]=h;
		if(s<=0){
		    if(mp.find(s)==mp.end())
		    mp[s]={node,0};
		    else{
		        int h2=mp2[mp[s].first];
		        if(h<h2){
		            mp[s]={node,0};
		        }
		    }
		}
		else{
		    if(mp.find(s)==mp.end())
		    mp[s]={node,0};
		    else{
		        int h2=mp2[mp[s].first];
		        if(h<h2){
		            mp[s]={node,0};
		        }
		    }
		}
		inOrder(node->right,s+1,h+1,mp,mp2);
	}
	void inOrder(Node* node,int s,unordered_map<int,pair<Node*,int>> &mp,vector<pair<pair<int,int>,int>>&v, unordered_map<Node*,int> &mp2){
		if(node==NULL) return;
		inOrder(node->left,s-1,mp,v,mp2);
	
		if(mp[s].second==0){
		    v.push_back({{s,mp2[mp[s].first]},mp[s].first->data});
		    mp[s].second=1;
		}
		inOrder(node->right,s+1,mp,v,mp2);
	}
	static bool cmp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
	    return a.first.first<b.first.first;   
	}
    vector<int> topView(Node *root)  // One easy approach will be level traversal and setting the first untracked witdh
    {
       vector<pair<pair<int,int>,int>>v;
       int s=0;
       unordered_map<int,pair<Node*,int>> mp;
       unordered_map<Node*,int> mp2;
       inOrder(root,s,1,mp,mp2);
       inOrder(root,0,mp,v,mp2);
       sort(v.begin(),v.end(),cmp);
       
       vector<int> ans;
       for(auto &i:v){
           ans.push_back(i.second);
       }
       return ans;
    }


vector<int> diagonal(Node *root) // diagonal traversal
{
   // your code here
  queue<Node*> q;
  vector<int> ans;
//   q.push(root);
  while(!q.empty()|| root!=NULL){
      if(root!=NULL){
          ans.push_back(root->data);
           q.push(root->left);
          root=root->right;
         
      }
      else{
          Node* temp=q.front();
      q.pop();
      if(temp==NULL) continue;
      root=temp;
      }
      
      
  }
  
   return ans;
}


 vector <int> boundary(Node *root) //******** stupid question*******
    {
        //Your code here
        vector<int> v;
        Node* temp=root;
        v.push_back(temp->data);
        temp=temp->left;
        
        while(temp!=NULL){
            v.push_back(temp->data);
            if(temp->left!=NULL) {
               
                temp=temp->left;
            }
            else if(temp->right!=NULL){
                
                temp=temp->right;   
            }
            else break;
        }
        // return v;
        if(v.size()!=1){
            v.pop_back();
        }
        // return v;
        int n=v.size();
        temp=root;
        stack<Node*> st;
        while (!st.empty()|| root!=NULL)
        {
            if(root!=NULL){
               if(root->left==NULL && root->right==NULL && root!=temp) v.push_back(root->data);
                st.push(root);
                root=root->left;
            }
            else{
                Node* temp=st.top();
                st.pop();
                root=temp->right;
            }
        }
      
        if(v.size()-n!=0){
        // v.pop_back();
        }
        // return v;
         
        vector<int> v2;
        temp=temp->right;
        while(temp!=NULL){
           
            if(temp->right!=NULL) {
                v2.push_back(temp->data);
                temp=temp->right;
            }
            else if(temp->left!=NULL){
                 v2.push_back(temp->data);
                temp=temp->left;   
            }
            else break;
        }
        // if(v2.size()!=0)
        // v2.pop_back();
        // return v2;
        reverse(v2.begin(),v2.end());
        
        for(auto i:v2){
            v.push_back(i);
        }
        return v;
    }


// Construct a Binary Tree from String with bracket representation 
// Input: “4(2(3)(1))(6(5))”
// Output: 4 2 3 1 6 5

Node* bracketToBinary(string s){
    stack<Node*> st;
    int f=0;
    int l=1;
    unordered_set<Node*> ss;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            
            Node* a=st.top();
            st.pop();
            Node* b=st.top();
           if(ss.find(b)==ss.end()){
               b->left=a;
               ss.insert(b);
           }
           else{
               b->right=a;
           }

        }
        else if(s[i]!='('){
            Node* temp=new Node((s[i]-'0'));
            temp->left=NULL;
            temp->right=NULL;
            st.push(temp);
        }

    }
    vector<int> v=findPreorderTraversal(st.top());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    return st.top();
}

 //Function to convert binary tree to doubly linked list and return it.
   void btoDLLrec(Node* root,Node* &pre){
        if(!root) return;
        btoDLLrec(root->left,pre);
        // if(pre)
        pre->right=root;
        root->left=pre;
        pre=root;
        btoDLLrec(root->right,pre);
        
    }
    Node * bToDLL(Node *root)
    {
        Node* temp=new Node(0);
         Node* temp2=temp;
        btoDLLrec(root,temp);
        temp2=temp2->right;
        temp2->left=NULL;
        return temp2;
        // your code here
    }

    // Construct Tree from Inorder & Preorder 

     Node* make(int in[],int pre[],int i1,int j1,int i2,int j2){
       if(j2-i2<=0) return NULL;
       if(j2-i2==1) {
           Node* temp=new Node(pre[i2]);
           return temp;
       }
       int k;
       for(int i=i1;i<j1;i++){
           if(in[i]==pre[i2]){
               k=i;
               break;
           }
       }
       Node* temp=new Node(pre[i2]);
       
       temp->left=make(in,pre,i1,k,i2+1,i2+(k-i1)+1);
       temp->right=make(in,pre,k+1,j1,i2+(k-i1)+1,j2);
       return temp;
       
   }
   
   
    Node* buildTree(int in[],int pre[], int n)
    {
        return make(in,pre,0,n,0,n);
    }
    
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        n=e*2;
        map<int,stack<int>>mp;
        for(int i=0;i<n-1;i+=2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0;i<n;i+=2){
            // cout<<B[i];
            if(mp[B[i]].empty()) return 0;
            if(mp[B[i]].top()==B[i+1]){
                mp[B[i]].pop();
            }
            else return 0;
        }
        for(auto i:mp){
            if(!i.second.empty()) return 0;
        }
        return 1;
        
    }

     //Function to return the maximum sum of non-adjacent nodes.
    
    void traverse(Node* root,map<pair<Node*,int>,int> &mp){
        if(!root) return ;
        mp[{root,0}]=-1;
        mp[{root,1}]=-1;
        traverse(root->left,mp);
        traverse(root->right,mp);
    }
    int isChoose(Node* root,int f,map<pair<Node*,int>,int> &mem){
        if(!root) return 0;
        if(mem[{root,f}]!=-1) return mem[{root,f}];
        if(f==0){
            // cout<<root->data;
            return mem[{root,f}]=isChoose(root->left,1,mem)+isChoose(root->right,1,mem);
        }
        else{
            // cout<<root->data;
            return mem[{root,f}]=max((root->data+isChoose(root->left,0,mem)+isChoose(root->right,0,mem)),(isChoose(root->left,1,mem)+isChoose(root->right,1,mem)));
        }
        
    }
    int getMaxSum(Node *root) 
    {
        map<pair<Node*,int>,int>mp;
        traverse(root,mp);
        return isChoose(root,1,mp);
    }

     //Function to return the lowest common ancestor in a Binary Tree.(LCA)
     pair<Node*,int> lcarec(Node* root,int n1,int n2){
         if(root==NULL) return {NULL,0};
           pair<Node*,int>a=lcarec(root->left,n1,n2);
         pair<Node*,int>b=lcarec(root->right,n1,n2);
         if(a.second==2) return {a.first,2};
         if(b.second==2) return {b.first,2};
         if(a.second==1 && (root->data==n1 || root->data==n2)) return {root,2};
         if(b.second==1 && (root->data==n1 || root->data==n2)) return {root,2};
       if(a.first){
           if(b.first){
            //   cout<<"here";
            //   cout<<a.first->data<<b.first->data;
               if((a.first->data==n1 && b.first->data==n2) || (a.first->data==n2 && b.first->data==n1)){
                //   cout<<"rere";
                   return {root,2};
               }
           }
       }
       if(a.first){
           if(a.first->data==n1 || a.first->data==n2){
               if(root->data==n1 || root->data==n2){
                   return {root,2};
               }
               else return {a.first,1};
           }
       }
       if(b.first){
           if(b.first->data==n1 || b.first->data==n2){
               if(root->data==n1 || root->data==n2){
                   return {root,2};
               }
               else return {b.first,1};
           }
       }
       if(root->data==n1 || root->data==n2) return{root,1};
       return {NULL,0};
     }
     
     
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return lcarec(root,n1,n2).first;  
        return root;
    }

    /* Should return minimum distance between a and b
    in a tree with given root*/
  
    pair<int,int> min(Node* root,int a,vector<Node*> &v){
        if(!root) return {0,0};
        if(root->data==a){
            v.push_back(root);
            return {1,1};
            
        }
        pair<int,int> c=min(root->left,a,v);
        if(c.second==1){
             v.push_back(root);
             return {c.first+1,1};
         } 
         pair<int,int> b=min(root->right,a,v);
         
         if(b.second==1){ 
             v.push_back(root);
             return {b.first+1,1};
         }
         return {0,0};
    }
     
    int findDist(Node* root, int a, int b) {
        vector<Node*> v;
        min(root,a,v);
        vector<Node*> v2;
        min(root,b,v2);
        reverse(v.begin(),v.end());
        reverse(v2.begin(),v2.end());
        int i=0;
        int j=0;
        // for(auto i:v) cout<<i->data<<" ";
        // for(auto j:v2) cout<<j->data<<" ";
        while(i<v.size() && j<v2.size()){
            if(v[i]==v2[j]){
                i++;
                j++;
                // cout<<i<<j;
                }
            else break;
        }
        // cout<<i<<j;
        return v.size()+v2.size()-2*i;
        
    }

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

string inOrderDuplicateshash(Node* root,map<Node* ,string> &mp){ // good hash function for tree
    if(!root) return "N";
    string a= inOrderDuplicateshash(root->left,mp);
    string b= inOrderDuplicateshash(root->right,mp);
    string ans="";
    ans+=(root->data+'0');
    ans+='(';
    ans+=a+b;
    ans+=')';
    
    
    mp[root]=ans;
    return ans;
     
}

void inOrderDuplicates(Node* root,map<Node*,string> mp,map<string,int> &mp2){
    if(!root) return;
 inOrderDuplicates(root->left,mp,mp2);
 if(mp2.find(mp[root])==mp2.end()){
     mp2[mp[root]]=0;
 }
 else if(mp2[mp[root]]==0) {
     
     mp2[mp[root]]++;
 }
 inOrderDuplicates(root->right,mp,mp2);
}

void preOrderR(Node* root,vector<Node*> &ans){
    if(!root) return;
    ans.push_back(root);
    preOrderR(root->right,ans);
    preOrderR(root->left,ans);
}
    vector<Node*> printAllDups(Node* root)
{
    // Code here
  map<Node*,string> mp;
  inOrderDuplicateshash(root,mp);
  map<string,int> mp2;
  vector<Node*> ans;
  ans.clear();
//   for(auto i:mp){
//       cout<<i.first->data<<" "<<i.second<<"\n";
//   }
  inOrderDuplicates(root,mp,mp2);
  preOrderR(root,ans);
  vector<Node*> v;
  v.clear();
  reverse(ans.begin(),ans.end());
  for(auto i:ans){
      if(mp2[mp[i]]==1){
          mp2[mp[i]]=0;
            v.push_back(i);   
      }
  }
  return v;
  
}
// Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL && root2==NULL) return 1;
        if(root1==NULL && root2!=NULL ) return 0;
        if(root2==NULL && root1!=NULL) return 0;
        if(root1->data!=root2->data) return 0;
        return (isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right)||isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left) );
   
    }
int main(){
    // bracketToBinary("4(2(3)(1))(6(5))");
    // int A[]={1,2,1,3,2,4,2,5,5,6,6,7,6,9};
    // int B[]={1,3,1,2,2,5,2,4,5,6,6,9,6,7};
    // cout<<checkMirrorTree(7,7,A,B);
    Node* root=new Node(5);
    Node* root1=new Node(1);
    Node* root2=new Node(9);
    Node* root3=new Node(4);
    Node* root4=new Node(7);
    root->left=root1;
    root->right=root2;
    root1->right=root3;
    root2->left=root4;
    
    

    cout<<lcarec(root,4,9).first->data;
    return 0;
}