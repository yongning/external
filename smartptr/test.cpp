#include <iostream>
#include <memory>
#include <string>

class ThreadFactory {
public:
    virtual ~ThreadFactory() = default;
    virtual int funcThread(int arg) = 0;
};

class NamedThreadFactory : public ThreadFactory {
public:
    NamedThreadFactory () = default;
    NamedThreadFactory (int arg1, int arg2) : a_(arg1), b_(arg2) {}
    int funcThread(int arg) override {
        std::cout << "logout from NamedThreadFactory" << std::endl;
        std::cout << arg << std::endl;
        return 0;
    }
    ~NamedThreadFactory() override {
        std::cout << "dtor of NamedThreadFactory" << std::endl;
    }
private:
    int a_;
    int b_;

};

class PriorityThreadFactory : public ThreadFactory {
public:
    PriorityThreadFactory () = default;
    PriorityThreadFactory (std::unique_ptr<ThreadFactory> factory, int priority)
                           : factory_(std::move(factory)), priority_(priority) {} 
    int funcThread(int arg) override {
        factory_->funcThread(priority_);
        std::cout << "logout from PriorityThreadFactory" << std::endl;
        std::cout << arg << std::endl;
        return 1;
    }

private:
    std::unique_ptr<ThreadFactory> factory_;
    int priority_;

};


int main()
{
    PriorityThreadFactory factory(std::make_unique<NamedThreadFactory>(100, 200), 300);

    factory.funcThread(500);

    return 2;
}
