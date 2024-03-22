class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> set = new HashSet<String>();
        for(List<String> list: paths){
            set.add(list.get(1));
        }
        // System.out.println(set);
        for(List<String> list: paths){
            if(set.contains(list.get(0))) set.remove(list.get(0));
        }
        for(String elem: set){
            return elem;
        }
        return "";
    }
}