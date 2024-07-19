class Solution {
public:
    string removeDigit(string number, char digit) {       
        string res = "";
        for(int i=0 ; i<number.size() ; i++){
            if(number[i]==digit){
                number.erase(number.begin()+i);
                res = max(res, number);
                number.insert(number.begin()+i, digit);
            }
        }
        
        return res;
    }
};