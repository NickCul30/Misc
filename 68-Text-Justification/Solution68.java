//68. Text Justification
//Nicholas Culmone

import java.util.*;

public class Solution68 {
	public static void main(String[]args){
		String[] line = {"justification."};
		System.out.println(fullJustify(line,16));
	}
    public static List<String> fullJustify(String[] words, int maxWidth) {
        int cur = 0;
        ArrayList<String> line = new ArrayList<String>();
        ArrayList<String> just = new ArrayList<String>();

        for(String s : words){
        	if(cur != 0) cur ++;
        	cur += s.length();

        	if(cur > maxWidth){
        		cur = 0;
        		int tot = 0, spaceBet = 0, extra = 0;
        		String ans = "";

        		for(String w : line){
        			tot += w.length();
        		}

        		if(line.size() == 1) spaceBet = maxWidth - tot;
        		else{
        			spaceBet = (maxWidth - tot) / (line.size() - 1);
	        		extra = (maxWidth - tot) % (line.size() - 1);
        		}
        		boolean flag = false;
        		for(String w : line){
        			if(flag){
        				for(int i=0;i<spaceBet;i++){
        					ans += " ";
        				}
        				if(extra > 0){
        					ans += " ";
        					extra --;
        				}
        			}
        			else flag = true;
        			ans += w;
        		}
        		while(ans.length() < maxWidth){
        			ans += " ";
        		}
        		just.add(ans);
        		line.clear();
        		line.add(s);
        		cur += s.length();

        	}
        	else{
        		line.add(s);
        	}
        }
        String tmp = "";
        boolean flag = false;
        for(String w : line){
        	if(flag){
        		tmp += " ";
        	}
        	else flag = true;
        	tmp += w;
        }
        while(tmp.length() < maxWidth){
        	tmp += " ";
        }
        just.add(tmp);

        return just;
    }
}