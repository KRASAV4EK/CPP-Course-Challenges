#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
};
void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int given_data {0};
    for (int i = 0; i < num; i++) {
        std::cout << "Enter given_data point [" << i + 1 << "] : ";
        std::cin >> given_data;
        std::shared_ptr<Test> ptr = std::make_shared<Test>(given_data);
        vec.push_back(ptr);
    }
};
void display(const std::vector<std::shared_ptr<Test>>&vec) {
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (auto obj : vec) {
        std::cout << obj->get_data() << std::endl;
    }
    std::cout << "=======================" << std::endl;
};

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}