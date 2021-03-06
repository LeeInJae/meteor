#include <iostream>
#include <vector> //vector 를 쓰려면 헤더파일을 include 해야 한다.

std::vector <int> number;

void IsEmpty()
{
	if( number.empty() ) { std:: cout << "현재 벡터는 비어있음" << std:: endl; }
	else          { std:: cout << "현재 벡터는 비어있지 않음" << std:: endl;}
}

void vectorPrint() //벡터 출력
{
	std:: cout << "벡터에 저장된 모든 값 = ";
	for ( int i=0; i<number.size(); ++i )
	{
		std:: cout << number.at(i) << "  ";
	}

	std:: cout << std:: endl;
}

void VectorAt( int pos ) //vector멤버 at
{
	std:: cout << "벡터의" << pos << "번째 인덱스에 저장된 값은 = " << number.at( pos ) << std:: endl;
}

void GetSize()
{
	std:: cout << "벡터의 크기는  = " << number.size() << std:: endl;
}

void VectorClear()
{
	std:: cout << "벡터의 모든 원소 삭제 " << std:: endl;
	number.clear(); //벡터의 모든 원소 삭제
}

void VectorFront()
{
	std:: cout << "벡터의 첫번째 원소는 " << number.front() << std:: endl;
}

void VectorBack()
{
	std:: cout << "벡터의 첫번째 원소는 " << number.back() << std:: endl;
}

void VectorPop()
{
	number.pop_back();
	std:: cout << "벡터의 마지막 원소 삭제" << std:: endl;
}

int main ( void )
{
	//벡터의 끝에 원소 추가
	number.push_back( 10 );
	number.push_back( 20 );
	number.push_back( 30 );

	vectorPrint();
	VectorAt( 1 );
	
	//int pivot = number[1];  
	
	//이렇게 배열처럼 접근해도 된다( 똑같은 기능 )
	//pivot 은 number 벡터의 1번째 인덱스의 원소를 가짐.
	IsEmpty();//벡터가 비었으면 ture, 비어있지않으면 false return

	VectorClear();
	IsEmpty();

	number.push_back( 1000);
	number.push_back( 2000 );
	number.push_back( 3000 );
	vectorPrint();

	//벡터의 첫번째 원소 출력
	VectorFront();

	//벡터의 마지막 원소 삭제
	VectorPop();
	
	//벡터의 마지막 원소 출력
	VectorBack();

	VectorClear();
	

	number.push_back( 1);
	number.push_back( 2 );
	number.push_back( 3 );
	number.push_back( 5 );
	number.push_back( 6 );
	number.push_back( 7 );

	std::vector<int>::iterator start ;
		
	//iterator는 반복자로 컨테이너 라이브러리가 효율적으로 라이브러리에 접근할 수 있도록 제공하는
	//포인터와 비슷한 개념으로 생각하면 된다.
	//반복자는 어떤 연산을 수행하려고 할 때마다 다시 설정해가며 해야 한다.

	start = number.begin(); 
	start += 3; //4번째 위치에 4를 넣어라.
	number.insert( start, 4 ); //지정한 위치에, 값을 집어넣음(반복자를 이용해야 한다)
	
	start = number.begin(); 
	number.insert( start+7, 10, 10 ); //8번쨰부터 10개를 0으로 채워라
	
	start = number.begin();
	number.erase( start+2 ); //반복자의 위치의 원소를 지움

	start = number.begin();
	number.insert( start+4, 100 ); //임의의 위치에 원소를 집어 넣을 수 있음
	vectorPrint();
	getchar();
	return 0;
}