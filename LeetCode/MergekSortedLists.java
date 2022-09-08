// 23. Merge k Sorted Lists
// Nicholas Culmone
// August 3rd 2022
// LeetCode Hard Solution

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        
        boolean allGood = false;
        for(int i=0; i<lists.length; i++){
            if(lists[i] != null){
                allGood = true;
            }
        }
        if(allGood == false) return null;
    
        ListNode cur = new ListNode();
        ListNode top = cur;
        
        int index = 0;
        
        while(true){
            int min = Integer.MAX_VALUE;
            boolean allDone = true;
            
            for(int i=0; i<lists.length; i++){
                if(lists[i] != null){
                    allDone = false;

                    if(lists[i].val < min){
                        min = lists[i].val;
                        index = i;
                    }
                }
            }

            if(allDone){
                break;
            }
            
            cur.val = min;
            lists[index] = lists[index].next;
            
            for(int i=0; i<lists.length; i++){
                if(lists[i] != null){
                    cur.next = new ListNode();
                    cur = cur.next;
                    break;
                }
            }
        }
        
        return top;
    }
}