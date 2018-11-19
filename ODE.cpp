#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

//Se calcula el vector de aceleracion en funcion de vx y vy
float a_x(float vx, float vy){
	float ax=-vx*sqrt(pow(vx,2)+pow(vy,2));
	return ax;
}
float a_y(float vx, float vy){
	float ay=-10-vy*sqrt(pow(vx,2)+pow(vy,2));
	return ay;
}

int main ()
{
	float x, y, vx, vy, vx_i_medio, vy_i_medio, tetha, dt, ax, ay, contador;
	tetha=3.141592654/4;
	dt=0.0001;
	x=0;
	y=0;
	vx=300*cos(tetha);
	vy=300*sin(tetha);
	//Se inicializan los los valores de vx y vy en i-dt/2 :
	ax=a_x(vx,vy);
	ay=a_y(vx,vy);
	vx_i_medio=vx-(dt/2)*ax;
	vy_i_medio=vy-(dt/2)*ay;
	ofstream bala("bala.txt");
	contador=0;
	// Para realizar la integral, realizamos un loop:
	while(y>=0){
		ax=a_x(vx,vy);// Se calcula el vector de aceleracion
		ay=a_y(vx,vy);
		vx_i_medio=vx_i_medio+dt*ax;
		vy_i_medio=vy_i_medio+dt*ay;//Se obtienen los valores en i+t/2
		//Se calculan las posiciones de X y Y:
		x=x+vx_i_medio*dt;
		y=y+vy_i_medio*dt;
		ax=a_x(vx_i_medio,vy_i_medio);
		ay=a_y(vx_i_medio,vy_i_medio);
		vx=vx_i_medio+(dt/2)*ax;
		vy=vy_i_medio+(dt/2)*ay;
		contador+=1;
		bala<<contador*dt<<","<<x<<","<<y<<","<<vx<<","<<vy<<"\n";
	}

	cout<<"La Distancia recorrida por el proyectil en metros es:  "<<x<<"\n";

	//SEGUNDA PARTE:
	//Se preparan los nombres de los archivos para los angulos entre 10 y 70 grados:
	//Genera una advertencia en la terminal, pero no afecta con el codigo
	char* nombres[8];
	nombres[1]="10.csv";
	nombres[2]="20.csv";
	nombres[3]="30.csv";
	nombres[4]="40.csv";
	nombres[5]="50.csv";
	nombres[6]="60.csv";
	nombres[7]="70.csv";

	//Se crean dos variables para almacenar el alcance maximo y el angulo optimo:
	float distancia_maxima, tetha_opt;
	//Asignar los valores del alcance a 45 grados
	distancia_maxima=x;
	tetha_opt=45;
	for (int k=1;k<8;k++){
	ofstream guardar(nombres[k]);

	float x, y, vx, vy, vx_i_medio, vy_i_medio, tetha, dt, ax, ay, contador;

	tetha=3.141592654*(k*10)/180;
	dt=0.0001;
	x=0;
	y=0;
	vx=300*cos(tetha);
	vy=300*sin(tetha);

	//Inicializacion para los valores de vx y vy en i-dt/2 :
	ax=a_x(vx,vy);
	ay=a_y(vx,vy);
	vx_i_medio=vx-(dt/2)*ax;
	vy_i_medio=vy-(dt/2)*ay;
	//Salida de los datos bala("bala.txt");
	contador=0;
	// Loop para integrar:
	while(y>=0){
		ax=a_x(vx,vy);// Calculo vector aceleracion
		ay=a_y(vx,vy);
		vx_i_medio=vx_i_medio+dt*ax;

		vy_i_medio=vy_i_medio+dt*ay;//Se obtienen los valores en i+t/2
		//Calculo de posiciones X y Y:
		x=x+vx_i_medio*dt;
		y=y+vy_i_medio*dt;
		ax=a_x(vx_i_medio,vy_i_medio);
		ay=a_y(vx_i_medio,vy_i_medio);
		vx=vx_i_medio+(dt/2)*ax;
		vy=vy_i_medio+(dt/2)*ay;
		contador+=1;
		guardar<<contador*dt<<","<<x<<","<<y<<","<<vx<<","<<vy<<"\n";
	}

	if (x>distancia_maxima){
		distancia_maxima=x;
		tetha_opt=10*k;
	}

	}

	cout<<"La Distancia maxima recorrida en metros es "<<distancia_maxima<<" y fue alcanzada para un angulo de "<<tetha_opt;
	return 0;
}
