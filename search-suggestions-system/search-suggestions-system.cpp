struct node{
    node *chars[26];
    bool end;
 
    node(){
        end = false;
        for( int i=0; i<26; i++){
            chars[i]=NULL;
        }
    }
};

class Solution {
public:
    
    node *origin;
    void insert(string word){
        node* t = origin;
        for(int i=0; i<word.size(); i++){
            if( t->chars[word[i]-'a'] == NULL ){
                t->chars[word[i]-'a'] = new node();
            }
            t=t->chars[word[i]-'a'];
        }
        t->end=true;
    }
    
    node* findNode(char c, node* s){
        if( s==NULL || s->chars[c-'a'] == NULL ) 
            return NULL;
        return s->chars[c-'a'];
    }
    
    void findStrings(string pf, node* s, vector<string> &ansWords, int &count){
                
        if( s->end == true ){
            count--;
            ansWords.push_back(pf);
            // cout<<pf<<endl;
        }
            
        if( count == 0 )
            return;  
        
        
        for( int i=0; i<26; i++ ){
            if(s->chars[i]!=NULL && count > 0) {
                findStrings(pf+(char)('a'+i), s->chars[i], ansWords, count);
            }
                
        }
    }
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        
        origin = new node();
        for(int i=0; i<products.size(); i++){
            insert(products[i]);
        }
        
        vector<vector<string>> ans;
        node *s = origin;
        string pf="";
        
        for(int i=0; i<searchWord.size(); i++){
            vector<string> ansWords;
            int count=3;
            
            pf+=searchWord[i];
            s = findNode(searchWord[i], s);
            
            if( s!=NULL )
                findStrings(pf, s, ansWords, count );
                
            ans.push_back( ansWords );
        }
        
        return ans;
    }
};