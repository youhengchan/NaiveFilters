/**
 * Lib name : NaiveFilter
 * Info : An img filter library based on opencv4.x
 * Version : 1.0.0
 * Email : youhengchan@qq.com
 * Usage : PLZ refer to README.md
 * Published : 10/5/2019
 * Site : https://github.com/youhengchan/NaiveFilters
 * License : MIT
 */

#ifndef NAIVEFILTER_H
#define NAIVEFILTER_H

#include <opencv2/opencv.hpp>

// nf : Abbr of NaiveFilter
namespace nf {

    class NaiveFilter {
        public:
            NaiveFilter();
            // Image processing with traditional method
            cv :: Mat nostalgia (cv :: Mat & I);
            cv :: Mat cameo (cv :: Mat & I);
            cv :: Mat carve (cv :: Mat & I);

            // Image processing with ML

    };

}


#endif // NAIVEFILTER_H
