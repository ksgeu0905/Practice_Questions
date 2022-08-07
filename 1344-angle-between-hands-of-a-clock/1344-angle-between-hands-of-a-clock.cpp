class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h=0,m=0;
        m = (6.0) * minutes;
        if(hour<12)
           h = (hour*(5.0) + (5.0)*(((float)minutes)/60.0))*6.0;
        else
           h=(30.0)*(((float)minutes)/60.0);
        float x=abs(h-m);
        float y=360.0-x;
        return min(x,y); 
    }
};