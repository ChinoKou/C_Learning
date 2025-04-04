#include <iostream>

class class_test{
    private:
    std::string m_name;
    std::string m_id;
    int m_age;
    class_test *next;

    static int count;

    public:
    class_test(std::string name, std::string id, int age) {
        std::cout << "调用了" << age << "构造函数" << std::endl;
        m_name = name;
        m_id = id;
        m_age = age;
        next = nullptr;
    }
    // class_test(const class_test &obj, int age){
    //     cout << "调用了拷贝构造函数" << endl;
    //     m_name = obj.m_name;
    //     m_id = obj.m_id;
    //     m_age = obj.m_age;
    //     next = new class_test(*obj.next);
    // }
    ~class_test(){
        std::cout << "调用" << m_age << "了析构函数" << std::endl;
    }
    void next_handle(class_test *node) {
        next = node;
    }
    class_test *return_next() {return next;}
    void show();
};

inline void class_test::show(){
    std::cout << "name: " << m_name << " id: " << m_id << " age: " << m_age << std::endl;
}

int class_test::count = 0;

int main(){
    class_test *temp = nullptr, *head = nullptr, *tail = nullptr;
    for (int i = 0; i < 10; i++){
        class_test *temp = new class_test("abc", "123", i + 1);
        if (head == nullptr) head = temp;
        else tail->next_handle(temp);
        tail = temp;
    }
    for (class_test *temp = head; temp != nullptr; temp = temp->return_next()){
        temp->show();
    }
    while (head != nullptr){
        temp = head->return_next();
        delete head;
        head = temp;
    }
}