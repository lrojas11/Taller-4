
import numpy as np
import matplotlib.pyplot as plt


#PUNTO 2 MOVIMIENTO PROYECTIL
#Leer los archivos

for i in range (7):
    variable=10+10*i
    name=str(variable)+'.csv'
    data=np.loadtxt(name,float,delimiter=',')
    plt.plot(data[:,1],data[:,2])
    plt.hold(True)

#Ahora el de 45 grados, contenido en el archivo bala:
data=np.loadtxt('bala.txt',float,delimiter=',')

#Graficas
plt.plot(data[:,1],data[:,2])
plt.title('Dinamica Proyectil')
plt.xlabel('Distancia Horizontal[Mts]')
plt.ylabel('Distancia Vertical[Mts]')
plt.legend(('10 $^\circ$','20 $^\circ$','30 $^\circ$','40$^\circ$','50$^\circ$','60$^\circ$','70$^\circ$','45$^\circ$'),loc='upper right')
plt.savefig('Dinamica_proyectil.png')
plt.close()

#PUNTO 3 ECUACION DE DIFUSION


#Como la malla no es cuadrada, se importa axes3d:
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

#Leer los datos para los tres casos
punto1=np.loadtxt('punto1.txt',float,delimiter=',',usecols=range(36))
punto2=np.loadtxt('punto2.txt',float,delimiter=',',usecols=range(36))
punto3=np.loadtxt('punto3.txt',float,delimiter=',',usecols=range(36))

#Cargar las coordenadas de los puntos:
nodos=np.loadtxt('coordenadas.txt',float,delimiter=',')

#Vectores X y Y con las coordenadas de los puntos importados en nodos:
X=nodos[:,0]
Y=nodos[:,1]
T=punto1[0,:]

#GRAFICA PRIMER CASO

grafica_3d = plt.figure()
axes = grafica_3d.gca(projection='3d')
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Condicion_inicial_caso_1.png')

#Estado estable:
axes.clear()
T=punto1[9999,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_estable_caso_1.png')
#Estados intermedios
axes.clear()
T=punto1[5000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t15000s_caso_1.png')
axes.clear()
T=punto1[1000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t3000s_caso_1.png')
print("Terminadas graficas de caso 1 -> Fronteras Fijas")

#GRAFICA SEGUNDO CASO
axes.clear()
T=punto2[0,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_inicial_caso_2.png')
#Estados intermedios
axes.clear()
T=punto2[99999,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_estable_caso_2.png')
axes.clear()
T=punto2[20000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t60000s_caso_2.png')
axes.clear()
T=punto2[50000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t150000s_caso_2.png')
print("Terminadas graficas de caso 2 -> Fronteras Abiertas")



#GRAFICA TERCER CASO:
axes.clear()
T=punto3[0,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_inicial_caso_3.png')
#Estados intermedios
axes.clear()
T=punto2[99999,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_estable_caso_3.png')
axes.clear()
T=punto2[20000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t200000s_caso_3.png')
axes.clear()
T=punto2[50000,:]
axes.plot_trisurf(X, Y, T)
grafica_3d.savefig('Estado_t500000s_caso_3.png')
print("Terminadas graficas de caso 3 -> Fronteras Periodicas")

#Calculo de los promedios

#CASO 1 :
plt.figure()
Temperatura_promedio=np.zeros(10000);
tiempo=np.linspace(0,30000,num=10000)
tiempo
for i in range(10000):
	Temperatura_promedio[i]=sum(punto1[i,:])/36
plt.hold(False)
plt.plot(tiempo,Temperatura_promedio)
plt.title('Temperatura promedio de la calcita en funcion del tiempo_ Caso1')
plt.xlabel('Tiempo')
plt.ylabel('Temperatura_bulk_C')
plt.savefig('Caso1_promedio.png')


#CASO 2:
Temperatura_promedio=np.zeros(100000);
tiempo=np.linspace(0,300000,num=100000)
tiempo
for i in range(100000):
	Temperatura_promedio[i]=sum(punto2[i,:])/36
plt.hold(False)
plt.plot(tiempo,Temperatura_promedio)
plt.title('Temperatura promedio de la calcita en funcion del tiempo_ Caso2')
plt.xlabel('Tiempo')
plt.ylabel('Temperatura_bulk_C')
plt.savefig('Caso2_promedio.png')


#CASO  3:
Temperatura_promedio=np.zeros(100000);
tiempo=np.linspace(0,1000000,num=100000)
tiempo
for i in range(100000):
	Temperatura_promedio[i]=sum(punto3[i,:])/36
plt.hold(False)
plt.plot(tiempo,Temperatura_promedio)
plt.title('Temperatura promedio de la calcita en funcion del tiempo_ Caso3')
plt.xlabel('Tiempo')
plt.ylabel('Temperatura_bulk_C')
plt.savefig('Caso3_promedio.png')
