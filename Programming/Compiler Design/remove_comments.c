#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_comments(char* , char* );

int main()
{
    char sourcefile[100] , outputfile[100];
    printf("Enter source file name with full path: ");
    scanf("%s",sourcefile);
    printf("\n");
    printf("Enter output file name with full path: ");
    scanf("%s",outputfile);
    remove_comments(sourcefile, outputfile);

    char choice;
    printf("Do you want to replace the original file with output file? (y/n) :");
    getchar();
    scanf("%c",&choice);

    if(choice == 'y' || choice == 'Y'){
        if(remove(sourcefile) == 0){ // removes() removes the original source file 
            if(rename(outputfile, sourcefile) == 0){ // rename() renames the output file to source file
                printf("Files replaced successfully.\n");
            }else{
                printf("Error: File could not be renamed.");
            }
        }else{
            printf("Error: Files cannot be replaced.\n");
        }
    }

    printf("Program Execution Completed.\n");
    return 0;
}

void remove_comments(char *sourcefile, char *outputfile)
{
    FILE *source, *output;
    char nextCh, ch;

    source = fopen(sourcefile, "r");
    output = fopen(outputfile, "w");

    if(source == NULL){
        printf("Error: Source file is either empty or does not exist.\n");
        return;
    }

    if(output == NULL){
        printf("Error: could not open output file.\n");
        fclose(source);
        return;
    }

    printf("Removing comments from %s file.....",sourcefile);

    while((ch = fgetc(source)) != EOF){
        if(ch == '/'){
            nextCh = fgetc(source);// read next character after '/' to kown either it is comment or not
            if(nextCh == '/'){//single line comment
                while(((ch = fgetc(source)) != EOF) && ch != '\n'){
                    //skip content
                }
                if(ch == '\n'){
                    fputc(ch, output); // preserving new line in output file
                }
            }
            else if(nextCh == '*'){//multiline comment
                while((ch = fgetc(source)) != EOF){
                    if(ch == '*'){
                        nextCh = fgetc(source);
                        if(nextCh == '/'){
                            //closing comment found
                            break;
                        }else{
                            //put back '/' onto the file as it is not a closing comment
                            ungetc(nextCh, source);
                        }
                    }
                }
            }else{//it was just single '/'
                fputc('/', output);
                //put next character that we had read back to input file
                if(nextCh != EOF){
                    ungetc(nextCh, source);
                }
            }
        }else{
            //regular character
            fputc(ch, output);
        }
    }

    fclose(source);
    fclose(output);
    printf("Comment removed successfully");

}