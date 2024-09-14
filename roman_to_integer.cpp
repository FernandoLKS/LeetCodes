#include <iostream>
#include <string>
#include <map>

        /* Example 3:
        Input: s = "MCMXCIV"
        Output: 1994
        Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
        */

std::map<char, int> mapRomanToInt{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
public:
    int romanToInt(std::string s) {
        int index = 0;
        int valueInt = 0;
        char digitRoman, nextDigitRoman;
        int digitInt, nextDigitInt;

        while(index < s.size()){            
            digitRoman = s[index];
            digitInt = mapRomanToInt[digitRoman];            
            
            if(index < s.size() - 1){
                nextDigitRoman = s[index+1];
                nextDigitInt = mapRomanToInt[nextDigitRoman];
            } 
            else{
                nextDigitRoman = 0;
                nextDigitInt = 0;
            }        

            if(nextDigitInt <= digitInt){
                index += 1;
                valueInt = valueInt + digitInt;
            }
            else{
                index += 2;
                valueInt = valueInt + (nextDigitInt - digitInt);
            }                      
        }
        return valueInt;
    }
};

int main(){

    Solution Solution;
    std::string Roman = "III";
    int Result = Solution.romanToInt(Roman);

    std::cout << Result << std::endl;

    return 0;
}