#pragma once
#include <iostream>
#include <vector>

class Add_Two_Numbers_2 {
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

public:
	ListNode* add_by_digit(ListNode* l1, ListNode* l2, int carry) {
		if (l1 == NULL) l1 = new ListNode(0);
		if (l2 == NULL) l2 = new ListNode(0);

		ListNode* l = new ListNode((l1->val + l2->val + carry) % 10);
		carry = (l1->val + l2->val + carry) / 10;

		if (l1->next != NULL || l2->next != NULL || carry == 1)
			l->next = add_by_digit(l1->next, l2->next, carry);

		return l;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return add_by_digit(l1, l2, 0);
	}

	ListNode* vector_to_linked_list(std::vector<int>& vec) {
		ListNode* n = NULL;
		ListNode* prev = NULL;
		for (int i = 0; i < vec.size(); ++i) {
			n = new ListNode(vec[i]);
			n->next = prev;
			prev = n;
		}
		return n;
	}

	void print_answer(ListNode* l) {
		while (true) {
			std::cout << l->val << " ";
			if (l->next == NULL)
				break;
			l = l->next;
		}
		std::cout << std::endl;
	}

	void test() {
		std::vector<int> vec1{ 2, 4, 3 };
		std::vector<int> vec2{ 5, 6, 4 };
		ListNode* l1 = vector_to_linked_list(vec1);
		ListNode* l2 = vector_to_linked_list(vec2);
		ListNode* ans = addTwoNumbers(l1, l2);
		print_answer(ans);
	}
};