//
//  main.c
//

#include <stdio.h>

typedef struct {
    char nombre[100];
    char carrera[100];
    double promedio;
    int semestre;
    char materia[100];
    double calis[4];
    int veces;
} registro_alumno;

/*
void crear()
{
    FILE *arch;
    arch=fopen("RegistroAlumnos.dat","wb");
    fclose(arch);
}*/

void altaAlumnos(){
    FILE *arch;
    arch=fopen("RegistroAlumnos.dat","ab");

    registro_alumno alumno;
    
    printf("Escribe el nombre del alumno \n");
    scanf("%s",&*alumno.nombre);

    printf("Escribe la carrera del alumno \n");
    scanf("%s",&*alumno.carrera);

    printf("Escribe el promedio del alumno \n");  
    scanf("%lf",&alumno.promedio);

    printf("Escribe el semestre del alumno \n");
    scanf("%i",&alumno.semestre);

    printf("Escribe la materia del alumno \n");
    scanf("%s",&*alumno.materia);

    double calificacion[4];
    for (int i=0; i<4; i++) {
        int numDeCal = i+1;
        printf("Escribe la Calificacion ");
        printf("%i\n", numDeCal);
        calificacion[i]=scanf("%lf",&alumno.calis[i]);
    }
    printf("Escribe la cantidad de veces que ha cursado la materia ");
    scanf("%i",&alumno.veces);
    
    fwrite(&alumno, sizeof(registro_alumno), 1, arch);
    fclose(arch);
}
void situacion(char nombre[100]){
    FILE *arch;
    arch=fopen("RegistroAlumnos.dat","rb");
    registro_alumno alumno;
    fread(&alumno, sizeof(registro_alumno), 1, arch);

     while(!feof(arch) && *nombre!=*alumno.nombre)
    {
        fread(&alumno, sizeof(registro_alumno), 1, arch);
    }

    double prom_materia;
    double prom_general;
    prom_materia = 0;

    printf("Nombre: %s Carrera: %s Promedio: %f Materia: %s ", alumno.nombre, alumno.carrera, alumno.promedio, alumno.materia);
    printf("\n");
    printf("Calificaciones: ");
    printf("\n");
    for (int i=0; i<4; i++) {
        printf("%f ", alumno.calis[i]);
        prom_materia = prom_materia + alumno.calis[i];
    }
    prom_materia = prom_materia/4;

    printf("\n");
    printf("\n");
    printf("El promedio final de la materia es: " );
    printf("%f ", prom_materia);

    printf("\n");
    printf("El promedio general es: " );
    prom_general = (alumno.promedio + prom_materia)/2.0;
    printf("%f ", prom_general);

    printf("\n");
    if(prom_materia >= 6.0){
        printf("El estatus es Acreditado " );
    }
    else{
        printf("El estatus es No Acreditado ");
    }
    printf("\n");
    if(alumno.veces < 3 && prom_materia < 6.0){
        printf("El alumno puede repetir materia");
    }
    else{
        printf("El alumno ya no puede repetir la materia ");
    }
    printf("\n");
        
}
void actualizar(char nombre[100]){
    FILE *arch;
    arch=fopen("RegistroAlumnos.dat","rb");
    registro_alumno alumno;
    fread(&alumno, sizeof(registro_alumno), 1, arch);
   
    while(!feof(arch) && *nombre!=*alumno.nombre)
    {
        fread(&alumno, sizeof(registro_alumno), 1, arch);
    }
    printf("%s %s %f %s ", alumno.nombre, alumno.carrera, alumno.promedio, alumno.materia);
    for (int i=0; i<4; i++) {
        printf("%f ", alumno.calis[i]);
    }
    printf("\n");
    FILE *archMod;
    archMod=fopen("RegistroAlumnosMod.dat","ab");

   
    printf("Escribe la nueva carrera del alumno \n");
    scanf("%s",&*alumno.carrera);

    printf("Escribe el semestre del alumno \n");
    scanf("%i",&alumno.semestre);
    fwrite(&alumno, sizeof(registro_alumno), 1, archMod);
    fclose(archMod);
    fclose(arch);
    
}

void consultaArch1()
{
    printf("Archivo\n");
    FILE *arch;
    arch=fopen("RegistroAlumnos.dat","rb");
    registro_alumno alumno;
    fread(&alumno, sizeof(registro_alumno), 1, arch);
    while(!feof(arch))
    {
        printf("Nombre: %s Carrera: %s Promedio: %f Materia: %s Semestre: %i ", alumno.nombre, alumno.carrera, alumno.promedio, alumno.materia, alumno.semestre);
        printf("\n");
        printf("Calificaciones:");
        printf("\n");
        for (int i=0; i<4; i++) {
            printf("%f ", alumno.calis[i]);
        }
        printf("\n");
        printf("Numero de veces: ");
        printf("%i\n", alumno.veces);
        fread(&alumno, sizeof(registro_alumno), 1, arch);
    }
    printf("\n");
    fclose(arch);
}
void consultaArch2()
{
    printf("Archivo Mod\n");
    FILE *arch;
    arch=fopen("RegistroAlumnosMod.dat","rb");
    registro_alumno alumno;
    fread(&alumno, sizeof(registro_alumno), 1, arch);
    while(!feof(arch))
    {
        printf("%s %s %f %s %i ", alumno.nombre, alumno.carrera, alumno.promedio, alumno.materia, alumno.semestre);
        for (int i=0; i<4; i++) {
            printf("%f ", alumno.calis[i]);
        }
        printf("%i\n", alumno.veces);
        fread(&alumno, sizeof(registro_alumno), 1, arch);
    }
    printf("\n");
    fclose(arch);
}

int main(int argc, const char * argv[]) {
    int menu;
    char nombre[100];

    //crear();
    do{
        printf("1: Alta Alumno\n");
        printf("2: Situacion academica de un alumno\n");
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
            case 4:
                consultaArch1();
                consultaArch2();
                break;
        }
    }while (menu!= 4);
}
