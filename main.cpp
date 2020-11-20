#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void do_task ( int a, int b )
{
	for ( int i = 0 ; i<a ; i++ ) {
		cout << i << " from " << b << "\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main ()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	std::vector<std::thread> threads;
	ll t = 1, limit = 10;
	cin >> t;
	while ( t-- ) {
		threads.push_back(thread(do_task, limit, t));
	}

	for(auto& thread : threads){
        thread.join();
    }

	return 0;
}
