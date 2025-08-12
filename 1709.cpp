#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	rep(i,0,n)
		cin >> a[i];
	rep(i,0,n)
		cin >> b[i];
	vector<pair<int,int>> ans;
	rep(i,0,n){
		rep(j,1,n){
			if(a[j-1]>a[j]){
				swap(a[j-1], a[j]);
				ans.push_back({1,j});
			}
		}
	}
	rep(i,0,n){
		rep(j,1,n){
			if(b[j-1]>b[j]){
				swap(b[j-1], b[j]);
				ans.push_back({2,j});
			}
		}
	}
	rep(i,0,n){
		if(a[i]>b[i])
			ans.push_back({3, i+1});
	}
	cout << ans.size() << endl;
	for(auto(x):ans)
		cout << x.first << " " << x.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    //int t = 1;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


