class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>ump;
        int c=1; //atleast 1 partition will be there in any string
        for (int i=0;i<s.size();i++){
            if (ump.find(s[i])!=ump.end()){
                    ump.clear();
                    c++;
            }
            ump[s[i]]++;
        }
        return c;
    }
};
