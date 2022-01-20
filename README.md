本代码库是学习侯捷老师C++的相关课程的记录


一、《C++面向对象高级开发》






二、《STL和泛型编程》

侯捷老师的c++系列视频，可能是因为版权原因被B站下架，我在知乎找到了相关视频，地址见：https://www.zhihu.com/people/cpp_yang/zvideos

第一讲(1-7):使用一个东西，却不知道道理，不高明

1.test_stl_containter文件夹中包含多种容器的的测试，如array/vector/list/forward_list/deque

2.test_stl_allocator是关于分配器的测试，侯捷老师给的结论是：
(1)在c++编程中不建议直接使用分配器allocator，而应该去使用容器container(会自带分配器分配内存);
(2)如果有小量的内存使用需求，建议使用new搭配delete或者malloc搭配free；


第二讲(8-):源码之前，了无秘密
C++基本语法
模板(Templates)基础-令你事半功倍
数据结构(Data Structures)和算法(Algorithm)基础-令你如鱼得水


