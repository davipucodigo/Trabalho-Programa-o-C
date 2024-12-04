#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

// ======================= Header BMP Structs ======================= //
typedef struct { 
    char Signature[2]; // 2 bytes caracter hexadecimal ASCII "BM"
    int32_t FileSize;  //Define o tamanho em Bytes da imagem
    int16_t Reserved1;
    int16_t Reserved2;
    int32_t File_Offset_to_PixelArray;

} FileHeader;

typedef struct{
    int32_t DIB_header_SIze; 
    int32_t width; // Define a largura da imagem
    int32_t height; // Define a altura da imagem
    int16_t planes;
    int16_t bits_per_pixel;
    int32_t compression;
    int32_t image_size;
    int32_t X;
    int32_t Y;
    int32_t color_table;
    int32_t important_color_coun;

} DIBHeader;

typedef struct {
    int32_t b;
    int32_t g;
    int32_t r;
    int32_t reserved;
} Cor;

// ======================= Functions ======================= //

void LoadImage (char *File, FileHeader *F, DIBHeader *D, Cor *P) {
    printf("\nCarregando Arquivo... '%s'\n", File);

    FILE * fp;
    fp = fopen(File,"rb");
        if (fp == NULL) {
            printf("Não foi possível ler o arquivo.");
        }
        fread(F, sizeof(FileHeader), 1, fp);
        fread(D, sizeof(DIBHeader), 1, fp);

        
        printf("\n------------------------> FILE HEADER\n");
        printf("Signature: %c%c\n", F->Signature[0], F->Signature[1]);
        printf("FileSize: %d\n", F->FileSize);
        printf("Reserved1: %d\n", F->Reserved1);
        printf("Reserved2: %d\n", F->Reserved2);
        printf("File Offset to Pixel Array: %d\n", F->File_Offset_to_PixelArray);


        printf("\n------------------------> DIB HEADER\n");
        printf("DIB Header Size: %d\n", D->DIB_header_SIze);
        printf("Width: %d\n", D->width);
        printf("Height: %d\n", D->height);
        printf("Planes: %d\n", D->planes);
        printf("Bits per Pixel: %d\n", D->bits_per_pixel);
        printf("Compression: %d\n", D->compression);
        printf("Image Size: %d\n", D->image_size);
        printf("X: %d\n", D->X);
        printf("Y: %d\n", D->Y);
        printf("Color Table: %d\n", D->color_table);
        printf("Important Color Count: %d\n", D->important_color_coun);

        
        fseek(fp, F->File_Offset_to_PixelArray, SEEK_SET);

        printf("\n------------------------> Pixels\n");
        for (int y = 0; y <= D->height; y++) {
            for (int x = 0; x <= D->width; x++) {
                fread(P, sizeof(Cor), 1, fp);
                printf("Pixel[x: %d,y: %d] = R(%d) G(%d) B)(%d);\n",x,y,P->r,P->g,P->b);
            }
        }

        printf("\nCarregamento Concluído. \n");

    fclose(fp);

}

int main () {
    // Structs Extends
    FileHeader FileH;
    DIBHeader DIB;
    Cor Pixel;

    // +++ Select File +++ //
    char file_name[100];
    printf("\nDigite o nome do arquivo: ");
    scanf("%[^\n]", file_name);
    getchar(); // para ter o /0
    fflush(stdin);

    // +++ Load Image +++ //
    LoadImage(file_name, &FileH, &DIB, &Pixel);



    return 0;
}