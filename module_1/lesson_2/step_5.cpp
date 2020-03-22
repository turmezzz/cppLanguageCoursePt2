#include <iostream>

using namespace std;

struct Base {

};

struct D1 : Base {

};

struct D2 : Base {

};

struct D3 : D1, D2 {

};

// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
const Base* D1BaseToD2Base(const Base* base) {
    const D1* d1_ptr = (const D1*)base;
    const D3* d3_ptr = (const D3*)d1_ptr;
    const D2* d2_ptr = (const D2*)d3_ptr;
    const Base* new_base = (const Base*)d2_ptr;
    return new_base;
}

int main() {
    return 0;
}