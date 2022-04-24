#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <class T>
class my_set {
public:
    my_set(std::vector<T>& vec);
    my_set();
    void Copy_set(std::vector<T>& vec);
    void push_el(T el);
    void Clear();
    void add(const my_set& r, std::vector<T>& buf);
    void mult(const my_set& r, std::vector<T>& buf);
    void sim_sub(my_set& r, std::vector<T>& buf);
    bool Ability_to_become_int(const std::string& Str);
private:
    std::vector<T> base;
};

template<class T>
my_set<T>::my_set(std::vector<T>& vec) {
    this->base = vec;
}

template<class T>
my_set<T>::my_set() {
    std::vector<T> base(0);
}

template<class T>
void my_set<T>::Copy_set(std::vector<T>& vec) {
    vec = this->base;
}

template<class T>
void my_set<T>::push_el(T el) {
    this->base.push_back(el);
    std::sort(this->base.begin(), this->base.end());
    auto last = std::unique(this->base.begin(), this->base.end());
    this->base.erase(last, this->base.end());
}

template<class T>
void my_set<T>::Clear() {
    this->base.clear();
}

template<class T>
void my_set<T>::add(const my_set& r, std::vector<T>& buf) {
    buf.clear();
    buf = this->base;
    for (size_t i = 0; i < r.base.size(); ++i) {
        this->push_el(r.base[i]);
    }
    std::sort(this->base.begin(), this->base.end());
    auto last = std::unique(this->base.begin(), this->base.end());
    this->base.erase(last, this->base.end());
    std::swap(this->base, buf);
}

template<class T>
void my_set<T>::mult(const my_set& r, std::vector<T>& buf) {
    buf.clear();
    for (size_t i = 0; i < this->base.size(); ++i) {
        for (size_t j = 0; j < r.base.size(); ++j) {
            if (this->base[i] == r.base[j]) {
                buf.push_back(r.base[j]);
                break;
            }
        }
    }
}

template<class T>
void my_set<T>::sim_sub(my_set& r, std::vector<T>& buf) {
    buf.clear();

    if (this->base.size() == 0) buf = r.base;
    if (r.base.size() == 0) buf = this->base;

    for (size_t i = 0; i < this->base.size(); ++i) {
        for (size_t j = 0; j < r.base.size(); ++j) {
            if (this->base[i] == r.base[j]) break;
            if ((r.base.size() - 1) == j) buf.push_back(this->base[i]);
        }
    }

    for (size_t i = 0; i < r.base.size(); ++i) {
        for (size_t j = 0; j < this->base.size(); ++j) {
            if (r.base[i] == this->base[j]) break;
            if ((this->base.size() - 1) == j) buf.push_back(r.base[i]);
        }
    }

    std::unique(buf.begin(), buf.end());
    std::sort(buf.begin(), buf.end());
}

template<class T>
bool my_set<T>::Ability_to_become_int(const std::string& Str) {
    std::string str = Str;
    for (size_t i = 0; i < str.size(); ++i) {
        if (int(str[i]) < 48 || int(str[i]) > 57) return 0;
    }
    return 1;
}
