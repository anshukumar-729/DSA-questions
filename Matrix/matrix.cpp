#include <bits/stdc++.h>
using namespace std;

// Spirally traversing a matrix


bool up(vector<vector<int>>& m,int i,int j){
    if(i==0 || m[i-1][j]==-1){
        return false;
    }else return true;
}
bool down(vector<vector<int>>& m,int i,int j){
    if(i==m.size()-1 || m[i+1][j]==-1){
        return false;
    }else return true;
}
bool left(vector<vector<int>>& m,int i,int j){
    if(j==0 || m[i][j-1]==-1){
        return false;
    }else return true;
}
bool right(vector<vector<int>>& m,int i,int j){
    if(j==m[i].size()-1 || m[i][j+1]==-1){
        return false;
    }else return true;
}

//Function to return a list of integers denoting spiral traversal of matrix. 
 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector <int> ans;
        int i=0,j=0;
        int p=0;
        // cout<<matrix[0][0]<<" ";
        ans.push_back(matrix[0][0]);
        matrix[0][0]=-1;
        while (true)
        {
            // cout<<i<<j<<"\n";
            if(!(right(matrix,i,j) || left(matrix,i,j) || up(matrix,i,j) || down(matrix,i,j))) {
                // cout<<matrix[i][j];
                // ans.push_back(matrix[i][j])       
                      break;
            }
            if(p==0){
                if(right(matrix,i,j)){
                    j++;
                    // cout<<matrix[i][j]<<" ";
                    ans.push_back(matrix[i][j]);

                    matrix[i][j]=-1;
                    
                    
                }
                else if(left(matrix,i,j)){
                    j--;
                    // cout<<matrix[i][j]<<" ";
                    ans.push_back(matrix[i][j]);
                    matrix[i][j]=-1;
                }
                else{
                    p=1;
                    // break;
                }
            }
            else{
                // cout<<"pp";
                // break;
                if(up(matrix,i,j)){
                    i--;
                    // cout<<matrix[i][j]<<" ";
                    ans.push_back(matrix[i][j]);
                    matrix[i][j]=-1;
                    
                }
                else if(down(matrix,i,j)){
                    
                    i++;
                    // cout<<matrix[i][j]<<" ";
                    ans.push_back(matrix[i][j]);
                    matrix[i][j]=-1;
                    // break;
                }
                else{
                    p=0;
                }
            }
        }
        return ans;
        
    }

// 74. Search a 2D Matrix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        while (i<matrix.size() && matrix[i][matrix[i].size()-1]<target)
        {
            i++;
        }
        if(i==matrix.size()){
            return false;
        }
        else{
            int f=0;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target){
                    f=1;
                    break;
                }
            }
            if(f) return true;
            else return false;
        }
    }

// Median in a row-wise sorted Matrix  // nested binary search awesome implementation
int lesserelements(vector<int> & v,int x){
    int l=0;
    int r=v.size()-1;
    while (r-l>1)
    {
        //  cout<<l<<r;
        int m=(r-l)/2+l;
        if(v[m]>=x){
            r=m-1;
        }
        else{
            l=m;
        }
    }
    int ans=l;
    if(v[l]<x) ans++;
    if(r!=l && v[r]<x) ans++;
    // cout<<l<<r;
    return ans;
    
}

int median(vector<vector<int>> &matrix, int row, int c){
        int l=1;
        int r=2001;
        while (r-l>1)
        {
            int m=(r-l)/2+l;
            int s=0;
            for(int i=0;i<matrix.size();i++){
            s+=lesserelements(matrix[i],m);
            }
            // cout<<m<<" "<<s<<"\n";
            if(s<(row*c)/2+1){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        int s=0;
        int ans;
        // cout<<l<<r<<"\n";
        for(int i=0;i<matrix.size();i++){
            s+=lesserelements(matrix[i],l);
            }
            // cout<<"s"<<s<<"\n";
            if(s>=(row*c)/2+1){
                ans=l;
            }
            else{
                ans=r;
            }
            // cout<<ans;

            int aa=INT_MIN;
            // cout<<row<<c<<"\n";
            for(int i=0;i<row;i++){
                int l=0;
                int r=c-1;
                while (r-l>1)
                {
                    int m=(r-l)/2+l;
                    if(matrix[i][m]>=ans){
                        r=m-1;
                    }
                    else{
                        l=m;
                    }
                }
                // cout<<"lr"<<l<<r<<"\n";
                if(matrix[i][r]<ans)
                aa=max(aa,matrix[i][r]);
                else if(matrix[i][l]<ans){
                    aa=max(aa,matrix[i][l]);
                }
                
                
            }
            // cout<<aa;


        
                return aa;
    }

// Row with max 1s in O(m+n)

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max=-1;
        int i=0;
        int j=m-1;
        while (j>=0 && i<n)
        {
            if(arr[i][j]==1){
                j--;
                max=i;
            }else{
                i++;
            }
        }
        return max;
        
	}


// Max rectangle
  
 void nearestSmallerElement(vector<int> &his,int n,pair<map<int,int>,map<int,int>> &p){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(i);
        }
        else{
            while (!s.empty() && his[s.top()]>his[i])
            {
                p.first[s.top()]=i;
                s.pop();
            }
            s.push(i);
            
        }
    }
    while (!s.empty())
    {
        p.first[s.top()]=n;
        s.pop();
    }
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            s.push(i);
        }
        else{
            while (!s.empty() && his[s.top()]>his[i])
            {
                p.second[s.top()]=i;
                s.pop();
            }
            s.push(i);
            
        }
    }
    while (!s.empty())
    {
        p.second[s.top()]=-1;
        s.pop();
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<p.first[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<p.second[i]<<" ";
    // }
    // cout<<"\n";
    return ;

}

int largestHistgramArea(vector<int> &his,int n){
    int ma=INT_MIN;
    pair<map<int,int>,map<int,int>> p;

    nearestSmallerElement(his,n,p);
    for(int i=0;i<n;i++){
        int area=(p.first[i]-p.second[i]-1)*his[i];
        ma=max(ma,area);
    }
    return ma;
}

int maxArea(int M[1000][1000], int n, int m) { //Overall O(n^2) TLE
    int ma=INT_MIN;
    vector<int> area;
    for(int i=0;i<m;i++){
            area.push_back(0);
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(M[i][j]==1)area[j]++;
        else area[j]=0;
        }
        // for(int i=0;i<m;i++){
        //     cout<<area[i]<<" ";
        // }
        // cout<<"\n";
        ma=max(ma,largestHistgramArea(area,m));
    }     
    return ma;
    }

// finding maximum diffrence in the matrix

int findMaxValue(vector<vector<int>> v){
    int n=v.size();
    vector<vector<int>> ma;
    for(int i=0;i<=n;i++){
        vector<int> temp;
        for(int j=0;j<=n;j++){
         temp.push_back(INT_MIN);
        }
        ma.push_back(temp);
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            ma[i][j]=max(v[i][j],max(ma[i+1][j],ma[i][j+1]));
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<ma[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans=INT_MIN;
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            ans=max(ans,ma[i+1][j+1]-v[i][j]);
        }
    }
    // cout<<ans<<"\n";
    return ans;
    
}

//Rotate a matrix by 90 degree in clockwise direction without using any extra space
void rotate90Matrix(vector<vector<int>> &v , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(v[i][j],v[j][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(v[i][j],v[i][n-j-1]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//Kth element in Matrix

int nosmallerElements(int array[],int n,int m){
    int s=0;
    int l=0,r=n-1;
    while (r-l>1)
    {
        int mid=(r-l)/2+l;
        if(array[mid]<=m){
            l=mid;
        }   
        else {
            r=mid-1;
        }
    }
    int ans;
    if(array[r]<=m) ans=r+1;
    else if(array[l]<=m) ans=l+1;
    else ans=0;
    // cout<<ans;
    return ans;
    
}

int kthSmallest(int mat[1000][1000], int n, int k)
{
  int l=1;
  int r=10000;
  while (r-l>1)
  {
      int m=(r-l)/2+l;
      int  s=0;
      for(int i=0;i<n;i++){
          s+=nosmallerElements(mat[i],n,m);
      }
      if(s>=k){
          r=m;
      }
      else {
          l=m+1;
      }
  }
  int s=0;
  int ans;
  for(int i=0;i<n;i++){
          int w=nosmallerElements(mat[i],n,l);
        //   cout<<w<<"\n";
          s+=w;
      }
      if(s==k) ans=l;
      else ans=r;
  
  return ans;
}

int main(){
vector<vector<int>> v={{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
        //    cout<<right(v,0,1);
// spirallyTraverse(v,4,4);
int v2[]={1,2,3,4,5,6,7,8};
int v3[1000][1000]= {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {24, 29, 37, 48},
                   {32, 33, 39, 50}};
// nosmallerElements(v2,8,5);
cout<<kthSmallest(v3,4,7);
// vector<int> v1={3,4,5,6,8,9};
// cout<<median(v,3,3);
    return 0;
}