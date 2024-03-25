#include <iostream>

class Vector {
public:
    int x, y;

    Vector(int a, int b) : x(a), y(b) {}

    friend Vector operator+(const Vector& lhs, const Vector& rhs) {
        return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
    }
};

int main() {
    Vector v1(2, 3);
    Vector v2(5, 7);
    Vector v3 = v1 + v2;

    std::cout << "v1 = (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2 = (" << v2.x << ", " << v2.y << ")" << std::endl;
    std::cout << "v3 = v1 + v2 = (" << v3.x << ", " << v3.y << ")" << std::endl;

    return 0;
}