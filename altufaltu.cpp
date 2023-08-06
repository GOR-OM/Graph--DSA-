
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


string getString(string str) {
    int n = str.size();
    vector<vector<int>>mp(26);
    for(int i=0;i<n;i++){
        mp[str[i]-'a'].push_back(i);
    }
   vector<pair<int,int>>fi;
    int pre= 0;
    for(int i=25;i>=0;i--){
        if(mp[i].empty())continue;
        
        if(lower_bound(mp[i].begin(),mp[i].end(),pre)==mp[i].end()){
            int k = mp[i].size();
            pre = mp[i][k-1];
           
            fi.push_back({pre,i});
            
        }
        else {
            pre = *lower_bound(mp[i].begin(),mp[i].end(),pre);
            
            fi.push_back({pre,i});
        }
        
    }
   
    sort(fi.begin(),fi.end());
    
    string ans ;
    for(auto i  :fi){
       char p = 'a' + i.second ; 
       ans.push_back(p);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string input_str;
    getline(cin, input_str);

    string result = getString(input_str);
    cout<<result<<endl;

    fout << result << "\n";

    fout.close();

    return 0;
}