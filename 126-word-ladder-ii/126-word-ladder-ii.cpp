#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        bool isendWordPresent = false;
        unordered_map<string, bool> mp;
        
        for(int i=0; i<wordList.size(); i++){
            mp[wordList[i]] = false;
            if(wordList[i]==endWord)
                isendWordPresent = true;
        }
        
        if(!isendWordPresent)
            return ans;
        
        vector<string> path;
        path.push_back(beginWord);
        mp[beginWord] = true;
        
        q.push(path);
        int levelSize = 0;
        bool flag = false;
        
        while(!q.empty()){
            levelSize = q.size();
            vector<string> markVisited;
            while(levelSize>0){
                vector<string> curr_path = q.front();
                q.pop();
                string curr_word = curr_path[curr_path.size()-1];
   
                if(curr_word == endWord){
                    ans.push_back(curr_path);
                    flag = true;
                }
                else{
                    for(int ind=0; ind<curr_word.size(); ind++){
                        char charToReplace = curr_word[ind];
                        for(char c='a'; c<='z'; c++){
                            curr_word[ind] = c;
                            if(mp.find(curr_word)!=mp.end() && !mp[curr_word]){
                                curr_path.push_back(curr_word);
                                q.push(curr_path);
                                curr_path.pop_back();
                                markVisited.push_back(curr_word);
                            }
                        }
                        
                       curr_word[ind] = charToReplace;
                    }
                } 
                
             levelSize--;
            }
            
            for(auto word : markVisited){
                    mp[word] = true;
            }
            
            if(flag)
                break;
        }
        
        return ans;
    }
};