class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res=0;
        vector<unordered_set<string>>v(26);
        int n=ideas.size();
        for(auto idea:ideas){
            v[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long c1=0,c2=0;
                for(auto p:v[i]){
                    if(v[j].find(p)==v[j].end())
                        c1++;
                }
                for(auto p:v[j]){
                    if(v[i].find(p)==v[i].end())
                        c2++;
                }
                res+=c1*c2*2;
            }
        }
        return res;
    }
};
