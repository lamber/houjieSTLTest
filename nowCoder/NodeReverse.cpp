#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL)
            return pHead;    
        ListNode *p1,*p2,*p3;
        p1=pHead;
        p2=pHead->next;
        p3=p2->next;
        while(p2!=NULL)
        {
            p3=p2->next;
            p2->next=p1;
            p1=p2;
            p2=p3;
        }
        pHead->next=NULL;
        pHead=p1;
        return pHead;

    }
};
int main()
{
    ListNode *head=new ListNode(1);
    ListNode *ph=head;
    for (size_t i = 0; i < 5; i++)
    {
        ListNode *p=new ListNode(i); 
        ph->next=p;
        ph=ph->next;
    }
    ListNode* p=head;
      while (p!=NULL)
    {
        std::cout<<p->val<<endl;
       p=p->next;
    }
    Solution sn;
    ListNode *pl= sn.ReverseList(head);
    while (pl!=NULL)
    {
        std::cout<<pl->val<<endl;
        pl=pl->next;
    }
    system("pause");
}