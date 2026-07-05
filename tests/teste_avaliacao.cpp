#include <iostream>

void foo(int a, int b) {
    std::cout << "foo(" << a << ", " << b << ")";
}

int main() {
    int i = 0;
    foo(i++, i++);

    return 0;
}