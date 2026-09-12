//Lo enfocamos hacia un objeto, datos, comportamiento, funciones, metodos, encapsulamiento, herencia, polimorfismo

///La clase es solo para datos + comportamiento	 ....
//por defecto es private los datos
//puede tener metodos
//Es utilizado para generar la estructura de datos y comportamiento de los objetos
class ProfesorClase
{
private:
	int id;
	char nombre[50];
	int edad;
	float salario;

	public:
		void depositarSalario() {
			// Lógica para depositar el salario del profesor
			salario += 1000; // Ejemplo de incremento de salario
			
		}

};