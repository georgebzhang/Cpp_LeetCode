#pragma once
#include <iostream>
#include <vector>

class Add_Two_Numbers {
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

public:
	void print_vector(std::vector<int>& vec) { // for debugging
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}

	void reverse_vector(std::vector<int>& vec) {
		std::reverse(vec.begin(), vec.end());
	}

	std::vector<int> linked_list_to_vector(ListNode* l1) {
		std::vector<int> vec;
		while (true) {
			vec.push_back(l1->val);
			if (l1->next == NULL)
				break;
			l1 = l1->next;
		}
		return vec;
	}

	int vector_to_value(std::vector<int> vec) {
		int val = 0;
		for (int i = 0; i < vec.size(); ++i) {
			val = val * 10 + vec[i];
		}
		return val;
	}

	std::vector<int> value_to_vector(int val) {
		std::vector<int> vec;
		while (true) {
			vec.push_back(val % 10);
			val = val / 10;
			if (val == 0)
				break;
		}
		return vec;
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

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		std::vector<int> vec1 = linked_list_to_vector(l1);
		std::vector<int> vec2 = linked_list_to_vector(l2);
		reverse_vector(vec1);
		reverse_vector(vec2);
		int val1 = vector_to_value(vec1);
		int val2 = vector_to_value(vec2);
		int val_total = val1 + val2;
		std::vector<int> vec_total = value_to_vector(val_total);
		reverse_vector(vec_total);
		ListNode* l_total = vector_to_linked_list(vec_total);
		return l_total;
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