#include <iostream>
#include <tuple>

using namespace std;

template <int TSize, typename... TRest>
struct TupleElemType;

template <int TSize, class TBegin, class ...TRest>
struct TupleElemType <TSize, tuple <TBegin, TRest...>> {
    using Type = typename TupleElemType <TSize - 1, tuple <TRest...>>::Type;
};

template <class TBegin, class ...TRest>
struct TupleElemType <0, tuple <TBegin, TRest...>> {
    using Type = TBegin;
};

template <int firstId, int secondId, class ...T>
std::pair <typename TupleElemType <firstId, tuple <T...>>::Type, typename TupleElemType <secondId, tuple <T...>>::Type>
to_pair(const std::tuple <T...>& data) {
    return make_pair(get<firstId>(data), get<secondId>(data));
}

int main() {
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair <double, char const*> p = to_pair <1, 2>(t);
    std::cout << p.first << ' ' << p.second << std::endl;


    return 0;
}