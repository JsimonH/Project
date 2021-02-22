#include "pch.h"
#include <iostream>
using namespace std;
#include "Connection.h"
#include "CommonConnectionPool.h"

int main()
{
	//Connection conn;
	//conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	
	clock_t begin = clock(); // 开始计时

#if 0
	//ConnectionPool *cp = ConnectionPool::getConnectionPool();
	// 单线程测试
	for (int i = 0; i < 10000; ++i)
	{
		// 无连接池
		Connection conn;
		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		conn.update(sql);
		
		// 有连接池
		/*shared_ptr<Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
		"zhang san", 20, "male");
		sp->update(sql);*/  
	}
#endif

	// 多线程测试
	thread t1([]() {
		//ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 250; ++i)
		{
			/*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	thread t2([]() {
		//ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 250; ++i)
		{
			/*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	thread t3([]() {
		//ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 250; ++i)
		{
			/*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	thread t4([]() {
		//ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 250; ++i)
		{
			/*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	clock_t end = clock(); // 结束计时
	
	cout << "花费时间: " << (end - begin) << "ms" << endl;
	return 0;
}
