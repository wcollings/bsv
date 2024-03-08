#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index_of_nl(char* arr, int arr_size)
{
	int id=0;
	for (id; id < arr_size && arr[id]!='\n';++id);
	return (id<arr_size?id:-1);
}

void 
int main()
{
	FILE * inf=fopen("test.csv","r");
	FILE * outf=fopen("test.bsv","w");
	char buff[100];
	char sep;
	fputc(1,outf);
	while ( !feof(inf))
	{
		// TODO: This doesn't break by comma, still just by newline. Why?
		fscanf(inf,"%s%[\n,]",buff,&sep);
		fputs(buff,outf);
		printf("name=%s\n",buff);
		if (sep=='\n')
		{
			printf("Found the newline!\n");
			break;
		}
		else
			fputc(0xFE,outf);
	}
	fputc(0x2,outf);
	fputc(0x3,outf);
	float val;
	while (!feof(inf))
	{
		fscanf(inf,"%f%c",&val,&sep);
		printf("%f\n",val);
		if (sep==',')
			sep=0xFE;
		else
			sep=0xFF;
		fprintf(outf,"%e%c",val,sep);
	}
	fputc(0x3,outf);
	fclose(outf);
	fclose(inf);
}
