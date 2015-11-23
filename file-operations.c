#include<stdio.h>

void file_size(char []);
void countWords(char []);
void copy_file(char [], char []);
void copy_pdf();

int main()
{
    file_size("fileName.txt");
	countWords("fileName.txt");
	copy_file("oldFile.txt","newFile.txt");
	file_size("fileName.pdf");
	copy_pdf();
	freq_pdf();

}

void file_size(char file_name[]) /*Find size of the file*/
{
    FILE *fp;
    char ch;
    int size_of_file = 0;
    fp = fopen(file_name, "r");
    if (fp == NULL)
        printf("\nFile unable to open ");
    fseek(fp, 0, 2);    /* file pointer at the end of file */
    size_of_file = ftell(fp);   /* take a position of file pointer un size variable */
    printf("\nFile Size of %s: %d\n",file_name,size_of_file);
    fclose(fp);
}

void countWords(char file_name[]) /*Print total words in the file*/
{
    FILE *f;
    char ch;
    int word=0;
    f=fopen(file_name, "r");
    while((ch=getc(f))!=EOF)
    {
        if(ch==' '||ch=='\t'||ch=='\n')
            word++;
        //putchar(ch);
    }
    fclose(f);
    printf("\nNo of word in %s: %d\n",file_name,word);
}

void copy_file(char file1[], char file2[]) /*Copy to new file with change in case of character*/
{
    char ch, source_file[20], target_file[20];
    FILE *source, *target;

    source = fopen(file1, "r");

    if( source == NULL )
    {
        printf("Press any key to exit...\n");
        exit(0);
    }

    target = fopen(file2, "w");

    if( target == NULL )
    {
        fclose(source);
        printf("Press any key to exit...\n");
        exit(0);
    }

    while( ( ch = fgetc(source) ) != EOF ){
        if (ch >= 'A' && ch <= 'Z')
            ch = tolower(ch);
        else if (ch >= 'a' && ch <= 'z')
            ch = toupper(ch);
        fputc(ch, target);
    }

    printf("\nFile copied successfully from %s to %s.\n",file1,file2);

    fclose(source);
    fclose(target);

}

void copy_pdf() //Create Copy of PDF - Not tested
{
    FILE *p,*q;
    char file1[20],file2[20];
    char ch;
    p=fopen("oldFile.pdf","r");
    if(p==NULL){
        printf("cannot open %s",file1);
        exit(0);
    }
    q=fopen("newFile.pdf","w");
    if(q==NULL){
        printf("cannot open %s",file2);
        exit(0);
    }
    while((ch=getc(p))!=EOF)
        fputc(ch,q);
    printf("\nFile wfile.pdf copied to new file new.pdf\n");
    fclose(p);
    fclose(q);
}


void freq_pdf() //Count frequecy of all characters in pdf
{
    int freq[256] = {0};
    FILE *p;
    int i,j;
    char file1[20],file2[20];
    char ch;
    p=fopen("filename.pdf","r");
    if(p==NULL){
        printf("cannot open %s",file1);
        exit(0);
    }

    while((ch=getc(p))!=EOF){
            freq[ch] = freq[ch] + 1;
    //putchar(ch);
    }
    printf("\nFrequery of characters:\n");
    for(i=65,j=0;i<123;i++,j++){
        if(j%8 == 0)
            printf("\n");
        if(i > 90 && i < 97){
            i = i+6;
        }
        printf(" %c : %d ",i,freq[i]);

    }

    fclose(p);
}
