class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		sort(begin(candidates), end(candidates));
		vector<int> path;
		this->combinationSum2(result, 0, path, target, candidates);
		return result;
	}
private:
	void combinationSum2(vector<vector<int>>& result, const int& start, vector<int>& path, const int& target, const vector<int>& candidates) {
		if (target < 0) 
			return;
		else if (target == 0) {
			if (path.empty())
				return;
			else {
				result.push_back(path);
				return;
			}
		}
		else {
			for (int i = start; i < candidates.size(); i++) {
				if (i > start && candidates[i] == candidates[i - 1])
					continue;
				path.push_back(candidates[i]);
				this->combinationSum2(result, i + 1, path, target - candidates[i], candidates);
				path.pop_back();
			}
			return;
		}

	}
};
