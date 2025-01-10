class Solution {
public:
    string convertToTitle(int col) {
        string result;
        while(col > 0){
            col--;
            char ch = (col)%26  +'A';
            result += ch;
            col  = col /26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};


//when colNum = 26
//colNum = 25
// ch = 'A' + 0;
//ch = "A0";
//then result = "A0" + 