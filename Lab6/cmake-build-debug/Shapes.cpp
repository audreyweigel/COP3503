#include "Shapes.h"
#define PI 3.14159f
#include <iostream>
using namespace std;

void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : ";
    cout << Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const {
    if (this->Area() > rhs.Area()) {
        return true;
    }
    return false;
}

bool Shape2D::operator<(const Shape2D &rhs) const {
    if (this->Area() < rhs.Area()) {
        return true;
    }
    return false;
}

bool Shape2D::operator==(const Shape2D &rhs) const {
    if (this->Area() == rhs.Area()) {
        return true;
    }
    return false;
}

Square::Square() {
    length = 0;
    area = 0;
    name = "";
}

Square::Square(float length) {
    this->length = length;
}

float Square::Area() const {
    float area = length * length;
    return area;
}

string Square::GetName2D() const {
    string name = "Square";
    return name;
}

void Square::Scale(float scaleFactor) {
    length *= scaleFactor;
    area *= scaleFactor;
}

void Square::Display() const {
    cout << "The area of the Square is: " << Area() << endl;
    cout << "Length of a side: " << length << endl;
}

Triangle::Triangle() {
    base = 0;
    height = 0;
    name = "";
}

Triangle::Triangle(float base, float height) {
    this->base = base;
    this->height = height;
}

float Triangle::Area() const {
    float area = 0.5 * base * height;
    return area;
}

string Triangle::GetName2D() const {
    string name = "Triangle";
    return name;
}

void Triangle::Scale(float scaleFactor) {
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const {
    cout << "The area of the Triangle is: " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

Circle::Circle() {
    radius = 0;
    area = 0;
    name = "";
}

Circle::Circle(float radius) {
    this->radius = radius;
}

float Circle::Area() const {
    float area = PI * radius * radius;
    return area;
}

string Circle::GetName2D() const {
    string name = "Circle";
    return name;
}

void Circle::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

void Circle::Display() const {
    cout << "The area of the Circle is: " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << " is : ";
    cout << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const {
    if (this->Volume() > rhs.Volume()) {
        return true;
    }
    return false;
}

bool Shape3D::operator<(const Shape3D &rhs) const {
    if (this->Volume() < rhs.Volume()) {
        return true;
    }
    return false;
}

bool Shape3D::operator==(const Shape3D &rhs) const {
    if (this->Volume() == rhs.Volume()) {
        return true;
    }
    return false;
}

TriangularPyramid::TriangularPyramid() {
    pyramidHeight = 0;
    volume = 0;
}

TriangularPyramid::TriangularPyramid(float pyramidHeight, float base, float height) : Triangle(base, height) {
    this->pyramidHeight = pyramidHeight;
}

float TriangularPyramid::Volume() const {
    float volume = (Triangle::Area() * pyramidHeight) / 3;
    return volume;
}

string TriangularPyramid::GetName3D() const {
    string name = "TriangularPyramid";
    return name;
}

void TriangularPyramid::Scale(float scaleFactor) {
    pyramidHeight *= scaleFactor;
    base *= scaleFactor;
    height *= scaleFactor;
}

void TriangularPyramid::Display() const {
    cout << "The volume of the TriangularPyramid is: " << Volume() << endl;
    cout << "The height is: " << pyramidHeight << endl;
    cout << "The area of the Triangle is: " << Triangle::Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

Cylinder::Cylinder() {
    volume = 0;
    radius = 0;
    height = 0;
    name = "";
}

Cylinder::Cylinder(float height, float radius) : Circle(radius) {
    this->height = height;
    this->radius = radius;
}

float Cylinder::Volume() const {
    float volume = PI * radius * radius * height;
    return volume;
}

string Cylinder::GetName3D() const {
    string name = "Cylinder";
    return name;
}

void Cylinder::Scale(float scaleFactor) {
    height *= scaleFactor;
    radius *= scaleFactor;
}

void Cylinder::Display() const {
    cout << "The volume of the Cylinder is: " << Volume() << endl;
    cout << "The height is: " << height << endl;
    cout << "The area of the Circle is: " << Circle::Area() << endl;
    cout << "Radius: " << radius << endl;
}

Sphere::Sphere() {
    radius = 0;
}

Sphere::Sphere(float radius) : Circle(radius) {
    this->radius = radius;
}

float Sphere::Volume() const {
    float volume = (4 * PI * radius * radius * radius) / 3;
    return volume;
}

string Sphere::GetName3D() const {
    string name = "Sphere";
    return name;
}

void Sphere::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

void Sphere::Display() const {
    cout << "The volume of the Sphere is: " << Volume() << endl;
    cout << "The area of the Circle is: " << Circle::Area() << endl;
    cout << "Radius: " << radius << endl;
}