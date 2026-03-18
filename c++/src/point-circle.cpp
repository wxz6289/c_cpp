#include<iostream>
using namespace std;

class Point{
    public:
        int x,y;
    public:
        Point(int x,int y){
            this->x = x;
            this->y = y;
        }

        void display(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
};

class Circle{
    private:
        Point center;
    public:
        int radius;
        Circle(Point c,int r):center(c),radius(r){}
        Point getCenter(){
            return center;
        }
        void display(){
            cout<<"Circle with center ";
            center.display();
            cout<<"and radius "<<radius<<endl;
        }
};

bool isInsideCircle(Point p, Circle c){
    Point center = c.getCenter();
    int dx = p.x - center.x;
    int dy = p.y - center.y;
    return (dx*dx + dy*dy) <= (c.radius * c.radius);
}

int main(){
    Point p(1,2);
    Circle c(p,5);
    Point p1 = Point(2, 3);
    Point p2 = Point(6, 10);
    cout << isInsideCircle(p1, c) << endl;
    cout << isInsideCircle(p2, c) << endl;
    return EXIT_SUCCESS;
}