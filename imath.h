/**
 * author:  Zexi
 * website: https://github.com/JokerShao
 */
#pragma once


namespace imath {

#ifdef MATHREAL_DOUBLE
    typedef double mathreal;
#else
    typedef float mathreal;
#endif

    // do not use this function in quaternion normalization.
    // it will lead to orientation error.
    // see http://blog.sina.com.cn/s/blog_15211dfec0102wvbz.html
    // actually, it isn't faster than std::sqrt :-(
    float fastinvsqrt(float x);

    double fastinvsqrt(double x);
}

