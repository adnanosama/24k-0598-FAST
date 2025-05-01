#include <iostream>
#include <exception>
#include <string>
#include <memory>
#include <typeinfo>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Requested type does not match the stored type.";
    }
};

class Placeholder {
public:
    virtual ~Placeholder() = default;
    virtual const type_info& type() const = 0;
    virtual unique_ptr<Placeholder> clone() const = 0;
};

template<typename T>
class Holder : public Placeholder {
    T value;
public:
    Holder(const T& val) : value(val) {}
    const type_info& type() const override {
        return typeid(T);
    }
    unique_ptr<Placeholder> clone() const override {
        return make_unique<Holder<T>>(value);
    }
    T get() const {
        return value;
    }
};

class TypeSafeContainer {
    unique_ptr<Placeholder> data;
public:
    template<typename T>
    void store(const T& value) {
        data = make_unique<Holder<T>>(value);
    }

    template<typename T>
    T get() const {
        if (!data || data->type() != typeid(T)) {
            throw BadTypeException();
        }
        return static_cast<Holder<T>*>(data.get())->get();
    }
};

int main() {
    TypeSafeContainer container;
    container.store<string>("Hello, Adnan!");
    try {
        cout << container.get<string>() << endl;
        int x = container.get<int>();
    } catch (const BadTypeException& e) {
        cout << e.what() << endl;
    }
    return 0;
}
