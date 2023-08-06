
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

vector<pair<int,int>>moves={
    {1,0},{0,1},{-1,0},{0,-1}
};

int minimumEffortPath(vector<vector<int>>& heights) {
    int n= heights.size();
    int m= heights[0].size();
    vector<vector<int>>dis(n,vector<int>(m,1e9));
    dis[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,0}});
    while(!q.empty()){
        auto p= q.top();
        q.pop();
        int ix= p.second.first;
        int iy = p.second.second;
        int wt = p.first;

        for(auto child : moves){
            int xx = ix + child.first;
            int yy = iy + child.second;
            if(xx<0 || xx>=n || yy<0 || yy>=m || heights[xx][yy]==-1)continue;
            if(dis[xx][yy]> max(dis[ix][iy],abs(heights[ix][iy]-heights[xx][yy]))){
                dis[xx][yy] = max(dis[ix][iy],abs(heights[ix][iy]-heights[xx][yy]));
                q.push({dis[xx][yy],{xx,yy}});
            }
      }
      return dis[n-1][m-1];

    }
}


// DFS :)

vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool dfs(vector<vector<int>>& heights, int n, int m, int x, int y, int effort, vector<vector<bool>>& visited) {
    if (x == n - 1 && y == m - 1) {
        return true; // Reached the bottom-right cell
    }

    visited[x][y] = true;

    for (auto child : moves) {
        int xx = x + child.first;
        int yy = y + child.second;

        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy]) {
            int curEffort = abs(heights[x][y] - heights[xx][yy]);
            if (curEffort <= effort && dfs(heights, n, m, xx, yy, effort, visited)) {
                return true;
            }
        }
    }

    return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    int left = 0, right = 1e6; // As per constraints

    while (left < right) {
        int mid = left + (right - left) / 2;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        if (dfs(heights, n, m, 0, 0, mid, visited)) {
            right = mid; // Effort is possible, try to minimize it
        } else {
            left = mid + 1; // Effort is not possible, try higher value
        }
    }

    return left;
}







int main(){

    



    return 0;
}