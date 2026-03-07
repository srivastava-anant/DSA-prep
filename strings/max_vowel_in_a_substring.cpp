class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c =='e' || c =='i'||c == 'o'||c =='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int maxcount = 0;
    for(int i = 0;i<k;i++){
        if(isvowel(s[i])){
            count++;
        }
    }
    maxcount =  count;
    for(int i=k;i<s.size();i++){
        if(isvowel(s[i]))
            count++;
        if(isvowel(s[i-k])){
            count--;
        }

        maxcount = max(maxcount,count);
    }
    return maxcount;
    }
};
