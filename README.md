#cairo demo
概述
==
cairo 开源计算机绘图库,他可以向多种设备上画图.可以输出到pdf,ps，xlib，XCB，win32，svg。用于渲染ofd文档
记录 cairo 使用

编译
==
1. os: macx
2. cairo version:1.14.6
2. url:https://www.cairographics.org/releases/cairo-1.14.6.tar.xz
3. `./configure; make;make install`

demo
==
1. hello world
	
	基本使用,输出hello world保存png

	$ `make;./main;` 当前目录下生成hello.png


资料
==
+ [用 cairo 实现跨平台图形](http://www.ibm.com/developerworks/cn/linux/l-cairo/)

+ [Cairo图形指南](http://blog.chinaunix.net/uid-20665885-id-1903545.html)
