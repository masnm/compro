#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double


void prepare_lookup_table ()
{
}

void do_task ()
{
	ll n,Q; cin >> n >> Q;

	vector<ll> llvec( n+5, 0 );
	vector<ll> look_up ( n+5, 0 );
	for ( ll i = 1 ; i <= n ; i++ ) cin >> llvec[i];

	ll sq = sqrt ( n );
	ll mlsq = (n/sq) * sq;

	ll p = 0;
	for ( p = 1 ; p <= mlsq ; p += sq ) {
		ll ans = 0;
		for ( ll i = p ; i < p+sq ; i++ ) {
			ans += llvec[i];
		}
		look_up [p+sq-1] = ans;
	}

	ll o;
	while ( Q-- ) {
		cin >> o;
		if ( o == 1 ) {
			ll index, old; cin >> index;
			index++;
			old = llvec[index];
			llvec[index] = 0;
			ll unknown = ((index/sq)+1)*sq;
			if ( unknown <= n )
				look_up[((index/sq)+1)*sq] -= old;
			cout << old << "\n";
		} else if ( o == 2 ) {
			ll index, value; cin >> index >> value;
			index++;
			llvec[index] += value;
			if ( ((index/sq)*sq) != index ) {
				look_up [((index/sq)+1)*sq] += value;
			} else {
				look_up [(index/sq)*sq] += value;
			}
			//cout << "lok ";for ( auto i : llvec ) cout << i << " "; cout << endl; for ( auto i : look_up ) cout << i << " "; cout << "\n";
		} else if ( o == 3 ) {
			ll ans = 0, l, r;
			cin >> l >> r;
			l++; r++;
			while ( l%sq != 0 && l != r ) {
				ans += llvec[l]; l++;
			}
			ans += llvec[l];
			for ( ll i = l+sq ; i<=r ; i += sq ) {
				l = i; ans += look_up[i];
			}
			l++;
			while ( l<=r ) {
				ans += llvec[l];
				l++;
			}
			cout << ans << "\n";
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	prepare_lookup_table();
	
	ll t = 1;
	cin >> t;
	while ( t-- ) {
		do_task();
	}
	

	return 0;
}
