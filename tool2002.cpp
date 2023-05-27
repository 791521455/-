#include <windows.h>
#include <stdio.h>

// ����Point�ṹ�壬����x,y������Ϣ
typedef struct {
    int x;
    int y;
} Point;

// ���������㺯���������������������Ϣ��������ӽ��
void connect(Point p1, Point p2) {
    printf("���ӵ�(%d,%d)�͵�(%d,%d)\n", p1.x, p1.y, p2.x, p2.y);
    // �ڴ˴�������Ӳ��������Ե���������������ֱ�Ӵ���
}

bool SetSize(int width, int height)
{
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ������
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 }; //���ÿ��
	bool ret = SetConsoleWindowInfo(hOutput, TRUE, &wrt); // ���ô���ߴ�
	if (!ret) return false;
	COORD coord = { width, height };
	ret = SetConsoleScreenBufferSize(hOutput, coord); // ���û���ߴ�
	return ret;
}

int main() {
	SetSize(30,20);
	int l_x=0,l_y=0;
    while (1) {
        // ��ȡ�������
        POINT pt;
        if (GetCursorPos(&pt)) {
        	if(pt.x!=l_x&&pt.y!=l_y) {
        		printf("��ǰ�������Ϊ(%d, %d)\n", pt.x, pt.y);
        	    //connect(mousePoint, Point{100, 100}); // ����connect�����������Ӳ���
			}
            Point mousePoint = {pt.x, pt.y};
            l_x=pt.x;
            l_y=pt.y;
            
        }
        Sleep(100); // ���1��
    }
    return 0;
}


	//printf("5���ʼ������"); 
	//Sleep(5000);
