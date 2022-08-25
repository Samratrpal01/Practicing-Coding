class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int Y=(y_center<y1)?y1:(y_center>y2)?y2:y_center;
        int X=(x_center<x1)?x1:(x_center>x2)?x2:x_center;
        int disX=x_center-X,disY=y_center-Y;
        return disX*disX+disY*disY<=radius*radius;
    }
};



 
        