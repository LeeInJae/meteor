#include <iostream>
#include <vector> //vector
 
int main ( void )
{
	std::vector< int > fibo; //vector fibonacci	
	fibo.push_back(1);
	fibo.push_back(2);

	for( int i=0; i<10; ++i )
	{
		std::vector<int>::iterator iter; //vector의 반복자 선언.

		iter = fibo.end();  //끝+1번째 원소의 위치를 반복자 값으로 반환
		fibo.push_back(  *( iter-1 )  + *( iter-2 ) ); //vector의 맨 끝 두 원소를 더해서 push_back 해줌
	}

	
	std::cout << "vector를 이용한 fibonacci 수열" << std::endl;
	std::cout << std::endl << std::endl;

	for( std::vector<int>::iterator iter = fibo.begin(); iter != fibo.end(); ++iter ) //begin~end-1 까지 vector의 모든 원소 검색
	{
		std::cout << *iter << ",  "; //반복자를 이용한 값 출력(iter는 포인터 클래스이므로, *를 이용하여 담겨이쓴 값을 볼 수 있다)
	}

	std::vector<int>::iterator iter = fibo.begin();
	
	std::cout << std::endl << std::endl;
	std::cout << "반복자를 이용한 첫번째 원소를 100으로 수정 " << std::endl;

	*iter = 100; //반복자를 이용한 수정도 가능(첫번째 원소를 100으로 바꿈)
	std::cout << std::endl << std::endl;;

	std:: cout << "수정 후 피보나치 수열 " << std::endl;
	for( std::vector<int>::iterator iter = fibo.begin(); iter != fibo.end(); ++iter )
	{
		std::cout << *iter << ",  ";
	}
	
	getchar();
	return 0;
}