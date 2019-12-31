#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank;  //秩
#define DEFAULT_CAPACITY 3  //默认的初始容量

template <typename T> class Vector
{   //向量模板类

protected:
    Rank _size;      //规模
    int _capacity;  //容量
    T* _elem;      //数据区

    void copyFrom (T const* A, Rank lo, Rank hi);   //copy array area A[lo, hi)
    void expand();      //expand the space when it is not enough
    void shrink();      //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);  // scan and exchange
    void bubbleSort(Rank lo, Rank hi); //bubble sort algorithom
    Rank max(Rank lo, Rank hi);    //choose the maximum element
    void selectionSort(Rank lo, Rank hi);

public:
    //构造函数
    Vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0);  //容量为c，规模为s，所有元素初始化为v

