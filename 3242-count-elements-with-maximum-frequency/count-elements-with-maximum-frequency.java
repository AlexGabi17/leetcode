class Solution {
    public int maxFrequencyElements(int[] nums) {
        int res = 0, maxVal = -1, sum = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0; i<nums.length; i++){
            if(map.containsKey(nums[i])){
                map.put(nums[i], map.get(nums[i]) + 1);
            }
            else{
                map.put(nums[i], 1);
            }
        }
        for(Map.Entry<Integer, Integer> entry: map.entrySet()){
            if(entry.getValue() > maxVal){
                maxVal = entry.getValue();
                sum = 0;
            }
            if(entry.getValue() == maxVal){
                sum += entry.getValue();
            }
        }
        return sum;
    }
}