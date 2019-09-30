#include <opencv2/opencv.hpp>
#include "naivefilter.h"


using namespace nf;
using namespace cv;
using namespace std;

int main(void) {

    // Import sample source image
    String dir = "/home/chenhanxuan/Pictures/tree.png";
    Mat srcImg = imread(dir, IMREAD_COLOR);
    if (srcImg.empty()) {
        cout << "Read img error" << endl;
        return -1;
    }


    // Create a image filter handler
    NaiveFilter nv;


    // Use filters methods of nv
    Mat nostalgiaImg = nv.nostalgia(srcImg);
    Mat cameoImg = nv.cameo(srcImg);
    Mat carveImg = nv.carve(srcImg);


    // Show effects
    imshow("SOURCE IMG", srcImg);
    imshow("NOSTALGIA IMG", nostalgiaImg);
    imshow("CAMEO IMG", cameoImg);
    imshow("CARVE IMG", carveImg);

    waitKey();
    return 0;
}
