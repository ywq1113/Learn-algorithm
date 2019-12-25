#include <iostream>


using namespace std;

template<typename T> void CQuene<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template<typename T> T CQuene<T>::deleteHead()
{
    
