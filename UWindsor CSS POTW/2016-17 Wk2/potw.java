import java.util.*;
import java.awt.*;

public class potw{

	public static void main(String[]args){
		int girlFind;
		int girlTot;
		Point willPos;
		ArrayList<Girl>girlPos = new ArrayList<Girl>();

		Scanner kb = new Scanner(System.in);

		String will = kb.nextLine();

		String[]values = will.split(" ");
		willPos = new Point(Integer.parseInt(values[0]), Integer.parseInt(values[1]));

		girlFind = kb.nextInt();
		girlTot = kb.nextInt();
		kb.nextLine();


		for(int i=0;i<girlTot;i++){
			String girl = kb.nextLine();

			String[]values2 = girl.split(" ");
			int girlX = Integer.parseInt(values2[0]);
			int girlY = Integer.parseInt(values2[1]);

			girlPos.add(new Girl(girlX, girlY, dist(girlX,girlY,willPos.x,willPos.y)));
		}

		Collections.sort(girlPos);
		Girl g;

		System.out.println("");

		for(int i=0;i<girlFind;i++){
			g = girlPos.get(i);
			System.out.println(g.getPos().x + " " +g.getPos().y);
		}



	}

	public static float dist(int x1, int y1, int x2, int y2){
		float d = (float)(Math.sqrt(Math.pow(y2-y1,2) + Math.pow(x2-x1,2)));
		return d;
	}
}

class Girl implements Comparable<Girl>{
	private Point pos;
	private float dist;

	public Girl(int x,int y,float d){
		pos = new Point(x,y);
		dist = d;
	}

	public float getDist(){
		return dist;
	}
	public Point getPos(){
		return pos;
	}

	@Override
		public int compareTo(Girl other){
			return (int)(dist - other.getDist());
		}
}