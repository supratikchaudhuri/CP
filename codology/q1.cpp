#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());

  vector<vector<int>> res = {intervals[0]};
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
}


int main(){
    int t; cin >> t;
    while(t--) {
      int n, k; cin >> n >> k;

      vector<vector<int>> intervals(n, vector<int> (2));

      for(int i = 0; i < n; i++) {
        cin >> intervals[i][0];
        cin >> intervals[i][1];
      }

      vector<vector<int>> new_intervals = merge_intervals(intervals);

      int doctors = intervals.size();

      for(auto i : new_intervals) {
        if(i[1] - i[0] > k)doctors++;
      }

      cout<<doctors;
    }
    return 0;
}