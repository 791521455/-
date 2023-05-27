#include <windows.h>
#include <stdio.h>

// 定义Point结构体，包含x,y坐标信息
typedef struct {
    int x;
    int y;
} Point;

// 连接两个点函数，输入两个点的坐标信息，输出连接结果
void connect(Point p1, Point p2) {
    printf("连接点(%d,%d)和点(%d,%d)\n", p1.x, p1.y, p2.x, p2.y);
    // 在此处完成连接操作，可以调用其他函数或者直接处理
}

bool SetSize(int width, int height)
{
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE); //获取输出句柄
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 }; //设置宽高
	bool ret = SetConsoleWindowInfo(hOutput, TRUE, &wrt); // 设置窗体尺寸
	if (!ret) return false;
	COORD coord = { width, height };
	ret = SetConsoleScreenBufferSize(hOutput, coord); // 设置缓冲尺寸
	return ret;
}

int main() {
	SetSize(30,20);
	int l_x=0,l_y=0;
    while (1) {
        // 获取鼠标坐标
        POINT pt;
        if (GetCursorPos(&pt)) {
        	if(pt.x!=l_x&&pt.y!=l_y) {
        		printf("当前鼠标坐标为(%d, %d)\n", pt.x, pt.y);
        	    //connect(mousePoint, Point{100, 100}); // 调用connect函数进行连接操作
			}
            Point mousePoint = {pt.x, pt.y};
            l_x=pt.x;
            l_y=pt.y;
            
        }
        Sleep(100); // 间隔1秒
    }
    return 0;
}


	//printf("5秒后开始！！！"); 
	//Sleep(5000);
