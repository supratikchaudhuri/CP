#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> v;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[y] |= (1 << (x - 1));
  }


  const int FULL = 3;
  v[2e9] = FULL;
  int hasLast = 0, lastColor = 0;
  for (auto[x, mask] : v) {
    if (mask != FULL && hasLast) {
      int color = (x + mask) % 2;
      if (lastColor == color) {
        cout << "NO\n";
        return;
      } else {
        hasLast = false;
      }
    } else if (mask == FULL && hasLast) {
        cout << "NO\n";
        return;
    } else if (mask != FULL) {
      lastColor = (x + mask) % 2;
      hasLast = true;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// 1472F - New Year's Puzzle
// If the first column is empty, we can always cover it with a vertical tile:

// if the next column is also empty, then we will have to put either two vertical or two horizontal tiles, but they are obtained from each other by rotating;
// if the next column contains at least one blocked cell, then we have no other options but to cover the column with a vertical board.
// If the first column is fully blocked, then we can just skip it.

// Remove such columns from the beginning, reducing the problem. Now the first column contains one empty and one blocked cell. Obviously, in place of an empty cell, we will have to place a horizontal tile. If this did not work, then the tiling does not exist. Otherwise there are two cases:

// if the next column is empty, it will turn into a column with one occupied cell. Then we continue to put horizontal tiles;
// if the next column contains one blocked cell, then it becomes fully blocked and we return to the first step.
// It turns out the following greedy algorithm, we sort all columns with at least one cell blocked (there are no more than m such columns) by number. Now, if we see a column with one occupied cell, then the next one must also be with one occupied cell (we skipped the empty columns), but this cell must have a different color in the chess coloring (so that we can tile the space between them with horizontal boards. This check is easy to do after sorting the columns