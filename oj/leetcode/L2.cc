#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		std::vector<short> result = {};
		int i=0;
		while(!(l1 == nullptr && l2 == nullptr))
		{
			short sum = 0;
			if(l1 != nullptr)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if(l2 != nullptr)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			result.push_back(sum);
		}
	}
};

int main()
{
	ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
	Solution solution;
	ListNode *result = solution.addTwoNumbers(l1, l2);

	while (result != nullptr)
	{
		std::cout << result->val << " ";
		result = result->next;
	}

	return 0;
}