#include <iostream>
#include <ostream>
#include <typeinfo>

void print_values(std::ostream& os) {
    return;
}

template <class T, class... TArgs>
void print_values(std::ostream& os, T arg, TArgs... args) {
    os << typeid(arg).name() << ": " << arg << '\n';
    print_values(os, args...);
}

int main() {

    print_values(std::cout, 0, 3.5, "Hello");

    return 0;
}