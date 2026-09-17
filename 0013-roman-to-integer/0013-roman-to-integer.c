int romanToInt(char* s) {
    int values[256]={0};
    values['I']= 1;
    values['V']= 5;
    values['X']= 10;
    values['L']= 50;
    values['C']= 100;
    values['D']= 500;
    values['M']= 1000;
    int result =0;
    for(int i =0;s[i] !='\0';i++){
        if (values[(unsigned char)s[i]]< values[(unsigned char)s[i+1]])
            result -= values [(unsigned char)s[i]];
        else 
        result += values[(unsigned char)s[i]];
    }
    return result;
}