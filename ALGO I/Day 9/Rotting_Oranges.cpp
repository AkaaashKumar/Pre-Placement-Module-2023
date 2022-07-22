 class Solution {
public:
	int p(int x, int y){
		return x*10+y;
	}
	void callme(int i, int j, vector<vector<int>>& grid, queue<int>& q, int& fresh){
		if(i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j]!=1)
			return;
		grid[i][j] = 2;
		fresh--;
		q.push(p(i, j));
	}
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> q;
        int fresh = 0;
        for(int i=0; i<n; i++)
        	for(int j=0; j<m; j++){
        		fresh += (grid[i][j]==1);
        		if(grid[i][j]==2)
        		q.push(p(i, j));
        	}
        int minutes = 0;
        while(!q.empty()){
        	queue<int> tmp;
        	while(!q.empty()){
        		int i = q.front()/10, j = q.front()%10; q.pop();
        		callme(i+1, j, grid, tmp, fresh);	callme(i-1, j, grid, tmp, fresh);
        		callme(i, j+1, grid, tmp, fresh);	callme(i, j-1, grid, tmp, fresh);
        	}
        	if(tmp.empty())	break;
        	minutes++;
        	q = tmp;
        }
        return fresh==0?minutes:-1;

    }
};
