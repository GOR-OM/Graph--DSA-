
/*


░██████╗░  ░█████╗░  ██████╗░
██╔════╝░  ██╔══██╗  ██╔══██╗
██║░░██╗░  ██║░░██║  ██████╔╝
██║░░╚██╗  ██║░░██║  ██╔══██╗
╚██████╔╝  ╚█████╔╝  ██║░░██║
░╚═════╝░  ░╚════╝░  ╚═╝░░╚═╝


░█████╗░███╗░░░███╗
██╔══██╗████╗░████║
██║░░██║██╔████╔██║
██║░░██║██║╚██╔╝██║
╚█████╔╝██║░╚═╝░██║
░╚════╝░╚═╝░░░░░╚═╝




                   YAao,
                    Y8888b,
                  ,oA8888888b,
            ,aaad8888888888888888bo,
         ,d888888888888888888888888888b,
       ,888888888888888888888888888888888b,
      d8888888888888888888888888888888888888,
     d888888888888888888888888888888888888888b
    d888888P'                    `Y888888888888,
    88888P'                    Ybaaaa8888888888l
   a8888'                      `Y8888P' `V888888
 d8888888a                                `Y8888
AY/'' `\Y8b                                 ``Y8b
Y'      `YP                                    ~~
         `'

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define ha cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define fr(x,n) for(int i=x;i<n;i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
const long long mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;


class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
    DisjointSet ds(n * m);
    vector<pair<int, int>> moves = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (auto it : moves) {
                    int xx = it.first + i;
                    int yy = it.second + j;
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1) {
                        ds.unionBySize(i * m + j, xx * m + yy);
                    }
                }
            }
        }
    }

    vector<int> componentSize(n * m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                int root = ds.findUPar(i * m + j);
                componentSize[root]++;
                ans = max(ans, componentSize[root]);
            }
        }
    }

    return ans;
    }





int main(){

    



    return 0;
}