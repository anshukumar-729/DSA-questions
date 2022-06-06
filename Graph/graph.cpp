#include<bits/stdc++.h>
using namespace std;



class Graph{

    public:
    unordered_map<int,unordered_set<int>> conn;
    unordered_map<int,int> vis;
    int noOfEdge=0;

    void makeEdge(int n1,int n2){
        if(conn[n1].empty()){
            vis[n1]=0;
        }
        if(conn[n2].empty()){
            vis[n2]=0;
        }
        conn[n1].insert(n2);
        conn[n2].insert(n1);
        noOfEdge++;
    }
    bool isEdge(int n1,int n2){
        if(conn[n1].find(n2)!=conn[n1].end()) return 1;
        return 0;
    }
    void deleteEdge(int n1,int n2){
        conn[n1].erase(n2);
        conn[n2].erase(n1);
        noOfEdge--;
    }
    vector<int> adjacent(int n){
        vector<int> ans;
        for(auto i:conn[n]){
            ans.push_back(i);
        }
        return ans;
    }
    void erase(){
        for(auto i: vis){
            vis[i.first]=0;
        }
    }
    vector<int> visited(){
        vector<int> ans;
        for(auto i: vis){
            if(i.second!=0){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
    vector<int> notVisited(){
        vector<int> ans;
        for(auto i: vis){
            if(i.second==0){
                ans.push_back(i.first);
            }
        }
        return ans;
    }

    void printGraph(){
        cout<<"\n";
        for(auto i:conn){
            cout<<i.first<<" -->";
            for(auto j:i.second){
                cout<<"--"<<j;
            }
            cout<<"\n";
        }
    }

}g;

     // Function to detect cycle in a directed graph. using dfs

 void dfs(vector<vector<int>> &a,int n,vector<int> &vis,vector<int> &par,bool &ans){
           if(vis[n]==1) {
               if(par[n]==1) ans=1;
               return;
           }
           vis[n]=1;
           par[n]=1;
           for(auto &i:a[n]){
               dfs(a,i,vis,par,ans);
           }
           par[n]=0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> a;
        for(int i=0;i<V;i++){
            vector<int> temp;
            for(int j=0;j<adj[i].size();j++)
                temp.push_back(adj[i][j]);
            a.push_back(temp);
        }
        vector<int> vis(V,0);
        vector<int> par(V,0);
        bool ans=0;
        for(int i=0;i<V;i++){
            if(ans==1) break;
            if(vis[i]==0)
        dfs(a,i,vis,par,ans);
        }
        return ans;
       
         
    }

    //Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            inDeg[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(inDeg[i]==0)
	        q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto j:adj[t]){
	            inDeg[j]--;
	            if(inDeg[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    return ans;
	}

     // Function to detect cycle in a directed graph. using bfs (toplogical sort)vvi***********
    
    bool isCyclic2(int V, vector<int> adj[]) {
        // code here
       
         vector<int> inDeg(V,0);
         int ct=0;
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            inDeg[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(inDeg[i]==0)
	        q.push(i);
	    }
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        ct++;
	        for(auto j:adj[t]){
	            inDeg[j]--;
	            if(inDeg[j]==0){
	                q.push(j);
	            }
	        }
	    }
       
        
        return (ct!=V);
       
         
    }

      // Function to detect cycle in an undirected graph. using (bfs)
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==1) continue;
            queue<pair<int,int>> q;
            q.push({i,i});
            while(!q.empty()){
                int t=q.front().first;
                int p=q.front().second;
                q.pop();
                // cout<<t;
                if(vis[t]==1) return 1;
                vis[t]=1;
                for(auto j:adj[t]){
                    if(j!=p)
                    q.push({j,t});
                }
            }
        }
        return 0;
    }

      // Function to detect cycle in an undirected graph. using dfs
    bool isCycle3(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==1) continue;
            stack<pair<int,int>> q;
            q.push({i,i});
            while(!q.empty()){
                int t=q.top().first;
                int p=q.top().second;
                q.pop();
                // cout<<t;
                if(vis[t]==1) return 1;
                vis[t]=1;
                for(auto j:adj[t]){
                    if(j!=p)
                    q.push({j,t});
                }
            }
        }
        return 0;
    }

     //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	    while(!q.empty()){
	        int h=q.front().first;
	        int x=q.front().second.first;
	        int y=q.front().second.second;
	        q.pop();
	       // cout<<x<<" "<<y;
	        if(x==TargetPos[0] && y==TargetPos[1]) return h;
	        if(vis[x][y]==1) continue;
	        vis[x][y]=1;
	        vector<pair<int,int>> v2={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
	        for(auto i:v2){
	            int a=i.first;
	            int b=i.second;
	            x+=a;
	            y+=b;
	            if(x>=1 && x<=N && y>=1 && y<=N){
	                q.push({h+1,{x,y}});
	            }
	            x-=a;
	            y-=b;
	        }
	        
	    }
	    return -1;
	}

// 1319. Number of Operations to Make Network Connected
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n,vector<int>());
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
             adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int comp=0;
        int wire=0;
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            comp++;
            queue<pair<int,int>> q;
            q.push({i,i});
            while(!q.empty()){
                int p=q.front().first;
                int par=q.front().second;
                q.pop();
                if(vis[p]==1){
                    // cout<<"extra"<<par<<p;
                    wire++;
                    continue;
                }
                vis[p]=1;
                for(auto i:adj[p]){
                    if(i!=par)
                    q.push({i,p});
                }
            }
        }
        if(wire/2>=comp-1){
            return comp-1;
        }
        return -1;
    }


// 127. Word Ladder

     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        unordered_map<string,int> vis;
        for(int i=0;i<wordList.size();i++){
            vis[wordList[i]]=0;
        }
        vis[beginWord]=0;
        while(!q.empty()){
            string w=q.front().first;
            int d=q.front().second;
            q.pop();
            if(vis[w]==1) continue;
            vis[w]=1;
            if(w==endWord) return d+1;
            string temp=w;
            string t2=temp;
            for(int i=0;i<temp.size();i++){
                temp=t2;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(vis.find(temp)!=vis.end()){
                        q.push({temp,d+1});
                    }
                }
            }
            
        }
        return 0;
    }

// Implementing Dijkstra Algorithm 
    	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ans(V,INT_MAX);
        vector<int> vis(V,0);
        set<pair<int,int>> st;
        st.insert({0,S});
        while(!st.empty()){
            int d=(*st.begin()).first;
            int v=(*st.begin()).second;
            st.erase(st.begin());
            if(vis[v]==1) continue;
            vis[v]=1;
            ans[v]=d;
            for(auto i:adj[v]){
                st.insert({d+i[1],i[0]});
            }
        }
        return ans;
    }

// Alien Dictionary 
     string findOrder(string dict[], int N, int K) {
        //code here
        map<char,int> in;
        map<char,int> vis;
        map<char,vector<char>> adj;
        for(int i=0;i<K;i++){
            
            in[i+'a']=0;
            vis['a'+i]=0;
            adj[i+'a']={};
            
        }
        for(int i=1;i<N;i++){
            int p=0;
            int q=0;
            while(p<dict[i-1].size() && q<dict[i].size() && dict[i-1][p]==dict[i][q]){
                p++;
                q++;
            }
            if(p<dict[i-1].size() && q<dict[i].size()){
            adj[dict[i-1][p]].push_back(dict[i][q]);
            // cout<<dict[i-1][p]<<"-";
            // cout<<dict[i][q];
            
            // cout<<"jj";
            in[dict[i][q]]++;
            }
            
        }
        // cout<<"oo"<<in['j']<<adj['g'].size();
        queue<char> q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        string ans="";
        while(!q.empty()){
            char p=q.front();
            q.pop();
            if(vis[p]==1) continue;
            vis[p]=1;
            ans+=p;
            for(auto i:adj[p]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
            
        }
        // for(auto i:in){
        //     cout<< i.first<<" "<<i.second;
        //     for(auto j:adj[i.first]){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<ans;
        return ans;
    }

    	//Function to find sum of weights of edges of the Minimum Spanning Tree.(Prim's algorithm)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set<pair<int,int>> ms;
        ms.insert({0,0});
        vector<int> vis(V,0);
        int ans=0;
        while(!ms.empty()){
            int p=(*ms.begin()).second;
            int d=(*ms.begin()).first;
            ms.erase(ms.begin());
            if(vis[p]==1) continue;
            vis[p]=1;
            ans+=d;
            for(auto i:adj[p]){
                ms.insert({i[1],i[0]});
            }
            
            
        }
        return ans;
    }

    	static bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	    return a.first<b.first;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree. (Kruskal’s algo)
	// Union and find function to detect cycle (DSU method)
	map<int,int> par;
	map<int,int> sizes;
	void Node(int p){
	    par[p]=p;
	}
	int find(int p){
	    if(par[p]==p)
	    return p;
	    return par[p]=find(par[p]);
	}
	int Union(int p,int q){
	    if(find(p)==find(q)){
	        return 1;
	    }
	    if(sizes[find(p)]>sizes[find(q)]){
	         par[find(q)]=find(p);
	    sizes[find(p)]=sizes[find(q)]+sizes[find(p)];
	    }
	    else{
	    par[find(p)]=find(q);
	    sizes[find(q)]=sizes[find(p)]+sizes[find(q)];
	    }
	    return 0;
	}
    int spanningTree2(int V, vector<vector<int>> adj[])
    {
        
        vector<pair<int,pair<int,int>>> edge;
        set<pair<int,int>> st;
        for(int i=0;i<V;i++){
            sizes[i]=1;
            Node(i);
            for(auto j:adj[i]){
                if(st.find({max(j[0],i),min(j[0],i)})!=st.end()) continue;
                st.insert({max(j[0],i),min(j[0],i)});
            edge.push_back({j[1],{max(j[0],i),min(j[0],i)}});
            }
        }
        sort(edge.begin(),edge.end(),cmp);
        int ans=0;
        for(auto i:edge){
            if(!Union(i.second.first,i.second.second)){
                ans+=i.first;
            }
        }
        return ans;
        
    }

    int isNegativeWeightCycle(int n, vector<vector<int>>edges){  //Bellman–Ford Algorithm
	    // Code here
	    vector<int> dis(n,1000000);
	    if(edges.size()>0)
	    dis[edges[0][0]]=0;
	    for(int j=0;j<n-1;j++){
    	    for(int i=0;i<edges.size();i++){
    	        if(dis[edges[i][0]]+edges[i][2]<dis[edges[i][1]]){
    	            dis[edges[i][1]]=dis[edges[i][0]]+edges[i][2];
    	        }
    	    }
	    }
	   // for(int i=0;i<n;i++) cout<<dis[i]<<" ";
	     for(int i=0;i<edges.size();i++){
    	        if(dis[edges[i][0]]+edges[i][2]<dis[edges[i][1]]){
    	            return 1;
    	            dis[edges[i][1]]=dis[edges[i][0]]+edges[i][2];
    	        }
    	    }
    	    return 0;
	}

void shortest_distance(vector<vector<int>>&matrix){   //Floyd Warshall 
	    
	    for(int i=0;i<matrix.size();i++){
	        for(int j=0;j<matrix[0].size();j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1000000;
	            }
	        }
	    }
	   // cout<<"pp";
	    for(int k=0;k<matrix.size();k++){
	         for(int i=0;i<matrix.size();i++){
        	        for(int j=0;j<matrix[0].size();j++){
        	            if(!(i==j || k==i || k==j)){
        	               // cout<<i<<j<<k;
        	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
        	            }
        	        }
        	    }   
	    
	    }
	    for(int i=0;i<matrix.size();i++){
	        for(int j=0;j<matrix[0].size();j++){
	            if(matrix[i][j]==1000000){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    
	}

// Travelling Salesman Problem 
    void ts(vector<vector<int>> &cost,int i,int n,vector<int> vis,int sum,int &ans){
    if(n==cost.size()){
        sum+=(cost[i][0]);
        ans=min(ans,sum);
        return;
    }
    for(int j=0;j<cost.size();j++){
        if(i!=j){
            if(vis[j]==1) continue;
            vis[j]=1;
            sum+=cost[i][j];
            
            ts(cost,j,n+1,vis,sum,ans);
            sum-=cost[i][j];
            vis[j]=0;
        }
    }
}
int total_cost(vector<vector<int>>cost){
    // Code here
    vector<int> vis(cost.size(),0);
    vis[0]=1;
    int sum=0;
    int ans=INT_MAX;
    ts(cost,0,1,vis,sum,ans);
    return ans;
    
}

// 909. Snakes and Ladders

 int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        // if(n==5 && board[4][0]==-1 && board[4][4]==15) return 2;
        queue<pair<int,int>> q;
        q.push({1,0});
        vector<int> vis(n*n+1,0);
        while(!q.empty()){
            int p=q.front().first;
            int d=q.front().second;
            q.pop();
            if(vis[p]==1) continue;
            vis[p]=1;
            if(p>=n*n) return d;
            for(int i=p+1;i<=p+6;i++){
                if(i>=n*n) return d+1;
                int r=n-(i-1)/n-1;
                int c;
                if(((i-1)/n)%2==0){
                    c=(i-1)%n;
                }
                else c=n-(i-1)%n-1;
                if(board[r][c]==-1){
                    q.push({i,d+1});
                }else{
                    if(board[r][c]>=n*n) return d+1;
                    q.push({board[r][c],d+1});
                }
            }
            
        }
        return -1;
    }

    void dfs(vector<vector<int>> &adj,int v,vector<int> &vis,int p,map<pair<int,int>,int> &vv){ //******** not checked all bridges in a graph
         if(vis[v]==1) 
         {
             vv[{min(v,p),max(v,p)}]=1;
             return;
         }
         vis[v]=1;
          
         for(auto i:adj[v]){
             if(i!=p)
            
             dfs(adj,i,vis,v,vv);
             
         }
         vis[v]=0;
     }
     
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V,0);
        map<pair<int,int>,int> vv;
        vector<vector<int>> ss;
        for(int i=0;i<V;i++){
            vector<int> temp;
            for(auto j:adj[i]){
                vv[{min(i,j),max(i,j)}]=0;
                temp.push_back(j);
            }
            ss.push_back(temp);
        }
        vis[0]=0;
        dfs(ss,0,vis,0,vv);
        // for(auto i:vv){
            
        //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second;
        // }
        if(vv[{min(c,d),max(c,d)}]==0) return 1;
        return 0;
        
    }

    //Function to find if the given edge is a bridge in graph.
    int isBridge2(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        queue<int> q;
        q.push(c);
        vector<int> vis1(V,0);
        vector<int> vis2(V,0);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            if(vis1[p]==1) continue;
            vis1[p]=1;
            for(auto i:adj[p]){
                if(i!=d){
                    q.push(i);
                }
            }
        }
        q.push(d);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            if(vis2[p]==1) continue;
            if(vis1[p]==1) return 0;
            vis2[p]=1;
            for(auto i:adj[p]){
                if(i!=c){
                    q.push(i);
                }
            }
        }
        return 1;
    }

    	//Function to find number of strongly connected components in the graph.
	
    void dfs(vector<int> adj[],vector<int> &vis,int v,vector<int> &order){
        if(vis[v]==1) return ;
        vis[v]=1;
        for(auto i:adj[v]){
            dfs(adj,vis,i,order);
        }
        order.push_back(v);
    }

    int kosaraju(int V, vector<int> adj[])
    {
       vector<int> order;
       
       vector<int> vis(V,0);
       vector<int> adj2[V];
       for(int i=0;i<V;i++){
           
           if(vis[i]==1) continue;
            dfs(adj,vis,i,order);
       }
       int ans=0;
       vector<int> vis2(V,0);
       vector<int> rr;
       
       for(int i=0;i<V;i++){
           for(auto j:adj[i]){
               adj2[j].push_back(i);
           }
       }
       
      for(auto it=order.rbegin();it!=order.rend();it++){
        //   cout<<*it;
            if(vis2[(*it)]==1) continue;
            ans++;
            dfs(adj2,vis2,(*it),rr);
      }
    return ans;
       
    }

    	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	  
	    vector<int> col(V,-1);
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	       if(vis[i]==1) continue;
	    col[i]=0;
	    queue<int> q;
	    q.push(i);
	    while(!q.empty()){
	        int p=q.front();
	        q.pop();
	        vis[p]=1;
	        for(auto j:adj[p]){
	            if(vis[j]==1){
	                if(col[j]==col[p]){
	                    return 0;
	                }
	                continue;
	            }
	            col[j]=col[p]^1;
	            q.push(j);
	        }
	    }
	    }
	     
	     return 1;
	   
	    
	}



long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> vis(n,0);
    vector<int> adj[n];
    for(auto &i:astronaut){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    
    long long ans=(n*1LL*(n*1LL-1))/2;
    for(int i=0;i<n;i++){
        if(vis[i]==1) continue;
        long long ct=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            if(vis[p]==1) continue;
            vis[p]=1;
            ct++;
            for(auto j:adj[p]){
                q.push(j);
            }
        }
        ans-=(ct*(ct-1))/2;
        
    }
    cout<<"pp"<<ans;
    return ans;
}

// 787. Cheapest Flights Within K Stops


  int find(vector<vector<vector<int>>> &adj,int s,int d,int k,map<pair<int,int>,int> &mem){
        if(s==d) return 0;
        if(k<0){
            
            return 1000000;
        }
        if(mem[{s,k}]!=-1) return mem[{s,k}];
        int mi=1000000;
        for(auto i:adj[s]){
            mi=min(mi,i[1]+find(adj,i[0],d,k-1,mem));
        }
        return mem[{s,k}]=mi;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n,vector<vector<int>>());
        map<pair<int,int>,int>mem;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                mem[{i,j}]=-1;
            }
        }
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        int ans=find(adj,src,dst,k,mem);
        return ans>=100000?-1:ans;
       
    }


    void dfs(vector<vector<int>> &adj,int i,map<int,pair<int,int>> &time,int &t,vector<int> &vis){
	if(vis[i]==1) return ;
	vis[i]=1;
	time[i].first=t++;
	for(auto j:adj[i]){
		if(vis[j]==0)
		dfs(adj,j,time,t,vis);
	}
	time[i].second=t++;
}
int dfsTimeQuestion() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 0 ; i < n-1 ; i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	map<int,pair<int,int>> time;
	vector<int> vis(n+1,0);
	int t=0;
	dfs(adj,1,time,t,vis);
	int qu;
	cin>> qu;

	for(int i=0;i<qu;i++){
		int d,a,b;
		cin>>d>>a>>b;
		if(d==0){
			if(time[a].first<time[b].first && time[b].second<time[a].second){
				cout<<"YES";
			}
			else{
				cout<<"NO";
			}
		}else{
			if(time[a].first>time[b].first && time[b].second>time[a].second){
				cout<<"YES";
			}
			else{
				cout<<"NO";
			}
		}
		cout<<"\n";
	}
	return 0;
}
struct State{
    pair<int,int> data;
    State* next;
    State(pair<int,int> x){
        data=x;
        next=NULL;
    }

};

void JugProb(int n,int m, int d){

    vector<vector<int>> vis(n+1,vector<int>(m+1,0));
    queue<State*> q;
    
    int f=0;
    State* temp=new State({0,0});
    q.push(temp);
    State* ans;
    while (!q.empty())
    {
        State* temp=q.front();
        int j1=temp->data.first;
        int j2=temp->data.second;
        // cout<<j1<<j2;
        q.pop();
        if(j1>n || j2>m || vis[j1][j2]==1) continue;
        vis[j1][j2]=1;
        if(j1==d || j2==d){
            ans=temp;
            f=1;
            break;
        }
        State* t1=new State({n,0});
        t1->next=temp;
        q.push(t1);
        State* t2=new State({0,m});
        t2->next=temp;
        q.push(t2);
        State* t3=new State({j1,m});
        t3->next=temp;
        q.push(t3);
        State* t4=new State({n,j2});
        t4->next=temp;
        q.push(t4);
        State* t5=new State({j1,0});
        t5->next=temp;
        q.push(t5);
        State* t6=new State({0,j2});
        t6->next=temp;
        q.push(t6);
        int p1,p2;
        int k=j1+j2;
        if(k>=n){
            p1=n;
            p2=j2-(n-j1);
        }else{
            p1=j1+j2;
            p2=0;
        }
        State* t7=new State({p1,p2});
        t7->next=temp;
        q.push(t7);
        k=j1+j2;
        if(k>=m){
            p2=m;
            p1=j1-(m-j2);
        }else{
            p1=0;
            p2=j1+j2;
        }
        State* t8=new State({p1,p2});
        t8->next=temp;
        q.push(t8);
    }
    if(f==0){
        cout<<-1<<"\n";
    }
    else{
        cout<<"find\n";
        while (ans!=NULL)
        {
            cout<<ans->data.first<<" "<<ans->data.second<<"\n";
            ans=ans->next;
        }
        
    }
    

}
int main(){

    // g.makeEdge(0,1);
    // g.makeEdge(2,1);
    // g.makeEdge(3,1);
    // cout<<g.noOfEdge;   
    // g.printGraph();
    // g.deleteEdge(1,0);
    // cout<<g.noOfEdge;
    // JugProb(10,9,5);


    return 0;
}