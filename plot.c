#include <stdio.h>
#include <stdlib.h>
//#include <gnuplot.h>

typedef struct {
	double x[20];
	double y[20];
} coord;

/*typedef struct {
	double m;
	int a;
	double p;
} __attribute__((packed)) point_t;*/

void plot(const char* name, coord* data, int size){
	FILE* gnuplot_pipe = popen ("gnuplot -persistent","w");
	fprintf(gnuplot_pipe,"set title '%s'\n",name);
	fprintf(gnuplot_pipe,"plot '-' with lines\n");
	int i;
	for(i=0; i<size;i++){
		fprintf(gnuplot_pipe,"%zu %f %f\n",i,data->x[i],data->y[i]);
	}
	fprintf(gnuplot_pipe,"e\nrefresh\n");
}

int main(void){
	coord Coords;
	unsigned long i;
	//double plt[6];
	for(i=0;i<6;i++){
		Coords.x[i] = i;
	        Coords.y[i] = 4 * i;	
		printf("X is %f, Y is %f \n",Coords.x[i],Coords.y[i]);
		//plt[i] = Coords.x[i];
	}
	plot("My first plot", &Coords, 6);

	//printf("Size of point_t is %lu\n", sizeof(point_t));
	

}
