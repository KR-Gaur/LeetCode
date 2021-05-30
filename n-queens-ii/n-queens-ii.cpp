class Solution {
public:
    bool isPossible(vector<int> &q, int n, int k, int c ){
        for(int r=0; r<k; r++){
            if(q[r] == c || abs(q[r]-c) == abs(r-k))
                return false;
        }
        return true;
    }
    void rec( vector<int> &q, int n, int& ans, int k){
        
        if(n == k){
            ans++;
            return;
        }
            
        for(int c=0; c<n; c++){
            if(isPossible(q, n, k, c)){
                q.push_back(c);
                rec(q, n, ans, k+1);
                q.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> q;
        int ans=0;
        rec(q, n, ans, 0);  
        return ans;
    }
};