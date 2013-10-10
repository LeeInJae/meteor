#include <iostream>
#include <list>

std::list< std::string > name; //string �� list ����
std::list< std::string* > name2; //string* �� list ����

void PrintList() //string �� list ���
{
	for( std::list< std::string >::iterator iter = name.begin(); iter != name.end(); ++iter ) //�ݺ��ڸ� �̿��� ���
	{
		std::cout << iter->c_str() << "  ";
	}
	std::cout << std::endl;
}

void PrintList2() //string* �� list ���
{
	for( std::list< std::string* >::iterator iter = name2.begin(); iter != name2.end(); ++iter )
	{
		std::cout << (*iter)->c_str() << "  ";
	}
	std::cout << std::endl;
}

int main ( void )
{
	name.push_back( "NEXT" );
	name.push_back( "��Ŀ��" );
	name.push_back( "������Ʈ" );

	PrintList();

	name.push_back( "�ڿ��߰�" );
	name.push_front( "�տ��߰�" );

	std::cout << std::endl << "�� ����ġ�� ���� �߰� " << std::endl;
	PrintList();
	
	std::cout << std::endl << "ù��°�� ���� ���� " << std::endl;
	std::list< std::string >::iterator iter;

	
	iter = name.begin();
	name.erase(iter);  //�ݺ��ڸ� �̿��Ͽ� ���ϴ� ��ġ�� ���Ҹ� ������ �� �ִ�.
	PrintList();

	std::cout << std::endl << "��������°�� ���� ���� " << std::endl;


	iter = name.end();
	--iter;
	name.erase(iter);  //�ݺ��ڸ� �̿��Ͽ� ���ϴ� ��ġ�� ���Ҹ� ������ �� �ִ�.
	PrintList();

	std::cout << std::endl << "�ݺ��ڸ� �̿��Ͽ� ����°�� ���ο� ���� �߰�" << std::endl;
	iter = name.begin();
	++iter;++iter;
	name.insert(iter, "NewInsert"); //iter�� ���������� �������� ���ϴ� ��ġ�� ���԰���
	PrintList();

	std::cout << std::endl << "�ݺ��ڸ� �̿��Ͽ� 2��° ���� ����" << std::endl;
	iter = name.begin();
	++iter;
	name.erase(iter); //iter�� ���������� �������� ���ϴ� ��ġ�� ���԰���
	PrintList();
	
	std::cout << "--------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << std::endl;
	std::string* data1=new std::string; 
	std::string* data2=new std::string;
	std::string *data3=new std::string;
	*data1 = "cowspirit";
	*data2 = "cowspirit2";
	*data3 = "cowspirit3";

	name2.push_back( data1 );
	name2.push_back( data2 );
	name2.push_back( data3 );

	PrintList2(); 

	std::cout << std::endl << " remove�� �̿��Ͽ� cowspirit ���� ���� " << std::endl;
	name2.remove( data1 ); //������������ �����, remove( �ּҰ� ) �� �Ѱ��ָ� list�� �ִ�  value���� ���� ���Ҹ� ����
	PrintList2();
	delete data1;
	delete data2;
	delete data3;

	getchar();
	return 0;
}