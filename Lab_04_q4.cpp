#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m , n;
    vector<vector<bool>> inpath ;
    bool solve(int i , int x , int y , vector<vector<char>>& board ,  string& word){
        if( i == word.size() ){
            return true;
        }
        if(x < 0 || x >= m || y < 0 || y >= n || inpath[x][y] || board[x][y] != word[i] )
        return false;

        inpath[x][y] = true;
        bool res =  solve(i + 1 , x , y + 1 , board , word ) || 
                    solve(i + 1 , x + 1 , y , board , word ) || 
                    solve(i + 1 , x , y - 1 , board , word ) ||
                    solve(i + 1 , x - 1 , y , board , word );
        inpath[x][y] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        inpath = vector<vector<bool>> ( m , vector<bool> ( n ,false )) ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if( board[i][j] == word[0] )
                    if( solve ( 0 , i , j , board , word))
                        return true;
            }
        }
        return false;
    }
};
int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    
    Solution sol;
    bool result = sol.exist(board, word);
    
    cout << (result ? "Word exists in the board." : "Word does not exist in the board.") << endl;
    
    return 0;
}