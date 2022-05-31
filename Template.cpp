/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to display how to use template
*/

#include <iostream>

class Set;

template<class T> int add(T& a, T& b);
int add(Set& a, Set& b);

class Set
{
private:
    std::string name;
    int t;
public:
    Set(std::string nm): name(nm) {}
    ~Set() {}

    void set(int st) { t = st; }

    void display() {
        std::cout << "contents: " << t << std::endl;
    }

    friend int add(Set& a, Set& b);
};

// template
template<class T>
int add(T& a, T& b) {
    return (int)(a + b);
}

// Specialized template
int add(Set& a, Set& b) {
    return a.t + b.t;
}

int main() {
    Set a("hello");
    a.set(3);
    Set b("world");
    b.set(6);
    std::cout << "result = " << add(a, b) << std::endl;
}
