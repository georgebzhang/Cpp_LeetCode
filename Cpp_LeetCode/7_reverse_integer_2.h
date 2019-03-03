#pragma once
#include <iostream>
#include <string>

class Reverse_Integer_2 {
public:
	int reverse(int x) {
		int sign = x >= 0 ? 1 : -1;
		x = (unsigned int)x; // abs(x) crashes if abs(x) > INT_MAX

		std::string s = std::to_string(x);
		std::reverse(std::begin(s), std::end(s));
		try {
			x = sign * std::stoi(s);
		}
		catch (const std::exception& e) { // if x > INT_MAX
			return 0;
		}

		return x;
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