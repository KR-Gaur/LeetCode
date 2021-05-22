class Solution {
public:
    void show(vector<string> &b){
        for( int i=0; i<b.size(); i++ ){
            cout<<b[i]<<" ";
            cout<<endl;
        }
    }
    
    bool isPossible(int r, int c, vector<int> &queens){
        for( int q=0; q<r; q++ ){
            if( c == queens[q] || abs(r-q) == abs(c-queens[q]) ) return false;
        }
        return true;
    }
    
    void rec( vector<string> &board, int r, vector<int> &queens, vector<vector<string>> &ans ){
        
        int n = board.size();
        
        if( r==n ){
            for( int i=0; i<n; i++ ){
                board[i]= string(n,'.');
                board[i][queens[i]]='Q';
            }
            ans.push_back(board);
            // show(board);
            return;
        }
        
        for( int c=0; c<n; c++ ){
            if( isPossible (r, c, queens) ){
                queens[r]=c;
                rec(board, r+1, queens, ans);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<int> queens(n);
        vector<string> board (n, string(n,'.'));
        // show(board);
        rec(board, 0, queens, ans);
        return ans;
    }
};