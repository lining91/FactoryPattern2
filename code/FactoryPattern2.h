#include <stdio.h>

//	��������
class Operation{
public:
	virtual int GetResult( int n1, int n2 ) = 0;
};


//  �Ӽ�������
class OperationAdd : public Operation{
public:
	virtual int GetResult(int n1, int n2)
	{
		return n1 + n2;
	}
};


class OperationSub : public Operation{
public:
	virtual int GetResult(int n1, int n2)
	{
		return n1 - n2;
	}
};

class OperationMul : public Operation{
public:
	virtual int GetResult(int n1, int n2)
	{
		return n1 * n2;
	}
};

class OperationDiv : public Operation{
public:
	virtual int GetResult(int n1, int n2)
	{
		if (n2 == 0)
			throw "��������Ϊ0��";
		return n1 / n2;
	}
};



//	���󹤳���
class IFactory
{
public:
	virtual Operation* CreateOperation() = 0;
};


//	���幤����
class AddFactory : public IFactory
{
public:
	Operation* CreateOperation()
	{
		return new OperationAdd();
	}
};

class SubFactory : public IFactory
{
public:
	Operation* CreateOperation()
	{
		return new OperationSub();
	}
};

class MulFactory : public IFactory
{
public:
	Operation* CreateOperation()
	{
		return new OperationMul();
	}
};

class DivFactory : public IFactory
{
public:
	Operation* CreateOperation()
	{
		return new OperationDiv();
	}
};