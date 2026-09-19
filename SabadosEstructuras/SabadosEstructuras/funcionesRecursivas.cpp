//Escribir una función o método que calcule, donde e son números enteros positivos.
//Escribir una función o método que calcule, donde yson números positivos.
//Escribir una función o método que calcule, donde e son números enteros positivos, y
//.
//Escribir una función o método que calcule el MCD(máximo común divisor) entre dos númerosy
//, donde e son números enteros positivos.

int calcularPotencias(int x, int y) {
	int resultado = 1;

	for (int i = 0; i < y; i++) {
		resultado *= x;
	}

	return resultado;
}

int calcularPotenciasRecursiva(int x, int y) {

	if (y == 0) return 1;
	return x * calcularPotenciasRecursiva(x, y-1);
}


//m*n
int calcularmultiplicacion(int m, int n) {
	
	int resultado = 0;

	for (int i = 0; i < n; i++)
	{
		resultado += m;
	}
	return resultado;
}

int calcularmultiplicacionRecursiva(int m, int n) {

	if (n == 0) return 0;
	return m + calcularmultiplicacion(m, n - 1);
}