class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalP=0;
        if(x>y){
            totalP+= remSubstr(s, "ab", x);
            totalP+= remSubstr(s, "ba", y);
        }else{
            totalP+= remSubstr(s, "ba", y);
            totalP+= remSubstr(s, "ab", x);
        }return totalP;
    }

   int remSubstr(string& inputString, string targetSubstring,
                        int pointsPerRemoval) {
        int totalPoints = 0;
        int writeIndex = 0;

        for (int readIndex = 0; readIndex < inputString.size(); readIndex++) {
            
            inputString[writeIndex++] = inputString[readIndex];
            if (writeIndex > 1 &&
                inputString[writeIndex - 2] == targetSubstring[0] &&
                inputString[writeIndex - 1] == targetSubstring[1]) {
                writeIndex -= 2; 
                totalPoints += pointsPerRemoval;
            }
        }
        inputString.erase(inputString.begin() + writeIndex, inputString.end());

        return totalPoints;
    }
};