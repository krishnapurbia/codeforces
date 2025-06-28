#include <bits/stdc++.h>
// #include <ctime> // for clock() and CLOCKS_PER_SEC
// #include <sys/resource.h>
// #include <iostream>
// #include <cstdlib>


// void capMemory(size_t M_bytes) {
//     struct rlimit rl;
//     // RLIMIT_AS caps total address space (stack + heap + code)
//     rl.rlim_cur = M_bytes;
//     rl.rlim_max = M_bytes;
//     if (setrlimit(RLIMIT_AS, &rl) != 0) {
//         perror("setrlimit");
//         std::exit(1);
//     }
// }





using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pip;
typedef pair<ll, ll> plip;
 
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<ll> vli;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vli> vvli;
typedef vector<pip> vpip;
typedef unordered_set<ll> usi;
typedef set<ll> si;
typedef priority_queue<ll> pq;
typedef unordered_map<ll, ll> umpi;
typedef map<ll, ll> mpi;
 
const int MOD = 1000000007;
 
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define Be(v) (v).begin()
#define Ee(v) (v).end()
#define Pb push_back
#define Mp make_pair
#define Sz(v) ((int)(v).size())
#define F first
#define S second
#define pr(v) cout << v << endl;
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
 
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
//EndCodeSnip
// jai sia ram
/*
        _________________
        |                |
        |                |
--------                 -------
|            made by kp        |
|                              |
|-------====__________=====____|
 
 */
 
auto comp (const plip & a , const plip & b ) {
    return tie(a.F , a.S) < tie(b.F , b.S);
}
auto compgreater (const plip & a , const plip & b ) {
    return tie(a.F , a.S) > tie(b.F , b.S);
}
 
ll mod_exp(ll b, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        exp /= 2;
    }
    return result;
 }
 
ll mod_inverse(ll a, ll mod) {
    return mod_exp(a, mod - 2, mod);
}



void lightsoff(){
        int n , t; cin >>  t >> n;
         // cyc , dp 
         vvi cyc(  (3*n+1) , vi(n) );
         for( int j = 1; j <= 3*n;j++)
                                            {
        for( int i = 0; i < n;i++){
                    cyc[j][i] = ( 1 <<i )  ^ ( cyc[j-1][(i+1)%n]);
            }
        }
        vector < vector <int >> dp ( 3*n+1 , vector<int>((1 <<  n) + 1)); // true or false
        dp[0][0] = 1;
        for( int turn =  1 ; turn <= 3*n ;turn++){
            for( int mask = 0 ; mask< (1 <<n); mask++){
                for( int i = 0; i < n; i++){
                  
                        if ( dp[turn-1][mask ^ ( cyc[turn][i])]){
                            dp[turn][mask] = 1;
                            break;
                        }
                    
                }
            }
        }
        for( int i = 0; i < t;i++){
            string a, b ;cin>>a>>b;
            reverse(ALL(a));
            reverse(ALL(b));
            int c = stoi(a , nullptr , 2);
            int d = stoi(b,nullptr,2);
            int pad = 0;
            for( int i = 0; i < 3*n+1;i++){
                int padd = c ^ pad;
                if (dp [ i][ padd]){
                    cout <<i <<endl;
                    break;
                }
                pad <<= 1;
                pad ^= d;
                if ( pad >= (1 << n)){
                        pad ^= ( 1 << n);
                        pad ^= 1;
                }
            }
        }

}

/*
void vorin(ll l) {
        ll l ;
        vi a( 19 + 1);
        ll tmp = l;
        int i=0;
        while( tmp ){
            a[i++] = tmp %10;
            tmp /=10;
        }
        vector < vector < vvli > > dp ( 19 +2 , vector < vvli >  (2 , vvli ( 2 , vli( 2)))); // dp [ i ] [ tight == 1 ][ odd == 1 ][ld == 1]
        dp[20][1][1][1] = 1;
        for  ( int i = 20; i >=0 ;i--) {
            ll tight = 1;
            {
                    ll ld = 0;
                    {
                           for( int i = 0; i < min(10,a[i-1] ), i++){
                                dp[i-1][0][1][0] += dp[i][tight][0][0];
                                dp[i-1][0][0][0] += dp[i][tight][1][0];
                           }     
                           dp[a[i-1]][tight][1][ld] +=  dp[a[i-1]][tight][1][ld]
                    }
                    ld = 1;
                    {

                    }
            }
            tight = 0;
            {
                ll ld = 0;
                {

                }
                ld = 1;
                {

                }
            }

            for( int tight = 0; tight < 2;tight++){
            if ( tight == 0){
                for( int dig = 0; dig < 10 ;dig++){

                }
            }
            else {
                for( int dig = 0; dig < min(10 , a[i-1]) ;dig++){
                        if ( dig == 0){
                            if ( ld == 1){
                                dp[i+1][]
                            }
                        }
                }

            }   
        }
        }
        
}
        */
    



 ll dp [2000 + 1][2000+1][2][2]; // pos , utight , ltight , started
string num1 ,num2; // nums1 -- l , nums2 -- r
ll d , m;
vli u ;
ll process(ll pos , ll num , bool utight , bool ltight , ll even ){
    if ( pos == num1.size() ){
        if ( num % m == 0) return 1;
        return 0;
    }
    if(dp[pos][num][utight][ltight] !=-1) return dp[pos][num][utight][ltight];
    ll ans = 0;
    if ( utight && ltight){
            for( ll i = num1[pos] -'0' ; i <= num2[pos]-'0';i++){
                if ( even && i != d)continue;
                if ( !even && i == d)continue;
                bool nu = ( i == num2[pos]-'0');
                bool nl = (i ==  num1[pos] -'0');
                ll res = ((i%m) * ( u[pos]) ) %m;
                res = (res + num)%m;
                ll debri =  process(pos+1 , res, nu,nl,!even);
                ans += debri;
                ans%= MOD;
            }
    }
    else if(ltight){
        for( ll i = num1[pos] -'0' ; i <= 9;i++){
                if ( even && i != d)continue;
                if ( !even && i == d)continue;
                 bool nu = 0;
                 bool nl = (i ==  num1[pos] -'0');
                 ll res = ((i%m) * ( u[pos]) ) %m;
                 res = (res + num)%m;
                 ll debri =  process(pos+1 , res, nu,nl,!even);
                 ans += debri;
                 ans%= MOD;
         }

    }
    else if(utight){
        for( ll i = 0 ; i <= num2[pos]-'0';i++){
                if ( even && i != d)continue;
                if ( !even && i == d)continue;
                 bool nu = ( i == num2[pos]-'0');
                 bool nl = 0;
                 ll res = ((i%m) * ( u[pos]) ) %m;
                 res = (res + num)%m;
                 ll debri =  process(pos+1 , res, nu,nl,!even);
                 ans += debri;
                 ans%= MOD;
         }

    }
    else{
        for( ll i =0 ; i <= 9 ;i++){
                if ( even && i != d)continue;
                if ( !even && i == d)continue;
                 bool nu = 0;
                 bool nl = 0;
                 ll res = ((i%m) * ( u[pos]) ) %m;
                 res = (res + num)%m;
                 ll debri =  process(pos+1 , res, nu,nl,!even);
                 ans += debri;
                 ans%= MOD;
         }
    }
  
    return dp[pos][num][utight][ltight] = ans;
}

ll  ons(){
    for(auto &a : dp){
        for( auto &b:  a){
            for( auto &c: b){
                for( auto &d : c){
                    d = -1;
                }
            }
        }
    }
    
   // cout <<num1 <<" "<<num2 <<endl;
      process(0,0,1,1,0);
      ll t = dp[0][0][1][1];
    return t;
}


int main() {
    cin>>m >> d;
    cin >> num1 >> num2;
    u.push_back(1);
    for( int i = 1; i <num1.size();i++){
        u.push_back(((10)%m*u[i-1])%m);
    }
    reverse(ALL(u));
    // for ( auto &x : u )cout <<x <<" ";
    // cout <<endl;
    // cout << num1 <<" "<<num2<<endl;
    // cout<<endl;
    cout <<ons()<<endl;
}

/*
int main () { 
   // clock_t start = clock();
   // setIO("odometer");
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
   // capMemory(256ULL * 1024 * 1024);
         // int t ; cin >> t;
        //  ll a , b;cin >>a >> b;
        //  cout << ans()<<endl;
ans();
    // clock_t end = clock();
    //  double time_taken = double(end - start) / CLOCKS_PER_SEC;
    //  std::cout << "Time taken: " << time_taken << " seconds" << std::endl;
     return 0;
}
     */