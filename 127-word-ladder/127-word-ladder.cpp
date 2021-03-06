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
    
    unordered_map<string, bool> wordExistsAndNotVisited;
    queue<string> q;
    bool endWordPresent = false;
    
    int wordsLen = wordList.size();
    for(int i=0; i<wordsLen; i++){
        wordExistsAndNotVisited[wordList[i]] = false;
        if(wordList[i] == endWord)
            endWordPresent = true;        
    }
    
  
    if(!endWordPresent)
        return 0;
    
    q.push(beginWord);
    
    wordExistsAndNotVisited[beginWord] = true;
    
    int len = 0;
    int depth = 1;
    // O(n)
    while(!q.empty()){
        len = q.size();
        while(len>0){
            string curr = q.front();
        	q.pop();
            
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
            
            // O(n * m^2)
            int l=curr.size();
            for(int i=0; i<l; i++){
                char charToReplace = curr[i];
                for(char c='a'; c<='z'; c++){   // O(m*26)
                    curr[i] = c;
                    if(c == charToReplace)
                        continue;
                    if(curr == endWord)         // O(m)
                        return depth+1;
                    if(wordExistsAndNotVisited.find(curr) != wordExistsAndNotVisited.end() 
                       && !wordExistsAndNotVisited[curr]){
                        q.push(curr);
                        wordExistsAndNotVisited[curr] = true;
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

