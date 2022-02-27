#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAdjacent(string s1, string s2){
        int count = 0; 
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count>1) return false;
            }
        }
        return true;
    }
    
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    unordered_map<string, bool> s;
    queue<string> q;
    bool endWordPresent = false;
    
    int wordsLen = wordList.size();
    for(int i=0; i<wordsLen; i++){
        s[wordList[i]] = false;
        if(wordList[i] == endWord)
            endWordPresent = true;        
    }
    
    // for(auto itr = s.begin(); itr!=s.end(); itr++)
    //     cout<< *itr << " ";
    //     cout << endl;
    if(!endWordPresent)
        return 0;
    
    q.push(beginWord);
    
    s[beginWord] = true;
    
    int ans = 0;
    int len = 0;
    int depth = 1;
    while(!q.empty()){
        len = q.size();
        while(len>0){
            string curr = q.front();
            // cout<< "iternating "<< curr << ", ";
        	q.pop();
            // cout<< " -- " << curr << " ";
            // O(n^2 * m)
            
        	// for(int i=0; i<wordList.size(); i++){
        	// if( !s[wordList[i]] && isAdjacent(curr, wordList[i])) { // O(n*m)
        	// if(wordList[i] == endWord)
        	// return depth+1;
        	// q.push(wordList[i]);
        	// // cout<< "pushed (" << wordList[i]<< ") ";
        	// s[wordList[i]] = true;
        	// }
        	// }
            int l=curr.size();
            for(int i=0; i<l; i++){
                char charToReplace = curr[i];
                for(char c='a'; c<='z'; c++){
                    curr[i] = c;
                    if(c == charToReplace)
                        continue;
                    if(curr == endWord)
                        return depth+1;
                    if(s.find(curr) != s.end()){
                        if (!s[curr])
                            {   
                                q.push(curr);
                                // cout<< " pushed " << curr<<" ,";
                                s[curr] = true;
                            }
                        // else cout<< " visited "<< curr<< " ";
                    }
                }  
                curr[i]=charToReplace;
            }
            
            len--;
        }
 		depth++;
        // cout<< endl;
    }
        // cout<<depth;
        return 0;
    }
};

