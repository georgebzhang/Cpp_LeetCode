#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

class Two_Sum {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result;
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i) {
			if (map.find(nums[i]) != map.end()) {
				result.push_back(map[nums[i]]);
				result.push_back(i);
			}
			else
				map[target - nums[i]] = i;
		}
		return result;
	}

	void print_answer(std::vector<int> ans) {
		for (int i = 0; i < ans.size(); ++i) {
			std::cout << ans[i] << " ";
		}
		std::cout << std::endl;
	}

	void test() {
		std::vector<int> nums{ 2, 7, 11, 15 };
		int target = 9;
		std::vector<int> ans = twoSum(nums, target);
		print_answer(ans);
	}
};