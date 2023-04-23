class Solution {
private:
    bool isvowel(char c){
    if(c>=97)
    c-=32;
    if(c=='A' || c=='E' || c=='I' || c=='O' ||c=='U')
        return true;
    return false;
    }
public:
    string reverseVowels(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            while(i<j && isvowel(s[i])==0)
                i++;
            while(i<j && isvowel(s[j])==0)
                j--;
            if(i<j)
                swap(s[i],s[j]);
        }
            return s;
    }
};
