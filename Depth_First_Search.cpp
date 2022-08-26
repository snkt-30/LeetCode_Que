#include"bits/stdc++.h"
using namespace std;

#define ll long long int 
#define ull unsigned long long int

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define forn(i,n) for(ll i = 0; i < n; i++)
#define forsn(i,s,n) for(ll i = s; i < n; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,n) for(ll i = s; i >= n; i--)

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define umii unordered_map<int,int>
#define umsi unordered_map<string,int>
#define umci unordered_map<char,int>
#define usi unordered_set<int>
#define usc unordered_set<char>
#define spi set<pair<int,int>>
#define si set<int>
#define sti stack<int>
#define stc stack<char>
#define stpi stack<pair<int,int>>

 
void dfs(vector<bool>&vis,vector<int>adj[], int node)
{
	vis[node]=1;
	cout<<node<<" ";

	for(auto x:adj[node])
	{
		if(!vis[x])
		{
			// vis[node]=1;
			dfs(vis,adj,x);
		}
	}
}


int main()
{
	int node,e;
	cin>>node>>e;

	vector<int>adjls[node+1];
	vector<bool>vis(node+1,0);

	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;

     // making adjacency list for undirected graph
		adjls[u].pb(v);
		adjls[v].pb(u);
	}

	for(int i=0;i<node;i++)
	{
		if(!vis[i])
		{
			dfs(vis,adjls,i);
		}
	}


}

