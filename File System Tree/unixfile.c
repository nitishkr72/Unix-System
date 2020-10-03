#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *root, *cwd;	//root pointer
char line[128];		//user command and pathname

int main(){
	int (*fptr[])(char *) = {(int (*)())mkdir, rmdir, ls, cd, pwd, creat, rm, reload, save, menu, quit};
	initialize();
	while(1) {
		printf(">> ");
		fgets(line, 128, stdin);
		line[strlen(line)-1] = 0; 
		sscanf(line, "%s %s", command, pathname);
		
		int index = findCmd(command);
		if(index==-1){		//command not found
			printf("-- please enter valid commands\n");
			printf("-- for listing all valid command enter menu\n");
			continue;
		}

		int r = fptr[findCmd(command)](pathname);
		printf("%s\n", pathname);
	}
	return 0;
}
