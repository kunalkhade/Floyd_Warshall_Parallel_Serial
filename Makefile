
all: Floyds_Sequential Floyds_OpenMp

Floyds_Sequential: Floyds_Sequential.c
	gcc -g -w -fopenmp -o floydc Floyds_Sequential.c -lm
	#Please type ./floydc


Floyds_OpenMp: Floyds_OpenMp.c
	gcc -g -w -fopenmp -o floydom Floyds_OpenMp.c -lm
	#Please type ./floydom



Clean:
	rm -rf Floyds_Sequential 
	rm -rf Floyds_OpenMp 
