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
