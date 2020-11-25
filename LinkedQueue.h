#pragma once

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkedQueue
{
private:
	Node<DataType>* front, * rear;
public:
	LinkedQueue();//构造函数
	~LinkedQueue();//析构函数
	void EnterQueue(DataType value);//入队函数
	DataType DeleteQueue();//将队头元素出队
	DataType GetFirst();//只读读取队头元素
	bool IsEmpty();//判断队列是否为空。是则返回1，否则返回0
};