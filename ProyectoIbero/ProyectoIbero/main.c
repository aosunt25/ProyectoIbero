//
//  main.c
//  ProyectoIbero
//
//  Created by Alfredo Osuna on 11/24/19.
//  Copyright © 2019 Alfredo Osuna. All rights reserved.
//

#include <stdio.h>

void altaAlumnos(){
    printf("Escribe el nombre del alumno \n");
    char nombre[100];
    scanf("%s",nombre);
    printf("Escribe la carrera del alumno \n");
    char carrera[100];
    scanf("%s",carrera);
    printf("Escribe el promedio del alumno \n");
    double promedio;
    scanf("%lf",&promedio);
    printf("Escribe el semestre del alumno \n");
    int semestre;
    scanf("%i",&semestre);
    printf("Escribe la materia del alumno \n");
    char materia[100];
    scanf("%s",materia);
    double calificacion[4];
    for (int i=0; i<4; i++) {
        int numDeCal = i+1;
        printf("Escribe la Calificacion ");
        printf("%i\n", numDeCal);
        calificacion[i]=scanf("%lf",&calificacion[i]);
    }
    printf("Escribe la cantidad de veces que ha cursado la materia ");
    int numVeces;
    scanf("%i",&numVeces);
    printf(nombre," ",carrera);
}
void situacion(char nombre[100]){
    
}
void actualizar(char nombre[100]){
    
}
int main(int argc, const char * argv[]) {
    int menu;
    char nombre[100];
    do{
        printf("1: Alta Alumno\n");
        printf("2:Situacion academica de un alumno\n");
        printf("3: Actualizar datos de un alumno\n");
        printf("4: Salir\n");
        scanf("%i",&menu);
        switch (menu) {
            case 1:
                altaAlumnos();
                break;
            case 2:
                printf("Escribe el nombre del alumno\n");
                scanf("%s",nombre);
                situacion(nombre);
                break;
            case 3:
                printf("Escribe el nombre del alumno\n");
                scanf("%s",nombre);
                actualizar(nombre);
            default:
                break;
        }
        
    }while (menu!=4);
    altaAlumnos();
}
