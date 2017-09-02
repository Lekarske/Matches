//PROGRAMA QUE DETERMINA LOS MEJORES RESULTADOS DE LOS DIFERENTES PARTIDOS PARA QUE UN EQUIPO SUBA O MANTENGA SU POSICION EL LA TABLA
//PIDE AL USUARIO EL NOMBRE DEL PAIS Y SEGUN ESO HACE LOS CALCULOS E INDICA CUALES DEBERIAN SER LOS RESULTADOS
#include<iostream>
#include<iomanip> // Para setw(), tabular las puntuaciones (estetico)
using namespace std;

int match(std::string a, int b, std::string c, int d, std::string f, int e){
	if (b<d && b>e || a == f){
		e+=3;
		cout << f << " tiene que ganar a " << c << endl;
	} 
	else if (b<e && b>d || a == c){
		d+=3;
		cout << c << " tiene que ganar a " << f << endl;
	}
	else{
		d+=1; e+=1;
		cout << c << " tiene que empatar con " << f << endl;
	}return d;
}
//Es la misma funcio que la anterior "match" pero sin el "cout" y retornado otro valor para cambiar el valor de las variables en la funcion main
int sameMatch(std::string a, int b, std::string c, int d, std::string f, int e){
	if (b<d && b>e || a == f)
		e+=3;
	else if (b<e && b>d || a == c)
		d+=3;
	else{
		d+=1; e+=1;
	}return e;
}

int main () {
	string country[10];// Creo que seria mejor si seria un Global Array pero deja de funcionar el programa ???
	country[0]="Brasil"; country[1]="Colombia"; country[2]="Uruguay"; country[3]="Chile"; country[4]="Argentina";
	country[5]="Peru"; country[6]="Paraguay"; country[7]="Ecuador"; country[8]="Bolivia"; country[9]="Venezuela";
	
	int score[10];//Del dia 2 de Setiembre
	score[0]=36; score[1]=25; score[2]=24; score[3]=23; score[4]=23; 
	score[5]=21; score[6]=21; score[7]=20; score[8]=10; score[9]=7;
	
	int a; string z;  
	cout << "Escriba el nombre del pais al que quiere favorecer: "; cin >> z;
	for (int i=0;i<10;i++){
		if (z==country[i])
			a=i;
	}
	
	string x = country[a]; int y = score[a];//Al ser el mismo indice para cada pais lo cambie a una unica variable aunque es mas codigo
	cout << "\nPara que " << country[a] << " suba o mantenga su posicion:\n";	
	score[8] = match(x,y, country[8], score[8], country[3], score[3]);
	score[7] = match(x,y, country[7], score[7], country[5], score[5]);
	score[1] = match(x,y, country[1], score[1], country[0], score[0]);
	score[4] = match(x,y, country[4], score[4], country[9], score[9]);
	score[6] = match(x,y, country[6], score[6], country[2], score[2]); //Este partido no estoy seguro si existe
	cout << endl;//Al no usar referencia los valores de las variables no cambian, por lo que los estoy cambiando uno por uno
	score[3] = sameMatch(x,y, country[8], score[8], country[3], score[3]);
	score[5] = sameMatch(x,y, country[7], score[7], country[5], score[5]);
	score[0] = sameMatch(x,y, country[1], score[1], country[0], score[0]);
	score[9] = sameMatch(x,y, country[4], score[4], country[9], score[9]);
	score[2] = sameMatch(x,y, country[6], score[6], country[2], score[2]);//Este partido no estoy seguro si existe
//Se ahorraria muchas lineas de codigo si se podria cambiar directamente los valores de las variables "score"
	cout << "Y las puntuaciones cambiarian a:\n";
	for (int i=0;i<10;i++)
		cout << setw(13) << country[i] << "  " << score[i] << endl;
	system("pause");
	return 0;
}
