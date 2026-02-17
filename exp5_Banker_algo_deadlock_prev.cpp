#include<bits/stdc++.h>
using namespace std;
//no. of resources
// resource array 
// max array 


#define pb push_back
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<ll,ll>>;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define pyes cout<<"YES"<<endl
#define pno cout<<"NO"<<endl
#define rt return
#define endl '\n'
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define tc  cerr << "Time: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";
#define MOD 100000000007
#define MAX_SIZE 200001
#define ps(x, y) fixed << setprecision(y) << x

ll INF = 1e18;

#ifdef ONLINE_JUDGE
#define debug(x...)
#define debugmul(v...)
#else
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugmul(v...) cerr<< "[" << #v <<"] = ["; __print_auto(v)
#define um unordered_map
void __print(auto x){ cerr << x; }
template <typename T, typename U>
void __print(const pair<T, U>& p) { cerr << "{"; __print(p.first); cerr << ","; __print(p.second); cerr << "}"; }
void _print() {cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
void __print_auto(){cerr << "]\n";}
template<typename T,typename... V>
void __print_auto(const T &x, const V&... y) {
    int f = 0;
    cerr << '{';
    for (const auto &i: x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
    if (sizeof...(y)) cerr << ", ";
    __print_auto(y...);
}
#endif


signed main(){
    int n ; cin>>n;
    int np ; cin>>np;
    vector<int> avail(n,0);
    vector<vector<int>>maxi(np,vector<int>(n,0));
    vector<vector<int>>res(np,vector<int>(n,0));
    vector<vector<int>>need(np,vector<int>(n,0));


    //avail resources
    for(int i =0 ; i<n ;++i){
        cin>>avail[i];
    }

    //max resources needed 
    for(int i =0 ;i <np;++i){
        for(int j = 0; j<n ; ++j){
            cin>>maxi[i][j];
        }
    }
    
    //alloted resources 
    for(int i =0 ;i<np;++i){
        for(int j =0 ; j<n; ++j){
            cin>>res[i][j];
        }
    }

    //need
    for(int i =0 ;i<np;++i){
        for(int j =0 ; j<n; ++j){
            need[i][j] = maxi[i][j] - res[i][j];
        }
    }
    int ct =0;
    set<int>s;
    
    while(ct<np){
        bool safe  =false;
    for(int i = 0; i<np; ++i){
        if(s.count(i)) continue;
        bool check = true;
        
        for(int j =0 ; j<n;++j){
            if(need[i][j]>avail[j]){
                check = false;break;
            }
           
            
        }
        if(check){

            
            for(int j = 0 ; j<n;++j){
                avail[j] +=res[i][j]; 
                res[i][j] = 0;
                need[i][j] = 0;
            }
            // debugmul(avail,ct);
            // if(s.count(i)==0){
            cout<<"Process "<<i+1<<" is completed"<<endl;
            ct++;
            s.insert(i);
            safe = true;
            // }
        }
        
    }
    
    if(!safe){
        cout<<"system is in Unsafe state "<<endl;
        return 0;
    }
    
    }
}
 
/*

3
4                                                                                                             
2 4 1
2 4 6
1 3 0
5 6 0
0 5 3
1 3 4
0 1 0
2 2 0
0 3 2

*/