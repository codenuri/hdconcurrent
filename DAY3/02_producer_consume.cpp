#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> Q;	// STL �����̳ʴ� ��Ƽ ������ ȯ�濡 �������� 
					// �ʽ��ϴ�.

// �Ʒ� �ڵ�� ����ȭ ���� �����Ƿ� ������ ���� �˴ϴ�.

void producer()
{
	while (true)
	{
		static int cnt = 0;
		Q.push(++cnt);
		std::cout << "producer : " << cnt << std::endl;
		if (cnt == 1000000) cnt = 0;
	}	
}
void consume()
{
	while (true)
	{
		int element = Q.front();
		Q.pop();
		std::cout << "\tconsume : " << element << ", current Q size : " << Q.size() << std::endl;
	}
}

int main()
{
	std::thread t1(producer);
	std::thread t2(consume);

	t1.join();
	t2.join();
}