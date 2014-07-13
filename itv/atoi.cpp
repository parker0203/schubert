/*
 * atoi, tested on leetcode
 */

class Solution {
  public:
    int atoi(const char *str) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(str == NULL) return 0;
      int len = strlen(str);
      int res = 0, flag = 0, i = 0;
      while(str[i] == ' ' && i < len){  // skip all front space
        ++i;
      }

      for(int j = 0; i < len; ++i, ++j){
        if(j == 0 && str[i] == '+'){
          continue;
        }else if(j == 0 && str[i] == '-'){
          flag = -1;
        }else if(str[i] >= '0' && str[i] <= '9'){
          if(res > (INT_MAX - str[i] + '0') / 10){  // if exceed INT_MAX
            if(flag == 0) return INT_MAX;
            else return INT_MIN;
          }
          res = res * 10 + str[i] - '0'; // res = (res << 3)+(res << 1) + str[i] - '0';
        }else{
          break;
        }
      }

      if(flag < 0) return -res;
      return res;
    }
};
