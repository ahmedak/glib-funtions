#include <glib.h>
#include <glib/gprintf.h>

int main (int argc, char** argv) {
	char * str;
	// Get string
	printf("\nEnter string: \n");
	scanf("%s",str);

	// Create new GString with str
	GString * s = g_string_new(str);
	printf("Enter string to be appended: ");
	scanf("%s",str);

	// Append str to s
	s = g_string_append(s, str);
	printf("\nNew string: %s",(char*)s->str);

	printf("\nEnter substring to be searched for:");
	scanf("%s",str);

	// Search for substring str in s
	if(g_strstr_len(s->str, -1, str))
		printf("\nFound substring\n");
	else
		printf("\nSubstring not found\n");

	printf("\nLength of string is: %d\n", (int)s->len);
	return 0;
}
