#include <stdio.h>

//	操作基类
class Operation{
public:
	virtual int GetResult( int n1, int n2 ) = 0;
};


//  加减乘数类
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
			throw "除数不能为0！";
		return n1 / n2;
	}
};



//	抽象工厂类
class IFactory
{
public:
	virtual Operation* CreateOperation() = 0;
};


//	具体工厂类
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