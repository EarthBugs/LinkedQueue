#include <iostream>
#include "LinkedQueue.cpp"
using namespace std;

int main()
{
	LinkedQueue<int>* linkedqueue = nullptr;

	//循环执行以下do-while部分，除非用户退出程序
	bool exit_flag = 0;
	do
	{
		int input;

		//输入并检测输入合法性 
		int error_flag = 0;
		do
		{
			error_flag = 0;

			cout << "选择将要进行的操作(输入对应序号)(可输入0获取帮助)：";
			cin >> input;

			switch (input)
			{

			case 0://输出帮助
			{
				cout << "1.退出程序\n2.创建空链队列\n3.检测链队列是否为空\n4.使用指定元素入队列\n5.只读读取队头元素\n6.队头元素出队" << endl;
				break;
			}

			case 1:case 2:break;

			case 3:case 4:case 5:case 6:case 7:
			{
				//判断linkedqueue指针是否为空，为空则不允许对指向的对象进行操作
				if (linkedqueue == nullptr)
				{
					cout << "请先创建链队列！" << endl;
					error_flag = 1;
				}
				break;
			}

			default://用户输入不属于上述任意选项时，将error_flag置1并输出提示语句，重新开始循环
				cout << "输入非法！" << endl;
				error_flag = 1;
				break;

			}

		} while (error_flag == 1);

		//执行对应命令
		switch (input)
		{

		case 1://退出程序
		{
			exit_flag = 1;
			break;
		}

		case 2:
		{
			linkedqueue = new LinkedQueue<int>();
			cout << "	已创建空链队列。" << endl;
			break;
		}

		case 3:
		{
			int flag = linkedqueue->IsEmpty();
			if (flag)
				cout << "	序列栈为空。" << endl;
			else
				cout << "	序列栈不为空。" << endl;
			break;
		}

		case 4:
		{
			int value;
			cout << "	请输入待压栈元素：";
			cin >> value;
			linkedqueue->EnterQueue(value);
			cout << "	已将元素“" << value << "”压栈。" << endl;
			break;
		}

		case 5:
		{
			int Top = linkedqueue->GetFirst();
			if (Top == -1)
				cout << "	顺序栈为空。" << endl;
			else
				cout << "	顺序栈顶的元素为：" << Top << "。" << endl;
			break;
		}

		case 6:
		{
			cout << "	已弹出栈顶元素，其值为：" << linkedqueue->DeleteQueue() << "。" << endl;
			if (linkedqueue->IsEmpty())
				cout << "	当前栈为空。" << endl;
			else
				cout << "	当前栈顶元素为：" << linkedqueue->GetFirst() << "。" << endl;
			break;
		}

		}
	} while (!exit_flag);
	cout << "程序已正常退出。" << endl;
}