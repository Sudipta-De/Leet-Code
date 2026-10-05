class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> current = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        backtrack(nums,0);
        return result;
    }
    private void backtrack(int[] nums,int start){
        result.add(new ArrayList<>(current));
        for(int i = start; i< nums.length; i++){
            current.add(nums[i]);
            backtrack(nums,i +1);
            current.remove(current.size()-1);
        }
    }
}