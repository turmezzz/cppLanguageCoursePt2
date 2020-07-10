#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    String() {
        data = nullptr;
        size = 0;
    }

    String(const char* data) {
        size = strlen(data);
        this->data = new char[size];
        strcpy(this->data, data);
    }

    String(const String& other) : String(other.data) {
    }

    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
        String box(other.data);
        swap(*this, box);
        return *this;
    }

    String(String&& other)  noexcept {
        swap(other.data, data);
        swap(other.size, size);

        cout << "here" << endl;
    }

    String& operator=(String&& other)  noexcept {
        swap(other.data, data);
        swap(other.size, size);

        cout << "here" << endl;

        return *this;
    }

    String operator+(const String& other) {
        String box;
        box.data = new char[size + other.size];
        strcpy(box.data, data);
        strcpy(box.data + size, other.data);
        return box;
    }

    ~String() {
        delete data;
    }

private:
    char* data{};
    int size{};
};

int main() {

    String s1 = String("Hello"); // 1

    String s2("world"); // 2

    String s3 = s1 + ", " + s2 + "!"; // 3

    String s4 = s3; // 4

    s1 = std::move(s4); // 5

    s2 = String(s1); // 6

    return 0;
}