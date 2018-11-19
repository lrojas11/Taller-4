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
plt.savefig('dinamica_proyectil.png')
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

