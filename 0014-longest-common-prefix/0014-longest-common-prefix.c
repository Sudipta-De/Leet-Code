char* longestCommonPrefix(char** strs, int strsSize) {
    int i =0;
    while(1){
        char c= strs[0][i];
        if(c == '\0')
        return strs[0];
        for(int j=1;j<strsSize;j++){
            if (strs[j][i] !=c || strs[j][i] == '\0'){
                strs[0][i] = '\0';
                return strs [0];
            }
        }
        i++;
    }
}