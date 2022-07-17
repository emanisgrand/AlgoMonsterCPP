#include "BinarySearch.h"

bool BinarySearch::feasible(std::vector<int> weights, int max_weight, int d) // 6
{
	int req_days = 1;
	int capacity = max_weight;
	int i = 0;
	int n = weights.size();

	while (i < n)
	{
		if (weights[i] <= capacity)
		{
			capacity -= weights[i];
			i++;
		}
		else
		{
			req_days++;
			capacity = max_weight;
		}
	}
	return req_days <= d;
}

int BinarySearch::min_max_weight(std::vector<int> weights, int d)
{
	int min_ptr = *std::max_element(weights.begin(), weights.end());
	int max_ptr = std::accumulate(weights.begin(), weights.end(), 0);
	int boundaryIndex = max_ptr;

	while (min_ptr <= max_ptr)
	{
		int mid = min_ptr + (max_ptr - min_ptr) / 2;
		if (feasible(weights, mid, d))
		{
			max_ptr = mid - 1;
			boundaryIndex = mid;
		}
		else {
			min_ptr = mid + 1;
		}
	}
	return boundaryIndex;
}



												




