/*langugae used is c++*/
#include <bits/stdc++.h> 
using namespace std; 
#define pb push_back
#define N 300000 

vector<int> adjacencymatrix[N]; 
int hght[N], dt[N]; 



void help1(int node, int nbr) { 
	for (auto u : adjacencymatrix[node]) { 
		if (u != nbr) { 
			help1(u, node); 
			hght[node] = max(hght[node], hght[u]); 
		} 
	} 
	hght[node] += 1; 
} 
void AE(int u, int v) { //function to add an edge
	adjacencymatrix[u].pb(v);  
	adjacencymatrix[v].pb(u); 
} 
void help2(int src, int nbr) { 
	int max1 = 0, max2 = 0; 
	for (auto u : adjacencymatrix[src]) { 
		if (u != nbr) {  
			if (hght[u] >= max1) { 
				max2 = max1; 
				max1 = hght[u]; 
			} 
			else if (hght[u] > max2) { 
				max2 = hght[u]; 
			} 
		} 
	} 

	int sum = 0; 

	for (auto u : adjacencymatrix[src]) { 
		if (u != nbr) { 
			sum = ((max1 == hght[u]) ? max2 : max1); 
			if (max1 == hght[u]) 
				dt[u] = 1 + max(1 + max2, dt[src]); 
			else
				dt[u] = 1 + max(1 + max1, dt[src]); 

			help2(u, src); 
		} 
	} 
} 

int main() { 
	int n, u, v; //n= number of nodes
                //u and v defines the node which have connection
	cin>>n; 
	for(int i=1;i<n;i++){
		cin>>u>>v;
		AE(u, v);
	}

	help1(1, 0); // hepler function for the creating dfs for the graph
	help2(1, 0); //helper function for the help1

	for (int i = 1; i <= n; i++) 
		cout << (max(dt[i], hght[i]) - 1) << " "; 

	return 0; 
}
// time complexity is O(N)