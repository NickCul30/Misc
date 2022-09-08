// 12. IntegerToRoman.java
// Nicholas Culmone
// July 26th 2022

public class IntegerToRoman{
    public static void main(String[]args){
        String num = intToRoman(454);
        System.out.println(num);
    
    }

    public static String intToRoman(int num){
        String ans = "";

        while(num >= 1000){
            ans += "M";
            num -= 1000;
        }

        if(num >= 900 && num < 1000){
            ans += "CM";
            num -= 900;
        }
        if(num >= 500){
            ans += "D";
            num -= 500;
        }


        if(num >= 400 && num < 500){
            ans += "CD";
            num -= 400;
        }
        while(num >= 100){
            ans += "C";
            num -= 100;
        }


        if(num >= 90 && num < 100){
            ans += "XC";
            num -= 90;
        }
        if(num >= 50){
            ans += "L";
            num -= 50;
        }


        if(num >= 40 && num < 50){
            ans += "XL";
            num -= 40;
        }
        while(num >= 10){
            ans += "X";
            num -= 10;
        }

        if(num == 9){
            ans += "IX";
            num -= 9;
        }
        if(num >= 5){
            ans += "V";
            num -= 5;
        }

        if(num == 4){
            ans += "IV";
            num -= 4;
        }
        while(num >= 1){
            ans += "I";
            num -= 1;
        }

        return ans;
    }
}