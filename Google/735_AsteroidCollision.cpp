class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto it: asteroids){
            bool destroyed=false;
            while(!ans.empty() && ans.back()>0 && it<0 && !destroyed){
                if(ans.back()>=-it) destroyed=true;
                if(ans.back()<=-it) ans.pop_back();
            }      
            if(!destroyed) ans.push_back(it);
        }        
        return ans;
    }
};