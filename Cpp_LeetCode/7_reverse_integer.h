#pragma once
#include <iostream>
#include <climits>

class Reverse_Integer {
public:
	int reverse(int x) {
		int result = 0;
		while (x != 0) {
			int digit = x % 10;
			x /= 10;
			if (result > INT_MAX / 10 || result == INT_MAX / 10 && digit > 7)
				return 0;
			if (result < INT_MIN / 10 || result == INT_MIN / 10 && digit < -8)
				return 0;
			result = result * 10 + digit;
		}
		return result;
	}

	void print_answer(int ans) {
		std::cout << ans << std::endl;
	}

	void test() {
		int x = 123;
		int ans = reverse(x);
		print_answer(ans);
	}
};