#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
// vector
class BinarySearch
{
public:
	bool feasible(std::vector<int> weights, int max_weight, int d);
	int min_max_weight(std::vector<int> weights, int d);
};

