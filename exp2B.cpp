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
    #define min_pq priority_queue<pii, vector<pii>, greater<pii>>
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
        auto cmp1 = [&](auto &a,auto &b){
    
            return a.id<b.id;
        };
        sort(all(p),cmp);
        min_pq pq;
        vector<P> ans;

        int current_time = 0;
    int i =0;
    while(i<n || !pq.empty()){
        while(i<n && p[i].at <=current_time){
            pq.push({p[i].bt,i});
            i++;
        }
        if(pq.empty()){
            current_time = p[i].at; continue;
        }
        auto [bt,idx] = pq.top();
        pq.pop();

        current_time+= bt;
        p[idx].ct = current_time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat-p[idx].bt;


        ans.push_back(p[idx]);
    }
    sort(all(ans),cmp1);

        cout << "PID  AT  BT  CT  TAT  WT\n";
        for (auto &x : ans) {
            cout << x.id << "   "
                << x.at << "   "
                << x.bt << "   "
                << x.ct << "   "
                << x.tat << "    "
                << x.wt << "\n";
        }

        
    }