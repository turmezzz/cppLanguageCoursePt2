#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

struct Expression {

};

struct BinaryOperation : Expression {

};

struct Number : Expression {

};

bool check_equals(const Expression* left, const Expression* right) {
    const auto& leftTypeId = typeid(*left);
    const auto& rightTypeId = typeid(*right);
    bool leftBeforeRight = leftTypeId.before(rightTypeId);
    bool rightBeforeLeft = rightTypeId.before(leftTypeId);
    return (!leftBeforeRight and !rightBeforeLeft);

}

int main() {

}