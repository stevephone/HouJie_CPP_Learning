#ifndef __TEST_COMPLEX__
#define __TEST_COMPLEX__

template <typename T>
class my_complex
{
public:
    my_complex(T r = 0, T i = 0)
        : re(r), im(i)
    {   }
    // my_complex() : re(0), im(0) {}
    my_complex &operator+=(const my_complex &); //操作数重载，复数相加
    T real()
        const { return re; }
    T imag()
        const { return im; }    //real()和imag()写在class body中，则为inline内联函数

private:
    T re, im;
};

#endif
