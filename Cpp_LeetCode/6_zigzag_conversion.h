#pragma once
#include <iostream>
#include <vector>

class ZigZag_Solution {
public:
	std::string convert(std::string s, int numRows) {
		if (numRows == 1) return s; // base case

		int n = s.size();
		std::vector<std::string> data(numRows, "");

		int row = 0;
		int d_row = 0; // change in row
		for (int i = 0; i < n; ++i) {
			data[row] += s[i];
			if (row == 0) d_row = 1;
			if (row == numRows - 1) d_row = -1;
			row += d_row;
		}

		std::string result;
		for (int row = 0; row < numRows; ++row) {
			result.append(data[row]);
		}

		return result;
	}

	void print_answer(std::string ans) {
		std::cout << ans.c_str() << std::endl;
	}

	void test() {
		std::string s = "PAYPALISHIRING";
		int numRows = 4;
		std::string ans = convert(s, numRows);
		print_answer(ans);
	}
};