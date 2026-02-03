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

typedef struct Process{
    ll id=0;
    ll at=0;
    ll bt=0;
    ll ct=0;
    ll tat=0;
    ll wt=0;
}P;
void solve(){
    int n; cin>>n;
    vector<P>p(n);

    cout<<"Enter The arrival Time and the burst time "<<endl;
    for(int i =1;i<=n;++i) p[i-1].id = i;
    for(int i =0;i<n;++i) cin>>p[i].at>>p[i].bt;

    auto cmp = [&](auto &a,auto &b){
        if(a.at == b.at){
            return a.id <b.id ;
        }
        return a.at<b.at;
    };
    sort(all(p),cmp);

    int current_time = 0;
    for(int i =0;i<n;++i){
        if(p[i].at>current_time) current_time = p[i].at;
        // if 0->5 first pid runs and then there is GAP 

        current_time +=p[i].bt;

        p[i].ct = current_time;
        p[i].tat = p[i].ct - p[i].at;// tat = ct - at
        p[i].wt = -p[i].bt + p[i].tat ;// tat  = wt + bt


    }

     cout << "PID  AT  BT  CT  TAT  WT\n";
    for (auto &x : p) {
        cout << x.id << "   "
             << x.at << "   "
             << x.bt << "   "
             << x.ct << "   "
             << x.tat << "    "
             << x.wt << "\n";
    }

      
}