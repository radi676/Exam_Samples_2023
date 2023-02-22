#pragma once
const long long BOUND = 10e9;
const int LOWER_BOUND = 2;
const int UPPER_BOUND = 49;
const int LOWER_BOUND_ASCII = 32;
const int UPPER_BOUND_ASCII = 126;

size_t getArrLen(const char* arr)
{
	size_t iter = 0;
	while (arr[iter++] != '\0');
	return iter - 1;
}
long reverse(long N)
{
	long newN = 0;
	while (N > 0)
	{
		newN = newN * 10 + N % 10;
		N /= 10;
	}
	return newN;
}
size_t getNumLen(long N)
{
	size_t len = 0;
	while (N > 0)
	{
		len++;
		N /= 10;
	}
	return len;
}

int analyzeArr(char* arr)
{
	if (arr == nullptr)
	{
		return -1;
	}

	size_t counterRepeatedChars = 0;
	size_t iter = 0;
	size_t len = getArrLen(arr);
	for (size_t i = 0; i < len; i++)
	{
		bool foundDubblicate = false;
		for (size_t j = 0; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				if (j < i)
				{
					foundDubblicate = true;
					break;
				}
				else if (j > i)
				{
					foundDubblicate = true;
				}
				counterRepeatedChars++;
			}
		}
		if (!foundDubblicate)
		{
			counterRepeatedChars--;
		}
	}
	return len - counterRepeatedChars;
}

int checkNum(long N)
{
	if (N > BOUND)
	{
		return -1;
	}

	size_t len = getNumLen(N);
	for (size_t i = 1; i <= len; i++)
	{
		long newNum = 0;
		size_t counter = len;
		long copy = N;
		while (copy > 0)
		{
			if (counter != i)
			{
				newNum = newNum * 10 + (copy - (copy / 10) * 10);
			}
			copy /= 10;
			counter--;
		}
		long newN = reverse(newNum);
		if (newN - (newN / 3) * 3 == 0)
		{
			return i;
		}
	}
	return 0;
}

char* encodeWord(char* str, int N)
{
	if (str == nullptr)
	{
		return nullptr;
	}
	if (N<LOWER_BOUND || N>UPPER_BOUND)
	{
		return nullptr;
	}
	char* newStr = new char[getArrLen(str) + 1];
	size_t iter = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] > LOWER_BOUND_ASCII || str[iter] < UPPER_BOUND)
		{
			return 0;
		}
		newStr[iter] = str[iter] + N;
		iter++;
	}

	return newStr;
}
