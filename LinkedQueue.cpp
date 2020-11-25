#include <iostream>
#include "LinkedQueue.h"
using namespace std;


//构造函数
template<class DataType>
inline LinkedQueue<DataType>::LinkedQueue()
{
	Node<DataType>* temp = new Node<DataType>;
	temp->next = nullptr;
	front = rear = temp;
}

//析构函数
template<class DataType>
inline LinkedQueue<DataType>::~LinkedQueue()
{
	Node<DataType>* temp = nullptr;
	while (front != nullptr)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
}

//入队函数
template<class DataType>
inline void LinkedQueue<DataType>::EnterQueue(DataType value)
{
	Node<DataType>* temp = new Node<DataType>;
	temp->data = value;
	temp->next = nullptr;
	rear->next = temp;
	rear = temp;
}

//将队头元素出队
template<class DataType>
inline DataType LinkedQueue<DataType>::DeleteQueue()
{
	Node<DataType>* temp = nullptr;
	int valuetemp;
	if (rear == front) throw "下溢";
	//头结点不属于该队列。以下操作为：将temp指针指向待出队元素，并将头指针指向该元素下一个元素，删除temp指针对应元素并返回值
	temp = front->next;
	valuetemp = temp->data;
	front->next = temp->next;
	//如果temp指向元素的下一个元素为空，则队列为空
	if (temp->next == nullptr)
		rear = front;
	delete temp;
	return valuetemp;
}

//只读读取队头元素
template<class DataType>
inline DataType LinkedQueue<DataType>::GetFirst()
{
	if (front != rear)
		return front->next->data;
	else
		return NULL;
}

//判断队列是否为空。是则返回1，否则返回0
template<class DataType>
inline bool LinkedQueue<DataType>::IsEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}