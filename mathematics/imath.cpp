/**
 * author:  Zexi
 * website: https://github.com/JokerShao
 */
#include "imath.h"


namespace imath {

    float fastinvsqrt(float x, int niter)
    {
        float xhalf = 0.5f * x;
        int i = *(int *)&x;
        i = 0x5f3759df - (i >> 1);
        x = *(float *)&i;
        // iterator
        for (int n = 0; n < niter; n++)
            x = x * (1.5f - xhalf * x * x);
        return x;
    }

}

