#include <iostream>
using namespace std;

class class_test{
    private:
    string m_name;
    string m_id;
    int m_age;
    class_test *next;

    public:
    class_test(string name, string id, int age){
        cout << "调用了" << age << "构造函数" << endl;
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
        cout << "调用" << m_age << "了析构函数" << endl;
    }
    void next_handle(class_test *node) {
        next = node;
    }
    class_test *return_next(){
        return next;
    }
    void show();
};

inline void class_test::show(){
    cout << "name: " << m_name << " id: " << m_id << " age: " << m_age << endl;
}

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