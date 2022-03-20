class Solution {
public:
    int longestDecomposition(string text) {
        
        string left = "";
        string right = "";
        
        int len = text.size();
        int res=0;
        for(int i=0; i<len; i++){
            left+=text[i];
            right=text[len-i-1]+right;
            if(left == right){
                res++;
                left = "";
                right = "";
            }
        }
        return res;
    }
};