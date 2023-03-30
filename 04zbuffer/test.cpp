TGAImage render(width,16,TGAImage::RGB);
int ybuffer[width];
for(int i = 0 ; i < width ; ++i)
	ybuffer[i] = std::numeric_limits<int>::min(); // 初始化为0
rasterize(Vec2i(20,34) , Vec2i(744,400) , render,red,ybuffer);
rasterize(Vec2i(120, 434), Vec2i(444, 400), render, green, ybuffer);
rasterize(Vec2i(330, 463), Vec2i(594, 200), render, blue,  ybuffer);
// 光栅化绘制这三条直线 但是要用ybuffe