    #include <iostream>
    using namespace std;

class Shape{
    virtual void shapeArea(){
    cout << "Area of shape." << endl;
    }
};

class Rectangle : public Shape{
    public:
    int width;
    int height;

    Rectangle(int w, int h): width(w), height(h) {}

    void shapeArea() override{
        int output = width * height;
        cout << "Area is: " << output << "." << endl;
    }
};

class Circle : public Shape{
    public:
    int radius;

    Circle(int r): radius(r) {}
        
    void shapeArea() override{
        const double pi = 3.14159;
        double output = 3.14 * (radius * radius);
        cout << "Area is: " << output << "." << endl;
    }
};

int main() {
    Rectangle floorplan(14, 5);
    floorplan.shapeArea();

    Circle garden(7);
    garden.shapeArea();

    return 0;
}