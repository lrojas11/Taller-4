#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
int main(){
	//Variables dadas en el problema
	float k=1.62;
	float density=(2.71/1000)*pow(100,3);
	float Cp=820;
	float delta_x=0.05;
	float x[36];
	float y[36];
	float T_i[36];
	float T_ii[36];
	float dt=3;
	float v=k/(density*Cp);
	//Coeficiente de difusion
	//cout<<v;
	//Se asignan Coordenadas de los puntos:
	for (int i=0;i<5;i++){//Recorrer las filas en y:
		for (int j=0;j<6;j++){
			x[j+6*i]=j*delta_x;
			y[j+6*i]=i*delta_x;
		}
	}
	//Nodos 30 a 34:
	for (int i=30;i<35;i++){
		x[i]=(i-30)*delta_x;
		y[i]=0.25;
	}
	//Nodo 35:
	x[35]=0.215;
	y[35]=0.215;
	//Escribir el archivo de las coordenadas de puntos para graficar en python:
	ofstream coordenadas("coordenadas.txt");
	for (int i=0;i<36;i++){
		coordenadas<<x[i]<<","<<y[i]<<"\n";
	}
	//PRIMER CASO: BORDES A 10 grados
	//Se asigna a todo el dominio T=0 grados
	for (int i=0;i<35;i++){
		T_i[i]=0;
	}
	//Las fronteras a 10 grados:
	for (int i=1;i<6;i++){
		T_i[i]=10;
		T_i[6*i]=10;
	}
	T_i[0]=10;
	//Las paredes del cilindro:
	T_i[34]=100;
	T_i[29]=100;
	T_i[35]=100;
	//Se genera el archivo para almacenar los datos:
	ofstream punto1("punto1.txt");
	//Calcular las temperaturas en los pasos de tiempo:
	for (int paso=0;paso<10000;paso++){
		//Nodos internos
		for(int i=1;i<5;i++){//recorrer y
			for(int j=1;j<6;j++){//recorrer x
				T_ii[j+6*i]=T_i[j+6*i]+dt*v*(-4*T_i[j+6*i]+T_i[j+6*i+1]+T_i[j+6*i-1]+T_i[j+6*i+6]+T_i[j+6*i-6])/(delta_x*delta_x);
			}
		}
		//Nodos simetria:
		for (int i =0;i<3;i++){
			T_ii[11+6*i]=T_i[11+6*i]+dt*v*(-4*T_i[11+6*i]+2*T_i[11+6*i-1]+T_i[11+6*i+6]+T_i[11+6*i-6])/(delta_x*delta_x);
			T_ii[31+i]=T_i[31+i]+dt*v*(-4*T_i[31+i]+2*T_i[31+i-6]+T_i[31+i+1]+T_i[31+i-1])/(delta_x*delta_x);
		}
		//Actualizar el vector T_i con los datos de T_ii:
		for(int i=1;i<5;i++){//recorrer y
			for(int j=1;j<6;j++){//recorrer x
				T_i[j+6*i]=T_ii[j+6*i];
			}
		}
		for (int i=0;i<3;i++){
			T_i[11+6*i]=T_ii[11+6*i];
			T_i[31+i]=T_ii[31+i];
		}
		T_i[29]=100;
		//Exportar las temperaturas nuevas:
		for (int i=0;i<36;i++){
			punto1<<T_i[i]<<",";
		}
		punto1<<"\n";
	}
	//SEGUNDO CASO: Fronteras Abiertas:
	//Se asigna T=0 a todo el dominio:
	for (int i=0;i<35;i++){
		T_i[i]=0;
	}
	//Las paredes del cilindro:
	T_i[34]=100;
	T_i[35]=100;
	T_i[29]=100;
	//Se genera el archivo para almacenar los datos:
	ofstream punto2("punto2.txt");

	for (int paso=0;paso<100000;paso++){
		// Nodos internos
		for(int i=1;i<5;i++){//recorrer y
			for(int j=1;j<6;j++){//recorrer x
				T_ii[j+6*i]=T_i[j+6*i]+dt*v*(-4*T_i[j+6*i]+T_i[j+6*i+1]+T_i[j+6*i-1]+T_i[j+6*i+6]+T_i[j+6*i-6])/(delta_x*delta_x);
			}
		}
		//Nodos simetria:
		for (int i =0;i<3;i++){
			T_ii[11+6*i]=T_i[11+6*i]+dt*v*(-4*T_i[11+6*i]+2*T_i[11+6*i-1]+T_i[11+6*i+6]+T_i[11+6*i-6])/(delta_x*delta_x);
			T_ii[31+i]=T_i[31+i]+dt*v*(-4*T_i[31+i]+2*T_i[31+i-6]+T_i[31+i+1]+T_i[31+i-1])/(delta_x*delta_x);
		}
		//Para garantizar fornteras abiertas, se igualan las Temperaturas de los nodos de los bordes a las de los adyacentes:
		for (int i=1;i<6;i++){
			T_ii[i]=T_ii[i+6];
			T_ii[6*i]=T_ii[i*6+1];
		}
		T_ii[0]=T_ii[1];
		//Actualizar el vector T_i con los datos de T_ii:
		for (int i=0;i<34;i++){
			T_i[i]=T_ii[i];
		}
		T_i[29]=100;
		T_i[34]=100;
		T_i[35]=100;
		//Exportar las temperaturas nuevas:
		for (int i=0;i<36;i++){
			punto2<<T_i[i]<<",";
		}
		punto2<<"\n";
	}
	
	}
	return 0;
}
