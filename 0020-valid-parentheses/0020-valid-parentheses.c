bool isValid(char* s) {
    int n=strlen(s);
    char stack[n];
    int top =-1;
    for(int i=0;i<n;i++){
        if(s[i] == '(' || s[i]=='{' || s[i]=='['){
            stack[++top] = s[i];
        }
        else{
            if(top==-1) return false;
            char open = stack[top--];
            if((s[i]==')' && open != '(')|| (s[i]==']' && open != '[') ||(s[i]=='}' && open != '{')){
                return false;
            }
        }
    }
    return top ==-1;
}