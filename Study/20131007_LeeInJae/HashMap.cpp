#include <iostream>
#include <hash_map> // ������� �������־�� �Ѵ�.

int main ( void )
{
	//stdext::hash_map < key type, value type> hash;
	stdext:: hash_map < int, float > hash;//key���� int, value ���� float �� ����

	hash.insert( stdext:: hash_map< int, float >::value_type( 10 , 45 )); 
 	stdext:: hash_map<int, float>:: iterator hashPoint;
	
	hashPoint = hash.find( 10 ); //Ű���� 10�� ���� �����͸� ������ 
	//�ؽ��� Ư�� Ű���� ���� �ݺ��ڸ� �����Ѵ�. ���� �ݺ��ڸ� �̿��Ͽ� ���� ����ؾ��Ѵ�.

	hash.erase( 10 );

	if ( hash.empty() ) { std::cout << "hash ���̺��� ������ϴ�" << std::endl; }

	//hash.insert( stdext:: hash_map< int, float >::value_type( 10 , 45 )); 
	hash.insert( stdext:: hash_map< int, float >::value_type( 1 , 100 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 3 , 200 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 2 , 300 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 4 , 400 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 5 , 500 ));

	std::cout << "���� �ؽ����̺��� ũ��� "<< hash.size() << "�Դϴ�." << std::endl;

	hashPoint = hash.find( 10 ); //Ű���� 10�� ���� �����͸� ������ 
	//������ Ű���� 10�� �ؽ����̺��� �����������Ƿ� �̶� �˻��ϰ����ϴ� Ű���� �������� ������ �����͸� �������ش�
	if( hashPoint == hash.end() )
	{
		std::cout << "Ű���� 10�� �ؽ����̺��� �����ϴ�" << std::endl;
	}
	else
	{
	//	++hashPoint;
		std:: cout << hashPoint->second << std:: endl; //�ݺ����� first�� key ��, second�� value��
	}
	hashPoint = hash.find( 3 ); 
	std:: cout << hashPoint->second << std:: endl; //�ݺ����� first�� key ��, second�� value��

	getchar();
	return 0;
}