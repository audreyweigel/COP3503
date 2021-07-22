#define PI 3.14159f
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape() {};
};

class Shape2D : virtual public Shape {
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
    virtual ~Shape2D() {};
};

class Square : public Shape2D {
public:
    Square();
    Square(float length);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float length;
    float area;
    string name;
};

class Triangle : public Shape2D {
public:
    Triangle();
    Triangle(float base, float height);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float area;
    string name;
protected:
    float base;
    float height;
};

class Circle : public Shape2D {
public:
    Circle();
    Circle(float radius);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float area;
    string name;
protected:
    float radius;
};

class Shape3D : virtual public Shape {
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
    virtual ~Shape3D() {};
};

class TriangularPyramid : public Shape3D, private Triangle {
public:
    TriangularPyramid();
    TriangularPyramid(float pyramidHeight, float length, float baseHeight);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float pyramidHeight;
    float baseHeight;
    float length;
    float volume;
    string name;
};

class Cylinder : public Shape3D, private Circle {
public:
    Cylinder();
    Cylinder(float height, float radius);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float volume;
    float height;
    float radius;
    string name;
};

class Sphere : public Shape3D, private Circle {
    // no private variables
public:
    Sphere();
    Sphere(float radius);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
private:
    float volume;
    string name;
protected:
    float radius;
};