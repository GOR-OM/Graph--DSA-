
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



int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>>g[n+1];
    int m = times.size();

    for(int i=0;i,m;i++){
        g[times[i][0]].push_back({times[i][1],times[i][2]});

    }
    vector<int>dis(n+1,1e9);
    dis[k]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,k});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int dist = p.first;
        int ix  =p.second;
        for(auto j : g[ix])
        {
            int wt = j.second;
            int xx =j.first;
            if(dis[xx]>dis[ix]+wt){
                dis[xx]= dis[ix]+wt;
                q.push({dis[xx],xx});
            }
        }
    }
    int maxi = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==1e9)return -1;
        maxi = max(maxi,dis[i]);
    }
    return maxi;

 }

int main(){

    



    return 0;
}