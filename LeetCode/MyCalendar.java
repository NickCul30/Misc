// 729. My Calendar I
// Nicholas Culmone
// August 3rd, 2022

import java.awt.*;
import java.util.*;

class MyCalendar {
    private ArrayList<Point> bookings;

    public MyCalendar() {
        bookings = new ArrayList<Point>();
    }
    
    public boolean book(int start, int end) {
        for(Point p : bookings){
            if((p.x <= start && p.y > start) || (p.x < end && p.y >= end) || (start <= p.x && end > p.x) || (start < p.y && end >= p.y)) return false;
        
        }
        
        Point pt = new Point(start, end);
        bookings.add(pt);
        
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */