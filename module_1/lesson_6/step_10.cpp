#include <iostream>

using namespace std;

template <class TObject, class TField>
bool compare(const TObject& a, const TObject& b, TField(TObject::*mptr)() const)
{
    return (a.*mptr)() < (b.*mptr)();
}

int main() {
    return 0;
}