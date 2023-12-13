#ifndef __STACK_H__
#define __STACK_H__

using namespace std;

const int MaxStackSize = 100;

template <class T> 
class TStack
{
	T* pMem;
	int size;
	int top;
public:

	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		pMem = new T[size];
	}

	~TStack()
	{
		delete[] pMem;
	}

	TStack(const TStack<T>& st)
	{
		size = st.size;
		pMem = new T[size];
		top = st.top;
		for (int i = 0; i < top + 1; i++)
			pMem[i] = st.pMem[i];
	}

	bool IsEmpty()
	{
		if (top != -1)
			return false;

		return true;
	}

	bool IsFull()
	{
		if (top + 1 == size) 
			return true;

		return false;
	}

	T Check()
	{
		if (IsEmpty()) throw "Error: empty stack";

		return pMem[top];
	}

	T Pop()
	{
		if (IsEmpty()) throw "Error: stack is empty";

		return pMem[top--];
	}

	void Push(T elem)
	{
		if (IsFull()) throw "Error: stack overflow";

		top++;
		pMem[top] = elem;
	}

	void Clear()
	{
		top = -1;
	}

};

#endif
