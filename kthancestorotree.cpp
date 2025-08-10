class TreeAncestor {
public:
        int Log ;
      //  int n;
        vector <vector <int>> up;
        vector <int> depth;
    TreeAncestor(int n, vector<int>& parent) {
         Log = 0;
         while ((1 << ( Log )) <= n)
         {
            Log++;
         }

        up = vector<vector<int>>( n , vector<int> ( Log));
        depth = vector<int> ( n );
        parent [0] = 0;
        // this is when for some i's  0...i-1 ancestors are not covered among them  
        vector <vector <int> > graph( n );
        for(int i = 1 ;i < n ;i++) {
                graph [ parent [i] ].push_back( i);
        }
        vector<int> vis( n );
        function <void( int i , int p )> dfs = [&] ( int i , int p) {
                vis [ i ] = 1;
                up [ i ][ 0 ] = p;
                if(i!=0)depth [ i ] = depth[p] +1;
                for( int j = 1;j < Log;j++){
                    up [i][j] = up [ up[i][j-1]][j-1];
                }
                for( const auto & x : graph [ i ] ) {
                        if( x != p && vis[x]==0 ) dfs(x ,i );
                }
        };
        dfs(0,0);
        // else this is efficient 
      //  for( int i = 0 ;i < n;i++) cout<<depth[i] <<" ";cout<<endl;
        //  for( int i = 0 ;i < n ;i++){
        //         up [ i ][ 0 ] = parent [i];
        //         if( i!=0){
        //             depth [i] = depth[ parent[i]] +1;
        //         }
        //         for( int j = 1; j <Log ;j++) {
        //             up [ i ][ j ] = up [ up [ i ][ j-1] ] [ j-1];
        //          }
        //  }
    }
    
    int getKthAncestor(int node, int k) {
            if( k > depth [ node ] ) return -1;
            for( int i = 0; i < Log; i++){
                if( (1<<i) & (k) ) {
                    node = up[node][i];
                }
            }
            return node;
    }
};
