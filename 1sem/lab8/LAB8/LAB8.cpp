//---------------------------------------------------------------------------
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <io.h>
#include <iostream>


struct TZap {
    char FIO[30];
    double s_b;
} Zap;
int size = sizeof(TZap);
FILE* Fz, * Ft;
const char File_Zap[] = "zapisi.dat";
const char File_Rez[] = "LAB8/rezult.txt";
void Out(TZap);


void main()
{
    int kod, D_f, i = 0, j, kol;
    long len;
    TZap st, * mas_Z;
    Ft = fopen(File_Zap, "w");
    while (true) {
        std::cout << "\n Create – 1\n Add – 2\n View – 3\n Sort – 4\n EXIT – 0";
        scanf_s("%d", &kod);
        switch (kod) {
        case 1:
            if ((Fz = fopen(File_Zap, "wb")) == NULL) {
                puts("\n Create ERROR!");
                return;
            }
            fclose(Fz);
            printf("\n Create New File %s !\n", File_Zap);
            break;
        case 2:
            Fz = fopen(File_Zap, "ab");
            printf("\n F.I.O. – ");
            fflush(stdin);
            gets_s(Zap.FIO);
            printf(" Ball – ");
            scanf_s("%lf", &Zap.s_b);
            fwrite(&Zap, size, 1, Fz);
            fclose(Fz);
            break;
        case 3:
            if ((Fz = fopen(File_Zap, "rb")) == NULL) {
                puts("\n Open ERROR!");
                return;
            }
            // Вывод на экран 
            printf("\n\t--------- Informations ---------");
            // Запись такой же информации в текстовый файл Ft
            fprintf(Ft, "\n\t--------- Informations ---------");
            while (1) {
                if (!fread(&Zap, size, 1, Fz)) break;
                Out(Zap);
            }
            fclose(Fz);
            break;
        case 4:
            Fz = fopen(File_Zap, "rb");
            D_f = _fileno(Fz);
            len = _filelength(D_f);
            kol = len / size;
            mas_Z = new TZap[kol];
            // Считываем записи из файла в динамический массив
            for (i = 0; i < kol; i++)
                fread((mas_Z + i), size, 1, Fz);
            fclose(Fz);
            printf("\n\t----- S O R T -----\n");
            fprintf(Ft, "\n\t----- S O R T -----\n");
            for (i = 0; i < kol - 1; i++)
                for (j = i + 1; j < kol; j++)
                    if (mas_Z[i].s_b > mas_Z[j].s_b) {
                        st = mas_Z[i];
                        mas_Z[i] = mas_Z[j];
                        mas_Z[j] = st;
                    }
            for (i = 0; i < kol; i++)
                Out(mas_Z[i]);
            delete[]mas_Z;
            break;
        case 0:
            fclose(Ft);
            return;
        }
    }
}
//----------------- Функция вывода одной записи на экран и в файл --------------------
void Out(TZap z)
{
    printf("\n %20s , %6.3lf .", z.FIO, z.s_b);
    fprintf(Ft, "\n %20s , %6.3lf .", z.FIO, z.s_b);
}
//-------------------------------------------------------