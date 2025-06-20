class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        int s=1;
        int i=0;
        vector<string>ans;
        while(i<m && s<=n){
            ans.push_back("Push");
            if(s!=target[i]){
                ans.push_back("Pop");
            }
            else{
                i++;
            }
            s++;
        }
        return ans;
    }
};