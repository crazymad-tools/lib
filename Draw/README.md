该类用于在linux终端绘制管理界面，具有绘制线条、擦除、输出、绘制边框等功能

需要注意的是，Draw中将屏幕左上角作为坐标原点，竖轴是x轴，横轴是y轴

API介绍：

```cpp
void move(int x, int y)
```

将光标移动到行号为x，列号为y的位置上

```cpp
void reset(int x1, int y1, int x2, int y2)
```

将以左上角顶点和右下角顶点确定出来的矩形区域内的字符全部擦除


