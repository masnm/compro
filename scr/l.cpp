#include "bits/stdc++.h"
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* _l1 = l1, _l2 = l2;
        string a, b;
        do {
            a += to_string(l1->val);
            l1 = l1->next;
        } while ( l1 != nullptr );
        do {
            b += to_string(l2->val);
            l2 = l2->next;
        } while ( l2 != nullptr );
        reverse ( a.begin(), a.end() );
        reverse ( b.begin(), b.end() );
        int _a = stoi(a), _b = stoi(b);
        int sum = _a + _b;
        a = to_string ( sum );
        reverse ( a.begin(), a.end() );
        l1 = _l1; l2 = _l2;
        bool b = true;
        for ( char i : a ) {
            if ( b ) {
                b = false;
                l1->val = i-'0';
            } else {
                if ( l1 -> next == nullptr )
                    l1->next = l2;
                l1 = l1->next;
                l1->val = i-'0';
            }
        }
        l1->next = nullptr;
        return _l1;
    }
};

int main ()
{
	ListNode _l, _r;
	_l.val = 2;_l.next=new ListNode;
	_l.val = 4;_l.next=new ListNode;
	_l.val = 3;_l.next=nullptr;


	_r.val = 5;_r.next=new ListNode;
	_r.val = 6;_r.next=new ListNode;
	_r.val = 4;_r.next=nullptr;

	Solution s;
	ListNode* ret = s.addTwoNumbers ( &_l, &_r );
	while ( ret != nullptr ) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;

	return 0;
}

