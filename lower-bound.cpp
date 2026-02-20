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


int lower_bound(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int lb = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            lb = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return lb;
}
void solve() {
	int length, target;
	cin >> length;
	cin >> target;
	vi arr(length);
	rep(i,0,length){
		cin >> arr[i];
	}
	sort(all(arr));
	int lb = lower_bound(all(arr), target)-arr.begin();
	cout << "lower bound = " << lb << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


