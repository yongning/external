#include <vector>
#include <iostream>
#include <memory>
#include <utility>

class objA {
public:
    objA() = default;
//    ojbA(objA&) = default:
    objA(int p1) : obj_(p1) {}
    ~objA() {
        std::cout << "obj dtor" << std::endl;
    }
private:
    int obj_;
};


int main(void)
{
    
    // std::vector<objA> vec1;
    // objA item1{10};
    // objA item2{100};
    // objA item3{1000};

    // std::vector<objA*> vec2;
    // objA* pitem1 = new objA{50};
    // objA* pitem2 = new objA{500};

    std::vector<std::unique_ptr<objA>> vec3;
    std::unique_ptr<objA> ptritem1 = std::make_unique<objA>(40);
    std::unique_ptr<objA> ptritem2 = std::make_unique<objA>(400);

    // vec1.push_back(std::move(item1));
    // vec1.push_back(std::move(item2));
    // vec1.push_back(std::move(item3));

    // vec2.push_back(pitem1);
    // vec2.push_back(pitem2);

    vec3.push_back(std::move(ptritem1));
    vec3.push_back(std::move(ptritem2));

    // std::cout << vec1.size() << std::endl;
    // std::cout << vec2.size() << std::endl;
    std::cout << vec3.size() << std::endl;
    // delete pitem1;
    // delete pitem2;

    return 0;
}
