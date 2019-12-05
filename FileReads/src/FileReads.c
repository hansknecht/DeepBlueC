#include "FileReads.h"

int main(void)
{
	clock_t begin, end;
	
	begin = clock();
	readWriteUnbufferedStd("Sample.txt", "Output.txt");
	end = clock();
	printClockTime(begin, end);

	begin = clock();
	readWriteSystem("Sample.txt", "Output.txt");
	end = clock();
	printClockTime(begin, end);
}

void printClockTime(clock_t begin, clock_t end)
{
	double processing_time = ((double)end - (double)begin) / CLOCKS_PER_SEC;
	printf("Processing Time: %lf\n", processing_time);

}

void readWriteUnbufferedStd(char* input, char* output)
{

	FILE* inf, *outf;
	inf = fopen(input, "r");
	outf = fopen(output, "w");

	int c;
	while ((c = getc(inf)) != EOF) putc((c), outf);
	fclose(inf);
	fclose(outf);
}
void readWriteSystem(char* input, char* output)
{

	int inf, outf;
	char buf[BUFSIZ];
	inf = open(input, O_RDONLY, 0);
	outf = creat(output, O_WRONLY);

	int c;
	while ((c = read(inf, buf, BUFSIZ)) > 0) write(outf, buf, c);
	close(inf);
	close(outf);
}
