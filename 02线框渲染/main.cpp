#include <vector>
#include <cmath>
#include "tgaimage.h"   //tga画图库
#include "model.h"      //模型类，主要实现模型的读取
#include "geometry.h"   //几何库，主要定义了Vec2和Vec3类型

//定义颜色
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
Model *model = NULL;
//定义宽度高度
const int width  = 800;
const int height = 800;

// drawing line algorithm
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    bool step = false;
    if(std::abs(x0-x1) < std::abs(y0-y1)){
        std::swap(x0,y0);
        std::swap(x1,y1);
        step=true;
    } 
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
    }
}

int main(int argc, char** argv) {
    //命令行控制方式和代码方式构造model
    //构造模型(obj文件路径)
    if (2==argc) {
        model = new Model(argv[1]);
    } else {
        model = new Model("obj/african_head.obj");
    }
    //构造tga(宽，高，指定颜色空间)
    TGAImage image(width, height, TGAImage::RGB);
    //模型的面作为循环控制变量
    for (int i=0; i<model->nfaces(); i++) {
        //创建face数组用于保存一个face的三个顶点坐标
        std::vector<int> face = model->face(i);
        // 遍历三角面的三个顶点然后连点成线
        for (int j=0; j<3; j++) {
            //顶点v0
            Vec3f v0 = model->vert(face[j]);
            //顶点v1
            Vec3f v1 = model->vert(face[(j+1)%3]);
            //根据顶点v0和v1画线
            //先要进行模型坐标到屏幕坐标的转换
            //(-1,-1)对应(0,0)   (1,1)对应(width,height)
            // 从NDC 坐标转换到屏幕坐标也是简单的 比例*屏幕size+ offset
            int x0 = (v0.x+1.)*width/2.;
            int y0 = (v0.y+1.)*height/2.;
            int x1 = (v1.x+1.)*width/2.;
            int y1 = (v1.y+1.)*height/2.;
            //画线
            line(x0,y0, x1,y1, image, white);
        }
    }

    //tga默认原点在左上角，现需要指定为左下角，所以进行竖直翻转
    image.flip_vertically();
    image.write_tga_file("output.tga");
    delete model;
    return 0;
}

