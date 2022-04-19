class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        // int *p=new int[size];
        string res="";
        for(int i=0; i<strs[0].length();i++)
        {
            char c=strs[0][i];
            // if(c=='\0')return res;
            for(int s=1;s<size;s++){
                if( i>=strs[s].length()||   strs[s][i]=='\0'||strs[s][i]!=c)return res;          
            }
            res+=c;
            
        }
        
        return res;
    }
};