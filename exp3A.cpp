//zorojuro clean temp

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define min_pq priority_queue<pll, vector<pll>, greater<pll>>
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


void solve();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1; 
    // cin>>t;
    while(t--){
        solve();
    }
}

// pseudocode first soln later 
    // check for edge cases 
    // skip during contest if takes time never skip while solving 
    // rewrite if taking long to debug 
    // dont jump to editorial directly
    // write  bf first while practising 


    /*observations / thoughtflow->

    */

    /* algo -> 

    */

    /* Golden rules 
        1) Solutions are simple.
        2) Proofs are simple.
        3) Implementations are simple.
    */
typedef struct Process{
    ll id;
    ll at;
    ll bt;
    ll ct=0;
    ll rmt=0;
    ll tat =0;
    ll wt =0;
}p;

void solve(){
    
    // int pid; 
   

    cout<<"Enter number of process"<<endl;
    int n ;
    cin>>n;

    // vll process(n);
    vector<p>v(n);

    cout<<"Enter arrival time of process"<<endl;
    rep(i,0,n){
        v[i].id = i + 1; 
        cin>>v[i].at;
    }    
    cout<<"Enter Burst time of process"<<endl;
    rep(i,0,n){
        cin>>v[i].bt;
        v[i].rmt = v[i].bt;
    }    
    

    int current_time =0;
    int i =0;
    min_pq pq;
    // pq.push();
    auto cmp = [&](auto &p1,auto &p2){
        return p1.at<p2.at;
    };
    sort(all(v),cmp);
    int completed=0;
    while(completed<n){
        while(i<n && v[i].at<= current_time){
            pq.push({v[i].rmt,i});
            i++;
        }

        if(pq.empty()){
            current_time++;
        }
        auto [rem,idx] = pq.top(); pq.pop();
        v[idx].rmt--;
        current_time++;

        if(v[idx].rmt==0) {v[idx].ct = current_time;completed++;}
        else pq.push({v[idx].rmt,idx});

    
        
    }
         for (int i = 0; i < n; i++) {
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt  = v[i].tat - v[i].bt;
    }
    sort(all(v), [](const p &a, const p &b) { return a.id < b.id; });
    cout << "\nID AT BT CT TAT WT\n";
    for (auto &x : v) {
        cout << x.id << " "
             << x.at << " "
             << x.bt << " "
             << x.ct << " "
             << x.tat << " "
             << x.wt << "\n";
    }
    

    
}