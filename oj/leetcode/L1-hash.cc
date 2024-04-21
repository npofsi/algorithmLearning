#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int> &nums, int target)
	{
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			m[target-nums[i]] = i;
		}
		
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) != m.end() && m[nums[i]] != i)
			{
				return {i, m[nums[i]]};
			}
		}
		return {-1};
	}

};

int main()
{
	std::vector<int> nums = {3, 2, 3};
	int target = 6;
	Solution s;
	std::vector<int> res = s.twoSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}