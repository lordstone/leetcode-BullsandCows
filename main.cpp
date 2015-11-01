class Solution {
public:

    string num2str(int num){
        if(num == 0) return "0";
        int tmp = num;
        string str = "";
        while(tmp != 0){
            char ctmp = ((tmp % 10) + '0');
            string strtmp = {ctmp};
            str = strtmp + str;
            tmp /= 10;
        }
        return str;
    }


    string getHint(string secret, string guess){
        map<int, int> myMap;
        int bull = 0, cow = 0;
        for(int i = 0; i < secret.length(); i ++){
            if(myMap.find(secret[i]) == myMap.end()) myMap[secret[i]] = 1;
            else myMap[secret[i]] ++;
        }
        for(int i = 0; i < secret.length(); i ++){
            if(secret[i] == guess[i]){
                bull ++;
                if(myMap[secret[i]] < 0){
                    cow += myMap[secret[i]] - 1;
                    myMap[secret[i]] = 0;
                }else if(myMap[secret[i]] > 0) myMap[secret[i]] --;
                else{
                    cow --;
                }
            }else{
                if(myMap.find(guess[i]) != myMap.end()){
                    if(myMap[guess[i]] > 0){
                        myMap[guess[i]] --;
                        cow ++;
                    }
                }
            }
        }
        if(cow<0) cow = 0;
        string bullc = num2str(bull);
        string cowc = num2str(cow);
        return bullc + "A" + cowc + "B";
    }
};
