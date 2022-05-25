#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    int key;
    int data;

    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int val;
    int key;
    int data;
    Node* next;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

// 450. Delete Node in a BST

 pair<TreeNode*,int> predecessorpre(TreeNode* root){
        if(root->left->right==NULL ) return {root,0};
        root=root->left;
        while(root->right->right!=NULL) root=root->right;
        return {root,1};
    }
     pair<TreeNode*,int> successorpre(TreeNode* root){
        if(root->right->left==NULL ) return {root,1};
        root=root->right;
        while(root->left->left!=NULL) root=root->left;
        return {root,0};
    }
    void deleting(TreeNode* pr,int p){
        if(p) pr->right=NULL;
        else pr->left=NULL;
        
    }
    void rec(TreeNode* pr,int p, int key){
        cout<<pr->val<<" "<<p<<"\n";
        if(p){
            if(pr->right->left==NULL && pr->right->right==NULL){
                deleting(pr,p);
            }
            else if(pr->right->left==NULL){
                pr->right=pr->right->right;
            }
            else if(pr->right->right==NULL){
                pr->right=pr->right->left;
            }
            else {
                pair<TreeNode*,int> p1=predecessorpre(pr->right);
                cout<<p1.first->val<<p1.second;
                if(p1.second){
                    swap(p1.first->right->val,pr->right->val);
                    rec(p1.first,p1.second,key);
                }
                else{
                     swap(p1.first->left->val,pr->right->val);
                    rec(p1.first,p1.second,key);
                }
            }
        }
        else{
            if(pr->left->left==NULL && pr->left->right==NULL){
                deleting(pr,p);
            }
            else if(pr->left->left==NULL){
                pr->left=pr->left->right;
            }
            else if(pr->left->right==NULL){
                pr->left=pr->left->left;
            }
            else {
                pair<TreeNode*,int> p1=predecessorpre(pr->left);
                cout<<p1.first->val<<p1.second;
                if(p1.second){
                    swap(p1.first->right->val,pr->left->val);
                    rec(p1.first,p1.second,key);
                }
                else{
                  swap(p1.first->left->val,pr->left->val);
                    rec(p1.first,p1.second,key);   
                }
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            TreeNode* temp=new TreeNode();
            temp->left=root;
            rec(temp,0,key);
            return temp->left;
        }
        else{
        TreeNode* pre=root;
            TreeNode* temp;
            int  p;
            
            if(pre->val<key){
                temp=pre->right;
                p=1;
                
            }
            else {
                temp=pre->left;
                p=0;
            }
            while(temp!=NULL && temp->val!=key){
                if(temp->val<key){
                    pre=temp;
                    p=1;
                    temp=temp->right;
                }
                else{
                    pre=temp;
                    p=0;
                    temp=temp->left;
                }
            }
            if(temp)
            rec(pre,p,key);
            return root;
        }
    }

    // This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

 pair<Node*,int> predecessorpre(Node* root){
        if(root->left->right==NULL ) return {root,0};
        root=root->left;
        while(root->right->right!=NULL) root=root->right;
        return {root,1};
    }
     pair<Node*,int> successorpre(Node* root){
        if(root->right->left==NULL ) return {root,1};
        root=root->right;
        while(root->left->left!=NULL) root=root->left;
        return {root,0};
    }
    
    
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre=NULL;
    suc=NULL;
    if(!root) return;
    Node* temp=root;
    Node* tpre=root;
    Node* tppre=root;
    int p=-1;;
    int pp=-1;
    while(temp!=NULL && temp->key!=key){
        p=pp;
        tppre=tpre;
        tpre=temp;
        if(temp->key<key){
            pp=1;
            pre=temp;
            temp=temp->right;
        }
        else{
            suc=temp;
            temp=temp->left;
            pp=0;
        }
    }
    if (!temp){
       
        return;
    }
    if(temp->left!=NULL) {
        
        pair<Node*,int> p=predecessorpre(temp);
        
        if(p.second){
            pre=p.first->right;
        }
        else{
            pre=p.first->left;
        }
    }
    if(temp->right!=NULL){
         pair<Node*,int> p=successorpre(temp);
        if(p.second){
            suc=p.first->right;
        }
        else{
            suc=p.first->left;
        }
    }

}


  //Function to check whether a Binary Tree is BST or not.
    pair<int,int> rec(Node* root,bool &ans){
        if(!root) return {-1,-1};
        pair<int,int> p1=rec(root->left,ans);
        pair<int,int> p2=rec(root->right,ans);
        int mi=root->data;
        int ma=root->data;
        if(p1.first!=-1 || p1.second!=-1){
            if(p1.second>=root->data){
                ans=0;
            }
            else{
                mi=p1.first;
            }
        }
         if(p2.first!=-1 || p2.second!=-1){
            if(p2.first<=root->data){
                ans=0;
            }
            else{
                ma=p2.second;
            }
        }
        return {mi,ma};
        
    }
    bool isBST(Node* root) 
    {
        bool ans=1;
        rec(root,ans);
        return ans;
       
    }

// Populate Inorder Successor for all nodes 
     void inord(Node* root,Node* &pre)
    {
        if(!root) return;
       
        inord(root->left,pre);
        
        pre->next=root;
         pre=root;
         inord(root->right,pre);
        
    }

    void populateNext(Node *root)
    {
        Node* t=new Node(0);
        inord(root,t);
    }

    //Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   if(!root) return root;
   if(root->data<n1 && root->data<n2){
       LCA(root->right,n1,n2);
   }
   else if(root->data> n1 && root->data>n2){
       LCA(root->left,n1,n2);
   }
  else return root;
}

// Construct BST from given preorder traversal | ***********good technique O(n)


Node* rec(vector<int> const &preorder,int &i,int mi,int ma){
		// cout<<i<<mi<<ma<<" ";
		if(i==preorder.size()) return NULL;
		if(preorder[i]<mi || preorder[i]>ma){
			return NULL;
		}
		Node* temp=new Node(preorder[i]);
		i++;
		temp->left=rec(preorder,i,mi,preorder[i-1]-1);
		temp->right=rec(preorder,i,preorder[i-1]+1,ma);
		return temp;
	}
	

	Node* constructBST(vector<int> const &preorder)
	{
		int i=0;
		return rec(preorder,i,INT_MIN,INT_MAX);
	}
      // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    int rec(Node* root, map<Node*,pair<int,int>> &mp,vector<int> & v){
        if(!root) return 0;
        int a=rec(root->left,mp,v);
        int b=rec(root->right,mp,v);
        v.push_back(root->data);
        mp[root]={a,b};
        return a+b+1;
    }
    void make(Node* root,vector<int> & v,int &i){
        if(!root) return;
        make(root->left,v,i);
        root->data=v[i];
        i++;
        make(root->right,v,i);
        
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        map<Node*,pair<int,int>> mp;
       rec(root,mp,v);
       sort(v.begin(),v.end());
    //   for(auto i:v) cout<<i<<" ";
    //   cout<<"\n";
       int i=0;
       make(root,v,i);
       return root;
    }

    // Your are required to complete this function
// function should return root of the modified BST

void preorderT(Node* root,vector<int> &v){
    if(!root) return ;
    preorderT(root->left,v);
    v.push_back(root->data);
    preorderT(root->right,v);
    
}
Node* makeB(vector<int> v,int i,int j){
   
    if(i>=j) return NULL;
    int m=(i+j)/2;
    Node* temp=new Node(v[m]);
    temp->left=makeB(v,i,m);
    temp->right=makeB(v,m+1,j);
    return temp;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int > v;
	preorderT(root,v);
	return makeB(v,0,v.size());
	
}
 void tra(Node* root,int &k,int &ans){
       if(!root) return;
       if(k<0) return;
       tra(root->right,k,ans);  
       
       if(k==0) ans=root->data;
       k--;
       tra(root->left,k,ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans;
        K--;
        tra(root,K,ans);
        return ans;
    }

    void rec3(Node* root,int l,int r,int &ans){
        if(!root) return ;
        rec3(root->left,l,r,ans);
        if(root->data>=l && root->data<=r) ans++;
        rec3(root->right,l,r,ans);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      int ans=0;
      rec3(root,l,h,ans);
      return ans;
    }

    // **********important** AVL Tree********************************************



    struct Avl{
        int data;
        Avl* left;
        Avl* right;
        int hl;
        int hr;
        Avl(int x){
            data=x;
            left=NULL;
            right=NULL;
            hl=0;
            hr=0;

        }
    };



 pair<Avl*,int> predecessorpre(Avl* root){
        if(root->left->right==NULL ) return {root,0};
        root=root->left;
        while(root->right->right!=NULL) root=root->right;
        return {root,1};
    }
     pair<Avl*,int> successorpre(Avl* root){
        if(root->right->left==NULL ) return {root,1};
        root=root->right;
        while(root->left->left!=NULL) root=root->left;
        return {root,0};
    }
    
    
void findPreSuc(Avl* root, Avl*& pre, Avl*& suc, int data)
{
    pre=NULL;
    suc=NULL;
    if(!root) return;
    Avl* temp=root;
    Avl* tpre=root;
    Avl* tppre=root;
    int p=-1;;
    int pp=-1;
    while(temp!=NULL && temp->data!=data){
        p=pp;
        tppre=tpre;
        tpre=temp;
        if(temp->data<data){
            pp=1;
            pre=temp;
            temp=temp->right;
        }
        else{
            suc=temp;
            temp=temp->left;
            pp=0;
        }
    }
    if (!temp){
       
        return;
    }
    if(temp->left!=NULL) {
        
        pair<Avl*,int> p=predecessorpre(temp);
        
        if(p.second){
            pre=p.first->right;
        }
        else{
            pre=p.first->left;
        }
    }
    if(temp->right!=NULL){
         pair<Avl*,int> p=successorpre(temp);
        if(p.second){
            suc=p.first->right;
        }
        else{
            suc=p.first->left;
        }
    }

}


    void preAvlTra(Avl* root){
        if(!root) return ;
        cout<<root->data<<" "<<root->hl<<" "<<root->hr<<" "<<root->left<<" "<<root->right<<"\n";
        preAvlTra(root->left);
        preAvlTra(root->right);
    }

    Avl* rotate(vector<pair<Avl*,int>> v,int i){
        int l1=v[i].second;
        int l2=v[i+1].second;
        if(l1==0 && l2==0){
            v[i].first->left=v[i+1].first->right;
            v[i+1].first->right=v[i].first;
            int tm=v[i+1].first->hr;
            v[i].first->hl=tm;
            v[i+1].first->hr=1+max(v[i].first->hl,v[i].first->hr);

            if(i==0) return v[i+1].first;
            if(v[i-1].second) {
                v[i-1].first->hr=1+max(v[i+1].first->hl,v[i+1].first->hr);
                v[i-1].first->right=v[i+1].first;
            }
            else{
                v[i-1].first->hl=1+max(v[i+1].first->hl,v[i+1].first->hr);
                v[i-1].first->left=v[i+1].first;
            }
        }
        else if(l1==0){
            v[i+1].first->right=v[i+2].first->left;
            v[i].first->left=v[i+2].first->right;
            v[i+2].first->left=v[i+1].first;
            v[i+2].first->right=v[i].first;
            int tm1=v[i+2].first->hl;
            int tm2=v[i+2].first->hr;
            v[i+1].first->hr=tm1;
            v[i].first->hl=tm2;
            v[i+2].first->hl=1+(max(v[i+1].first->hl,v[i+1].first->hr));
            v[i+2].first->hr=1+(max(v[i].first->hl,v[i].first->hr));
             if(i==0) return v[i+2].first;
             if(v[i-1].second) {
                 v[i-1].first->hr=1+max(v[i+2].first->hl,v[i+2].first->hr);
                v[i-1].first->right=v[i+2].first;
            }
            else{
                v[i-1].first->hl=1+max(v[i+2].first->hl,v[i+2].first->hr);
                v[i-1].first->left=v[i+2].first;
            }
        }
        else if(l2==0){
             v[i+1].first->left=v[i+2].first->right;
            v[i].first->right=v[i+2].first->left;
            v[i+2].first->right=v[i+1].first;
            v[i+2].first->left=v[i].first;
            int tm1=v[i+2].first->hl;
            int tm2=v[i+2].first->hr;
            v[i].first->hr=tm1;
            v[i+1].first->hl=tm2;
            v[i+2].first->hr=1+(max(v[i+1].first->hl,v[i+1].first->hr));
            v[i+2].first->hl=1+(max(v[i].first->hl,v[i].first->hr));
             if(i==0) return v[i+2].first;
             if(v[i-1].second) {
                 v[i-1].first->hr=1+max(v[i+2].first->hl,v[i+2].first->hr);
                v[i-1].first->right=v[i+2].first;
            }
            else{
                v[i-1].first->hl=1+max(v[i+2].first->hl,v[i+2].first->hr);
                v[i-1].first->left=v[i+2].first;
            }
        }
        else{
            v[i].first->right=v[i+1].first->left;
            v[i+1].first->left=v[i].first;
            
              int tm=v[i+1].first->hl;
            v[i].first->hr=tm;
            v[i+1].first->hl=1+max(v[i].first->hl,v[i].first->hr);
             if(i==0) return v[i+1].first;
            if(v[i-1].second) {
                v[i-1].first->right=v[i+1].first;
            }
            else{
                v[i-1].first->left=v[i+1].first;
            }
        }
        return v[0].first;
    }

    Avl* insertAvl(Avl* root,int k){
        vector<pair<Avl*,int>> track;
        if(root==NULL){
            Avl* temp=new Avl(k);
            return temp;
        }
        else{
            Avl* tt=root;
            while (true)
            {
                if(root->data<k){
                    track.push_back({root,1});
                    if(root->right==NULL) break;
                    root=root->right;
                }
                else{
                    track.push_back({root,0});
                    if(root->left==NULL) break;
                    root=root->left;
                }
            }
            Avl* temp=new Avl(k);
           
            if(root->data<k) {
                root->right=temp;
            }
            else root->left=temp;
            track.push_back({temp,0});
            int h=1;
            
            for(int i=track.size()-2;i>=0;i--){
                if(track[i].second==0){
                    track[i].first->hl=max(track[i].first->hl,h);
                }
                else{
                    track[i].first->hr=max(track[i].first->hr,h);
                }
                h++;
                if(abs( track[i].first->hl-track[i].first->hr)>1){
                    // cout<<"hit";
                    tt=rotate(track,i);
                    
                    break;
                }
            }
            // cout<<tt->data;
        return tt;
            
        }
    }

    // Replace every element with the least greater element on its right 

vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans;
        set<int> s;
        s.insert(INT_MAX);
        for(int i=n-1;i>=0;i--){
            s.insert(arr[i]);
            int a=*(s.upper_bound(arr[i]));
            if(a==INT_MAX) a=-1;
            ans.push_back(a);
        }
         
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // Check whether BST contains Dead End 

    void inorder(Node* root,Node* &p1,Node* &p2,Node* &p3,bool &ans){
    if(!root) return ;
    inorder(root->left,p1,p2,p3,ans);
    // cout<<p1->data<<","<<p2->data<<","<<p3->data<<","<<ans<<" ";
    p1=p2;
    p2=p3;
    p3=root;
    if((p1->data+1==p2->data && p2->data==p3->data-1 && p2->left==NULL && p2->right==NULL)&&(p1->data!=-1&&p2->data!=-1 && p3->data!=-1)) ans=1;
    inorder(root->right,p1,p2,p3,ans);
    
}
bool isDeadEnd(Node *root)
{
    bool ans=0;
    Node* p1=new Node(-1);
    Node* p2=new Node(-1);
    Node* p3=new Node(0);
    inorder(root,p1,p2,p3,ans);
    return ans;
}

// Return the size of the largest sub-tree which is also a BST
    pair<pair<int,int>,pair<int,int>> rec(Node* root,int &ans){
        if(!root) return{{0,1},{INT_MAX,INT_MIN}};
        pair<pair<int,int>,pair<int,int>> p1=rec(root->left,ans);
        pair<pair<int,int>,pair<int,int>> p2=rec(root->right,ans);
        
        if(p1.first.second==1 && p2.first.second==1){
            if(root->data>p1.second.second && root->data<p2.second.first){
                // cout<<root->data;
                ans=max(ans,p1.first.first+p2.first.first+1);
                if(p1.second.first==INT_MAX) p1.second.first=root->data;
                if(p2.second.second==INT_MIN) p2.second.second=root->data;
                return {{p1.first.first+p2.first.first+1,1},{p1.second.first,p2.second.second}};
            }
        }
          return {{p1.first.first+p2.first.first+1,0},{p1.second.first,p2.second.second}};   
    }
    int largestBst(Node *root)
    {
    	int ans=INT_MIN;
    	rec(root,ans);
    	return ans;
    }

int main(){
    // Avl* root=NULL;
    // root=insertAvl(root,42);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,46);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,16);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,43);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,36);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,4);
    // preAvlTra(root);
    // cout<<"\n";
    // root=insertAvl(root,16);
    // preAvlTra(root);
    // cout<<"\n";
    // Avl* pre;
    // Avl* suc;
    // findPreSuc(root,pre,suc,3);
    // if(pre) cout<<pre->data;
    // if(suc) cout<<suc->data;
    // root=insertAvl(root,7);
    // preAvlTra(root);
    // root=insertAvl(root,-1);
    // preAvlTra(root);
    // root=insertAvl(root,);
    // preAvlTra(root);

    // preAvlTra(insertAvl(root,5));
    // preAvlTra(insertAvl(root,2));
    return 0;

}