#ifndef NUMBERARR_H
#define NUMBERARR_H


template <typename T>
class NumberArr {
public:
    explicit NumberArr(int length);
    T *get_x() const;
    void print_value();
    void set_value(int value);
    int get_length();
private:
    int* x;
    int length_;
};

#endif // NUMBERARR_H