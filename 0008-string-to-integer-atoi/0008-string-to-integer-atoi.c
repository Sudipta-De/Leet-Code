int myAtoi(char* s) {
    int i =0;
    int sign =1;
    long long result =0;
    while (s[i]==' '){
         i++;
    }
    if(s[i]=='-'){
        sign =-1;
        i++;

    }
    else if (s[i]=='+'){
        i++;
    }
    while (s[i] >= '0' && s[i] <='9'){
        int digit = s[i]-'0';
        result = result * 10 + digit;
        if (sign ==1 && result >2147483647){
            return 2147483647;
        }
        if (sign == -1 && -result < -2147483648LL) {
            return -2147483648LL;
        }

        i++;
    }

    return (int)(sign * result);
    
}