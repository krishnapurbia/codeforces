
class Segtree{
    public : 
        ll size ;
        vector < ll  >  sums ;
        Segtree ( ll n ) {
            size = 1;
            while (size <  n )
            {
                size *= 2;
            }
             sums.assign(size*2,0LL);
        }
        void set(  ll i , ll v , ll x , ll lx , ll rx) {
            if( rx  - lx  == 1) {
                
                 sums [x  ] = v;
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
                if( lx >= l && rx <= r ) return  sums[x];
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
                if( l < ( ll )a.size () ) 
                sums [ x ] = a[ l ];

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

