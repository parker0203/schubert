/*
 * if a integer is palindrome
 * reverse the integer and compare
 * tested on leetcode
 */
class Solution {
  public:
    bool isPalindrome(int x) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(x < 0) return false;
      int res = 0, temp = x;
      while(temp != 0){
        if((res > INT_MAX - temp % 10) / 10) return false;  // is reversed integer exceed INT_MAX
        res = res * 10 + temp % 10;
        temp /= 10;
      }
      return x == res;
    }
}; 

/*
 *  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 *  For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 *
 *  Note:
 *  Have you consider that the string might be empty? This is a good question to ask during an interview.
 *  For the purpose of this problem, we define empty string as valid palindrome.
 *  
 *  tested on leetcode
 */
class Solution {
  public:
    bool isPalindrome(string s) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      for(int i = 0, j = s.length() - 1; i < j;){
        if(!isalpha(s[i]) && !isdigit(s[i])){
          ++i;
          continue;
        }else if(!isalpha(s[j]) && !isdigit(s[j])){
          --j;
          continue;
        }else if(tolower(s[i]) != tolower(s[j])){
          return false;
        }else{
          ++i, --j;
        }
      }
      return true;
    }
};
