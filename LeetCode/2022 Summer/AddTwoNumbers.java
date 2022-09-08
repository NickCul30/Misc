// 2. AddTwoNumbers.java
// Nicholas Culmone
// July 28th 2022

public class AddTwoNumbers {
    public static void main(String[]args){
        ListNode a1 = new ListNode(3);
        ListNode a2 = new ListNode(4, a1);
        ListNode a3 = new ListNode(2, a2);

        ListNode b1 = new ListNode(4);
        ListNode b2 = new ListNode(6, b1);
        ListNode b3 = new ListNode(5, b2);

        ListNode ans = addTwoNumbers(a3, b3);

        System.out.print(ans.val);
        ans = ans.next;
        while(ans != null){
            System.out.print(" --> " + ans.val);
            ans = ans.next;
        }
        System.out.println("\n");
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode((l1.val + l2.val) % 10);
        int carry = 0;
        if(l1.val + l2.val >= 10) carry = 1;
        
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        ListNode curAns = ans;
        
        while(cur1.next != null || cur2.next != null || carry == 1){
            if(cur1.next == null) cur1.next = new ListNode(0);
            if(cur2.next == null) cur2.next = new ListNode(0);
            
            cur1 = cur1.next;
            cur2 = cur2.next;
            
            curAns.next = new ListNode((cur1.val + cur2.val + carry) % 10);
            
            if(cur1.val + cur2.val + carry >= 10) carry = 1;
            else carry = 0;
            
            curAns = curAns.next;            
        }
        return ans;
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
