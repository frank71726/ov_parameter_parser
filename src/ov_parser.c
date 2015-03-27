#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int __attribute__((unused))argc , char **argv)
{
    int cnt=0;
    int total_item=0, total_data=0;
    FILE *conf = NULL;
    FILE *init1 = NULL;
    FILE *init2 = NULL;
    FILE *init3 = NULL;

    char buffer[128];
    char filename[256];

    strcpy(filename,argv[1]);
    strcat(filename,".hb");
    init1 = fopen(filename, "w");
    if(init1 == NULL) {
        fprintf(stderr, "open init hb file fail!\n");
        return -1;
    }
    else
        fprintf(stderr, "open file :%s\n", filename);

    strcpy(filename,argv[1]);
    strcat(filename,".lb");
    init2 = fopen(filename, "w");
    if(init2 == NULL) {
        fprintf(stderr, "open init lb file fail!\n");
        return -1;
    }
    else
        fprintf(stderr, "open file :%s\n", filename);

    strcpy(filename,argv[1]);
    strcat(filename,".data");
    init3 = fopen(filename, "w");
    if(init3 == NULL) {
        fprintf(stderr, "open init data file fail!\n");
        return -1;
    }
    else
        fprintf(stderr, "open file :%s\n", filename);

    strcpy(filename,argv[1]);
    strcat(filename,".set");
    conf = fopen(filename, "r");
    if(conf == NULL) {
        fprintf(stderr, "open source file fail!\n");
        return -1;
    }
    else
        fprintf(stderr, "open file :%s\n", filename);

    while(fgets(buffer,70, conf)) {
        printf("%s\n",buffer);

        cnt++;
        total_data++;
        total_item++;

        fprintf(init1, "0x%c%c, ", buffer[0], buffer[1]);
        fprintf(init2, "0x%c%c, ", buffer[2], buffer[3]);
        fprintf(init3, "0x%c%c, ", buffer[5], buffer[6]);

        if(cnt == 10){
            fprintf(init1, "\n");
            fprintf(init2, "\n");
            fprintf(init3, "\n");
            cnt = 0 ;
        }
    }

    printf("Total_ITEM = %d\n", total_item);
    printf("Total_DATA = %d\n", total_data);

    fclose(conf);
    fclose(init1);
    fclose(init2);
    fclose(init3);
    return 1;
}

