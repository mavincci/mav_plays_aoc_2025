#include <iostream>
#include <vector>

using namespace std;

using grid_t = vector< vector< char>>;

// straight from my game of life
int get_surr_count(grid_t & grd, int h, int k) {
    auto rows = grd.size();
    auto cols = (rows > 0) ? grd[h].size() : 0;

	int r_strt	= (h == 0 ? 0 : -1);
	int r_end	= (h == rows-1 ? 0 : 1);

	int c_strt	= (k == 0 ? 0 : -1);
	int c_end	= (k == cols-1 ? 0 : 1);

	int count = 0;

	for(int i = r_strt; i <= r_end; ++i)
		for(int j = c_strt; j <= c_end; ++j)
			count += ((grd[h + i][k + j] == '@') ? 1 : 0);

	return count - ((grd[ h ][ k ] == '@') ? 1 : 0);
}

int main() {
    string input;
    grid_t grid;

    while(cin >> input) {
        grid.push_back(vector<char>(input.begin(), input.end()));
    }

    auto count{0l};
    for(auto i = 0; i < grid.size(); ++i) {
        for(auto j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] != '@') continue;

            auto c = get_surr_count(grid, i, j);

            if(c < 4) {
                ++count;
            }
        }
    }
    cout << count;
}