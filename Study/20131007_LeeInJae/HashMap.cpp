#include <iostream>
#include <hash_map> // 헤더파일 포함해주어야 한다.

int main ( void )
{
	//stdext::hash_map < key type, value type> hash;
	stdext:: hash_map < int, float > hash;//key값은 int, value 값은 float 로 선언

	hash.insert( stdext:: hash_map< int, float >::value_type( 10 , 45 )); 
 	stdext:: hash_map<int, float>:: iterator hashPoint;
	
	hashPoint = hash.find( 10 ); //키값이 10인 것이 데이터를 가져옴 
	//해쉬는 특정 키값에 관한 반복자를 리턴한다. 따라서 반복자를 이용하여 값을 출력해야한다.

	hash.erase( 10 );

	if ( hash.empty() ) { std::cout << "hash 테이블이 비었습니다" << std::endl; }

	//hash.insert( stdext:: hash_map< int, float >::value_type( 10 , 45 )); 
	hash.insert( stdext:: hash_map< int, float >::value_type( 1 , 100 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 3 , 200 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 2 , 300 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 4 , 400 ));
	hash.insert( stdext:: hash_map< int, float >::value_type( 5 , 500 ));

	std::cout << "현재 해쉬테이블의 크기는 "<< hash.size() << "입니다." << std::endl;

	hashPoint = hash.find( 10 ); //키값이 10인 것이 데이터를 가져옴 
	//위에서 키값이 10인 해쉬테이블을 삭제해줬으므로 이때 검색하고자하는 키값이 없을경우는 마지막 포인터를 리턴해준다
	if( hashPoint == hash.end() )
	{
		std::cout << "키값이 10인 해쉬테이블은 없습니다" << std::endl;
	}
	else
	{
	//	++hashPoint;
		std:: cout << hashPoint->second << std:: endl; //반복자의 first가 key 값, second가 value값
	}
	hashPoint = hash.find( 3 ); 
	std:: cout << hashPoint->second << std:: endl; //반복자의 first가 key 값, second가 value값

	getchar();
	return 0;
}