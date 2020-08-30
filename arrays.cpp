#include <stdio.h>
#include <TXLib.h>

//-----------------------------------------------------------------------------

void ReadData  (int data[],        int size,
                const char name[]);

void SortData  (int data[],        int size);

void PrintData (const int data[], int size,
                const char name[], const char reason[]);

//-----------------------------------------------------------------------------


int main() {

    printf("# Data Sorting \n\n");

    const int size = 10;

    int temperature[size] = {10, 20, 30};

    temperature[5] = 50;

    ReadData(temperature, size, "temperature");

    SortData(temperature, size);

    PrintData(temperature, size, "temperature", "result");

    $(temperature);

    return 0;
}

//-----------------------------------------------------------------------------

void ReadData (int* data, int size, const char name[]) {

    for (int i = 0; i < size; i++) {
        printf("Enter %s [%d]: ", name, i);
        scanf("%d", data + i);
    }
    printf("\n");

}

//-----------------------------------------------------------------------------

void SortData (int data[], int size) {

}

//-----------------------------------------------------------------------------

void PrintData (const int* data, int size,
                const char name[], const char reason[]) {
    $y
    printf("%s:\n\n", reason);
    for (int i = 0; i < size; i++) {
        printf("%s [%d] = %d\n", name, i, data[i]);
    }
    $d
}
