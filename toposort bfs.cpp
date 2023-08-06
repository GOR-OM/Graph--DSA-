
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


vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    
    vector<int>intake(nodes,0);
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
        intake[graph[i][1]]++;
    }
    queue<int>q;
    for(int i=0;i<nodes;i++){
        if(intake[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        ans.push_back(i);
        for(auto child : adj[i]){
            intake[child]--;
            if(intake[child]==0){
                q.push(child);
            }
        }

    }
    return ans ;
    
   
}



int topologicalSort(vector<pair<int,int>>&graph, int edges, int nodes) {
    
    vector<int>intake(nodes+1,0);
    vector<int>adj[nodes+1];
    for(int i=0;i<edges;i++)
    {
        adj[graph[i].first].push_back(graph[i].second);
        intake[graph[i].second]++;
    }
    queue<int>q;
    for(int i=0;i<nodes;i++){
        if(intake[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        ans.push_back(i);
        for(auto child : adj[i]){
            intake[child]--;
            if(intake[child]==0){
                q.push(child);
            }
        }

    }

    if(ans.size()==nodes)return 0;
    return 1 ;
    
   
}






int main(){

    



    return 0;
}