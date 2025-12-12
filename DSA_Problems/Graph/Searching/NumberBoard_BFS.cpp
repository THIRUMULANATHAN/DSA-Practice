#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    string curr_state;

    // flatten 2D board into a string
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            curr_state.push_back('0' + board[i][j]);
        }
    }

    string target_state = "123450";
    queue<string> q;
    q.push(curr_state);
    unordered_set<string> seen;
    seen.insert(curr_state);

    // adjacency list for each index of the flattened 2x3 board
    vector<vector<int>> dirs = {
        {1, 3},      // 0
        {0, 2, 4},   // 1
        {1, 5},      // 2
        {0, 4},      // 3
        {1, 3, 5},   // 4
        {2, 4}       // 5
    };

    int level = 0;
    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            string curr = q.front();
            q.pop();

            if (curr == target_state) {
                return level;
            }

            // find index of '0'
            int zero_pos_index = -1;
            for (int j = 0; j < 6; j++) {
                if (curr[j] == '0') {
                    zero_pos_index = j;
                    break;
                }
            }

            // generate new states
            for (int dir : dirs[zero_pos_index]) {
                string new_state = curr;
                swap(new_state[zero_pos_index], new_state[dir]);

                if (!seen.count(new_state)) {
                    seen.insert(new_state);
                    q.push(new_state);
                }
            }
        }

        level++;
    }

    return -1;
}

int main() {
    vector<vector<int>> arr(2, vector<int>(3));

    // Input
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << slidingPuzzle(arr) << endl;
    return 0;
}
