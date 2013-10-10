#include <iostream>
#include <list>

std::list< std::string > name; //string 형 list 생성
std::list< std::string* > name2; //string* 형 list 생성

void PrintList() //string 형 list 출력
{
	for( std::list< std::string >::iterator iter = name.begin(); iter != name.end(); ++iter ) //반복자를 이용한 출력
	{
		std::cout << iter->c_str() << "  ";
	}
	std::cout << std::endl;
}

void PrintList2() //string* 형 list 출력
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
	name.push_back( "리커버" );
	name.push_back( "프로젝트" );

	PrintList();

	name.push_back( "뒤에추가" );
	name.push_front( "앞에추가" );

	std::cout << std::endl << "앞 뒤위치에 원소 추가 " << std::endl;
	PrintList();
	
	std::cout << std::endl << "첫번째의 원소 삭제 " << std::endl;
	std::list< std::string >::iterator iter;

	
	iter = name.begin();
	name.erase(iter);  //반복자를 이용하여 원하는 위치의 원소를 삭제할 수 있다.
	PrintList();

	std::cout << std::endl << "마지막번째의 원소 삭제 " << std::endl;


	iter = name.end();
	--iter;
	name.erase(iter);  //반복자를 이용하여 원하는 위치의 원소를 삭제할 수 있다.
	PrintList();

	std::cout << std::endl << "반복자를 이용하여 세번째에 새로운 원소 추가" << std::endl;
	iter = name.begin();
	++iter;++iter;
	name.insert(iter, "NewInsert"); //iter를 순차적으로 증가시켜 원하는 위치에 삽입가능
	PrintList();

	std::cout << std::endl << "반복자를 이용하여 2번째 원소 제거" << std::endl;
	iter = name.begin();
	++iter;
	name.erase(iter); //iter를 순차적으로 증가시켜 원하는 위치에 삽입가능
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

	std::cout << std::endl << " remove를 이용하여 cowspirit 원소 삭제 " << std::endl;
	name2.remove( data1 ); //포인터형으로 만들면, remove( 주소값 ) 을 넘겨주면 list에 있는  value값과 같은 원소를 삭제
	PrintList2();
	delete data1;
	delete data2;
	delete data3;

	getchar();
	return 0;
}