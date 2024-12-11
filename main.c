#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 

#pragma pack(1)

// ======================= Header BMP Structs ======================= //
typedef struct { 
    char Signature[2]; // 2 bytes caracter hexadecimal ASCII "BM"
    int32_t FileSize; 
    int16_t Reserved1;
    int16_t Reserved2;
    int32_t File_Offset_to_PixelArray;

} FileHeader;

typedef struct{
    int32_t DIB_header_SIze; 
    int32_t width;
    int32_t height; 
    int16_t planes;
    int16_t bits_per_pixel;
    int32_t compression;
    int32_t image_size;
    int32_t X;
    int32_t Y;
    int32_t color_table;
    int32_t important_color_coun;

} DIBHeader;

typedef struct{
    uint8_t b;
    uint8_t g;
    uint8_t r;
} Cor;

// ======================= Functions ======================= //

void LoadImage(char *File, FileHeader *F, DIBHeader *D, Cor *P) {
    printf("\nCarregando Arquivo... '%s' \n", File);

    FILE * fp;
    fp = fopen(File, "rb");
    if (fp == NULL) {
        printf("Não foi possível ler o arquivo.\n");
        return;
    }

    fread(F, sizeof(FileHeader), 1, fp);
    fread(D, sizeof(DIBHeader), 1, fp);

    printf("\n------------------------> FILE HEADER\n");
    printf("Signature: %x%x\n", F->Signature[0], F->Signature[1]);
    printf("FileSize: %x\n", F->FileSize);
    printf("Reserved1: %x\n", F->Reserved1);
    printf("Reserved2: %x\n", F->Reserved2);
    printf("File Offset to Pixel Array: %x\n", F->File_Offset_to_PixelArray);

    printf("\n------------------------> DIB HEADER\n");
    printf("DIB Header Size: %x\n", D->DIB_header_SIze);
    printf("Width: %x\n", D->width);
    printf("Height: %x\n", D->height);
    printf("Planes: %x\n", D->planes);
    printf("Bits per Pixel: %x\n", D->bits_per_pixel);
    printf("Compression: %x\n", D->compression);
    printf("Image Size: %x\n", D->image_size);
    printf("X: %x\n", D->X);
    printf("Y: %x\n", D->Y);
    printf("Color Table: %x\n", D->color_table);
    printf("Important Color Count: %x\n", D->important_color_coun);

    int padding = (4 - (D->width * 3) % 4) % 4;
    fseek(fp, F->File_Offset_to_PixelArray, SEEK_SET); // Pular para a área de pixels
    printf("\n------------------------> Pixels da Imagem\n");
    for (int y = 0; y < D->height; y++) {
        for (int x = 0; x < D->width; x++) {
            fread(P, sizeof(Cor), 1, fp);
            printf("Linha %d, Pixel %d: R(%02X) G(%02X) B(%02X)\n", y, x, P->r, P->g, P->b);
        }
        fseek(fp, padding, SEEK_CUR);
    }

    printf("\nCarregamento Concluído.\n");
    fclose(fp);
}

void SaveImage(char *File, FileHeader *F, DIBHeader *D, Cor *P, int out_color) {
    FILE * fp;
    fp = fopen("out_image_color.bmp", "wb");
    if (fp == NULL) {
        printf("Não foi possível ler o arquivo.\n");
        return;
    }
    
    fwrite(F, sizeof(FileHeader), 1, fp);
    fwrite(D, sizeof(DIBHeader), 1, fp);
    
    // Lendo os pixels do original.
    FILE *orig = fopen(File, "rb");
    fseek(orig, F->File_Offset_to_PixelArray, SEEK_SET); 

    fseek(fp, F->File_Offset_to_PixelArray, SEEK_SET); // Pular para a área de pixels
    for (int y = 0; y < D->height; y++) {
        for (int x = 0; x < D->width; x++) {
            fread(P, sizeof(Cor), 1, orig);

            switch (out_color) {
                case 1:
                    P->g = 0;
                    P->b = 0;
                    break;
                case 2:
                    P->r = 0;
                    P->b = 0;
                    break;
                case 3:
                    P->r = 0;
                    P->g = 0;
                    break;
                case 4: // Cinza (média dos canais de cor)
                    {
                        uint8_t gray = (P->r + P->g + P->b) / 3;
                        P->r = gray;
                        P->g = gray;
                        P->b = gray;
                    }
                    break;
            }

            fwrite(P, sizeof(Cor), 1, fp);
        }
        

        int padding = (4 - (D->width * 3) % 4) % 4;
        for (int p = 0; p < padding; p++) {
            fputc(0, fp); 
        }
    }

    fclose(orig);
    fclose(fp);
}

int main() {
    //variables
    int loop = 1;
    
    // Structs
    FileHeader FileH;
    DIBHeader DIB;
    Cor Pixel;

    // +++ Select File +++ //
    char file_name[30];
    printf("\nDigite o nome do arquivo: ");
    scanf("%[^\n]",file_name);
    getchar();
    fflush(stdin);

    // +++ Load Image +++ //
    LoadImage(file_name, &FileH, &DIB, &Pixel);

    // Decision
    while (loop) {
        int op;
        printf("\n1)Cor\n2)Corte\n3)Sair\nDigite a decisão: ");
        scanf("%d",&op);
        fflush(stdin);

        switch (op) {
            case 1: // SaveImage();
                int cor;
                printf("Cores 1->Vermelho 2->Verde 3->Azul 4->Cinza: ");
                scanf("%d",&cor);
                fflush(stdin);
                SaveImage(file_name, &FileH, &DIB, &Pixel, cor);
            break;
            case 2: //CutImage();
                // em breve.
            break;
            case 3:
                loop = 0;
            break;
        }
    } 

    return 0;
}
