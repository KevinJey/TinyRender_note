#include "tgaimage.h"
#include <cstdlib>
#include <time.h>
// #include <unistd.h>
#include <chrono>
#include <thread>
/**
 * @brief 
 *      
 * 
 */
TGAImage image(100, 100, TGAImage::RGB);    // 相当于创建了一个buffer

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    bool step = false;
    if(std::abs(x0-x1) < std::abs(y0-y1)){
        std::swap(x0,y0);
        std::swap(x1,y1);
        step=true;
    } //如果斜率小于1 则需要交换坐标的x,y 坐标，这个是由bresenham算法决定的
    if(x0 > x1) {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }
    for(int x = x0 ; x <= x1 ; ++x){
        float m = (x-x0)/(float)(x1-x0);
        int y = m*(y1-y0)+y0;
        if(step){
            image.set(y,x,color);
        }else{
            image.set(x,y,color);
        }
        image.write_tga_file("output.tga");
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}

int main(int argc, char** argv) {
    line(13, 20, 80, 40, image, white); //线段A
    line(20, 13, 40, 80, image, red); //线段B
    line(80, 40, 13, 20, image, red);//线段C    image.flip_vertically();
    return 0;
}

