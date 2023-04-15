class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        for(int i=s.length()-1;i>=0;i--){
            if(isalpha(s[i]))
                ans++;
            else if(ans!=0) 
                return ans;
        }
        return ans;
    }
};
