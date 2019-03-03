#pragma once
#pragma once
#include <iostream>
#include <string>

class Palindrome_Number_2 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || x % 10 == 0 && x != 0) return false; // if x is negative or if x ends with zero and is not zero

		int reverse = 0;
		while (reverse < x) {
			int digit = x % 10;
			reverse = reverse * 10 + digit;
			x /= 10;
		}

		return x == reverse || x == reverse / 10;
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