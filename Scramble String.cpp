class Solution {
public:

    bool helper(string a,string b,unordered_map<string,int>& mp){

         if(a.compare(b) == 0)
          return true;

          if(a.length() <= 1)
          return false;

          string key = a;
            key += " " + b;

        if(mp.find(key) != mp.end())
        return mp[key];

        int n = a.length();
        bool flag = false;

          for(int i=1;i<=n-1;i++){

              bool cond1 = helper(a.substr(0,i),b.substr(n-i,i),mp) && helper(a.substr(i,n-i),b.substr(0,n-i),mp);

               bool cond2 = helper(a.substr(0,i),b.substr(0,i),mp) && helper(a.substr(i,n-i),b.substr(i,n-i),mp);

                if(cond1 || cond2){
                    flag  = true;
                    break;
                }

               
          }

        return mp[key] = flag;  

    }

    bool isScramble(string s1, string s2) {
        
         unordered_map<string,int> mp;

        return helper(s1,s2,mp);
    }
};
