#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int value){  
        if(value < 0)
            return false;
        
        long int reversed = 0;
        int valueTemp = value;

        while(valueTemp != 0){
            int digit = valueTemp % 10;
            reversed = reversed * 10 + digit;
            valueTemp = valueTemp / 10;
        }

        if(value == reversed)
            return true;
        return false;
    }
};

int main(){
    int input = -1;

    Solution Solution;
    bool Result;
    Result = Solution.isPalindrome(input);
    std::cout << Result << std::endl;

    return 0;
}