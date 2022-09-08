// 383. RansomNote.java
// August 25th 2022
// Nicholas Culmone
// Daily Challenge for LeetCode August

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] ransomCount = new int[26];
        int[] magazineCount = new int[26];
        
        for(int i=0; i<ransomNote.length(); i++){
            ransomCount[ransomNote.charAt(i)-97] ++;
        }
        for(int i=0; i<magazine.length(); i++){
            magazineCount[magazine.charAt(i)-97] ++;
        }
        
        for(int i=0;i<26;i++){
            if(ransomCount[i] > magazineCount[i]) return false;
        }
        return true;
    }
}