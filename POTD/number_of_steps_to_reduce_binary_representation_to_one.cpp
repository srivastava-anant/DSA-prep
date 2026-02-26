class Solution {
public:
    int numSteps(string s) {

        int steps = 0;
        int carry = 0;

        // start from rightmost bit
        for(int i = s.size()-1; i > 0; i--){

            int bit = s[i] - '0';

            // effective value after carry
            if(bit + carry == 1){
                // odd → +1 then /2
                steps += 2;
                carry = 1;
            }
            else{
                // even → only /2
                steps += 1;
                // carry stays same
            }
        }

        // if carry still exists at MSB
        return steps + carry;
    }
};
