class Solution {
    public String minWindow(String s, String t) {
        if(s.length()<t.length()){
            return "";
        }
        int[] freq = new int[128];
        for(char c: t.toCharArray()){
            freq[c]++;
        }
        int left =0;
        int start=0;
        int minLen=Integer.MAX_VALUE;
        int required=t.length();
        for(int right = 0;right<s.length();right++){
            char c = s.charAt(right);
            if(freq[c]>0){
                required--;
            }
            freq[c]--;
            while(required==0){
                int windowLen=right - left +1;
                if(windowLen < minLen){
                    minLen = windowLen;
                    start = left;
                }
                char leftChar = s.charAt(left);
                freq[leftChar]++;
                if(freq[leftChar]>0){
                    required++;
                }
                left++;
            }
        }
        if (minLen == Integer.MAX_VALUE) {
            return "";
        } else {
            return s.substring(start, start + minLen);
        }
    }
}