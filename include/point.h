#ifndef POINT_H
#define POINT_H


class Point{
    private:
        double x;
        double y;
    public:
        Point(double x = 0.0, double y = 0.0): x(x), y(y) {}
        ~Point() {}

        double getX();
        double getY();
};

#endif