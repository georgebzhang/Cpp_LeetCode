#pragma once
#include <iostream>

class Longest_Palindromic_Substring {
public:
	std::string longestPalindrome(std::string s) {
		int n = s.size();
		std::vector<std::vector<bool>> mem(n, std::vector<bool>(n, false));
		int max_length = 1;
		int begin_index = 0;

		for (int i = 0; i < n; ++i) { // length 1 substrings
			mem[i][i] = true;
		}

		for (int i = 0; i < n - 1; ++i) { // length 2 substrings
			if (s[i] == s[i + 1]) {
				max_length = 2;
				begin_index = i;
				mem[i][i + 1] = true;
			}
		}

		for (int curr_length = 3; curr_length <= n; ++curr_length) { // length 3+ substrings
			for (int i = 0; i <= n - curr_length; ++i) {
				int j = i + curr_length - 1;
				if (s[i] == s[j] && mem[i + 1][j - 1]) {
					max_length = curr_length;
					begin_index = i;
					mem[i][j] = true;
				}
			}
		}

		auto begin_ptr = s.begin() + begin_index;
		std::string result(begin_ptr, begin_ptr + max_length);
		return result;
	}

	void print_answer(std::string ans) {
		std::cout << ans.c_str() << std::endl;
	}

	void test() {
		std::string s = "babad";
		std::string ans = longestPalindrome(s);
		print_answer(ans);
	}
};