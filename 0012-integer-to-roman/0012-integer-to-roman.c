char* intToRoman(int num) {

        static char result[20];
        int values []={
            1000,900,500,400,100,90,50,40,10,9,5,4,1
        };
        char* symbols[]={
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
        }; 
        int pos=0;
        for(int i=0;i<13;i++){
            while(num>=values[i]){
                num -= values[i];
                int len = strlen(symbols[i]);
                for(int j=0;j<len;j++){
                    result[pos++]=symbols[i][j];
                }
            }
        }
        result[pos]='\0';
        return result;
}