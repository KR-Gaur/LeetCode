class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26,-1);
        int start=0, len=s.size();
        for(int i=0; i<len; i++)
            m[s[i]-'a']=i;
        vector<int> ans;
        int begin = start;
        while(begin<len){
            int next = begin;
            int maxPos = m[s[begin]-'a'];
            while(next<len && next<=maxPos){
                maxPos = max(m[s[next]-'a'] , maxPos);
                next++;
                
            }
            ans.push_back(next-begin);
            begin = next;
        }
        return ans;
    }
};