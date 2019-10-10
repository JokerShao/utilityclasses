/**
 * author:  Zexi
 * website: https://github.com/JokerShao
 */
#ifndef _IMATH_H_
#define _IMATH_H_


namespace imath {

    #ifdef MATHREAL_DOUBLE
        typedef double mathreal;
    #else
        typedef float mathreal;
    #endif

    // do not use this function in quaternion normalization.
    // it will lead to orientation error.
    // see http://blog.sina.com.cn/s/blog_15211dfec0102wvbz.html
    // actually, it is't faster than std::sqrt :-(
    float fastinvsqrt(float x);

    double fastinvsqrt(double x);

}
#endif

