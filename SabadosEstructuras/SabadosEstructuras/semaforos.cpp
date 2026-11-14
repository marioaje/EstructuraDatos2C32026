#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <semaphore>

using namespace std;

counting_semaphore<3> semaforo(3);
mutex consolaControlMutex;

//Un laboratorio PC
//Seleccionar PC
//PC favorita ocupada seleccionamos otra o esperamos

void usarComputadora(int estudiante) {
	semaforo.acquire();

	{
		lock_guard<mutex> bloqueo(consolaControlMutex);
		cout << "Estudiante: " << estudiante << " utilizando computadora \n";

	}

	this_thread::sleep_for(chrono::seconds(6));


	{
		lock_guard<mutex> bloqueo(consolaControlMutex);
		cout << "Estudiante: " << estudiante << " finalizo la utilizacion de computadora \n";

	}

	semaforo.release();

}

int main() {


	thread estd[6];
	cout << "Inclusion de hilos a los estudiantes" << endl;

	for (int i = 0; i < 6; i++)
	{
		estd[i] = thread(usarComputadora, i + 1);
	}

	cout << "Inicio de hilos a los estudiantes" << endl;
	for (int i = 0; i < 6; i++)
	{
		estd[i].join();
	}

	cout << "Todos finalizados" << endl;

	return 0;

}