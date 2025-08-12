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
Node* deleteTail(Node*head){
	if(head == nullptr || head->next == nullptr) return nullptr;
	Node* temp = head;
	while(temp->next->next!=nullptr){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = nullptr;
	return head;
}

Node* deleteElement(Node* head, int k){
	if(head == nullptr) return nullptr;
	if (k == 1){
		Node* temp = head;
		head = head->next;
		free (temp);
		return head;
	}
	Node* temp = head;
	Node* prev = nullptr;
	int c=0;
	while(temp!=nullptr){
		c++;
		if(c==k){
			prev->next = prev->next->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}

	return head;
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
Node* removeElement(Node* head, int element){
	if(head->data == element){
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* temp = head;
	Node* prev=nullptr;
	while(temp!=NULL){
		if(temp->data == element){
			prev->next = prev->next->next;
			free (temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}
Node* insertHead(Node* head, int n){
	Node* temp = new Node(n, head);
	return temp;

}
Node* insertElement(Node* head, int n, int pos){
	Node* ins = new Node(n,nullptr);
	
	Node* temp = head;
	int cnt = 1;
	if (pos==1) return insertHead(head,n);
	while(temp!=nullptr && cnt < pos -1){
			temp = temp->next;
			cnt++;
		}
	if(temp==nullptr) return head;
	ins->next = temp->next;
	temp->next = ins;
	return head;
}

Node* insertEl(Node* head, int n, int num){
	Node* ins = new Node(n,nullptr);
	
	Node* temp = head;
	if (head->data==num) return insertHead(head,n);
	while(temp!=nullptr && head->data!=num)
			temp = temp->next;
	if(temp==nullptr) return head;
	ins->next = temp->next;
	temp->next = ins;
	return head;
}

void solve() {
	vi arr = {2,3,4, 5,6,7,8};
	Node* head = convertArr2LL(arr);
	int k, pos;
	cin >> k >> pos;
	Node* temp = insertEl(head,k, pos); 
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


