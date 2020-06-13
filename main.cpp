#include <iostream>
using namespace std;
//Liskov Substitution Principle:
//subtypes should be immediately substitutable for their base types.
class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

     int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }
    int area() const {
        return width * height;
    }

};

class Square :  public Rectangle
{
public:
    Square(int size): Rectangle(size, size){}

public:

    //These functions will break the Liskov Substitution principle because the process function doesn't work
    //for Square although Square should be processed since it's a subtype of Rectangle
    void setWidth(int width) override {
        this -> width = height = width;
    }

    void setHeight(int height) override {
        this -> height = width = height;
    }
};
void process(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout<<"expected area = " << (w*10)
        <<", got "<< r.area()<<endl;
}

//A solution: Avoid using the square class
struct RectangleFactory
{
    static Rectangle create_Rectangle(int w, int h);
    static Rectangle create_square(int size);
};
int main() {
    Rectangle r {3,4};
    process(r);
    return 0;
}
