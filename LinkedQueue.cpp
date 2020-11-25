#include <iostream>
#include "LinkedQueue.h"
using namespace std;


//���캯��
template<class DataType>
inline LinkedQueue<DataType>::LinkedQueue()
{
	Node<DataType>* temp = new Node<DataType>;
	temp->next = nullptr;
	front = rear = temp;
}

//��������
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

//��Ӻ���
template<class DataType>
inline void LinkedQueue<DataType>::EnterQueue(DataType value)
{
	Node<DataType>* temp = new Node<DataType>;
	temp->data = value;
	temp->next = nullptr;
	rear->next = temp;
	rear = temp;
}

//����ͷԪ�س���
template<class DataType>
inline DataType LinkedQueue<DataType>::DeleteQueue()
{
	Node<DataType>* temp = nullptr;
	int valuetemp;
	if (rear == front) throw "����";
	//ͷ��㲻���ڸö��С����²���Ϊ����tempָ��ָ�������Ԫ�أ�����ͷָ��ָ���Ԫ����һ��Ԫ�أ�ɾ��tempָ���ӦԪ�ز�����ֵ
	temp = front->next;
	valuetemp = temp->data;
	front->next = temp->next;
	//���tempָ��Ԫ�ص���һ��Ԫ��Ϊ�գ������Ϊ��
	if (temp->next == nullptr)
		rear = front;
	delete temp;
	return valuetemp;
}

//ֻ����ȡ��ͷԪ��
template<class DataType>
inline DataType LinkedQueue<DataType>::GetFirst()
{
	if (front != rear)
		return front->next->data;
	else
		return NULL;
}

//�ж϶����Ƿ�Ϊ�ա����򷵻�1�����򷵻�0
template<class DataType>
inline bool LinkedQueue<DataType>::IsEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}