/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */

import java.awt.*;
import java.util.*;

public class Solution {
	public static void main(String[]args){
		Point[]points = new Point[4];
		int[]x = {3,12,3,-6};
		int[]y = {1,3 ,1,-1};

		for(int i = 0; i < points.length; i++) {
    		points[i] = new Point(x[i],y[i]);
		}

		int ans = maxPoints(points);
		System.out.println(ans);
	}

    public static int maxPoints(Point[] points) {
        if(points.length <= 2) return points.length;

        int most = 0;

        for(int i=0;i<points.length-1;i++){
        	for(int j=0;j<points.length-i;j++){
        		Point p1 = points[i];
        		Point p2 = points[i+j];
        		int onLine = 0;

        		if(p2.x - p1.x == 0){
        			onLine = checkVertLine(p1.x,points);
        		}
        		else{
	        		double m = ((double)(p2.y) - (double)(p1.y)) / ((double)(p2.x) - (double)(p1.x));
	        		double b = (double)(p1.y) - (double)(p1.x) * m;

	        		onLine = checkOnLine(m,b,points);
	        	}

        		if(onLine > most) most = onLine;
        	}
        }
        return most;
    }

    public static int checkOnLine(double m,double b,Point[] points){
    	int tot = 0;
    	for(Point p : points){
    		if((double)(p.y) == round((double)(p.x) * m + b,5)) tot ++;
    	}
    	return tot;
    }

    public static int checkVertLine(int x,Point[] points){
    	int tot = 0;

    	for(Point p : points){
    		if(x == p.x) tot ++;
    	}
    	return tot;
    }
    public static double round(double value, int places) {
	    long factor = (long) Math.pow(10, places);
	    value = value * factor;
	    long tmp = Math.round(value);
	    return (double) tmp / factor;
	}
}