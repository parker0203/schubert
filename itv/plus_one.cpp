
//Given a number represented as an array of digits, plus one to the number.
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>::iterator iter = digits.end();
        --iter;
        int carry = 1;
        while(carry){
            ++(*iter);
            carry = *iter / 10;
            *iter = *iter % 10;
            if(iter == digits.begin() && carry == 1){
                digits.insert(iter, 1);
                break;
            }
            --iter;
        }
        return digits;
    }
};
