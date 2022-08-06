// BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1){
            return -1;
        }
        deque<int> q;
        set<int> seen;
        int m = grid.size(), n = grid[0].size();
        int step = 1;
        seen.insert(0);
        q.push_back(0);
        while(q.size()){
            int width = q.size();
            for(int i = 0; i < width; ++i){
                int p = q.front();
                q.pop_front();
                int r = p / n, c = p % n;
                if(r == m - 1 && c == n -1){
                    return step;
                }
                for(int j = -1; j <= 1; j++){
                    for(int k = -1; k <= 1; k++){
                        if(j == 0 && k == 0){
                            continue;
                        }
                        else{
                            int nr = r + j, nc = c + k;
                            int np = nr * n + nc;
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n 
                               && seen.find(np) == seen.end() && grid[nr][nc] == 0){
                                seen.insert(np);
                                q.push_back(np);
                            }
                        }
                    }
                }
            }
            step += 1;
        }
        return -1;
    }
};
