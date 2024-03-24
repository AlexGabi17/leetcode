class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> res;
        Set<Integer> set1 = new HashSet<Integer>();
        Set<Integer> set2 = new HashSet<Integer>();
        for(int i=0; i<nums1.length; i++){
            if(!set1.contains(nums1[i])){
                set1.add(nums1[i]);
            }
        }
        for(int i=0; i<nums2.length; i++){
            if(!set2.contains(nums2[i])){
                set2.add(nums2[i]);
            }
        }

        res = new ArrayList<List<Integer>>();
        res.add(new ArrayList<Integer>());
        Iterator<Integer> it = set1.iterator();
        while(it.hasNext()){
            Integer val = it.next();
            if(!set2.contains(val)){
                res.get(0).add(val);
            }
        }
        it = set2.iterator();
        res.add(new ArrayList<Integer>());
        while(it.hasNext()){
            Integer val = it.next();
            if(!set1.contains(val)){
                res.get(1).add(val);
            }
        }
        
        return res;
    }
}