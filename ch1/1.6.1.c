//1.6.1(a) 指出赋给w,x,y,z的值
int w, x, y, z;
int i = 4; int j = 5;
{
    int j = 7;
    i = 6;
    w = i + j;
}

x = i + j;

{
    int i = 8;
    y = i + j;
}

z = i + j;

// w = 13, x = 11, y = 13, z = 11
