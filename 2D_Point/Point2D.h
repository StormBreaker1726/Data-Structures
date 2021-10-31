#ifndef D3C5AA9B_49EF_4DA0_BD41_A9231F86736F
#define D3C5AA9B_49EF_4DA0_BD41_A9231F86736F

class Point2D{
private:
    float x;
    float y;

public:
    Point2D(float xx, float yy);
    ~Point2D();
    
    float getX();
    float getY();
    float distance(Point2D p2);

    void setX(float val);
    void setY(float val);

    bool isTriangle(Point2D p2, Point2D p3);
};

#endif /* D3C5AA9B_49EF_4DA0_BD41_A9231F86736F */
/*
Created by João Víctor Costa de Oliveira (StormBreaker1726)
*/