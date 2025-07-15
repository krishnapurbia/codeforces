#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#include <climits>
#include <cstdio>
#include <string>
#include <tuple>
#include <cstdlib>
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
 
typedef   int  ll;
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
typedef map<int , int > mpi;
 
const int MOD = 1000000007;
const int MOD1 = 998244353;
 
#define For(i, a, b) \
  for (int i = (a), __end = (b), __dir = ((a) < (b) ? 1 : -1); \
       (__dir > 0 ? i < __end : i > __end); \
       i += __dir)
#define Rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define Be(v) (v).begin()
#define Ee(v) (v).end()
#define Pb push_back
#define Mp make_pair
#define Sz(v) ((int)(v).size())
#define F first
#define S second
#define pc(v) cout << v ;
#define pr(v) cout << v << " ";
#define pe(v) cout << v << endl;
 
// using ll = long long;
  
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void in(int &x) {
    cin >> x;
}
void in(long long &x) {
    cin >> x;
}
void in(char &x) {
    cin >> x;
}
void in( pip  & x){
    cin >>x.first >> x.second;
}
template<typename T>
void in( vector<T> &v) {
    for (auto &t : v)
        in(t); 
}
 
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
// jai sia ram
 
auto comp (const pip & a , const pip & b ) {
    return tie(a.F , a.S) < tie(b.F , b.S);
}
auto compgreater (const pip & a , const pip & b ) {
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

unordered_set <int > st;
vi stk;
unordered_set <int> curstk ; // cyc detection 
bool dfs( int i  , vector<vector <int>> & graph ){
    st.insert(i);
    curstk.insert(i);
    bool fa = false;
    for( auto & x :graph[i]){
        if(st.find(x) == st.end()){
            fa |= dfs(x,graph); 
        }
        else if( curstk.find(x) !=curstk.end()) return true;
    }
    curstk.erase(i);
    stk.push_back(i);
    return fa;
}
#include <numeric>
int main () {
   // setIO("timeline");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n , m ; cin>> n >>m;
   
    string rf ; cin>>rf;
    
    vector<vector<int> > graph(n);
    bool sm = false;
    set <pip > rrr;
    for( int i = 0 ; i <m;i++){
        int a , b  ;cin>>a >> b ;a--,b--;
         if(a == b) sm = true;
         if(rrr.find({a, b} ) == rrr.end())graph[a].push_back(b);
         rrr.insert({a, b});
    }
    if(sm){
         cout <<-1<<endl;return 0;
    }
    unordered_set < int > strter;
    for( int i = 0 ; i < n;i++) strter.insert(i);
    for( auto & x : graph) {
        for( auto & y : x){
            strter.erase(y);
        }
    }
    
   
    for( auto & x : strter){
     if(dfs(x , graph)) {
        cout <<-1<<endl;return 0; // cyc detecion
     }
    }
    if( stk.size() != n){ // cycle detection 
        cout <<-1 <<endl;return 0;
    }
    reverse(ALL(stk));
    int values = 0;
    for( int i = 0 ; i < 26;i++){
        vi dp(n);
       for( int  j = 0 ; j < n ;j++) if(rf[j] - 'a' == i) dp[j]++;
        int  v = 0;
    for( const auto & x : stk){
        if( v < dp[x]) v = dp[x];
        for( const auto & y : graph[x]){
           dp[y] = max(dp[y], dp[x] +  (rf[y] - 'a' == i ? 1 :0)  );
        }
    }
    if(values < v){
        values = v;
    }
}
   
    cout << values<<endl;
    return 0;




}
