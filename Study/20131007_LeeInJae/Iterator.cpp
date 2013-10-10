#include <iostream>
#include <vector> //vector
 
int main ( void )
{
	std::vector< int > fibo; //vector fibonacci	
	fibo.push_back(1);
	fibo.push_back(2);

	for( int i=0; i<10; ++i )
	{
		std::vector<int>::iterator iter; //vector�� �ݺ��� ����.

		iter = fibo.end();  //��+1��° ������ ��ġ�� �ݺ��� ������ ��ȯ
		fibo.push_back(  *( iter-1 )  + *( iter-2 ) ); //vector�� �� �� �� ���Ҹ� ���ؼ� push_back ����
	}

	
	std::cout << "vector�� �̿��� fibonacci ����" << std::endl;
	std::cout << std::endl << std::endl;

	for( std::vector<int>::iterator iter = fibo.begin(); iter != fibo.end(); ++iter ) //begin~end-1 ���� vector�� ��� ���� �˻�
	{
		std::cout << *iter << ",  "; //�ݺ��ڸ� �̿��� �� ���(iter�� ������ Ŭ�����̹Ƿ�, *�� �̿��Ͽ� ����̾� ���� �� �� �ִ�)
	}

	std::vector<int>::iterator iter = fibo.begin();
	
	std::cout << std::endl << std::endl;
	std::cout << "�ݺ��ڸ� �̿��� ù��° ���Ҹ� 100���� ���� " << std::endl;

	*iter = 100; //�ݺ��ڸ� �̿��� ������ ����(ù��° ���Ҹ� 100���� �ٲ�)
	std::cout << std::endl << std::endl;;

	std:: cout << "���� �� �Ǻ���ġ ���� " << std::endl;
	for( std::vector<int>::iterator iter = fibo.begin(); iter != fibo.end(); ++iter )
	{
		std::cout << *iter << ",  ";
	}
	
	getchar();
	return 0;
}