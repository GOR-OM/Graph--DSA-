
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





void dfs(int i, int j, int n, int m, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
    visited[i][j] = true;

    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (int d = 0; d < 4; ++d) {
        int x = i + directions[d][0];
        int y = j + directions[d][1];

        if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && heights[x][y] >= heights[i][j]) {
            dfs(x, y, n, m, heights, visited);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
        return {};
    }

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

   
    for (int i = 0; i < n; ++i) {
        dfs(i, 0, n, m, heights, pacific);
        dfs(i, m - 1, n, m, heights, atlantic);
    }

    for (int j = 0; j < m; ++j) {
        dfs(0, j, n, m, heights, pacific);
        dfs(n - 1, j, n, m, heights, atlantic);
    }

    vector<vector<int>> result;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({ i, j });
            }
        }
    }

    return result;
}







int main(){

    



    return 0;
}