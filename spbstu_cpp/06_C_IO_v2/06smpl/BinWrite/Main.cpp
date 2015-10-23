#include <stdio.h>

int main(void)
{
	int arr[20];
	for (int i=0; i<20; i++)
		arr[i]=i;
	FILE* fout=fopen("out.txt", "wb");
	if (fout==0)
	{
		printf("Error opening file out.txt\n");
		return -1;
	}
	fwrite(arr, sizeof(int), 20, fout);
	fclose(fout);
	return 0;
}