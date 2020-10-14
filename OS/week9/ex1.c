#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
	Excercise 1.
	Made by Vladislav Lamzenkov.
	
	Implementing Aging Algorithm.
	
	Test cases:
	N = 10 => 8 / 992
	N = 50 => 50 / 950
	N = 100 => 93 / 907
*/

//To create a "bool" type for flags
typedef enum {false, true} bool;

//Each entry in table of pages stores as object: id = number of page; bits = counter of the page
struct page {
	int id;
	unsigned int bits; //bits
};

int main() {
	int n;
	
	//Input: number N > 0
	printf("Enter N:");
	scanf("%d", &n);
	
	if(n <= 0) {
		printf("Sorry, but N must be positive :)");
		return -1;
	}
	
	FILE *fptr = fopen("Input.txt", "r");
	if(fptr == NULL)
	{
		printf("Sorry, but we couldn't open the file :()");
		return -1;
	}
	
	//Allocate memory for storing our pages
	//We store all pages in the array of struct page
	struct page* pages = malloc(n * sizeof(struct page));
	if(pages == NULL) {
		printf("Sorry, but we couldn't allocate the memory :('");
		return -1;
	}
	
	//Initialyze our table with "emtpy pages"(imitate absence of pages)
	int i;
	for(i = 0; i < n; i++) {
		struct page temp_page;
		temp_page.id = -1;
		*(pages + i) = temp_page;
	}
	
	//Current number of the page from the file
	unsigned int requested_page = 0;
	
	//Counters
	unsigned int hit_page = 0;
	unsigned int miss_page = 0;
	
    while (fscanf(fptr, "%d", &requested_page) == 1)
    {
    	//Try to find it inside our list of current pages
        bool flag_in_table = false;
        
        for(i = 0; i < n; i++) {
        	if((pages + i)->id == requested_page) {
        		//The requested page is already in our table, just increment hit
        		hit_page += 1;
        		flag_in_table = true;
        		
        		break;
			}
		}
		
		if(!flag_in_table) {
			//We didn't find the requested page, so we need to put it there
			
			bool found_free = false;
			
			//Initially, try to find a free place in the array of pages, if there is - just fill it.
			for(i = 0; i < n; i++) {
				if((pages + i)->id == -1) {
					struct page new_page;
					new_page.id = requested_page;
					new_page.bits = 0;
					*(pages + i) = new_page; 
					found_free = true;
					break;
				}
			}
			
			if(!found_free) {
				//There was no free places, so we need to remove a page with the lowest counter
				//according to Aging algorithm
				
				unsigned int min_val = INT_MAX;
				unsigned int min_index = INT_MAX;
				//Find the lowest counter
				for(i = 0; i < n; i++) {
					if(min_val > (pages + i)->bits) {
						min_val = (pages + i)->bits;
						min_index = i;
					}
				}
				
				//Replace a page with the lowest counter with a new one
				struct page new_page;
				new_page.id = requested_page;
				new_page.bits = 0;
				
				*(pages + min_index) = new_page;
			}
			
			miss_page += 1;
		}
		
		//Shift all counters to right
		for(i = 0; i < n; i++) {
			//Shift 1 bit to the right for each
			(pages + i)->bits >>= 1;
			
			if(flag_in_table && requested_page == (pages + i)->id) {
				//It was hit, increment
				//We shift 31, because id has int data type which consists of 32 bits
				//and we need to add 1 leading to the right. So, 32 - 1 = 31.
				(pages + i)->bits |= 1 << 31;
			}
		}
        
    }
   	
   	//Output
   	printf("Number of hits = %u\n", hit_page);
   	printf("Number of misses = %u\n", miss_page);
   	printf("Number of hits / Number of misses = %f\n", ((float)hit_page / (float) miss_page));
   	
   	//Close file and free the memory
   	fclose(fptr);
   	free(pages);
	
	return 0;
}
