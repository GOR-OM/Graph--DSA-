
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



vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<pair<int,int>>g[vertices];
    for(int i=0;i<edges;i++){
        g[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        g[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }
    vector<int>val(vertices,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,source});
    val[source]=0;
    while(!q.empty()){
        int wtx = q.top().first;
        int ix = q.top().second;
        for(auto child : g[ix]){
            int wt = child.second;
            int i = child.first;
            if(val[i]<val[ix]+ wt){
                val[i]= val[ix]+ wt; 
                q.push({val[i],i});
            }

        }
    }
    for(int i=0;i<vertices;i++)
    {
        if(val[i]==1e9){
            val[i]=-1;
        }
    } 
    return val;   

}






int main(){

    



    return 0;
}