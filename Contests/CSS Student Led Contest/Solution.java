// First Repeating Character
// Nicholas Culmone

import java.util.*;

public class Solution{
  public static void main(String[]args){
    Scanner kb = new Scanner(System.in);
    String word = kb.nextLine();
    boolean flag = false;
    
    for(int i=0;i<word.length();i++){
      char c = word.charAt(i);
      for(int j=i+1;j<word.length();j++){
        if(c == word.charAt(j)){
          System.out.println(c);
          flag = true;
          break;
        }
      }
      if(flag) break;
    }
  }
}