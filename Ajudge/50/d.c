#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;

char ch[200005];
int cnt[30];

static inline void solve ()
{
	for ( int i = 0 ; i < 30 ; ++i ) cnt[i] = 0;
	scanf ( "%s", ch );
	int len = strlen ( ch );
	ll sum = 0;
	for ( int i = 0 ; i < len ; ++i )
		cnt[(int)ch[i]-'a']++;
	for ( int i = 0 ; i < 30 ; ++i )
		sum += ((ll)(i+1)) * (ll)cnt[i];
	ll tar; scanf ( "%lld", &tar );
	if ( sum <= tar ) {
		printf ( "%s\n", ch );
		return;
	}
	int cur = (int)'z' - 'a';
	while ( sum > tar ) {
		while ( cnt[cur] == 0 ) --cur;
		cnt[cur]--;
		sum -= cur;
	}
	for ( int i = 0 ; i < len ; ++i ) {
		if ( cnt[(int)ch[i]-'a'] > 0 ) {
			printf ( "%c", ch[i] );
			cnt[(int)ch[i]-'a']--;
		}
	}
	puts ( "" );
}

int main ( int argc, char* argv[] )
{
	int t; scanf ( "%d", &t );
	while ( t-- )
		solve ();

	return 0;
}

