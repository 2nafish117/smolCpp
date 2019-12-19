#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef int s32;
typedef unsigned int u32;

char isCaps(char c)
{
	if(c >= 'a' && c <= 'z')
		return('a');

	return('A');
}

s32 isAlphabet(char c)
{
	if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;

	return 0;
}

void vigenereEncrypt(const char* text, const char* key, char* result)
{
	u32 i, j;

    u32 text_len = strlen(text);
    u32 key_len = strlen(key);
	for(i = 0;i < text_len;i++)
	{
		if(!isAlphabet(text[i]))
			return;
	}

	for(i = 0;i < text_len;i = i + key_len)
	{
		for(j = 0 ; j < key_len && i + j < text_len; j++)
		{
			result[i + j] = (text[i + j] - isCaps(text[i + j]) + key[j] - isCaps(key[j])) % 26 + isCaps(text[i + j]);
		}
	}
	result[text_len] = '\0';
}

void vigenereDecrypt(const char* text, const char* key, char* result)
{
	u32 i, j;

    u32 text_len = strlen(text);
    u32 key_len = strlen(key);
	for(i = 0;i < text_len;i++)
	{
		if(!isAlphabet(text[i]))
			return;
	}

	for(i = 0;i < text_len;i = i + key_len)
	{
		for(j = 0 ; j < key_len && i + j < text_len; j++)
		{
			result[i + j] = (text[i + j] - isCaps(text[i + j]) - key[j] + isCaps(key[j]) + 26) % 26 + isCaps(text[i + j]);
		}
	}
	result[text_len] = '\0';
}

int main()
{
	const char* key = "HEasf";
	const char* plain = "PENIafDSS";
	char cypher[40];
    char decrypt[40];

	vigenereEncrypt(plain, key, cypher);
    vigenereDecrypt(cypher, key, decrypt);

    printf("key: %s\n", key);
    printf("plaintext: %s\n", plain);
	printf("cyphertext: %s\n", cypher);
	printf("decrypted : %s\n", decrypt);

	return 0;
}
