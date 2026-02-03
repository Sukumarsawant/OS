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
#define max_q priority_queue<int>
#define min_q priority_queue<pll, vector<pll>, greater<pll>>
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
    cin>>t;
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
    for(int i=1;i<=n;++i) v[i-1].id = i;
    cout<<"Enter arrival time of process"<<endl;
    rep(i,0,n){
        
        cin>>v[i].at;
    }    
    cout<<"Enter Burst time of process"<<endl;
    rep(i,0,n){
        cin>>v[i].bt;
        v[i].rmt = v[i].bt;
        
    }    
    

    int current_time =0;
    int i =0;
    queue<pll> q;
    // q.push();
    auto cmp = [&](auto &p1,auto &p2){
        return p1.at<p2.at;
    };
    sort(all(v),cmp);
    int completed=0;
    //preamptive we count completed 
    
    while(completed<n){
        while(i<n && v[i].at<= current_time){
            q.push({v[i].rmt,i});
            i++;
        }
        // no process arrived no process executing 
        if(q.empty()){
            current_time++;continue;
        }
        auto [rem,idx] = q.front(); q.pop();
        v[idx].rmt-= min(3LL,rem+ 0LL);
        current_time+=min(3LL,rem+ 0LL);


         while(i<n && v[i].at<= current_time){
            q.push({v[i].rmt,i});
            i++;
        }
        if(v[idx].rmt==0) {v[idx].ct = current_time;completed++;}
        else q.push({v[idx].rmt,idx});

       

}
  for (int i = 0; i < n; i++) {
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt  = v[i].tat - v[i].bt;
    }
    cout << "\nID AT BT RT CT TAT WT\n";
    for (auto &x : v) {
        cout << x.id << " "
             << x.at << " "
             << x.bt << " "
             << x.rmt<<" "
             << x.ct << " "
             << x.tat << " "
             << x.wt << "\n";
    }


        
    }

    

    
