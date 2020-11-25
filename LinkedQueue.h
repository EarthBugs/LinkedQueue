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
	LinkedQueue();//���캯��
	~LinkedQueue();//��������
	void EnterQueue(DataType value);//��Ӻ���
	DataType DeleteQueue();//����ͷԪ�س���
	DataType GetFirst();//ֻ����ȡ��ͷԪ��
	bool IsEmpty();//�ж϶����Ƿ�Ϊ�ա����򷵻�1�����򷵻�0
};