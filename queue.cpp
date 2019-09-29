#include <stdlib.h>
#include <iostream>
using namespace std;

class MyQueue
{
public:
	MyQueue(int queueCapacity);
	~MyQueue();
	void ClearQueue();
	bool QueueEmpty()const;
	bool QueueFull()const;
	int QueueLength()const;
	bool EnQueue(int element);
	bool DeQueue(int &element);
	void QueueTraverse();
private:
	int *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;
};

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	m_pQueue = new int[queueCapacity];
	//  cout << "ok"<<endl;
}

MyQueue::~MyQueue()
{
	delete []m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty()const
{
	/*
	if (m_iQueueLen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return m_iQueueLen == 0?true:false;
}

bool MyQueue::QueueFull()const
{

	return m_iQueueLen == m_iQueueCapacity?true:false;
}

int MyQueue::QueueLength()const
{
	return m_iQueueLen;
}

bool MyQueue::EnQueue(int element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail%m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}
bool MyQueue::DeQueue(int &element)
{
	if (QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead%m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}

void MyQueue::QueueTraverse()
{
	for (int i = m_iHead; i < m_iQueueLen+m_iHead; ++i)
	{
		cout<<m_pQueue[i%m_iQueueCapacity]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	MyQueue *p = new MyQueue(4);
	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(18);
	p->EnQueue(12);
	p->QueueTraverse();

	int e = 0;
	p->DeQueue(e);
	cout<<endl;
	cout << e << endl;

	p->DeQueue(e);
	cout<<endl;
	cout << e << endl;

	cout<<endl;
	p->QueueTraverse();	

	p->ClearQueue();
	p->QueueTraverse();	

	delete p;
	p = NULL;
	return 0;
}