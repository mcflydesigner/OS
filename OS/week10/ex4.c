#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

//A constant
#define MAX_NUM_OF_FILES 100

//To create a "bool" type for flags
typedef enum {false, true} bool;

//Store array os files entries
struct fileEntry
{
	char file_names[MAX_NUM_OF_FILES][255]; //Store all file names in the array
	unsigned int size; //The number of file names which are added
	unsigned long i_node; //The Inode's number
};

int main()
{	
	//Open dir "/tmp"
	DIR *dir = opendir("./tmp");
	if(dir == NULL) {
		printf("Sorry, could not open the directory :(");
		return -1;
	}
	
	struct dirent *file;
	
	//To deal with system directories
	char sys_dir_1[] = ".";
	char sys_dir_2[] = "..";
		
	//Store all linked files as an array of structures
	struct fileEntry* linked_files = malloc(MAX_NUM_OF_FILES * sizeof(struct fileEntry));
	
	//Initialize the array of linked_files
	int i;
	for(i = 0; i < MAX_NUM_OF_FILES; i++) {
		struct fileEntry file;
		file.i_node = -1;
		*(i + linked_files) = file;
	}

	while((file = readdir(dir)) != NULL) {
		//Skip system files
		if(strcmp(sys_dir_1, file->d_name) == 0) continue;
		if(strcmp(sys_dir_2, file->d_name) == 0) continue;
		
		//Work with current file
		struct stat fstat;
		
		//length of the path is 4 + max length of the file name
		char path_to_file[4 + 255] = "tmp/";
		if(stat(strcat(path_to_file, file->d_name), &fstat) != 0) {
			printf("Sorry, could not read the statistics of a file :(");
			//return -1;
		}
		
		//Now check the number of hard links of the file
		//According to the tasks, this value must be greater than 1
		if(fstat.st_nlink <= 1) continue;
		//Debug only
		//printf("File reaches: %s\n", file->d_name);
		
		//inode's number
		bool flagInodeIsInTheList = false;
		
		//If we already consider such inode's before, just add
		//the file in the list of connected files to the current inode
		for(i = 0; i < MAX_NUM_OF_FILES; i++) {
			if((i + linked_files)->i_node == fstat.st_ino) {
				//Such Inode is already in the list
				flagInodeIsInTheList = true;
				
				//Add the name of the file
				strcat((i + linked_files)->file_names[(i + linked_files)->size], file->d_name);
				(i + linked_files)->size += 1;
				
				break;
			}
		}
		
		if(!flagInodeIsInTheList) {
			//Such Inode is not in the list, add it on the first free place of
			//the array
			for(i = 0; i < MAX_NUM_OF_FILES; i++) {
				if((i + linked_files)->i_node == -1) {
					//We found a free place, store the current inode
					struct fileEntry newFileEntry;
					newFileEntry.i_node = fstat.st_ino;
					newFileEntry.size = 0;
					*(i + linked_files) = newFileEntry;
					
					//Add the name of the file
					
					strcat((i + linked_files)->file_names[(i + linked_files)->size], file->d_name);
					(i + linked_files)->size += 1;
					
					//Debug
					//printf("Store a new one for %ul", fstat.st_ino);
					break;
				}
			}
		}
		
		
		//printf("%s\n", file->d_name);
	}
	
	for(i = 0; i < MAX_NUM_OF_FILES; i++) {
		//Print nonempty elements of the linked_files
		if((i + linked_files)->i_node != -1) {
			printf("Inode's number is %lu:\n", (i + linked_files)->i_node);
			//Print names of the files which are linked
			int j;
			for(j = 0; j < (i + linked_files)->size; j++) {
				printf("%s\n", (i + linked_files)->file_names[j]);
			}
			printf("\n");
		}
	}
	
	//Close the directory
	closedir(dir);
	
	return 0;
}
