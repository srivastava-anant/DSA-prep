class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        int count1[26] = {0};
        int count2[26] = {0};

        for (int i = 0; i < n; i++)
            count1[s1[i] - 'a']++;

        for (int i = 0; i < n; i++)
            count2[s2[i] - 'a']++;

        bool same = true;
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                same = false;
                break;
            }
        }
        if (same) return true;

        for (int i = n; i < m; i++) {

            count2[s2[i] - 'a']++;
            count2[s2[i - n] - 'a']--;

            same = true;
            for (int j = 0; j < 26; j++) {
                if (count1[j] != count2[j]) {
                    same = false;
                    break;
                }
            }

            if (same) return true;
        }

        return false;
    }
};

