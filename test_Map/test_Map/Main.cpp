

#include<iostream>
#include<fstream>
#include <string>
#include<windows.h>
using namespace std;

#pragma pack(1)
struct header
{
    int16_t header;
    int32_t filesize;
    int16_t reser;
    int16_t reser1;
    int32_t dataoffset;
};

struct infoheader
{
    int32_t headersize;
    int32_t width;
    int32_t height;
    int16_t plans;
    int16_t bpp;
    int32_t compression;
    int32_t datasize;
    int32_t re;
    int32_t ve;
    int32_t color;
    int32_t importantcolor;
};


struct  PIxel
{
    unsigned char G;
    unsigned char B;
    unsigned char R;
};
   

void outinfo(PIxel* p, infoheader info)
{
    int i, j;
    cin >> i >> j;
    int index = i * info.width + j;
    cout << (int)p[index].G << "  " << (int)p[index].B << "  " << (int)p[index].R << endl;
   
    cout << "new1" << endl;

}


int main()
{
    cout << 1<<" ";
    header h;
    infoheader info;
    PIxel* p;
    ifstream file("bmp3.bmp", ios::binary);
    if (file.is_open())
    {
        
        cout << "true" << endl;
        file.read((char*)&h, sizeof(h));
        if (h.header == 0x4D42)
        {
            cout << 1 << endl;
            file.read((char*)&info, sizeof(info));
            cout << info.width << " " << info.height << " " << h.filesize << " " << info.bpp << endl;
            int pa = info.width % 4;
            int size = info.width * info.height * (info.bpp / 8) +pa * info.height;
            char* arr = new char[size];
            file.read(arr, size);
            char* temp = arr;
            int sizep = info.height * info.width;
            p = new PIxel[sizep];

            for (int i = info.height - 1; i >= 0; i--)
            {
                for (int j = 0; j < info.width; j++)
                {
                    //temp++;
                    int index = i * info.width + j;
                    p[index].B= *(temp++);
                    p[index].G = *(temp++);
                    p[index].R = *(temp++);
                    //p = p + 3;
                }
                //temp++;
                temp += pa;
            }

            ofstream file1;
            file1.open("bmpt.bmp", ios::binary);
            if (file1.is_open())
            {
                cout << "hwlo" << endl;
                file1.write((char*)&h, sizeof(header));
                file1.write((char*)&info, sizeof(infoheader));
                file1.write(arr, size);
            }
            else
            {
                cout << "123" << endl;
            }
          //  outinfo(p, info);
            HWND consoleWindow = GetConsoleWindow();
            HDC hdc = GetDC(consoleWindow);
            for (int i = 0; i < info.height; i++)
            {
                for (int j = 0; j < info.width; j++)
                {
                    int index = i * info.width + j;
                    PIxel m = p[index];
                    SetPixel(hdc, j, i, RGB(m.R, m.G, m.B));
                }
            }
            ReleaseDC(consoleWindow, hdc);
        }
        else
        {
            cout << 0;
        }
    }
   
}