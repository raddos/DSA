#include <vector>
#include <unordered_map>


std::vector<int> solve(std::vector<int> v, int n) {

	//O(n) map and space complexity - leaner time
	//min O(1) - const time 
	//max O(n^2) - quadratic time
	std::unordered_map<int, int> m;

	for (size_t i = 0; i < v.size(); i++)
	{
		int complement = n - v[i];

		auto it = m.find(complement);

		if (it != m.end())
			return { it->second, (int)i };

		m[v[i]] = i;
	}

	return {};
}
