#include <glib.h>
#include <stdio.h>
void hash_print(gpointer key1, gpointer val1, gpointer user_data){
	printf(user_data, (char*)key1, (char*)val1);
}

void hash_print_file(gpointer key2, gpointer val2, gpointer user_data){
	fprintf((FILE*)user_data, "%s\t%s\n", (char*)key2, (char*)val2);
}

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("\nUsage: ./example <InputFile>");
    return 0;
  }
	GHashTable * hash = g_hash_table_new(g_str_hash, g_str_equal);
	FILE * fp = fopen(argv[1], "r+");
	char  key[10],  val[25], ch='y';
	if(!fp)	printf("\nFile not linked!!");
	while(fscanf(fp, "%s\t%s", key, val)==2)
		g_hash_table_insert(hash, g_strdup(key),g_strdup(val));
	int a = 10;
	do{	
		printf("\n\n1.Add element\n2.Delete element\n3.Search element\n4.Length of hashtable\n5.Print hashtable\n0.Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &a);
		switch(a){
				case 0:
					ch = 'n';
					break;
				case 1:
					printf("\nEnter key: ");
					scanf("%s", key);
					//key = g_strdup(temp);
					printf("Enter value: ");
					scanf("%s",val);
					printf("\nkey:%s val:%s",key,val);
					if(g_hash_table_insert(hash, g_strdup(key), g_strdup(val)))	
						printf("\nElement successfully inserted");
					else	printf("\nKey already exists in hashtable");
					break;
				case 2:
					printf("\nEnter the key of element to be deleted: ");
					scanf("%s", key);
					if(g_hash_table_remove(hash, key))
						printf("\nElement removed");
					else	printf("\nElement not found");
					break;
				case 3:
					printf("\nEnter the key to be searched for: ");
					scanf("%s", key);
					if(g_hash_table_contains(hash,key))
						printf("\nKey: %s\tval: %s", key, (char*)(g_hash_table_lookup(hash,key)));
					else	printf("\nElement not found");
					break;
				case 4: 
					printf("\nLength of hashtable is : %i ", g_hash_table_size(hash));
					break;
				case 5: 
					g_hash_table_foreach(hash, (GHFunc)hash_print, "\nKey: %s\tVal: %s");
					break;
				default:
					printf("\nInvalid entry. Try again\n");
					break;
		}
		getchar();
	}while(ch=='y');
	fseek(fp, 0 ,SEEK_SET);
	g_hash_table_foreach(hash, (GHFunc)hash_print_file, fp);
	g_hash_table_destroy(hash);
	fclose(fp);
	printf("\n");
	return 0;
}
