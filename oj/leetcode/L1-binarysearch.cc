#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int> &nums, int target)
	{
		std::vector<std::pair<int, int>> v;
		for (int i = 0; i < nums.size(); i++)
		{
			v.push_back(std::make_pair(nums[i], i));
		}
		std::sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			int idx = binarySearch(v, target - v[i].first, v[i].second);
			if (idx != -1)
			{
				//nums.clear();
				//nums.push_back(v[i].second);
				//nums.push_back(idx);
				//return nums;
				return {v[i].second, idx};
			}
		}
		return {-1};
	}

	int binarySearch(std::vector<std::pair<int, int>> &v, int target, int exclude = -1)
	{
		int l = 0, r = v.size() - 1;
		while (l < r)
		{

			int mid = l + ((r - l)) / 2;
			//std::cout << "[" << l << "," << r << "]" << mid << std::endl;
			if (v[mid].first < target)
			{
				l = mid + 1;
			}
			else if (v[mid].first > target)
			{
				r = mid - 1;
			}
			else
			{
				if(v[l].first < target)
				{
					l++;
				}
				if(v[r].first > target)
				{
					r--;
				}
			}

			if (v[l].first == v[r].first)
			{
				break;
			}
		}

		if (v[l].first != target)
		{
			return -1;
		}

		while (l <= r)
		{
			if (v[l].second != exclude)
			{
				return v[l].second;
			}
			l++;
		}

		return -1;
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