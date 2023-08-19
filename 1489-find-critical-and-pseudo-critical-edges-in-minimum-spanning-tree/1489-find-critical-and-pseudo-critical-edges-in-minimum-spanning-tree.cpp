struct DSU{
    int parent[101];
    int size[101];
    DSU(int n){
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};
int sz;
class Solution {
private:
    int kruskal(vector<vector<int>>& edges, int n, int skip, int pick){
        DSU dsu(n);
        int sum = 0;

        if(pick > -1){
            dsu.unionBySize(edges[pick][0],edges[pick][1]);
            sum += edges[pick][2];
            n--;
        }

        for(int i=0; i<sz; i++){
            if(skip == i) continue;
            int u = edges[i][0];
            int v = edges[i][1];

            if(dsu.unionBySize(u,v)){
                sum += edges[i][2];
                n--;
            }
        }
        
        if(n == 1) return sum;
        return 1e9;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        sz = edges.size();
        for(int i=0; i<sz; i++){
            edges[i].push_back(i);
        }
        auto comp = [&](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };
        sort(edges.begin(),edges.end(),comp);

        int mst_wt = kruskal(edges,n,-1,-1);

        vector<int> critical;
        vector<int> pseudo;
        for(int i=0; i<sz; i++){

            if(kruskal(edges,n,i,-1) > mst_wt){
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(edges,n,-1,i) == mst_wt){
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical,pseudo};
    }
};