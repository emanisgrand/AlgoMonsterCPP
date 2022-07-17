#include <algorithm>	// copy
#include <iostream>		// cin, cout, streamsize
#include <iterator>		// back_inserter, istream_iterator, ostream_iterator, prev
#include <limits>		// numeric_limits
#include <queue>		// queue
#include <sstream>		// istringstream
#include <string>		// getline, string
#include <vector>		// vectors

#include "BinarySearch.h" // min_max_weight

struct Coordinate {
	int r;
	int c;
	Coordinate(int r, int c) :r(r), c(c) {}
};

std::vector<Coordinate> get_neighbors(Coordinate cell, int num_rows, int num_cols) {
	std::vector<Coordinate> neighbors;
	int delta_row[4] = { -1, 0, 1, 0 };
	int delta_col[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int neighbor_row = cell.r + delta_row[i];
		int neighbor_col = cell.c + delta_col[i];
		if (0 <= neighbor_row && neighbor_row < num_rows && 0 <= neighbor_col && neighbor_col < num_cols) {
			neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
		}
	}
	return neighbors;
}

void bfs(std::vector<std::vector<int>>& grid, Coordinate root, int num_rows, int num_cols) {
	std::queue<Coordinate> q;
	q.push(root);
	grid[root.r][root.c] = 0;
	while (q.size() > 0) {
		Coordinate node = q.front();
		std::vector<Coordinate> neighbors = get_neighbors(node, num_rows, num_cols);
		for (Coordinate neighbor : neighbors) {
			if (grid[neighbor.r][neighbor.c] == 0) continue;
			q.push(neighbor);
			grid[neighbor.r][neighbor.c] = 0;
		}
		q.pop();
	}
}

int count_number_of_islands(std::vector<std::vector<int>> grid) {
	int num_rows = grid.size();
	int num_cols = grid[0].size();
	int count = 0;
	// bfs starting from each unvisited land cell
	for (int r = 0; r < num_rows; r++) {
		for (int c = 0; c < num_cols; c++) {
			if (grid[r][c] == 0) continue;
			bfs(grid, Coordinate(r, c), num_rows, num_cols);
			// bfs would find 1 connected island, increment count
			count++;
		}
	}
	return count;
}

template<typename T>
std::vector<T> get_words() {
	std::string line;
	std::getline(std::cin, line);
	std::istringstream ss{ line };
	std::vector<T> v;
	std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
	return v;
}

void ignore_line() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{	
	std::vector<std::vector<int>> grid = {{1,1,1,0,0,0},
										  {1,1,1,1,0,0}, 
										  {1,1,1,0,0,0},
										  {0,1,0,0,0,0},
										  {0,0,0,0,1,0},
										  {0,0,0,0,0,0},
	};
	
	std::cout << count_number_of_islands(grid) << std::endl;
}