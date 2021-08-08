#include <iostream>
#include <vector>

using namespace std;
typedef struct Heap
{
    vector<int> items;

    int parent(int index)
    {
        if (index == 0)
            return 0;
        else
            return (index - 1) / 2;
    }
    int left(int index)
    {
        return index * 2 + 1;
    }
    int right(int index)
    {
        return index * 2 + 2;
    }

    void swap(int &a, int &b)
    {
        int c = b;
        b = a;
        a = c;
    }
    void siftUp(int k)
    {
        while (k > 0 && items[k] > items[parent(k)])
        {
            swap(items[k], items[parent(k)]);
            k = parent(k);
        }
    }
    void siftDown(int k)
    {
        while (left(k) < size())
        { // 从左节点开始，如果左节点小于数组长度，就没有右节点了
            int j = left(k);
            if (j + 1 < size() && items[j + 1] > items[j])
            { // 选举出左右节点最大的那个
                j++;
            }
            if (items[k] >= items[j])
            { // 如果当前节点大于左右子节点，循环结束
                break;
            }
            swap(items[k], items[j]);
            k = j;
        }
    }
    void push(int);
    int pop();
    int top();
    int size();
} Heap;

void Heap::push(int item)
{
    this->items.push_back(item);
    this->siftUp(this->size() - 1);
    return;
}

int Heap::pop()
{

    int ret = this->items[0];
    this->items.removeLast();
    siftDown(0);
    return ret;
}

int Heap::top()
{
}
int Heap::size() { return this->items.size(); }
void build_heap(Heap &h) {}
void swap(int &a, int &b)
{
    int c = b;
    b = a;
    a = c;
}
int main(int, char **) { std::cout << "Hello, world!\n"; }