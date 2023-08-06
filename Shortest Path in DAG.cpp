
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


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<int>val(n,1e9);
    vector<int>inco(n,0);
    vector<pair<int,int>>g[n];
    for(int i=0;i<m;i++){
        g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        inco[edges[i][1]]++;
    }
    queue<int>q;
    q.push(0);
    val[0]=0;
    while(!q.empty()){
        int i= q.front();
        q.pop();
        for(auto chi : g[i]){
            int idx= chi.first;
            int wt = chi.second;
            if(val[idx]>val[i]+wt){
                val[idx]= val[i]+wt;
                q.push(idx);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(val[i]==1e9){
            val[i]=-1;
        }
    }
    return val;
    
    

}


int main(){

    



    return 0;
}