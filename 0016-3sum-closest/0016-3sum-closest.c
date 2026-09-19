int threeSumClosest(int* nums, int numsSize, int target) {
    int i,left,right;
    int closest = nums[0] + nums[1] + nums[2];
    for(i=1;i< numsSize;i++ ){
        int key = nums[i];
        int j = i-1;
        while(j>=0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    for(i=0;i< numsSize -2;i++){
        left = i+1;
        right = numsSize-1;
        while(left < right){
            int sum = nums[i]+ nums[left]+nums[right];
            if(sum == target)
                return target;
            if((sum > target ? sum - target : target - sum) < (closest>target ? closest - target : target - closest)){
                closest = sum;
            }
                
            if(sum < target)
                left ++;
            else
                right--;
            
        }
    }
    return closest;
}