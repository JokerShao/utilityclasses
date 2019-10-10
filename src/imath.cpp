/**
 * author:  Zexi
 * website: https://github.com/JokerShao
 */
#include "imath.h"


namespace imath {

    float fastinvsqrt(float x)
    {
        float xhalf = 0.5f * x;
        int i = *(int *)&x;
        i = 0x5f3759df/*0x5f375a86*/ - (i >> 1);
        x = *(float *)&i;
        x = x * (1.5f - xhalf * x * x);
        x = x * (1.5f - xhalf * x * x); // 2nd iteration, this can be removed
        return x;
    }

    double fastinvsqrt(double x)
    {
        double xhalf = 0.5 * x;
        long i = *(long*)&x;
        i = 0x5fe6eb50c7aa19f9 - (i >> 1);
        x = *(double*)&i;
        x = x * (1.5 - xhalf * x * x);
        x = x * (1.5 - xhalf * x * x); // 2nd iteration, this can be removed
        return x;
    }

}

