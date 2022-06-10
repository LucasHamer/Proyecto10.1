#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nomyapy[81];
    int nota1;
    int nota2;
    float prom;

}Salumno;

void lectura();

int main()
{
    Salumno alum;

    FILE*ap;
    ap=fopen("alumno.dat","wb");
    if(ap==NULL)
    {
        printf("Error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    printf("Ingrese DNI: ");
    scanf("%d",&alum.dni);
    printf("Ingrese Nombre y Apellido: ");
    fflush(stdin);
    gets(alum.nomyapy);
    printf("Ingrese nota 1: ");
    scanf("%d",&alum.nota1);
    printf("Ingrese nota 2: ");
    scanf("%d",&alum.nota2);
    alum.prom=(alum.nota1+alum.nota2)/2;

    fwrite(&alum,sizeof(alum),1,ap);

    fclose(ap);

    lectura(alum);

    return 0;
}
void lectura()
{
    Salumno alum;
    FILE*fp;
    fp=fopen("alumno.dat","rb");
    if(fp==NULL)
    {
        printf("Error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&alum,sizeof(alum),1,fp);
    printf("\n%-8s  %-30s %6s  %6s  %6s\n","DNI","Nombre y Apellido","Nota 1","Nota 2","Nota Promedio");
    while(!feof(fp))
    {
        printf("\n%-8d  %-30s %6d  %6d  %6.2f\n",alum.dni,alum.nomyapy,alum.nota1,alum.nota2,alum.prom);
        fread(&alum,sizeof(alum),1,fp);
    }
    fclose(fp);
}




