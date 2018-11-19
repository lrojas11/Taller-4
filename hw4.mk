#Se genera el archivo pdf
Resultados_hw4.pdf: Resultados_hw4.tex 
	pdflatex Resultados_hw4.tex


#Se actualiza el .tex usando los archivos necearios para correr el .py
Resultados_hw4.tex: Plots_hw4.py punto1.txt punto2.txt punto3.txt coordenadas.txt 10.csv 20.csv 30.csv 40.csv 50.csv 60.csv 70.csv bala.txt
	python Plots_hw4.py

	
#Se actualizan los archivos .txt que contienen los datos
punto1.txt punto2.txt punto3.txt coordenadas.txt: PDE.cpp
	g++ -o pde.out PDE.cpp 
	./pde.out 	

10.csv 20.csv 30.csv 40.csv 50.csv 60.csv 70.csv bala.txt: ODE.cpp
	g++ -o ode.out ODE.cpp 
	./ode.out 	
	
#Se borran los archivos que se crean al compilar los archivos de LaTex y los archivos de c++, ejecutar el comando clean en la terminal luego de escribir make -f hw4.mk
clean:
	rm -f *.png
	rm -f *.csv
	rm -f *.txt
	rm -f *.pdf
	rm -f *.jpg
	rm -f *.log
	rm -f *.aux
