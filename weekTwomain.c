#include <stdio.h>
#include <stdlib.h>
#include "weekTwoBinary.h"
#include <time.h>


int main(void){

	

	double total_time=0.0;
	double sample_time=0.0;
	clock_t start,end,start_sample,stop_sample;


	node *tree = NULL;

	

	int test[100];

	

	for(int i=0;i<1000;i++)
	{
		
		total_time = clock();
		sample_time=0.0;
		for(int j=0;j<100;j++)
		{
			test[j] = j+1;
		}


		for(int j=0;j<100;j++)
		{
			tree=insert(tree,i);
		}

		for(int j=0;j<100;j++)
		{
			start_sample = clock();

			findNode(tree,(j+1));

			stop_sample = clock();

			sample_time += (double)(stop_sample - start_sample);
		}
			
			
		

		tree = NULL;	
		
		end = clock();

		total_time+=((double)(end-start));

	}
	
		printf("\nInt array 100x-search: %f sec",sample_time/CLOCKS_PER_SEC/100);
		printf("\nInt array 1000x-create+search: %f sec",total_time/CLOCKS_PER_SEC/1000);


	double testD[100];
	nodeD *treeD = NULL;

	

	for(int i=0;i<1000;i++)
	{
		
		total_time = clock();
		sample_time=0.0;
		for(int j=0;j<100;j++)
		{
			testD[j] = j+1.25;
		}


		for(int j=0;j<100;j++)
		{
			treeD=insertD(testD[j]);
		}

		for(int j=0;j<100;j++)
		{
			start_sample = clock();

			findNodeD(treeD,(j+1.25));

			stop_sample = clock();

			sample_time += (double)(stop_sample - start_sample);
		}
			
			
		

		tree = NULL;	
		
		end = clock();

		total_time+=((double)(end-start));

	}
	
		printf("\nDouble array 100x-search: %f sec",sample_time/CLOCKS_PER_SEC/100);
		printf("\nDouble array 1000x-create+search: %f sec",total_time/CLOCKS_PER_SEC/1000);

	
}
