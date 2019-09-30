#include "naivefilter.h"

using namespace nf;

NaiveFilter :: NaiveFilter() {}

cv :: Mat NaiveFilter :: nostalgia (cv :: Mat & I) {
    // Only deal with BGR imgs
    int cols = I.cols, rows = I.rows;
    cv :: Mat ret(I.size(), CV_8UC3);
    for (int j = 0; j < rows ; ++j) {
            uchar * p0  = I.ptr<uchar>(j);
            uchar * p1  = ret.ptr<uchar>(j);
            for (int i = 0; i < cols ; i++) {
                float B = p0[3*i];
                float G = p0[3*i+1];
                float R = p0[3*i+2];
                float newB = 0.272 * R + 0.534 * G + 0.131 * B;
                float newG = 0.349 * R + 0.686 * G + 0.168 * B;
                float newR = 0.393 * R + 0.769 * G + 0.189 * B;
                if (newB > 255) newB = 255;
                if (newG > 255) newG = 255;
                if (newR > 255) newR = 255;
                p1[3*i] = (uchar)newB;
                p1[3*i+1] = (uchar)newG;
                p1[3*i+2] = (uchar)newR;
        }
    }
    return ret;
}

cv :: Mat NaiveFilter :: carve (cv :: Mat & I) {
    cv :: Mat ret(I.size(), I.type());
    cv :: Mat retGray(I.size(), I.type());
    for (int j = 1 ; j < I.rows - 1 ; ++j) {
        uchar* p0 = I.ptr<uchar>(j);
        uchar* p1 = I.ptr<uchar>(j);
        uchar* q = ret.ptr<uchar>(j);
        for (int i = 1 ; i < I.cols - 1 ; ++i) {
            for (int s = 0 ; s < 3 ; ++s) {
                short tmp = p1[3*(i+1)+s] - p0[3*(i-1)+s] + 128;
                if (tmp < 0) {
                    q[3*i+s] = 0;
                }
                else if (tmp > 255) {
                    q[3*i+s] = 255;
                }
                else {
                    q[3*i+s] = tmp;
                }
            }
        }
    }
    cv :: cvtColor(ret, retGray, cv :: COLOR_BGR2GRAY);
    return retGray;
}

cv :: Mat NaiveFilter :: cameo (cv :: Mat & I) {
    cv :: Mat ret(I.size(), I.type());
    cv :: Mat retGray(I.size(), I.type());
    for (int j = 1 ; j < I.rows - 1 ; ++j) {
        uchar* p0 = I.ptr<uchar>(j);
        uchar* p1 = I.ptr<uchar>(j);
        uchar* q = ret.ptr<uchar>(j);
        for (int i = 1 ; i < I.cols - 1 ; ++i) {
            for (int s = 0 ; s < 3 ; ++s) {
                short tmp = p0[3*(i-1)+s] - p1[3*(i+1)+s] + 128;
                if (tmp < 0) {
                    q[3*i+s] = 0;
                }
                else if (tmp > 255) {
                    q[3*i+s] = 255;
                }
                else {
                    q[3*i+s] = tmp;
                }
            }
        }
    }
    cv :: cvtColor(ret, retGray, cv :: COLOR_BGR2GRAY);
    return retGray;
}
