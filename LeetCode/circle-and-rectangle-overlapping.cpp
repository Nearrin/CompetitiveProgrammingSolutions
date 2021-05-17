class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x1<=x_center&&x2>=x_center&&y1<=y_center&&y2>=y_center)
            return true;
        auto sqr=[](int x){return x*x;};
        if(sqr(x1-x_center)+sqr(y1-y_center)<=sqr(radius))return true;
        if(sqr(x2-x_center)+sqr(y1-y_center)<=sqr(radius))return true;
        if(sqr(x1-x_center)+sqr(y2-y_center)<=sqr(radius))return true;
        if(sqr(x2-x_center)+sqr(y2-y_center)<=sqr(radius))return true;
        if(x1<=x_center&&x2>=x_center&&abs(y1-y_center)<=radius)return true;
        if(x1<=x_center&&x2>=x_center&&abs(y2-y_center)<=radius)return true;
        if(y1<=y_center&&y2>=y_center&&abs(x1-x_center)<=radius)return true;
        if(y1<=y_center&&y2>=y_center&&abs(x2-x_center)<=radius)return true;
        return false;
    }
};
