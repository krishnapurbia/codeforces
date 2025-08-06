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
#include <iomanip>
#include <stack> 
#include <cstdint>
#include <cstdlib>
#include <numeric> // for std::gcd
// #include <ctime> // for clock() and CLOCKS_PER_SEC
// #include <sys/resource.h>
// #include <iostream>
// #include <cstdlib>

//kris
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
 
typedef   long long  int  ll;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
//       cout.setf(ios::fixed);
//    cout<<setprecision( 10 );
    if (!name.empty()) {
        if (!freopen((name + ".in").c_str(), "r", stdin)) {
            cerr << "Input file " << name << ".in not found.\n";
            exit(1);
        }
        if (!freopen((name + ".out").c_str(), "w", stdout)) {
            cerr << "Output file " << name << ".out could not be created.\n";
            exit(1);
        }
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






class DSU  {
    public :
    ll n ; vli p, u ;
    DSU(ll n ) {
                p.assign( n ,  0  ) ;
                u.assign( n , 1 ) ;
                for( ll i = 0 ; i <   n ; i++) p [ i ] =  i ;
    }
    ll find( ll i ){
        return p[i] = p[i] == i ? i : find(p[i]);
    }
    bool same( ll i , ll j) {
        return find( i ) == find( j );
    }
    ll unite ( ll i , ll j ) {
         i = find( i ) ;
         j = find( j );
         if( i == j ) return u [ i ];
         if( u[ i ] < u [ j ] ) swap( i , j );
         u[i] += u[j];
         p[j] = i ;
         return u [ i ];
    }

};


class Segtree{
    public : 
        ll size ;
        vector < long long int  >  sums ;
        Segtree ( ll n ) {
            size = 1;
            while (size <  n )
            {
                size *= 2;
            }
            sums.assign( size * 2 , 0LL);
        }
        void set(  ll i , ll v , ll x , ll lx , ll rx) {
            if( rx  - lx  == 1) {
                sums [x] = v;
                return;
            }
            ll m = (lx + rx) /2;
            if( i < m ){
                set(  i ,  v , 2 * x + 1 , lx , m );
            }
            else {
                set(  i , v , 2*x + 2 , m , rx);
            }
            sums [x] = sums [ 2*x + 1] + sums [ 2 *x  +2];
        }
        void set ( ll x , ll v ){
               
            set( x , v , 0 , 0, size );
        }
        ll sum ( ll l , ll r , ll x , ll lx , ll rx ){
                if( lx >= r || rx <= l ) return 0 ;
                if( lx >= l && rx <= r ) return sums[ x ];
                ll m = ( lx + rx ) /2;
                ll s1 = sum( l,r,2*x +1 , lx , m );
                ll s2 = sum ( l ,r,2* x + 2 , m , rx  );
                return s1 + s2;
        }
        ll sum ( ll l , ll r ){
                return sum( l ,r , 0 ,0, size );
        }
        void build( vector < ll > & a , ll  x , ll l , ll r){
            if(  r - l == 1) {
                if( l < ( ll )a.size () ) sums [ x ] = a[ l ];
                return;

            }
            ll mid = ( l  + r )/2;
            build ( a , 2*x+1 , l , mid ) ;
            build ( a , 2 * x + 2 , mid , r );
            sums [ x ] = sums [ 2*x + 1] + sums [ 2 * x  +2];
        }
        void build ( vector < ll > & a ){
            build( a , 0 , 0,size );
        }
};

void solve() {
        string s; cin >> s;
        s.append("$");
        ll n = s.size();
        vector < ll > c ( n ), p ( n ); // class equivalent, position of i on the ith 
         {
            vector < plip > a( n );
            for( int i = 0 ; i < n ;i++)
                a [ i ] =  { s[ i ] - '$' , i  };
            sort(ALL( a ));
            For( i ,0 ,n ) p[ i ] = a[  i ].second;
            For( i, 1, n ){
                if( a[ i ].first == a[ i-1 ].first ) c[ p[i] ] =c [ p[i-1] ];
                else c[ p[i] ] = c[ p[i-1 ]] + 1;
            }
    
         }
         ll k = 0;
         while ((1 << k ) < n )
         {
           vector < pair < plip , ll  > > a( n );
           For( i ,0, n)  a [ i ] = { { c[ i ] , c[( i + ( 1 << k ) ) % n ]} , i };
            sort(ALL(a));
            For(  i ,0, n ) p [ i ] =  a[ i ].second;
            For( i ,1, n ){
                if( a[ i ].first == a[ i-1].first ) c [ p [ i ]]  = c[ p [ i -1 ] ];
                else c [ p [ i ] ] = c[ p [ i-1] ] + 1;
             }
             k++;
         }
        //  for (const auto & x : p ){
        //     cout << s.substr ( x )<<endl;
        //  }
         ll q; cin >> q;
         while (q--)
         {
            string qu ; cin >> qu;
            bool found = 0;
            ll low = 0 ; ll high = n-1;
            auto check  = [ & ] (ll in ) {
                    auto r = qu  <  s.substr(in , min((ll)qu.size(),(n-1) - in +1));
                    if( r == true ) return 2LL;
                    r = qu == s.substr(in ,  min((ll)qu.size(),(n-1) - in +1));
                    if( r == true ) return 1LL;
                    return 0LL;
            };
            ll mini = INT_MAX;
            ll mxi = -1;
            while ( low <= high )
            {
                ll mid = ( low + high )/2;
                ll ca = check  ( p[mid] );
                if( ca == 1) {
                  //  cout <<mid <<endl;
                        mini = min(mini ,mid);
                        high = mid-1;
                }
                else if( ca == 0 ){
                            low = mid+1;
                }
                else{
                        high = mid-1;
                }
            }
            low = 0 , high = n-1;
           // cout <<endl;
             while ( low <= high )
            {
                ll mid = ( low + high )/2;
                ll ca = check  ( p[mid] );
                if( ca == 1) {
                   //  cout <<mid <<endl;
                        mxi = max(mxi ,mid);
                        low = mid+1;
                }
                else if( ca == 0 ){
                            low = mid+1;
                }
                else{
                        high = mid-1;
                }
            }
          //   cout <<endl;
            cout  << max ( 0LL , mxi - mini + 1 )<<endl;
           //  cout <<endl;
             // cout <<endl;
           // if( found) cout <<"Yes\n";
           // else cout << "No\n";
         }

}





int main () {

        setIO("");
        ll t; t =1;
        // cin>>t;
        while (t--)
        {
            /* ce */
            solve();
        }
        


    return 0 ;


}
