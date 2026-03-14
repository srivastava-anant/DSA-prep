class Solution {
public:

    void solve(int n, string &curr, vector<string> &res){

        if(curr.length() == n){
            res.push_back(curr);
            return;
        }

        char arr[3] = {'a','b','c'};

        for(int i = 0; i < 3; i++){

            char ch = arr[i];

            if(curr.length() == 0 || curr[curr.length() - 1] != ch){

                curr.push_back(ch);

                solve(n, curr, res);

                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {

        vector<string> res;
        string curr;

        solve(n, curr, res);

        if(k > res.size()){
            return "";
        }

        return res[k-1];
    }
};
