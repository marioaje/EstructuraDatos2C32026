//#include <iostream>
//#include <thread>
//#include <chrono>
//
//
//using namespace std;
//
//void tarea(int id) {
//
//	cout <<  endl;
//	for (int i = 0; i < 6; i++)
//	{
//		cout << "Hijo " << id << " ejecutandose en paso " << i << endl;
//		this_thread::sleep_for(chrono::milliseconds(500));
//	}
//}
//
//int main() {
//	thread hilo1(tarea, 1);
//	thread hilo2(tarea, 2);
//
//	//tarea(3);
//	//tarea(4);
//
//	hilo1.join();
//	hilo2.join();
//
//	cout << "Todos los hilos finalizados\n";
//
//	return 0;
//}