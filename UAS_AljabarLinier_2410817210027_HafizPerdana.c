#include <stdio.h>
#include <math.h>

#define ROW 3
#define COL 4

void printMatrix(double matrix[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (fabs(matrix[i][j]) < 0.0001) {
                matrix[i][j] = 0.0;
            }
            if (matrix[i][j] == (int)matrix[i][j]) {
                printf("%.0f\t", matrix[i][j]);
            } else {
                printf("%g\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void gaussJordan(double matrix[ROW][COL]) {
    int step = 1;
    for (int i = 0; i < ROW; i++) {
        double diagElement = matrix[i][i];
        printf("\nLangkah %d: Membagi seluruh baris %d dengan %g agar elemen diagonal menjadi 1\n", step++, i+1, diagElement);
        
        for (int j = 0; j < COL; j++) {
            matrix[i][j] /= diagElement;
        }
        printMatrix(matrix);

        for (int k = 0; k < ROW; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                printf("\nLangkah %d: Mengurangi baris %d dengan %g kali baris %d (R%d - %g * R%d)\n", step++, k+1, factor, i+1, k+1, factor, i+1);

                for (int j = 0; j < COL; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
                printMatrix(matrix);
            }
        }
    }
}

int main() {
    double matrix[ROW][COL] = {
        {2, 3, 1, 80},
        {1, 1, 2, 70},
        {3, 2, 1, 75}
    };

    printf("Diketahui :\n");
    printf("- Model pertama menggunakan 2 unit data piksel, 3 unit fitur tekstur, dan 1 unit data warna, menghasilkan akurasi 80%%\n");
    printf("- Model kedua menggunakan 1 unit data piksel, 1 unit fitur tekstur, dan 2 unit data warna, menghasilkan akurasi 70%%\n");
    printf("- Model ketiga menggunakan 3 unit data piksel, 2 unit fitur tekstur, dan 1 unit data warna, menghasilkan akurasi 75%%\n\n");

    printf("Misalkan :\n");
    printf("- kontribusi data piksel = x\n");
    printf("- kontribusi fitur tekstur = y\n");
    printf("- kontribusi data warna = z\n\n");

    printf("Sistem persamaan linier yang terbentuk :\n");
    printf("1. 2x + 3y + z = 80\n");
    printf("2. x + y + 2z = 70\n");
    printf("3. 3x + 2y + z = 75\n\n");


    printf("Matriks yang terbentuk sebelum eliminasi Gauss-Jordan:\n");
    printMatrix(matrix);
    
    printf("\nLangkah-langkah eliminasi Gauss-Jordan:");
    gaussJordan(matrix);
    
    printf("\nSolusi Akhir:\n");
    if (matrix[0][3] == (int)matrix[0][3]) printf("x (Kontribusi data piksel) = %.0f\n", matrix[0][3]);
    else printf("x (Kontribusi data piksel) = %.3f\n", matrix[0][3]);
    
    if (matrix[1][3] == (int)matrix[1][3]) printf("y (Kontribusi fitur tekstur) = %.0f\n", matrix[1][3]);
    else printf("y (Kontribusi fitur tekstur) = %.3f\n", matrix[1][3]);
    
    if (matrix[2][3] == (int)matrix[2][3]) printf("z (Kontribusi data warna) = %.0f\n", matrix[2][3]);
    else printf("z (Kontribusi data warna) = %.3f\n", matrix[2][3]);
    
    return 0;
}