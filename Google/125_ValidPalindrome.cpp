class Solution {
public:
    bool isPalindrome(string s) {
      string result;
      for(char &c : s){
        if(isalnum(c)) result += c;
      }
      for(char &c : result){
        c = tolower(c);
      }
      int i = 0;
      int j = result.size() - 1;
      while(j-i>0){
        if(result[i] != result[j]){
            return false;
        }
        i++;
        j--;
      }
      return true;
    }
};