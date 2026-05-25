void longest_word()
{
	char input[100];
	printf("Enter any string");
	//fgets(input,100,stdin);
	int index=0,count=0,high_count=0;
	for(int i=0;i<100;i++)
	{
		if(input[i]==' ' || input[i]=='\0')
		{
			if(high_count<count)
			{
				high_count=count;
				index=i;
			}
			count=0;
		}
		if(input[i]=='\0')
			break;
		count++;
	}
	for(int i=index-high_count+1;i<index;i++)
	{
		printf("%c",input[i]);
	}
}

void compare_strings()
{
		char str1[100],str2[100];
		printf("Enter str1");
		//fgets(str1,100,stdin);
		printf("Enter str2");
	//	fgets(str2,100,stdin);
		int len1=0,len2=0;
		while(str1[len1]!='\0') len1++;
		while(str2[len2]!='\0') len2++;
		if((len1-len2)!=0)
			printf("both strings are not equal");
		else
		{
			int i=0;
			int eq=0;
			while(i<len1)
			{
				if(str1[i]>str2[i])
				{
					printf("str1 is greater than str2");
					eq=0;
					break;
				}
				else if (str1[i]<str2[i])
				{
					printf("str2 is greater than str1");
					eq=0;
					break;
				}
				else
					eq=1;
				i++;
			}
			if(eq==1)
				printf("Both strings are equal");
		}
}

void bubble_sort()
{
	char str1[100];
	printf("Enter str1");
	//fgets(str1,100,stdin);
	int i=0;
	while(i<4)
	{
		int j=1;
		while(j<4)
		{
			if(str1[j-1]>str1[j])
			{
				int temp=str1[j];
				str1[j]=str1[j-1];
				str1[j-1]=temp;
			}
			j++;
		}
		i++;
	}
	printf("%s",str1);
}

void case_change()
{
	char str1[100];
	printf("Enter str1");
	//fgets(str1,100,stdin);
	int i=0;
	while(str1[i]!='\n')
	{
		if(str1[i]!=' ')
		{
			int diff=str1[i]-'A';
			if(diff>26)
				str1[i]='A'+(diff-32);
			else
				str1[i]='a'+diff;
		}

		i++;
	}
	printf("%s",str1);
}

void remove_chars()
{
	char str1[100];
	printf("Enter str1");
	//fgets(str1,100,stdin);
	int j=0,i=0;
	while(str1[j]!='\0')
	{
		if((str1[j]>=65 && str1[j]<=91)||(str1[j]>=97 && str1[j]<=123))
		{
			str1[i]=str1[j];
			i++;
		}
		j++;
	}
	while(i<j)
	{
		str1[i]='\0';
		i++;
	}
	printf("%s",str1);
}

void occ_count()
{
		char str1[100], str2[100];

	    printf("Enter str1: ");
	    //fgets(str1, 10, stdin);

	    printf("Enter str2: ");
	    //fgets(str2, 10, stdin);

	    int len1 = 0, len2 = 0;

	    while(str1[len1] != '\n' && str1[len1] != '\0')
	        len1++;

	    while(str2[len2] != '\n' && str2[len2] != '\0')
	        len2++;

	    int i = 0, j = 0, occ = 0;

	    while(i <= len1 - len2)
	    {
	        j = 0;

	        while(str1[i + j] == str2[j])
	        {
	            j++;

	            if(j == len2)
	            {
	                occ++;
	                break;
	            }
	        }

	        i++;
	    }

	    printf("Occurrences = %d", occ);

	    return 0;
}

void encrypt_decrypt()
{
	char str1[10];
	printf("Enter str1");
	//fgets(str1,10,stdin);
	int key;
	printf("Enter key");
	scanf("%d",&key);
	int i=0;
	while(str1[i]!='\n'){
		str1[i]=str1[i]+key;
		i++;
	}
	printf("%s",str1);
}

void balanced_expression()
{
	char str[100];
	printf("Enter any expression string");
	//fgets(str,100,stdin);
	int i=0,count_p=0,count_s=0,count_c=0;
	while(str[i]!='\n')
	{
		if(str[i]=='{') count_c++;
		if(str[i]=='}') count_c--;
		if(str[i]=='[') count_s++;
		if(str[i]==']') count_s--;
		if(str[i]=='(') count_p++;
		if(str[i]==')') count_p--;
		i++;
	}
	if((!count_p)&&(!count_c)&&(!count_s))
		printf("Balanced");
	else
		printf("Not balanced");
}

void removeDuplicates(char str[])
{
    int i, j;
    int changed = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == str[i + 1])
        {
            changed = 1;

            // find end of duplicate group
            j = i;

            while(str[j] == str[i])
                j++;

            // shift remaining string left
            int k = i;

            while(str[j] != '\0')
            {
                str[k] = str[j];
                k++;
                j++;
            }

            str[k] = '\0';

            // start again recursively
            removeDuplicates(str);
            return;
        }
    }
}

void check()
{
    char str[100];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int left = 0;
    int right = strlen(str) - 1;

    while(left < right)
    {
        if(str[left] != str[right])
        {
            int i, j;

            // remove left character
            i = left + 1;
            j = right;

            while(i < j && str[i] == str[j])
            {
                i++;
                j--;
            }

            if(i >= j)
            {
                printf("Yes");
                return;
            }

            // remove right character
            i = left;
            j = right - 1;

            while(i < j && str[i] == str[j])
            {
                i++;
                j--;
            }

            if(i >= j)
            {
                printf("Yes");
                return;
            }

            printf("No");
            return;
        }

        left++;
        right--;
    }

    printf("Yes");
}

void vowels()
{
    char str[100];

    int a = 0, e = 0, i = 0, o = 0, u = 0;

    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Vowels: ");

    for(int j = 0; str[j] != '\0'; j++)
    {
        if(str[j] == 'a' || str[j] == 'A')
        {
            printf("a(%d) ", j);
            a++;
        }

        else if(str[j] == 'e' || str[j] == 'E')
        {
            printf("e(%d) ", j);
            e++;
        }

        else if(str[j] == 'i' || str[j] == 'I')
        {
            printf("i(%d) ", j);
            i++;
        }

        else if(str[j] == 'o' || str[j] == 'O')
        {
            printf("o(%d) ", j);
            o++;
        }

        else if(str[j] == 'u' || str[j] == 'U')
        {
            printf("u(%d) ", j);
            u++;
        }
    }

    printf("\n");

    printf("Counts: ");
    printf("a=%d ", a);
    printf("e=%d ", e);
    printf("i=%d ", i);
    printf("o=%d ", o);
    printf("u=%d ", u);
}

void replaceChars()
{
    char str[100];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    // lookup table
    char oldChars[] = {'a', 'e', 'i', 'o', 'u'};
    char newChars[] = {'@', '3', '1', '0', '_'};

    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(str[i] == oldChars[j])
            {
                str[i] = newChars[j];
                break;
            }
        }
    }

    printf("Modified string: %s", str);
}

void base64()
{
    char str[100];

    char table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    printf("Base64 Encoded: ");

    for(int i = 0; i < len; i += 3)
    {
        int value = 0;
        int count = 0;

        // combine up to 3 characters into 24 bits
        for(int j = 0; j < 3; j++)
        {
            value <<= 8;

            if(i + j < len)
            {
                value |= str[i + j];
                count++;
            }
        }

        // extract 4 groups of 6 bits
        for(int j = 0; j < 4; j++)
        {
            if(j <= count)
            {
                int index = (value >> (18 - 6 * j)) & 63;
                printf("%c", table[index]);
            }
            else
            {
                printf("=");
            }
        }
    }
}

int mystrcmp(char str1[], char str2[])
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return 1;

        i++;
    }

    if(str1[i] == str2[i])
        return 0;

    return 1;
}

void palindrome()
{
    char str[100], rev[100];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    int j = 0;

    for(int i = len - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }

    rev[j] = '\0';

    if(mystrcmp(str, rev) == 0)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}


void mystrrchr()
{
    char str[100], ch;
    int lastIndex = -1;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character: ");
    scanf("%c", &ch);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        {
            lastIndex = i;
        }
    }

    if(lastIndex == -1)
        printf("Character not found");
    else
        printf("Last occurrence index = %d", lastIndex);
}

int my_strchr(char str[], char ch)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
            return i;
    }
    return -1;
}

/* ---------------- my strstr ---------------- */
int my_strstr(char str[], char sub[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;

        while(str[i + j] == sub[j] && sub[j] != '\0')
            j++;

        if(sub[j] == '\0')
            return i;
    }

    return -1;
}

/* ---------------- my atoi ---------------- */
int my_atoi(char str[])
{
    int i = 0, num = 0, sign = 1;

    if(str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    while(str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num * sign;
}

/* ---------------- my itoa ---------------- */
void my_itoa(int num, char str[])
{
    int i = 0, sign = 0;

    if(num < 0)
    {
        sign = 1;
        num = -num;
    }

    do
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    while(num > 0);

    if(sign)
        str[i++] = '-';

    str[i] = '\0';

    // reverse string
    int start = 0, end = i - 1;

    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/* ---------------- my strcat ---------------- */
void my_strcat(char dest[], char src[])
{
    int i = 0, j = 0;

    while(dest[i] != '\0')
        i++;

    while(src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

int match(char s1[], char s2[], int i)
{
    int j = 0;

    while(s2[j] != '\0' && s1[i + j] == s2[j])
        j++;

    return (s2[j] == '\0');
}

/* get length */
int length(char str[])
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

/* reverse string */
void reverse(char src[], char rev[])
{
    int len = length(src);

    for(int i = 0; i < len; i++)
        rev[i] = src[len - i - 1];

    rev[len] = '\0';
}

/* remove all occurrences of s2 */
void removeAll(char s1[], char s2[])
{
    char res[200];
    int i = 0, k = 0;

    while(s1[i] != '\0')
    {
        if(match(s1, s2, i))
        {
            i += length(s2);   // skip substring
        }
        else
        {
            res[k++] = s1[i++];
        }
    }

    res[k] = '\0';

    printf("\nAfter Removal: %s", res);
}

/* hide all occurrences */
void hideAll(char s1[], char s2[])
{
    char res[200];
    int i = 0, k = 0;
    int len2 = length(s2);

    while(s1[i] != '\0')
    {
        if(match(s1, s2, i))
        {
            for(int j = 0; j < len2; j++)
                res[k++] = '*';

            i += len2;
        }
        else
        {
            res[k++] = s1[i++];
        }
    }

    res[k] = '\0';

    printf("\nAfter Hiding: %s", res);
}

/* replace s2 with reverse(s2) */
void replaceWithReverse(char s1[], char s2[])
{
    char res[200], rev[100];
    int i = 0, k = 0;

    reverse(s2, rev);

    int len2 = length(s2);

    while(s1[i] != '\0')
    {
        if(match(s1, s2, i))
        {
            for(int j = 0; j < len2; j++)
                res[k++] = rev[j];

            i += len2;
        }
        else
        {
            res[k++] = s1[i++];
        }
    }

    res[k] = '\0';

    printf("\nAfter Reverse Replace: %s", res);
}

void countWords()
{
    char str[200];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    int i = 0, words = 0, inWord = 0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\n')
        {
            if(inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }

        i++;
    }

    printf("Number of words = %d", words);
}

