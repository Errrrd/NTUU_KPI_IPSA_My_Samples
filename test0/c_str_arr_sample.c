#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	unsigned int countOfWords = 0;
	
	printf("set please count of words (0 < countOfWords <= 20)\n");
	for(;countOfWords == 0 || countOfWords > 20;)
	{
		if( scanf("%u", &countOfWords) != 1 )
		{
			printf("Incorrect data (not unsigned INT 32 type)\n");
			exit(1);
		}
		if(countOfWords > 20)
		{
			printf("Incorrect data (count of words [INT:%d; UINT:%u] out of range). Repeat please again.\n", countOfWords, (int)countOfWords);
		}
	}
	printf("countOfWords = %d)\n",countOfWords);

	char * arrWords[countOfWords];
	printf("Please set %d \"words\" (any symbols <= 255. Attention: \"Enter\" is end of \"word\")\n", countOfWords);
	for (int i = 0; i < countOfWords; i++)
	{
		char word[255];
		scanf("%255s", word);
		printf("\nyour word %s, size: %d\n", word, (int)strlen(word));
		arrWords[i] = malloc(strlen(word)+1);
		strcpy(arrWords[i], word);
	}
	
	for (int i = 0; i < countOfWords; i++)
	{
		printf("Word:[%s], addr:[%p], first symb:[%c]\n", arrWords[i], arrWords[i], arrWords[i][0]);
		free(arrWords[i]);
		printf("After free (trash in memory should to print for Word): Word:[%s], addr:[%p], first symb:[%c]\n", arrWords[i], arrWords[i], arrWords[i][0]);
	}
	return 0;
}
