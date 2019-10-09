# NaiveFilters
&nbsp;  

***An auxiliary image filter library based on opencv4.x***

***Easy to use with only 4 lines code.***
 &nbsp;  
 &nbsp;  
&nbsp;  
———————————————————————————————      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NaiveFilter 是一个用于处理图片的滤镜库   
———————————————————————————————    
&nbsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NaiveFilter 中文文档  
  
作者： 陈汉轩 HNU  
邮箱：youhengchan@qq.com  
发布时间：9 / 30 / 2019  
开源协议： MIT    
 &nbsp;  
 &nbsp;  
 &nbsp;  
 
## **特性简介**  
  
@基于 opencv4.x 和 C++ 开发，未封装opencv的最基本的操作如读入  
和保存，在使用NaiveFilter之前需要首先安装opencv4.x  
  
@基于 opencv4.x对机器学习的强大支持，NaiveFilter不仅提供了常见的基  
于传统图像处理方法的滤镜效果，同时内置了几种传统滤镜无法做到的基于  
神经网络的风格迁移滤镜  
  
@欢迎加入到NaiveFilter的开发中，正如名字所言，目前它还很Naive，  
NaiveFilter 因你更强大  
  
@后期计划加入实时处理功能和更多的基于ML方法实现的上妆卸妆效果  
（针对人物进行自动识别和关键点标定处理，对视频流进行处理速度优化）  
  

  
 &nbsp;  
 &nbsp;  
 &nbsp;  

  
## **安装与使用**  
&nbsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`NaiveFilter的使用十分简单，一共只需要5步，4行代码 `  
&nbsp;  
  
**第一步**    
git clone 并导入库到你的项目中  
`git clone https://github.com/youhengchan/NaiveFilters.git`  
将naivefilter.h和naivefilter.cpp导入对应的工程下  
&nbsp;    
&nbsp;   

**第二步**    
导入头文件  
`include "naivefilter.h"  `
&nbsp;    
&nbsp;   

**第三步**    
使用命名空间  
`using namespace nf  `
&nbsp;    
&nbsp;   

为了避免命名冲突，建议使用nf :: NaiveFilter，尽量不要直接使用  
上面的`using namespace nf  `
&nbsp;    
&nbsp;  

**第四步**    
创建一个NaiveFilter对象  
`nf :: NaiveFilter nv;  `
 &nbsp;  
 &nbsp;   
 
**第五步**    
一行代码调用  
`Mat dstImg = nv.nostalgia(srcImg);  `  
这个方法将返回给你一张调色好的怀旧风格的图片　　

&nbsp;    
&nbsp;　　
&nbsp;  　
&nbsp;  　
&nbsp;  　

  
  
## **API说明&实现原理**  

### 怀旧风格  
`nf :: NaiveFilter :: cv :: Mat nostalgia (cv :: Mat & I);`    
基于调色实现，对每一个点进行局部的点运算，调色系数配比采用：  
R = 0.393R + 0.769Ｇ + 0.189B  
G = 0.349R + 0.686G + 0.168B  
B = 0.272R + 0.534G + 0.131B  
![怀旧](https://github.com/youhengchan/NaiveFilters/blob/master/NaiveFilter/Samples/NostalgiaSample.jpeg)  
&nbsp;    
&nbsp;　　
&nbsp; 　

### 浮雕效果  
`nf :: NaiveFilter :: cv :: Mat cameo (cv :: Mat & I)；`  
首先使用图像一阶梯度算子对图像进行处理，得到边缘图像  
然后对得到的图像使用OpenCV内置的转换函数cvtColor()  
将对应的图像进行灰度处理得到结果  
![浮雕](https://github.com/youhengchan/NaiveFilters/blob/master/NaiveFilter/Samples/cameoSample.jpeg)  
&nbsp;    
&nbsp;　　
&nbsp; 　

### 雕刻效果  
`nf :: NaiveFilter :: cv :: Mat carve (cv :: Mat & I);`   
雕刻和浮雕的不同仅仅是处理顺序的不同   
![雕刻](https://github.com/youhengchan/NaiveFilters/blob/master/NaiveFilter/Samples/carveSample.jpeg)  
&nbsp;    
&nbsp;　　
&nbsp; 　
　　
  
  
  




