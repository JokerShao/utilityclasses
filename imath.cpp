/**
 * author:  Zexi
 * website: https://github.com/JokerShao
 */
#include "imath.h"


namespace imath {

    float fastinvsqrt(float x)
    {
        float xhalf = 0.5f * x;
        int i = *(int*)&x;
        i = 0x5f3759df/*0x5f375a86*/ - (i >> 1);
        x = *(float*)&i;
        x = x * (1.5f - xhalf * x * x);
        x = x * (1.5f - xhalf * x * x); // 2nd iteration, this can be removed
        return x;
    }

    double fastinvsqrt(double x)
    {
        double xhalf = 0.5 * x;
        long long i = *(long*)&x;
        i = 0x5fe6eb50c7aa19f9 - (i >> 1);
        x = *(double*)&i;
        x = x * (1.5 - xhalf * x * x);
        x = x * (1.5 - xhalf * x * x); // 2nd iteration, this can be removed
        return x;
    }
}
//
//function q = rotMat2qRichard(R)
//vX = R(1, :);
//vY = R(2, :);
//
//qX = qUtoV(vX, [1, 0, 0]);
//
//y = qMultiVec(vY, qX);
//qY = qUtoV(y, [0, 1, 0]);
//
//qx = [-qX(1), qX(2:4)];
//qy = [-qY(1), qY(2:4)];
//
//q = qMultiQ(qx, qy);
//
//end
//
//
//function[qq] = qMultiQ(p, q) % p * q
//qq = [...
//p(1) * q(1) - p(2) * q(2) - p(3) * q(3) - p(4) * q(4)...
//, p(2) * q(1) + p(1) * q(2) - p(4) * q(3) + p(3) * q(4)...
//, p(3) * q(1) + p(4) * q(2) + p(1) * q(3) - p(2) * q(4)...
//, p(4) * q(1) - p(3) * q(2) + p(2) * q(3) + p(1) * q(4)];
//
//end
//
//
//function q = qUtoV(v1, v2) % two vetor rotation to quaternions
//nv1 = v1 / norm(v1);
//nv2 = v2 / norm(v2);
//
//if norm(nv1 + nv2) == 0
//q = [0, [1, 0, 0]];
//else
//half = (nv1 + nv2) / norm(nv1 + nv2);
//q = [nv1 * half',cross(nv1, half)];
//end
//end

//function[vector] = qMultiVec(vec, q) % sensor frame to world frame
//x = q(2);
//y = q(3);
//z = q(4);
//w = q(1);
//
//vecx = vec(1);
//vecy = vec(2);
//vecz = vec(3);
//
//x_ = w * vecx + y * vecz - z * vecy;
//y_ = w * vecy + z * vecx - x * vecz;
//z_ = w * vecz + x * vecy - y * vecx;
//w_ = -x * vecx - y * vecy - z * vecz;
//
//vector = [x_ * w + w_ * -x + y_ * -z - z_ * -y ...
//, y_ * w + w_ * -y + z_ * -x - x_ * -z ...
//, z_ * w + w_ * -z + x_ * -y - y_ * -x ...
//];
//
//end
//
//
//
//void getQuaternion(Mat R, double Q[])
//{
//    double trace = R.at<double>(0, 0) + R.at<double>(1, 1) + R.at<double>(2, 2);
//
//    if (trace > 0.0)
//    {
//        double s = sqrt(trace + 1.0);
//        Q[3] = (s * 0.5);
//        s = 0.5 / s;
//        Q[0] = ((R.at<double>(2, 1) - R.at<double>(1, 2)) * s);
//        Q[1] = ((R.at<double>(0, 2) - R.at<double>(2, 0)) * s);
//        Q[2] = ((R.at<double>(1, 0) - R.at<double>(0, 1)) * s);
//    }
//
//    else
//    {
//        int i = R.at<double>(0, 0) < R.at<double>(1, 1) ? (R.at<double>(1, 1) < R.at<double>(2, 2) ? 2 : 1) : (R.at<double>(0, 0) < R.at<double>(2, 2) ? 2 : 0);
//        int j = (i + 1) % 3;
//        int k = (i + 2) % 3;
//
//        double s = sqrt(R.at<double>(i, i) - R.at<double>(j, j) - R.at<double>(k, k) + 1.0);
//        Q[i] = s * 0.5;
//        s = 0.5 / s;
//
//        Q[3] = (R.at<double>(k, j) - R.at<double>(j, k)) * s;
//        Q[j] = (R.at<double>(j, i) + R.at<double>(i, j)) * s;
//        Q[k] = (R.at<double>(k, i) + R.at<double>(i, k)) * s;
//    }
//}

