/*
 * Best Time to Buy and Sell Stock
 * tested on LeetCode
 */


/*
 * Best Time to Buy and Sell Stock I
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() == 0) return 0;
        int res = 0;
        int min = prices[0];
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] > min && prices[i] - min > res){
                res = prices[i] - min;
            }else if(prices[i] < min){
                min = prices[i];
            }
        }
        return res;
    }
};

/*
 * Best Time to Buy and Sell Stock II
 */
 
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() == 0) return 0;
        int res = 0;
        int prev = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prev){
                res += prices[i] - prev;
            }
            prev = prices[i];
        }
        return res;
    }
};
