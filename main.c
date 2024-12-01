#include <stdio.h>
#include <stdlib.h>

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
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char reserved;
} Cor;

int main () {
    
    CabeçalhoArquivo Arquivo;
    CabeçalhoImage Image;
    Cor pixels;

    return 0;
}