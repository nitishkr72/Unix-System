char command[64], pathname[64];
char dname[32][64], bname[64];	//they will get their value in tokenize()
char *cmd[] = {"mkdir", "rmdir", "ls", "cd", "pwd", "creat", "rm", "reload", "save", "menu", "quit", NULL};

int findCmd(char * u_cmd){   //return cmd index
	int i = 0;
	while(cmd[i]) {
		if(!strcmp(u_cmd, cmd[i]))
			return i;
		i++;
	}
	return -1;
}

void tokenize(char * path){
	char str[strlen(path)];
	for(int i=0;i<strlen(path);i++)
		str[i] = path[i];
	int i = 0;
	char *s;
	s = strtok(str, "/");
	while(s){
		memcpy(dname, s, strlen(s));
		s = strtok(0, "/")
		i++;
	}
	memcpy(bname, dname[i-1], strlen(dname[i]));
}

int mkdir(char * pathname){
	tokenize(pathname);

}
int rmdir(char * pathname){return -1;}
int ls(char * pathname){return -1;}
int cd(char * pathname){return -1;}
int pwd(char * pathname){return -1;}
int creat(char * pathname){return -1;}
int rm(char * pathname){return -1;}
int reload(char * filename){return -1;}
int save(char * filename){return -1;}
int menu(char * pathname){
	printf("-- file system commands are:\n");
	printf("-- 1. mkdir: usage: mkdir <pathname>, create directory on given pathname\n");
	printf("-- 2. rmdir: usage: rmdir <pathname>, remove directory from its path\n");
	printf("-- 3. cd: usage: cd <pathname>, change CWD to given pathname\n");
	printf("-- 4. ls: usage: ls <pathname> or ls, list dir. content of pathname\n");
	printf("-- 5. pwd: usage: pwd, print absolute pathname of CWD\n");
	printf("-- 6. creat: usage: creat <pathname>, create FILE on given pathname\n");
	printf("-- 7. rm: same usage as rmdir but it remove, file\n");
	printf("-- 8. save: usage: save <filename>, save the current file system tree as file\n");
	printf("-- 9. reload: usage: reload <filename>, construct a file system tree from a file\n");	
	printf("-- 10.menu: usage: menu, it shows the available commands.\n");
	printf("-- 11.quit: usage: quit, terminate program.\n");
	return 0;
}
int quit(){
	break;
	return -1;
}