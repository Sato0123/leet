#include <stdio.h>
#include <queue>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
	public :
		ListNode *addTwoNumbers(ListNode *l1 , ListNode *l2) {
			std::queue<int> num_que;
			int carup = 0;
			int sum = 0;
			
		//cal and toQueue part
			//first process
			int val1 = 0;
			int val2 = 0;
			ListNode *cu1 = l1;
			ListNode *cu2 = l2;
			sum = cu1->val + cu2->val;
			if (sum >= 10){
				carup = 1;
				sum = sum % 10;
			}
			num_que.push(sum);
			//second... process
			while(cu1->next != nullptr || cu2->next != nullptr){
				if(cu1->next != nullptr){
					cu1 = cu1->next;
					val1 = cu1->val;
				}else{
					val1 = 0;
				}
				if(cu2->next != nullptr){
					cu2 = cu2->next;
					val2 = cu2->val;
				}else{
					val2 = 0;
				}
				
				sum =  val1 + val2 + carup;
				carup = 0;
				if (sum >= 10){
					carup = 1;
					sum = sum % 10;
				}
				num_que.push(sum);
			}
			if (carup)
				num_que.push(1);
		//toListNode part
			ListNode *res_head = new ListNode(num_que.front());
			ListNode *res_cur = res_head;
			num_que.pop();
			while(!num_que.empty()){
				ListNode *next = new ListNode(num_que.front());
				res_cur->next = next;
				res_cur = next;
				num_que.pop();
			}
			return (res_head);
		}
};


int main(){
//test data
#if 0
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(4);
	ListNode *c = new ListNode(3);

	ListNode *d = new ListNode(5);
	ListNode *e = new ListNode(6);
	ListNode *f = new ListNode(9);
	a->next = b;
	b->next = c;

	d->next = e;
	e->next = f;
#endif
#if 0
	ListNode *a = new ListNode(0);
	ListNode *d = new ListNode(0);
#endif
#if 1
	ListNode *a = new ListNode(9);
	ListNode *b = new ListNode(9);
	ListNode *c = new ListNode(9);
	a->next = b;
	b->next = c;

	ListNode *d = new ListNode(9);
	ListNode *e = new ListNode(9);
	ListNode *f = new ListNode(9);
	ListNode *g = new ListNode(9);
	ListNode *h = new ListNode(9);

	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
#endif

//call target code
	Solution *sol = new Solution();
	ListNode *x = sol->addTwoNumbers(a,d);

//debug code
	do{
		printf("%d",x->val);	
		x = x->next;
	}while(x != nullptr);
}
