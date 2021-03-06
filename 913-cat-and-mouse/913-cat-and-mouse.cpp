class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<char>>> states(n, vector<vector<char>>(n, vector<char>(2, Draw)));
        vector<vector<vector<int>>> indegree(n, vector<vector<int>>(n, vector<int>(2)));
        queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            if(0 != i){
                states[0][i][MTurn] = states[0][i][CTurn] = MWin;
                q.emplace(vector<int>{0, i, MTurn, (int)MWin});
                q.emplace(vector<int>{0, i, CTurn, (int)MWin});
                states[i][i][MTurn] = states[i][i][CTurn] = CWin;
                q.emplace(vector<int>{i, i, MTurn, (int)CWin});
                q.emplace(vector<int>{i, i, CTurn, (int)CWin});
            }
            for(int j = 0; j < n; j++){
                indegree[i][j][MTurn] = graph[i].size(); // when the mouse is at i, the cat is at j, and it's mouse's turn, how many routes the mouse can go.
                indegree[i][j][CTurn] = graph[j].size(); // when the mouse is at i, the cat is at j, and it's cat's turn, how many routes the cat can go.
                if(find(graph[j].begin(), graph[j].end(), 0) != graph[j].end()) indegree[i][j][CTurn]--; // cat cannot move to the hole, so 0 cannot be considered as a route for cat.
            }

        }

        while(!q.empty()){
            int m_pos = q.front()[0], c_pos = q.front()[1], turn = q.front()[2], result = q.front()[3];
            q.pop();
            int prev_turn = !turn;
            if(MTurn == prev_turn) { // previous turn is mouse's turn
                for(auto &i : graph[m_pos]) {
                    if(Draw == states[i][c_pos][prev_turn]) {
                        if(MWin == result){ // N-position, the mouse found a way to escape
                             states[i][c_pos][prev_turn] = MWin;
                        } else { 
                            indegree[i][c_pos][prev_turn]--; // this way is blocked by the cat
                            if(0 == indegree[i][c_pos][prev_turn]) states[i][c_pos][prev_turn] = CWin; // P-position, the mouse has no choices
                        }
                        if(Draw != states[i][c_pos][prev_turn]) {
                            q.emplace(vector<int>{i, c_pos, prev_turn, (int)states[i][c_pos][prev_turn]});
                        }
                    }
                }
            } else { // previous turn is cat's turn
                for(auto &i : graph[c_pos]) {
                    if(0 == i) continue; // cat cannot be at the hole!!
                    if(Draw == states[m_pos][i][prev_turn]) {
                        if(CWin == result){ // N-position, the cat is guaranteed to catch the mouse in next step
                            states[m_pos][i][prev_turn] = CWin;
                        } else {
                            indegree[m_pos][i][prev_turn]--; // the mouse can escape if the cat take this move
                            if(0 == indegree[m_pos][i][prev_turn]) states[m_pos][i][prev_turn] = MWin;  // P-position, the cat has no choices
                        }
                        if(Draw != states[m_pos][i][prev_turn]) {
                            q.emplace(vector<int>{m_pos, i, prev_turn, (int)states[m_pos][i][prev_turn]});
                        }
                    }
                }
            }
        }
        return states[1][2][MTurn];
    }
private:
    const int MTurn = 0;
    const int CTurn = 1;
    const char Draw = 0;
    const char MWin = 1;
    const char CWin = 2;

};