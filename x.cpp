/*
 * https://github.com/MohamedAhmed04/Competitive-programming/blob/master/COCI/COCI%2017-Ceste.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
//#define mp make_pair
#define mid (l+r)/2
#define Le Node * 2 
#define Ri Node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=1e18;
const ll Mod=1e9+7;
const ld pai=acos(-1);
ll n , m ;
ll Ans [2009] , Mn [2009] ;
vector < pair < ll , pll > > v [2009] ;
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) Ans [i] = Mn [i] = inf ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int a , b , t , c ;
		cin >> a >> b >> t >> c ;
		a -- , b -- ;
		v [a] .pb ( { b , { t , c } } ) ;
		v [b] .pb ( { a , { t , c } } ) ;
	}
	set < pair < ll , pll > > s ;
	s .ins ( { 0 , { 0 , 0 } } ) ;
	while ( s .size () ) {
		pair < ll , pll > Crnt = *s.begin () ;
		s . era ( s .begin () ) ;
		ll Node = Crnt .se.se , t = Crnt .fi , c = Crnt .se.fi ;
		Ans [Node] = min ( Ans [Node] , t * c ) ;
		if ( c > Mn [Node] ) C ;
		Mn [Node] = c ;
		for ( auto u : v [Node] ) {
			ll nnode = u.fi ;
			ll nt = t + u.se.fi ;
			ll nc = c + u.se.se ;
			if ( nt > n * m ) C ;
			s . ins ( { nt , { nc , nnode } } ) ;
		}
	}
	for ( int i = 1 ; i < n ; i ++ ) 
		cout << ( Ans [i] == inf ? -1 : Ans [i] ) << endl ; 
}
