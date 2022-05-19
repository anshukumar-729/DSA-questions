#include<bits/stdc++.h>
using namespace std;

// linked List Implementation

struct Node
{
    int data;
    Node *next;
    Node* bottom;
    Node* arb;

    Node(int x){
        data=x;
        next=NULL;
        bottom=NULL;
        arb=NULL;
    }
};

void display(Node *head){
    Node *next=head;
    while (next!=NULL)
    {
        cout<<next->data<<" ";
        next=next->next;
    }
    cout<<"\n";
    
}
Node* insertNodeAtBeggining(Node *head,int data){
    if(head==NULL){
       head=(Node*) (malloc(sizeof(Node)));
        head->data=data;
        head->next=NULL;
    }

    else{
       Node *next;
       next=(Node*)(malloc(sizeof(Node*)));
       next->data=data;
       next->next=head;
       head=next;

    }
    return head;
}
Node* insertNodeAtEnd(Node *head,int data){
    if(head==NULL){
       return insertNodeAtBeggining(head,data);
    }
    Node *next=head;
    while (next->next!=NULL)
    {
        next=next->next;
    }
    Node *temp;
    temp=(Node*)(malloc(sizeof(Node)));
    temp->data=data;
    temp->next=NULL;
    next->next=temp;
    return head;
}


struct Node* reverseList(struct Node *head) // using iteration
    {
       struct Node* temp;
        temp=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp2;
        temp2=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp3;
        temp3=(struct Node*) (malloc(sizeof(struct Node)));
        temp2=NULL;
        temp=head;
        while (temp!=NULL)
        {
            temp3=temp->next;
            temp->next=temp2;
            temp2=temp;
            temp=temp3;
            
        }
        head=temp2;
        return head;
        
    }

    struct Node* reverseListrec(struct Node *head,struct Node *pre=NULL){ // using recursion
        struct Node* temp;
        temp=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp2;
        temp2=(struct Node*) (malloc(sizeof(struct Node)));
        temp=head->next;
       
        head->next=pre;
         if(temp==NULL){
             temp2=head;
             return temp2;
        }
       return reverseListrec(temp,head);
        
    }
    struct Node *reverse (struct Node *head, int k)
    { 
        // cout<<"hrr";
        struct Node* temp;
        // temp=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp2;
        // temp2=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp3;
        // temp3=(struct Node*) (malloc(sizeof(struct Node)));
       struct Node* temp4;
        // temp4=(struct Node*) (malloc(sizeof(struct Node)));
        temp2=NULL;
       struct Node* temp5;
        // temp5=(struct Node*) (malloc(sizeof(struct Node)));
        
        int i=0;
        int f=0;
        while (true)
        {
            
            int ct=k;
            temp=head;
            temp2=NULL;
            // cout<<"i"<<i<<" ";
                while ( ct>0)
                {
                    // cout<<ct<<" ";
                    ct--;
                    if(temp==NULL){
                        f=1;
                        break;
                    }
                    // cout<<temp->data;
                    temp3=temp->next;
                    temp->next=temp2;
                    temp2=temp;
                    temp=temp3;
                }
                head=temp2;
                if(i==0){
                    temp4=head;
                }
                else{
                    temp5=temp4;
                    while (temp5->next!=NULL)
                    {
                        temp5=temp5->next;
                        // cout<<"pppp";
                    }
                    temp5->next=head;
                    
                }
                i++;
                head=temp3;
               
               if(f==1) break;

                
        }
        head=temp4;
        
        
        return head;
    }

      //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        struct Node *next=head;
        while(next!=NULL){
            if(next->data>0)
            next->data=-1*(next->data);
            else return true;
            next=next->next;
            
        }
        return false;
    }

     void removeLoop(struct Node*head){ // use unordered map as its check any element in O(1) // by hashing
      struct Node *next=head;
      struct Node *prev=head;
      unordered_map<Node*,int> mp;
        while (next!=NULL)
        {
            if(mp.find(next)!=mp.end()){
                mp[next]=1;
            }
            else{
                break;
            }
            prev=next;
            next=next->next;
        }
        prev->next=NULL;
        

        }

        // by left and right method in Space O(1)
  void removeLoop2(struct Node*head){ 
      struct Node *left=head;
      struct Node *right=head;
      struct Node *prright=head;
      bool f=0;
      if(head==NULL) return;
        while (true)
        {
          left=left->next;
          right=right->next;
          prright=right;
          if(right==NULL || left==NULL) {
              return;
          }
          right=right->next;
          if(right==NULL) {
              return ;
          }
          if(right==left){
              break;
          }
        }
        left=head;
        if(left==right){
            prright->next=NULL;
            return;
        }
        
        while (right->next!=left->next)
        {
            left=left->next;
            right=right->next;   
        }
        right->next=NULL;

        
        

        }

   //Function to remove duplicates from sorted linked list.
     Node *removeDuplicates2(Node *head)
{

    if(head==NULL || head->next==NULL) return head;
    
    struct Node* ptr=head->next;
    struct Node* pre=head;
    
    while (ptr!=NULL)
    {
        
       if(ptr->data==pre->data){
           pre->next=ptr->next;
       }
       else{
           pre=pre->next;
       }
       ptr=ptr->next;
       
    }
    
    // pre->next=NULL;
    return head;
    
}

  //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(head==NULL || head->next==NULL) return head;
        struct Node* ptr=head->next;
        struct Node* pre=head;
        unordered_map<int,bool> mp;
        mp[pre->data]=1;
        while (ptr!=NULL)
        {
            if(mp.find(ptr->data)==mp.end()){
                mp[ptr->data]=1;
                pre->next=ptr->next;
            }
            else{
                pre=pre->next;
            }
            ptr=ptr->next;
        }
        return head;
    }

   int addOneRec(Node* head){
        if(head->next==NULL){
            int carry=(head->data+1)/10;
            head->data=(head->data+1)%10;
            return carry;
        }
        int carry=addOneRec(head->next);
        int carry2=(head->data+carry)/10;
        head->data=(head->data+carry)%10;
        return carry2;
    }

    Node* addOne(Node *head) 
    {
        if(head==NULL) return head;
        
        int carry=addOneRec(head);
        
    //   cout<<carry;
        if(carry!=0){
            Node* ptr=new Node(carry);
                        // ptr->data=0;
                                ptr->next=head;

            return ptr;
        }
        return head;
       
        
        
    }


    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first=reverseList(first);
       second=reverseList(second);
       int carry=0;
       struct Node* pre=NULL;
       
       while (first!=NULL && second!=NULL)
       {
           
            Node* temp=new Node((carry+first->data+second->data)%10);
            temp->next=pre;
            pre=temp;
            carry=(carry+first->data+second->data)/10;
            first=first->next;
            second =second->next;
            
       }
       while (first!=NULL)
       {
           
           Node* temp=new Node((carry+first->data)%10);
           temp->next=pre;
            pre=temp;
           carry=(carry+first->data)/10;
           first=first->next;
       }
       while (second!=NULL)
       {
           
           Node* temp=new Node((carry+second->data)%10);
           temp->next=pre;
            pre=temp;
           carry=(carry+second->data)/10;
           second=second->next;
       }
       
       if(carry!=0){
           Node* nn=new Node(carry);
           nn->next=pre;
           return nn;
       }
       return pre;
       
    }



//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*> st;
    while(head1!=NULL){
        st.insert(head1);
        head1=head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2)!=st.end()){
            return head2->data;
        }
        head2=head2->next;
    }
    return -1;
}

    Node* findIntersection(Node* head1, Node* head2)
{
        unordered_set<int> st1;
        Node* ptr=NULL;
        while (head1!=NULL)
        {
            st1.insert(head1->data);
            head1=head1=head1->next;
        }
        while (head2!=NULL)
        {
            if(st1.find(head2->data)!=st1.end()){
                Node* temp=new Node(head2->data);
                temp->next=ptr;
                ptr=temp;
            }
            head2=head2=head2->next;
        }
        ptr=reverseList(ptr);
        return ptr;
}

    //Function to sort the given linked list using Merge Sort.
   void  mergeLL(Node* head,Node* mid,Node* tail){
       Node* ptr=NULL;
       Node* ptr1=head;
       Node* ptr2=mid;

       while (ptr1!=mid && ptr2!=tail)
       {    
            if(ptr1->data<ptr2->data){
                Node* temp =new Node(ptr1->data);
                temp->next=ptr;
                ptr=temp;
                ptr1=ptr1->next;
            }
            else{
                Node* temp =new Node(ptr2->data);
                temp->next=ptr;
                ptr=temp;
                ptr2=ptr2->next;
            }
       }
       while (ptr1!=mid )
       {    
                Node* temp =new Node(ptr1->data);
                temp->next=ptr;
                ptr=temp;
                ptr1=ptr1->next;
            
       }
       while (ptr2!=tail )
       {    
                Node* temp =new Node(ptr2->data);
                temp->next=ptr;
                ptr=temp;
                ptr2=ptr2->next;
            
       }
       ptr=reverseList(ptr);
       while (ptr!=NULL && head!=NULL)
       {
           head->data=ptr->data;
           ptr=ptr->next;
           head=head->next;
       }
       
       
   }

    void mergeSortRecLL(Node* head,Node* tail,int n){
        if(n==1) return;
        Node* mid=head;
        int ct=n/2;
        while (ct>0)
        {
            mid=mid->next;
            ct--;
        }
        mergeSortRecLL(head,mid,n/2);
        mergeSortRecLL(mid,tail,n-n/2);
        mergeLL(head,mid,tail);
        

    }

    Node* mergeSort(Node* head) {
        // your code here
        int n=0;
        Node* ptr=head;
        while (ptr!=NULL)
        {
            n++;
            ptr=ptr->next;
        }
        mergeSortRecLL(head,NULL,n);
        return head;
    }

    // quick sort using linked list
    Node* partitionLL(Node* head,Node* tail){
        int pivot=head->data;
        Node* i=head;
        Node* j=head->next;
        while (j!=tail)
        {
            if(j->data<pivot){
                i=i->next;
                swap(i->data,j->data);

            }
            j=j->next;
        }
        swap(head->data,i->data);
        return i;
        

    }
    void quickRec(Node* head,Node* tail){
        if(head==tail || head->next==tail ) return;
        Node* p=partitionLL(head,tail);
        // Node* p=head;
        quickRec(head,p);
        quickRec(p->next,tail);
    }
    void quickSort(struct Node **headRef) {
        quickRec((*headRef),NULL);
}

 Node* middleNode(Node* head) {
        Node* n1=head;
        Node* n2=head;
        while (n2!=NULL)
        {
           
            n2=n2->next;
            if(n2==NULL){
                return n1;
            }
             n1=n1->next;
            n2=n2->next;

        }
        return n1;
    }

    void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* pr=head;
    (*head1_ref)=head;
    (*head2_ref)=head;
    // cout<<"ooo";
    if(head->next==NULL) return ;
    // return;
        while ((*head2_ref)!=NULL)
        {
            // cout<<"pp";
            (*head2_ref)=(*head2_ref)->next; 
            if((*head2_ref)==NULL){
                pr=pr->next;
                break;
            }  
            (*head2_ref)=(*head2_ref)->next; 
            pr=(*head1_ref);
            (*head1_ref)=(*head1_ref)->next; 
            
        }
        (*head2_ref)=(pr)->next;
        (pr)->next=NULL;
        (*head1_ref)=head;
        
    return;   
}

Node* palindromeRec(Node* head,Node* end,bool &ans){
    
       if(end==NULL){
        //    Node* p=new Node(0);
        //    end=p;
        //    cout<<"ret";
           return head;
       }
       Node* temp=palindromeRec(head,end->next,ans);
    //    cout<<temp->data<<end->data;
       ans=ans&(temp->data==end->data);
       return temp->next;

    
}

//Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        bool ans=1;
        palindromeRec(head,head,ans);
        // cout<<ans;
        return ans;
    }

 /* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

    Node* pre=(*head);
    Node* ptr=(*head);
    if((*head)->data==key){
        (*head)=NULL;
    }
    while(ptr!=NULL){
        if((ptr)->data==key){
            pre->next=(ptr)->next;
            break;
        }
        pre=(ptr);
        (ptr)=(ptr)->next;
    }

}

/* Function to reverse the circular linked list */
 void reverse(struct Node** head_ref)
{

unordered_set<Node*> st;
Node* temp;
Node* pre=NULL;
Node* ptr=(*head_ref);
st.insert(ptr);
while(ptr!=NULL){
    
//  cout<<ptr->data;
    temp=ptr;
    ptr=ptr->next;
    temp->next=pre;
    pre=temp;
    if(st.find(ptr)!=st.end()){
        break;
    }
       st.insert(ptr);
    //   cout<<temp->data<<" ";
   
}
// cout<<pre->data;
(*head_ref)->next=pre;
 *head_ref=pre;

}

/*  Function which returns the  root of 
    the flattened linked list. */


Node* addEnd(struct Node *head,int data) // using iteration
    {
        Node* ptr=head;
        if(ptr==NULL){
             Node* temp=new Node(data);
            temp->bottom=NULL;
            return temp;
        }
        while(ptr->bottom!=NULL){
            ptr=ptr->bottom;
        }
        Node* temp=new Node(data);
        temp->bottom=NULL;
        ptr->bottom=temp;
        return head;
    }


Node *flatten(Node *root)
{
    
    Node* ans=NULL;
    unordered_set<Node*> st;
    while (true)
    {
        Node* next=root;
        int mi=INT_MAX;
        Node* miNode;
        while (next!=NULL)
        {
            Node* btm=next;
            while (btm!=NULL && st.find(btm)!=st.end())
            {
                btm=btm->bottom;
            }
            if(btm!=NULL){
                // cout<<btm->data;
                if(btm->data<mi){
                  
                    mi=btm->data;
                    miNode=btm;
                }
            }
            
           next=next->next;
        }
        // cout<<"\n";
        if(mi==INT_MAX) break;
          st.insert(miNode);
        // cout<<mi<<"\n";
      ans=addEnd(ans,mi);
        // break;

    
    }
    // reverseList(ans);
    return ans;
    

}

  //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* temp=new Node(0);
        temp->next=head;
       Node* i=temp;
       Node* j=head;
       while (j!=NULL)
       {
            if(j->data==0){
                i=i->next;
                swap(i->data,j->data);
            }   
            j=j->next;
       }
        j=i->next;
        while (j!=NULL)
        {
           if(j->data==1){
                i=i->next;
                swap(i->data,j->data);
            }   
            j=j->next;
        }
        
        return head;
       
        
    }
    // Clone a linked list with next and random pointer 

    Node *copyList(Node *head)
    {
        map<Node*,Node*> mp;
        Node* ptr=head;
        while(ptr!=NULL){
            Node* temp=new Node(ptr->data);
            mp[ptr]=temp;
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL){
            mp[ptr]->next=mp[ptr->next];
            mp[ptr]->arb=mp[ptr->arb];
            ptr=ptr->next;
        }
        return mp[head];
    }

    long long  multiplyTwoLists (Node* l1, Node* l2) // not checked********
{
    vector<Node*> v;
    reverseList(l1);
    reverseList(l2);
    long long off=0;
    Node* a=l1;
    while (a!=NULL)
    {
        Node* ans=NULL;
        Node* b=l2;
        long long c=0;
        long long k=off;
        while (k>0)
        {
            Node* temp=new Node(0);
            temp->next=ans;
            ans=temp;
            k--;
        }
        
        while (b!=NULL)
        {
            int tt=(a->data*b->data+c);
            Node* temp =new Node(tt%10);
            c=tt/10;
            temp->next=ans;
            ans=temp;
            b=b->next;   
        }
        if(c!=0){
            Node* temp=new Node(c);
            temp->next=ans;
            ans=temp;
        }
        v.push_back(ans);
        off++;
        
    }
    for(int i=0;i<v.size();i++){
        reverseList(v[i]);
    }
    long long ans=0;
    off=0;
        long long c=0;
        long long aaa=0;
    Node* aa=NULL;
    while (true)
    {
        int f=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=NULL){
                f=1;
                long long tt=v[i]->data+ans;
                ans=tt%10;
                c=tt/10;
                v[i]=v[i]->next;
            }
        }   
        if(f==0) break;
        Node* temp = new Node(ans);
        aaa+=(ans*pow(10,off));
        off++;
        temp->next=aa;
        aa=temp;
        ans=0;

    }
    aaa+=(c*pow(10,off));
    while (c>0)
    {
        Node* temp=new Node(c%10);
        temp->next=aa;
        aa=temp;
        c=c/10;
    }
    return aaa;
    
    
    
}
// Delete nodes having greater value on right 

 Node *compute(Node *head)
    {
        Node* kk=head;
        Node* pre=new Node(0);
        pre->next=head;
        Node* ptr=head;
        stack<pair<Node*,Node*>> sp;
        while(ptr!=NULL){
            while(!sp.empty()){
                int tt=sp.top().second->data;
                if(tt<ptr->data){
                  
                    sp.pop();
                }
                else break;
            }
            // print(head);
            // cout<<"\n";
            sp.push({pre,ptr});
            pre=ptr;
            ptr=ptr->next;
        }
        Node* ans=NULL;
        while(!sp.empty()){
            Node* temp=sp.top().second;
            sp.pop();
            temp->next=ans;
            ans=temp;
        }
        return ans;
    }

    // Segregate even and odd nodes in a Link List 

     Node* divide(int N, Node *head){
        // code here
        Node* i=new Node(0);
        Node* kk=i;
        i->next=head;
        Node* j=head;
        Node* pj=i;
        while(j!=NULL){
            if(j->data%2==0){
                pj->next=j->next;
                j->next=i->next;
                i->next=j;
                i=i->next;
            }
            pj=j;
            j=j->next;
        }
        return kk->next;
    }
    

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast2(struct Node *head, int n,int &f)
{
    if(head==NULL) return n;
    
     int k=getNthFromLast2(head->next,n,f)-1;
     if(k==0){ f=head->data; }
     return k;
}
int getNthFromLast(struct Node *head, int n)
{
    int f=-1;
   int k=getNthFromLast2(head,n,f);
   return f;
}

		string FirstNonRepeating(string A){ 
		    vector<char> vp;
		    int pj=0;
		   
		    string ans;
		    map<char,int> mp;
		    for(char i='a';i<'z';i++){
		        mp[i]=0;
		    }
		    for(int i=0;i<A.size();i++){
		        if(mp[A[i]]==0) {
		            vp.push_back(A[i]);
		        }
		        mp[A[i]]++;
		        int f=0;
		        for(int j=pj;j<vp.size();j++){
		            if(mp[vp[j]]==1){
		                pj=j;
		                f=1;
		                ans.push_back(vp[j]);
		                break;
		            }
		        }
		        if(f==0) ans.push_back('#');
		    }
		    
		    return ans;
		}

int main(){
    Node *head=NULL;
    // head=insertNodeAtEnd(head,10);
    head=insertNodeAtBeggining(head,5);
    // head=insertNodeAtBeggining(head,4);
    // head=insertNodeAtBeggining(head,3);
    // head=insertNodeAtBeggining(head,2);
    // head=insertNodeAtBeggining(head,1);
    // head=insertNodeAtBeggining(head,3);
    // head=insertNodeAtBeggining(head,5);
    // head=insertNodeAtEnd(head,9);
    display(head);
    isPalindrome(head);
    // head=reverse(head,3);
    // Node* h1=NULL;
    // Node* h2=NULL;
    // splitList(head,&h1,&h2);
    // display(h1);
    // display(h2);
    return 0;
}

// reverse a doubly LL
// struct Node* reverseDLL(struct Node * head)
// {
//     Node* temp;
//     while (head->next!=NULL)
//     {
//         temp=head->prev;
//         head->prev=head->next;
//         head->next=temp;
//         head=head->pre;
//     }
//     temp=head->prev;
//         head->prev=head->next;
//         head->next=temp;
//         return head;

    
// }