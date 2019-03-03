#pragma once
#include <iostream>
#include <string>

class Palindrome_Number {
public:
	bool isPalindrome(int x) {
		std::string s = std::to_string(x);
		std::string s_reverse = s;
		std::reverse(std::begin(s_reverse), std::end(s_reverse));
		return s == s_reverse;
	}

	void print_answer(bool ans) {
		std::cout << ans << std::endl;
	}

	void test() {
		int x = 121;
		bool ans = isPalindrome(x);
		print_answer(ans);
	}
};