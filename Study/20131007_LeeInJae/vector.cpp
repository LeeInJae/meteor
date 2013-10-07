#include <iostream>
#include <vector> //vector �� ������ ��������� include �ؾ� �Ѵ�.

std::vector <int> number;

void IsEmpty()
{
	if( number.empty() ) { std:: cout << "���� ���ʹ� �������" << std:: endl; }
	else          { std:: cout << "���� ���ʹ� ������� ����" << std:: endl;}
}

void vectorPrint() //���� ���
{
	std:: cout << "���Ϳ� ����� ��� �� = ";
	for ( int i=0; i<number.size(); ++i )
	{
		std:: cout << number.at(i) << "  ";
	}

	std:: cout << std:: endl;
}

void VectorAt( int pos ) //vector��� at
{
	std:: cout << "������" << pos << "��° �ε����� ����� ���� = " << number.at( pos ) << std:: endl;
}

void GetSize()
{
	std:: cout << "������ ũ���  = " << number.size() << std:: endl;
}

void VectorClear()
{
	std:: cout << "������ ��� ���� ���� " << std:: endl;
	number.clear(); //������ ��� ���� ����
}

void VectorFront()
{
	std:: cout << "������ ù��° ���Ҵ� " << number.front() << std:: endl;
}

void VectorBack()
{
	std:: cout << "������ ù��° ���Ҵ� " << number.back() << std:: endl;
}

void VectorPop()
{
	number.pop_back();
	std:: cout << "������ ������ ���� ����" << std:: endl;
}

int main ( void )
{
	//������ ���� ���� �߰�
	number.push_back( 10 );
	number.push_back( 20 );
	number.push_back( 30 );

	vectorPrint();
	VectorAt( 1 );
	
	//int pivot = number[1];  
	
	//�̷��� �迭ó�� �����ص� �ȴ�( �Ȱ��� ��� )
	//pivot �� number ������ 1��° �ε����� ���Ҹ� ����.
	IsEmpty();//���Ͱ� ������� ture, ������������� false return

	VectorClear();
	IsEmpty();

	number.push_back( 1000);
	number.push_back( 2000 );
	number.push_back( 3000 );
	vectorPrint();

	//������ ù��° ���� ���
	VectorFront();

	//������ ������ ���� ����
	VectorPop();
	
	//������ ������ ���� ���
	VectorBack();

	VectorClear();
	

	number.push_back( 1);
	number.push_back( 2 );
	number.push_back( 3 );
	number.push_back( 5 );
	number.push_back( 6 );
	number.push_back( 7 );

	std::vector<int>::iterator start ;
		
	//iterator�� �ݺ��ڷ� �����̳� ���̺귯���� ȿ�������� ���̺귯���� ������ �� �ֵ��� �����ϴ�
	//�����Ϳ� ����� �������� �����ϸ� �ȴ�.
	//�ݺ��ڴ� � ������ �����Ϸ��� �� ������ �ٽ� �����ذ��� �ؾ� �Ѵ�.

	start = number.begin(); 
	start += 3; //4��° ��ġ�� 4�� �־��.
	number.insert( start, 4 ); //������ ��ġ��, ���� �������(�ݺ��ڸ� �̿��ؾ� �Ѵ�)
	
	start = number.begin(); 
	number.insert( start+7, 10, 10 ); //8�������� 10���� 0���� ä����
	
	start = number.begin();
	number.erase( start+2 ); //�ݺ����� ��ġ�� ���Ҹ� ����

	start = number.begin();
	number.insert( start+4, 100 ); //������ ��ġ�� ���Ҹ� ���� ���� �� ����
	vectorPrint();
	getchar();
	return 0;
}