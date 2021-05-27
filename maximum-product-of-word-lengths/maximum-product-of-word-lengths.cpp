class Solution {
public:
    int maxProduct(vector<string>& words) {
        
         // ArrayList<Integer> w = new ArrayList<Integer>();
        vector<int> w;
        int len = words.size();
        
        for( string wo : words ){
            int len = wo.size();
            int wordsInteger = 0;
            for( int i=0; i<len; i++ )
                wordsInteger |= ( 1<<(wo[i]-97) );
            
            w.push_back(wordsInteger);
        }
        // for( int i=0; i<len; i++)
        //     cout<<w[i]<<" ";
        int ans=0;
        for(int i=0; i<words.size()-1; i++){
            for( int j=i+1; j<words.size(); j++){
                if( (w[i] & w[j])==0 && ans < words[i].size() * words[j].size() ){
                    ans = words[i].size() * words[j].size();
                    // cout<< ans;    
                }
                
            }
        }
        
        return ans;
        
    }
};