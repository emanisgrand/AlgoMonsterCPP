#include "solo.h"
#include "raylib.h"
// Advanced
#include <vector>	// vector
#include <limits>	// numeric_limits
#include <iterator>	// back_inserter, istream_iterator
#include <sstream>	// istringstream
#include <string>	// getline, string
#include <iostream>	// cin, cout, streamsize
#include <numeric>	// accumulate
#include <algorithm> // copy max element

bool feasible(std::vector<int> weights, int max_weight,int d)
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
		else {
			req_days++;
			capacity = max_weight;
		}
	}
	return req_days <= d;
}

int min_max_capacity(std::vector<int> weights, int d)
{
	int min_ptr = *std::max_element(weights.begin(), weights.end());;
	int max_ptr = std::accumulate(weights.begin(), weights.end(), 0);
	int boundaryIndex = max_ptr;

	while (min_ptr <= max_ptr)
	{
		int mid = min_ptr + (max_ptr - min_ptr) / 2;
		if (feasible(weights, max_ptr, d))
		{
			boundaryIndex = mid;
			max_ptr = mid - 1;
		}
		else{
			min_ptr = mid + 1;
		}
	}
	return boundaryIndex;
}

int main()
{
			
}