#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

float T_next(float T, float Ti1, float Tj1, float Ti_1,float Tj_1,float dt, float v,float dx){
	float T_next=T+ dt*v*(Ti1+Tj1+Ti_1+Tj_1-4*T)/(dx*dx);
	return T_next;
}
int main(){
	//datos del problema:
	float cp,k,densidad,dt,dx;
	//se crean los vectores para la malla:
	float index[34];
	float x[34];
	float y[34];
	float T[34];
	float T_next[34];//el vector para el tiempo en t+dt
	dx=0.05;
	//llenar los indices:
	for (int i=0;i<34;i++){
		index[i]=i;
	}
	//llenar las coordenadas x y y:
	for (int i=0;i<4;i++){//avance en y
		for(int j=0;j<6;j++){//avance en x
			x[j+6*i]=j*dx;
			y[j+6*i]=i*dx;
		}
	}
	for (int i=0;i<2;i++){//avance en y
		for(int j=0;j<4;j++){//avance en x
			x[24+j+4*i]=j*dx;
			y[24+j+4*i]=(i+4)*dx;
		}
	}
	//los nodos sobre el cilindro:
	x[32]=0.0134+3*dx;
	y[32]=4*dx;
	x[33]=4*dx;
	y[33]=3*dx+0.0134;
	ofstream malla("malla.txt");
	// exportar datos de la malla:
	for (int i=0;i<34;i++){
		malla<<index[i]<<","<<x[i]<<","<<y[i]<<"\n";
	}
	//CASO 1: FRONTERAS EXTERNAS IGUAL A 10°c.
	//APLICACION DE CONDICIONES DE FRONTERA:
	//primero ponemos todas las temperaturas en 100°
	
	for(int i=0;i<34;i++){
		T[i]=100;
	}
	
	for(int i=0;i<6;i++){//base inferior
		T[i]=10;
	}
	//lado izquierdo:
	for (int i=0;i<5;i++){
		T[6*i]=10;
	}
	//Esquina superior izquierda:
	T[28]=10;
	//VERIFICAR:
	ofstream T_ini("verificar.txt");
	for (int i=0;i<34;i++){
		T_ini<<index[i]<<","<<T[i]<<"\n";
	}
	//SOLUCION PRIMER CASO:
	for(int it=0;it<1000;it++){//bucle de pasos temporales
		//primero resolvemos los nodos internos:
		for (int i=0;i<3;i++){//avance en y
			for (int j=0;j<5;j++){//avance sobre x:
				
			}
		}
		
	
	}
	return 0;
}
