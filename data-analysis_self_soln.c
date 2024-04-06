/*
	Course:		CS2024 DSA Lab 
	Semester:	2024 Jan-Apr
	Lab No:		1
	Aim: 		Simple data analysis on a list of non-zero integers. 
	Instructions:
		1.	Read a list of numbers from the terminal and store it in an array.
		2.	You can also read the list by redirecting a file data.txt to the input 
		3.	Complete a set of data analytic tasks on these numbers.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define N 100		// The maximum amount of data the program will handle



int main()
{
	int a[N];
	int i, len, temp;

	for(i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if(temp == 0){
			len = i;
			break;}
		else{
			a[i] = temp;}
	}

	/* Task 1. Modify the loop below to print the numbers in reverse order
	*/

	// for(i = len-1; i >=0; i--)
	// 	printf("%d\n", a[i]);

	/* Task 2. Find some cumulative statistics of the data
		a) 	Average 
		b)	Standard Deviation
		c)	Minimum value
		d) 	Maximum value
	*/

	//Avg

	// int sum = 0;
	// for(i=0;i<len;i++){
	// 	sum += a[i];
	// }
	// float avg = (float) sum/len;
	// printf("Average: %f\n",avg);

	//Std dev = (sum((xi-x)^2))/len)^0.5

	// float devsum = 0;
	// for(i=0;i<len;i++){
	// 	devsum += pow(a[i]-avg,2);
	// }
	// float devavg = (float)devsum/len;
	// printf("Std dev: %f\n",sqrt(devavg));

	//Min

	// long long min = INT64_MAX;
	// for(i=0;i<len;i++){
	// 	if(a[i]< min){
	// 		min = a[i];
	// 	}
	// }
	// printf("Min: %lld\n",min);

	//Max

	long long max = INT64_MIN;
	for(i=0;i<len;i++){
		if(a[i]> max){
			max = a[i];
		}
	}
	// printf("max: %lld\n",max);


	/* Task 3. Generate a histogram of the data in the following form
		01 - 10 : ####
		11 - 20 : ########
		...
		91 -100 : ##
		
		Here the number of #'s after i-j denote the number of numbers in the
		list which are between i and j (i and j included)
	*/

	// int arr[10] = {0};

	// for(int i=0;i<len;i++){
	// 	if( a[i]>=1 && a[i]<=10 ){
	// 		arr[0]+=1;
	// 	}
	// 	if( a[i]>=11 && a[i]<=20){
	// 		arr[1]+=1;
	// 	}
	// 	if( a[i]>=21 && a[i]<=30 ){
	// 		arr[2]+=1;
	// 	}
	// 	if( a[i]>=31 && a[i]<=40 ){
	// 		arr[3]+=1;
	// 	}
	// 	if( a[i]>=41 && a[i]<=50 ){
	// 		arr[4]+=1;
	// 	}
	// 	if( a[i]>=51 && a[i]<=60 ){
	// 		arr[5]+=1;
	// 	}
	// 	if( a[i]>=61 && a[i]<=70 ){
	// 		arr[6]+=1;
	// 	}
	// 	if( a[i]>=71 && a[i]<=80 ){
	// 		arr[7]+=1;
	// 	}
	// 	if( a[i]>=81 && a[i]<=90 ){
	// 		arr[8]+=1;
	// 	}
	// 	if( a[i]>=91 && a[i]<=100 ){
	// 		arr[9]+=1;
	// 	}
	// }

	// for(i=0;i<10;i++){
	// 	for(int j=0;j<arr[i];j++){
	// 		printf("#");
	// 	}
	// 	printf("\n");
	// }

	/* Task 4. Search type tasks
		a) 	Find the number of times the maximum value repeats in the list
		b)	Find the value which repeats the maximum number of times in the list
			(this is called the mode of the list)
	*/

	//(a)
	// int max_num = 0;
	// for(i=0;i<len;i++){
	// 	if(a[i] == max){
	// 		max_num +=1;
	// 	}
	// }
	// printf("%d\n",max_num);

	//(b)
	int arr[max];
	memset( arr, 0, max*sizeof(int) );
	for(i=0;i<len;i++){
		arr[a[i]] += 1;
	}
	
	long long max_times = INT64_MIN;
	int m = arr[0];
	for(i=0;i<max;i++){
		if(arr[i]>max_times){
			max_times = arr[i];
			m = i;
		}
	}
	printf("%d\n",m);

	/* Task 5. Sorting
		a) Sort the array in the non-decreasing order 
		b) Print the array in sorted order*/

	//(a)
	// int arr1[len];
	// arr1[0] = a[0];
	// int cur_idx = 1;

	// for(i=1;i<len;i++){
	// 	bool is_incl = false;
	// 	for(int j=0;j<cur_idx;j++){
	// 		if(a[i]<arr1[j]){
	// 			int z = arr1[j];
	// 			for(int k = j+1;k<cur_idx+1;k++){
	// 				int v = arr1[k];
	// 				arr1[k] = z;
	// 				z=v;
	// 			}
	// 			arr1[j] = a[i];
	// 			cur_idx +=1;
	// 			is_incl = true;
	// 			break;
	// 		}
	// 	}
	// 	if(!is_incl){
	// 		arr1[cur_idx] = a[i];
	// 		cur_idx += 1;
	// 	}
	// }

	//(b)
	// for(i=0;i<len;i++){
	// 	printf("%d\n",arr1[i]);
	// }

	/* Task 6.  Uniqueness
		a) Create a new array which contains all elements of the first 
				but without any repetition.
		b) Print this array
	*/

	//(a)
	// int array[N]={0};
	// int length = 0;
	// for(i=0;i<len;i++){
	// 	bool is_in = false;
	// 	for(int j=0;j<N;j++){
	// 		if(a[i]==array[j]){
	// 			is_in = true;
	// 		}
	// 	}
	// 	if(!is_in){
	// 		array[length]=a[i];
	// 		length += 1;
	// 	}
	// }

	//(b)
	// for(i=0;i<length-1;i++){
	// 	printf("%d\n",array[i]);
	// }

	return 0;
}
