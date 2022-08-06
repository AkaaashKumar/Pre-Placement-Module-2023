class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		if(rooms.size()<2) return true;
		stack<int> s;
		vector<bool> visited(rooms.size(), false);

		//dfs
		s.push(0);
		visited[0] = true;
		while(!s.empty()){
			//get new room id
			int new_room = s.top();
			s.pop();
			//put keys into stack
			for(int i=0; i<(int)rooms[new_room].size(); ++i){
				int new_key = rooms[new_room][i];
				if(!visited[new_key]){
					visited[new_key] = true;
					s.push(new_key);
				}
			}
		}
		//check if there is any room that is not visited
		for(int i=0; i<(int)visited.size(); ++i){
			if(visited[i]==false) return false;
		}

		return true;
    }
};
