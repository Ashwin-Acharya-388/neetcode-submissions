class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>res = new HashMap<>();
        for(String s : strs){
            char[] ch = s.toCharArray();
            Arrays.sort(ch);
            String st = new String( ch);
            res.putIfAbsent(st,new ArrayList<>());
            res.get(st).add(s);
        }
        return new ArrayList<>(res.values());
    }
}
