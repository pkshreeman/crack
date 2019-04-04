// LAB 9:  "START CRACKING"
//clang hashpass.c md5.c -o hashpass -l crypto
/*
TestONE
./hashpass rockyou100.txt hashes.txt

e10adc3949ba59abbe56e057f20f883e
827ccb0eea8a706c4c34a16891f84e7b
25f9e794323b453885f5181f1b624d0b
5f4dcc3b5aa765d61d8327deb882cf99
f25a2fc72690b780b2a14e140ef6a9e0

TEST TWO
./hashpass words.txt wordhashes.txt

ead5330998999cced1d8c989bdaea5ba
03318769a5ee1354f7479acc69755e7c
9dee45a24efffc78483a02cfcfd83433
5703038ffb5c1a34b391111460c74586
d2feb9b6718bb374dfdd689380676954
f14ca2ecf31aafc53cdff07f4b4a9fc8

 */

#include <stdio.h>
#include "md5.h"
#include "sha256.h"
#include <string.h> // for strings 
#include <stdlib.h> // for exit, free...

int main(int argc, char *argv[])
{
    
    int writeToFile = 1;
    FILE *r;
    FILE *f;
    
    if (argv[1] == NULL){
        printf("Please enter filename to analyze\n");
        exit(1);
    }
    
    if (argv[2] == NULL){ //Option to either printf or fprintf
        writeToFile = 0;
    }
    else if(strcmp(argv[1],argv[2]) == 0)
    {
        printf("Output file is same as input file\n");
        exit(1);
    }
   
   if(writeToFile){
        r = fopen(argv[2], "w");
        if (r == NULL)
        {
            printf("Can't open %s for writing\n", argv[2]);
            exit(1);
        }
   }
    
    // Open file for reading
    
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }


    
    // Loop through the file, one line at a time
    char line[1000];
   
    while(fgets(line, 1000, f) != NULL )
    {
       
        char *hash = md5(line, strlen(line)-1); 	
        if(writeToFile == 0) {printf("%s\n", hash);}
        else {fprintf(r, "%s\n", hash);};
        free(hash);
    }
    
    fclose(f);
    if(writeToFile == 1) {fclose(r);}

}
