#include <iostream>
using namespace std;

#include "FactoryPattern2.h"


void main()
{
	int n1 = 33;
	int n2 = 52;

	//	����������������࣬�����Ҫ�޸��µļ��㷽ʽ����Ҫ�������ɸ���
	IFactory* pFactory = new MulFactory();
	if ( pFactory == NULL )
		return;

	Operation* pOpe = pFactory->CreateOperation();
	if (pOpe == NULL)
		return;

	try{
		int nResult = pOpe->GetResult(n1, n2);
		cout << n1 << " * " << n2 << " is " << nResult << endl;
	}
	catch(char* pErr)
	{
		cout << pErr << endl;
	}
	delete pOpe;
	pOpe = NULL;
	delete pFactory;
	pFactory = NULL;

	system("pause");
}