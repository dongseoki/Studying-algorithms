package leetcode.group_anagrams;

import java.util.*;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Hash Map , key : String(rearranged), value : arrayList.
        Map<String, ArrayList<String>> anagMap = new HashMap<String, ArrayList<String>>();
        for (String item:strs
             ) {
            char[] chars = item.toCharArray();
            Arrays.sort(chars);
            String reArragedWord = String.join("",new String(chars));
            if(anagMap.containsKey(reArragedWord)){
                anagMap.get(reArragedWord).add(item);
            }
            else {
                anagMap.put(reArragedWord, new ArrayList<String>(Arrays.asList(item)));
            }
        }

        // store data into hashmap

        // get keys value to list list string.
        Iterator<String> keys = anagMap.keySet().iterator();
        List<List<String>> answer = new ArrayList<>();
        while(keys.hasNext()){
            String strKey = keys.next();
            ArrayList<String> arrayList = anagMap.get(strKey);

        }

        return null;
    }

    public static void main(String[] args) {
        String[] strs = {"eat","tea","tan","ate","nat","bat"};
        Solution solution = new  Solution();
        System.out.println("solution.groupAnagrams(strs) = " + solution.groupAnagrams(strs));
        
    }
}
