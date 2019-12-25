/*队列中包含两个栈stack1和stack2
 *
 *
 *
 *
 */

template <typename T> calss CQuene
{
public:
    CQuene(void);
    ~CQuene(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};
