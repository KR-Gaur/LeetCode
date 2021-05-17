class Solution {
public:
    vector<vector<int>> edges;
    vector<int> count;
    int longest(int v){
        if(count[v]>0) 
            return count[v];
        
        count[v]=1;
        for( int i : edges[v] ){
            count[v] = max(count[v], longest(i)+1);
        }
        return count[v];
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        edges.clear();
        edges.resize(n);
        count.clear();
        count.resize(n);
        for( int i=0; i<n; i++ ){
            m[words[i]] = i;
        }
        
        for( int i=0; i<n; i++ ){
            string word = words[i];
            int wSize = word.size(); 
            for( int j=0; j<wSize; j++ ){
                string s = word.substr(0,j) + word.substr(j+1);
                if(m.find(s) != m.end()){
                    edges[m[s]].push_back(i);
                }
            }
        }
        int ans = 0;
        for( int i=0; i<n; i++ ){
            ans = max(ans, longest(i));
        }
        return ans;
    }
};