// async1 - packaged task2 ����
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;



int add(int a, int b)
{
	std::cout << "add" << std::endl;

	std::this_thread::sleep_for(2s);

	std::cout << "finish add" << std::endl;
	return a + b;
}

int main()
{
	std::future<int> ft = std::async(add, 10, 20);

	std::cout << "main ��� ����" << std::endl;

	// int ret = ft.get();	// ����� ��� ���� ������ ��� �ɱ� ?

}	// <= �������� ft �� �ı� �˴ϴ�.
	// <= ft �� �Ҹ��ڰ� ȣ��˴ϴ�.
	// <= ����ڰ� "ft.get()" �� ȣ���� ���� ������ �Ҹ��ڿ��� "ft.get()"
	// <= ��, async �� ������ �Լ��� ���Ḧ ����ϰ� �˴ϴ�.
