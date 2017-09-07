//PROGRAMA QUE DETERMINA EL MEJOR RESULTADO DE LOS DIFERENTES PARTIDOS PARA QUE UN EQUIPO SUBA O MANTENGA SU POSICION EL LA TABLA
//PIDE AL USUARIO EL NOMBRE DEL PAIS Y SEGUN ESO HACE LOS CALCULOS E INDICA CUALES DEBERIAN SER LOS RESULTADOS
#include<iostream>
#include<iomanip> // Para setw(), tabular las puntuaciones (estetico)
using namespace std;

int match(std::string a, int b, std::string c, int d, std::string e, int f){
	if (b<d && b>=f || a == e){//SE COMPARA al equipo favorecido con las puntuaciones de los equipos que jugaran
		f+=3;//para saber si el equivo favorecido (str a, int b) esta jugando dentro de este partido se debe comparar los nombres (str a == str e)
		cout << e << " tiene que ganar a " << c << endl;//Dos equipos puenden tener el mismo puntaje y pero no el mismo nombre
	}//al comparar los nombre si o si el equipo favorecido ganara
	else if (b<f && b>=d || a == c){
		d+=3;
		cout << c << " tiene que ganar a " << e << endl;
	}
	else{
		d+=1; f+=1;
		cout << c << " tiene que empatar con " << e << endl;
	}return d;
}
//Es la misma funcion que la anterior "match" pero sin el "cout" y retornado otro valor para cambiar el valor de las variables en la funcion main
int sameMatch(std::string a, int b, std::string c, int d, std::string e, int f){
	if (b<d && b>=f || a == e)
		f+=3;
	else if (b<f && b>=d || a == c)
		d+=3;
	else{
		d+=1; f+=1;
	}return f;
}

int main () {
	string country[10];// Creo que seria mejor si seria un Global Array pero deja de funcionar el programa ???
	country[0]="Brasil"; country[1]="Colombia"; country[2]="Uruguay"; country[3]="Chile"; country[4]="Argentina";
	country[5]="Peru"; country[6]="Paraguay"; country[7]="Ecuador"; country[8]="Bolivia"; country[9]="Venezuela";
	
	int score[20];//Del dia 2 de Septiembre
	score[0]=36; score[1]=25; score[2]=24; score[3]=23; score[4]=23; 
	score[5]=21; score[6]=21; score[7]=20; score[8]=10; score[9]=7;
//Score tiene hasta 20 valores para que no remplace los valores originales y genere problemas
	int a; string z;
	cout << "Escriba el nombre del pais al que quiere favorecer: "; cin >> z;
	for (int j=0;j<10;j++){
		if (z==country[j])
			a=j;//Compara los nombres de los paises con la palabra ingresada y da el indice del pais para ingresarlo en la funcion match
	}
//Almacene los 10 nuevos vales de score en los 10 espacios restantes para no genere problemas al momente de llamar 2 veces la misma funcion
	string x = country[a]; int y = score[a];//Al ser el mismo indice para cada pais lo cambie a una unica variable aunque es mas codigo
	cout << "\nPara que " << country[a] << " suba o mantenga su posicion:\n";	
	score[18] = match(x,y, country[8], score[8], country[3], score[3]);
	score[17] = match(x,y, country[7], score[7], country[5], score[5]);
	score[11] = match(x,y, country[1], score[1], country[0], score[0]);
	score[14] = match(x,y, country[4], score[4], country[9], score[9]);
	score[16] = match(x,y, country[6], score[6], country[2], score[2]); 
	cout << endl;//Al no usar referencia los valores de las variables no cambian, por lo que los estoy cambiando uno por uno
	score[13] = sameMatch(x,y, country[8], score[8], country[3], score[3]);
	score[15] = sameMatch(x,y, country[7], score[7], country[5], score[5]);
	score[10] = sameMatch(x,y, country[1], score[1], country[0], score[0]);
	score[19] = sameMatch(x,y, country[4], score[4], country[9], score[9]);
	score[12] = sameMatch(x,y, country[6], score[6], country[2], score[2]);
//Se ahorraria muchas lineas de codigo si se podria cambiar directamente los valores de las variables "score"
	cout << "Y las puntuaciones cambiarian a:\n";
//elegi insertion sort porque para mi es el mas sencillo y facil de entender ademas de que no llega (en este caso) a un O(n^2)
	for (int i=10;i<20;i++){
		int m=i,n=score[i];//se necesita 2 valores enteros: uno que almacene el indice y otro el valor
		string o = country[i-10];
		while ((m > 10) && (score[m-1] < n)){//se inicia en 10 porque desde esa posicion estan los nuevos puntajes
			score[m] = score[m-1];//se pierde el valor de la posicion m 
			country[m-10] = country[m-11];//es m-10 porque el indice de country empieza en 0 "(10-10)"
			m--;//se reduce el valor en 1
		}
		score[m] = n;//se otorga el valor almacenado antes del while
		country[m-10] = o;
	}
	for (int i=10;i<20;i++)//Imprime todos los paises con sus respectivas puntuaciones
		cout << setw(13) << country[i-10] << "  " << score[i] << endl;
	system("pause");//LA TABLA DE POSICIONES YA ESTA ORDENADA
	return 0;
}
