class DSU
{

    private:
        vector<int> parent, sz;
public:
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find_par(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = find_par(parent[node]);
    }

    void Union(int a, int b)
    {
        int par_a = find_par(a);
        int par_b = find_par(b);

        if (par_a != par_b)
        {
            if (sz[par_a] < sz[par_b])
                swap(par_a, par_b);

            parent[par_b] = par_a;

            sz[par_a] += sz[par_b];
        }
    }
};

class Solution
{

    public:
        bool equationsPossible(vector<string> &equations)
        {

            DSU ds(26);

            for (auto x: equations)
            {
                int v1 = x[0];
                int eq = x[1];
                int v2 = x[3];

                if (eq == '=')
                {
                    int a = ds.find_par( v1 - 'a');
                    int b = ds.find_par( v2 - 'a');   
                    
                    if(a!=b)
                    {
                        ds.Union(a,b);
                    }
                }
            }

            for (auto x: equations)
            {
                int v1 = x[0];
                int eq = x[1];
                int v2 = x[3];

                if (eq == '!')
                {
                    int a = ds.find_par(v1 - 'a');
                    int b = ds.find_par(v2 - 'a');

                    if (a == b)
                        return false;
                }
            }

            return true;
        }
};