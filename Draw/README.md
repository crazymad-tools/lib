该类用于在linux终端绘制管理界面，具有绘制线条、擦除、输出、绘制边框等功能

需要注意的是，Draw中将屏幕左上角作为坐标原点，竖轴是x轴，横轴是y轴

API介绍：

```cpp
void move(int x, int y)
将光标移动到行号为x，列号为y的位置上
```

```cpp
void reset(int x1, int y1, int x2, int y2)
将以左上角顶点和右下角顶点确定出来的矩形区域内的字符全部擦除
```

```cpp
void line(int x1, int y1, int x2, int y2, char ch)
绘制线条，根据给出的两个端点以及给定的字符绘制线条，线条会被指定字符填充，但是只能绘制横竖两种线条
```

```cpp
void print(int x, int y, char* str, int len)
根据给定的位置(x, y)，在给定的位置输出str字符串，因为内部使用的是write函数来输出的，所以需要指定字符串长度
```
