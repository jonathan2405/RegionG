#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <omp.h>
#include <memory.h>
//#include "opencv2/opencv.hpp”

//using namespace cv;
using namespace std;
typedef int element;

short adaptativeProcess (const Mat &im, int row, int col, int kernelSize, int maxSize)
{
    vector <short> pixels;
for (int a = -kernelSize / 2; a <= kernelSize / 2; a++) {
    for (int b = -kernelSize / 2; b <= kernelSize / 2; b++){
        pixels. push_back(im[row + a][col + b]) ;

}
}
sort(pixels. begin(), pixels.end());
auto min = pixels[0];
auto max = pixels[kernelSize * kernelSize -1];
short  med = pixels[kernelSize * kernelSize / 2];
short  zxy = im.at <short>(row,col);
if(med > min && med < max) {
        if (zxy > min && zxy < max) {
            return zxy;
         }else{
  return med;
          }
}
else{
kernelSize +=2;
if (kernelSize <= maxSize)
return adaptiveProcess(im, row, col, kernelSize, maxSize);
else
    return med;
}
}



