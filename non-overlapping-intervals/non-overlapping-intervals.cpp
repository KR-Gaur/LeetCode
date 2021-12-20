using namespace std;
class Solution {
public:
    bool static comp(vector<int> &a, vector<int>&b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if( intervals.size() == 1 )
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        auto itPrev = intervals.begin();
        auto it = itPrev+1; 
        int ans = 0;
        while( it != intervals.end() ){
            // cout<< (*it)[0] <<" "<<(*it)[1]<<endl;
            if((*it)[0] < (*itPrev)[1]){
                ans++;
                // cout<< (*itPrev)[0] <<" "<<(*itPrev)[1]<< " --- "; 
                // cout<< (*it)[0] <<" "<<(*it)[1]<<endl;
            }
            else 
                itPrev=it;
            ++it;
        }
        return ans;
    }
};