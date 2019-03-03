#pragma once
#include <iostream>
#include <string>
#include <climits>

class String_To_Integer {
public:
	int myAtoi(std::string str) {
		int result = 0;
		int sign = 1;
		int bound = INT_MAX;
		bool has_sign = false;
		bool has_number = false;

		int plus_val = '+' - '0';
		int minus_val = '-' - '0';
		int whitespace_val = ' ' - '0';

		for (int i = 0; i < str.size(); ++i) {
			int val = str[i] - '0';

			if (!has_number) {
				if (!has_sign) {
					if (val == whitespace_val) continue;
				}
			}

			if (!has_sign) {
				if (!has_number) {
					if (val == plus_val) {
						has_sign = true;
						continue;
					}
					if (val == minus_val) {
						sign = -1;
						bound = INT_MIN;
						has_sign = true;
						continue;
					}
				}
			}

			if (val >= 0 && val <= 9) {
				if (result > INT_MAX / 10 || result == INT_MAX / 10 && val > 7) return bound;
				result = result * 10 + val;
				has_number = true;
			}
			else if (has_number) {
				result = result * sign;
				return result;
			}
			else {
				return 0;
			}
		}
		result = result * sign;
		return result;
	}

	void print_answer(int ans) {
		std::cout << ans << std::endl;
	}

	void test() {
		std::string str = "   -42";
		int ans = myAtoi(str);
		print_answer(ans);
	}
};