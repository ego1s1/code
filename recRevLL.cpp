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
class Node{
	public:
		int data;
		Node* next;

	public:
		Node(int data1, Node*next1){
			data = data1;
			next = next1;
		}
	public:
		Node(int data1){
			data = data1;
			next = nullptr;
		}
};

Node* revLL(Node* head){
	Node* temp = head;
	Node* prev = nullptr;
	Node* front;
	while(temp){
		front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	return prev;

}

Node* convertArr2LL(vi &arr){
	Node* head = new Node(arr[0]);
	Node* mover = head;
	for(int i = 1;i<arr.size();i++){
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		mover = temp;
	}
	return head;
}

void solve() {
	vi arr = {2,3,4, 5,6,7,8};
	Node* head = convertArr2LL(arr);
	Node* temp = head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	Node* rev = revLL(head);
	temp = rev;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
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


