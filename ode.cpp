#include<iostream>
#include<math.h>
#include<fstream>


using namespace std;
//calculamos el vector aceleracion como funcion de vx y vy
float a_x(float vx, float vy){
	float ax=-vx*sqrt(pow(vx,2)+pow(vy,2));
	return ax;
}
float a_y(float vx, float vy){
	float ay=-10-vy*sqrt(pow(vx,2)+pow(vy,2));
	return ay;
}

int main (){
	float x, y, vx, vy, vx_i_medio, vy_i_medio, tetha, dt, ax, ay, contador;
	tetha=3.141592654/4;
	dt=0.0001;
	x=0;
	y=0;
	vx=300*cos(tetha);
	vy=300*sin(tetha);
	//inicializamos los valores de vx y vy en i-dt/2 de la fomra:
	ax=a_x(vx,vy);
	ay=a_y(vx,vy);
	vx_i_medio=vx-(dt/2)*ax;
	vy_i_medio=vy-(dt/2)*ay;
	ofstream bala("bala.txt");
	contador=0;
	// hacemos el bucle para integrar:
	while(y>=0){
		//cout<<ax<<"  "<<ay<<"\n";
		ax=a_x(vx,vy);// calcumamos el vector aceleracion
		ay=a_y(vx,vy);
		vx_i_medio=vx_i_medio+dt*ax;
		
		vy_i_medio=vy_i_medio+dt*ay;//obtenemos los valores en i+t/2
		//calculamos las posiciones de x y y:
		x=x+vx_i_medio*dt;
		y=y+vy_i_medio*dt;
		ax=a_x(vx_i_medio,vy_i_medio);
		ay=a_y(vx_i_medio,vy_i_medio);
		vx=vx_i_medio+(dt/2)*ax;
		vy=vy_i_medio+(dt/2)*ay;
		//cout<<vx<<"  "<<vy<<"\n";
		contador+=1;
		bala<<contador*dt<<","<<x<<","<<y<<","<<vx<<","<<vy<<"\n";
	}
	 
	
}
