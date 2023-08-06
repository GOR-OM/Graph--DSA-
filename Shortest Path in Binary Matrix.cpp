
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
  {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}  
};

 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n= grid.size();
    if(grid[0][0]==1|| grid[n-1][n-1]==1)return -1;
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({1,{0,0}});
    vector<vector<int>>dis(n,vector<int>(n,1e9));
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int ix = p.second.first;
        int iy = p.second.second;
        int wt = p.first;
        grid[ix][iy]=1;

        for(auto j : moves){
            int xx= ix+ j.first;
            int yy =iy+ j.second;
            if(xx>=n || xx<0 || yy<0 ||yy>=n|| grid[xx][yy]==1)continue;
            if(dis[xx][yy]>dis[ix][iy]+1){
                dis[xx][yy] =dis[ix][iy]+1;
                q.push({dis[xx][yy],{xx,yy}});
            }
        }
        grid[ix][iy]=0;
    }
    if(dis[n-1][n-1]==1e9){
        return -1;
    }
    return dis[n-1][n-1];
    


    
}

int main(){

    



    return 0;
}