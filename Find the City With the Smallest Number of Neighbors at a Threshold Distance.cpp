
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


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>dp(n,vector<int>(n,1e9));
    for(auto it : edges)
    {
        int p = it[0];
        int q = it[1];
        int wt = it[2];
        dp[p][q]=wt;
    }
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j,n;j++)
            {
                if(dp[i][k]!=1e9 && dp[k][j]!=1e9){
                    dp[i][j] =min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
      vector<int> reachableCities(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dp[i][j] <= distanceThreshold) {
                reachableCities[i]++;
            }
        }
    }

    // Find the city with the smallest number of reachable cities and the greatest city number in case of a tie
    int smallestCities = INT_MAX, city = -1;
    for (int i = 0; i < n; i++) {
        if (reachableCities[i] <= smallestCities) {
            smallestCities = reachableCities[i];
            city = i;
        }
    }

    return city;

}







int main(){

    



    return 0;
}