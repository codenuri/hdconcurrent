// async1 - packaged task2 복사
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

//------------------------------------------------
// async          : 함수를 비동기로 수행
//				    결과를 future 로 반환
//					내부적으로 packaged_task 로 구현
//----------------------------------------------
// packaged_task  : "return 값"으로 된 함수를 스레드로 수행하기 위해
//					내부적으로 promise future 사용
//---------------------------------------------
// promise/future : 연산의 결과를 얻기위한 도구
//----------------------------------------------
// std::thread : 가장 기본 클래스
//-----------------------------------------------
// OS 시스템 콜 : CreateThread(), pthread_create()


// std::thread vs std::async

// std::thread : 스레드를 만드는 가장 기본 적인 도구
//				 C++에서는 가장 낮은 레벨의 도구
//			     스레드로 수행한 함수의 결과를 얻을수 없다.

// std::async : 스레드로 함수를 실행후 결과를 얻을수 있다.
//				"return 값" 의 결과를 future를 통해서 얻을수 있다.
//				스레드를 고려하지 않고 만든 일반 함수의 결과도 가능

// std::packaged_task   vs  std::async

// std::async			: 함수를 즉시 비동기로 실행

// std::packaged_task	: 함수를 저장했다가 비동기로 실행
//				std::packaged_task<int(int, int)> task(foo);
// 
//				"std::vector<std::packaged_task> v"
//				처럼 스레드로 수행할 함수를 저장 가능.
//				스레드 풀링 기술.


int add(int a, int b)
{
	std::cout << "add" << std::endl;

	std::this_thread::sleep_for(2s);
	return a + b;
}

int main()
{
	// std::async : 특정 함수를 비동기(스레드)로 실행하고
	//				결과를 얻을수 있는 future를 반환
	std::future<int> ft = std::async(add, 10, 20);
			
	std::cout << "main 계속 실행" << std::endl;

	int ret = ft.get();

	std::cout << ret << std::endl;
}

