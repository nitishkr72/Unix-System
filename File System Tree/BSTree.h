//implementation of Binary Search Tree function

typedef struct NODE {
	char name[64];	//node name
	char type;	//either 'D' or 'F';
	struct NODE * childPtr, *siblingPtr, *parentPtr;
}NODE;

void initialize() {
	root = (NODE *)malloc(sizeof(NODE));
	char name[] = "root";
	memcpy(root->name, name, 4);
	root->siblingPtr = root;
	root->parentPtr = root;
	root->childPtr = NULL;
	root->type = 'D';
}

NODE * NodeSearch(char * dirname[], NODE * base, int i){
	NODE * current = base->childPtr;
	while(current!=NULL){
		if(current->name==dirname)
			return current->parentPtr;
		else
			current = current->siblingPtr;
	}
}