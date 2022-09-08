// 201. Bitwise AND of Numbers Range
// Nicholas Culmone
// August 1st 2022

public class BitwiseAND{
    public static void main(String[]args){
        int ans = rangeBitwiseAnd(1, 2147483647);
        System.out.println(ans);
    }

    public static int rangeBitwiseAnd(int left, int right) {
        String bin1 = "";
        String bin2 = "";
        int ans = 0;

        for(int i=31; i>=0; i--){
            if(left >= Math.pow(2,i)){
                left -= Math.pow(2,i);
                bin1 += "1";
            }
            else{
                bin1 += "0";
            }
            if(right >= Math.pow(2,i)){
                right -= Math.pow(2,i);
                bin2 += "1";
            }
            else{
                bin2 += "0";
            }
        }

        boolean andGo = true;
        String ansS = "";

        for(int i=0; i<32; i++){
            if(bin1.charAt(i) == bin2.charAt(i) && andGo){
                ansS += bin1.charAt(i);
            }
            else{
                ansS += "0";
                andGo = false;
            }
        }

        for(int i=0; i<32; i++){
            if(ansS.charAt(i) == '1'){
                ans += Math.pow(2,31-i);
            }
        }
        return ans;
    }
}