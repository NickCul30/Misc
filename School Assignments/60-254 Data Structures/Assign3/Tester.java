// Tester.java
// Nicholas Culmone
// A tester class for the Priority Queue
		
import java.awt.geom.Point2D;

public class Tester{
	public static void main(String[]args){
		Point2D.Double tmp = new Point2D.Double(5.1,3.6);
		tmp = swap(tmp);

		System.out.println(tmp);
	}

	public static Point2D.Double swap(Point2D.Double tmp){
		double n = tmp.x;
		tmp.x = tmp.y;
		tmp.y = n;
		return tmp;
	}
}