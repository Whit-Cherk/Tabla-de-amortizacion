#include<iostream>
#include<cmath>
using namespace std;

//Función que calcula la cuota
double cuota(double capital, double tasaAnual, int anos) {
	double numPagosPorAno = 12;
	
	// Convertir la tasa de interés anual a una tasa de interés por período
	double r = tasaAnual / numPagosPorAno;

	// Calcular el número total de pagos
	int n = numPagosPorAno * anos;

	// Aplicar la fórmula de la anualidad
	double pago = (capital * r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);

	return pago;
}

double interes(double i, double c) {
	return (i * c) / 100;
}

double capAmort(double cuota, double i, double c) {

	return cuota - interes(i, c);
}


int main()
{
	double cap, inA, plz; int z(1), k;
	system("cls");
	cout << endl << " Introduzca Capital: ";
	cin >> cap;
	cout << endl << " Introduzca Interes anual: ";
	cin >> inA;
	cout << endl << " Introduzca Plazo (en años): ";
	cin >> plz;


	//Calcular datos fijos
	cout << endl << "Tasa de interes periodica = \t" << inA / 12;
	cout << endl << "Numero de cuotas = \t" << plz * 12;
	
	//Calcular la cuota fija
	double cuotaFija = cuota(cap, inA * 0.01, plz);
	cout << endl << "Cuota fija = \t\t" << cuotaFija;

	//Calcular tasa de interes periodica
	double tip = inA / 12;
	cout << endl << "Tasa de interes periodica = \t\t" << tip;
	


	cout << endl << endl;
	cout << "\t" << "Numero de cuota" << "\t\t" << "Interes" << "\t\t " << "Capital Amortizado" << "\t\t" << "Cuota a pagar"<< "\t\t" "Capital Vivo" << endl;
	do {


		cout <<
			//numero de cuota
			"\t " << z <<
			//interes
			"\t\t\t" << interes(tip, cap) <<
			//capital amortizado
			"\t\t\t" << capAmort(cuotaFija, tip, cap) <<
			//cuota a pagar
			"\t\t\t" << cuotaFija <<
			//capital vivo
			"\t\t\t" << cap - capAmort(cuotaFija, tip, cap) <<
			
			endl;

		cap = cap - capAmort(cuotaFija, tip, cap);
		z++;
	} while (z <= plz * 12);
	return 0;
}
