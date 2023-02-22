#pragma once

const long long BOUND = 10e9;
const char POINT = '.';
const char UPPER_BOUND_DIGIT = '9';
const char LOWER_BOUND_DIGIT = '0';
const char DIGIT_TO_CHAR = '0';

int getNumLen(long N)
{
	if (N == 0)
	{
		return 0;
	}

	return 1 + getNumLen(N / 10);
}

int reverse(long num)
{
	long result = 0;
	while (num > 0)
	{
		result = result * 10 + num - (num / 10) * 10;
		num /= 10;
	}
	return result;
}


int getStrLen(const char* str)
{
	int iter = 0;
	while (str[iter++] != '\0');
	return iter - 1;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* arr, size_t len)
{
	for (size_t i = 0; i < len - 1; i++)
	{
		size_t minIndex = i;
		for (size_t j = i; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}
}

void squareArr(int* arr, size_t len)
{
	if (len <= 0)
	{
		return;
	}
	if (arr == nullptr)
	{
		return;
	}

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = arr[i] * arr[i];
	}
	selectionSort(arr, len);
}

int checkNum(long N, unsigned int m, unsigned int l)
{
	if (N > BOUND)//
	{
		return -1;
	}
	if (N < 0)
	{
		N *= -1;
	}

	int len = getNumLen(N);
	if (m < 1 || l < 1 || m<len || l>len)
	{
		return -1;
	}


	long copy = N;
	int currentIndex = len;
	while (currentIndex != m)
	{
		copy /= 10;
		currentIndex++;
	}
	int mDigit = copy - (copy / 10) * 10;

	currentIndex = len;
	copy = N;
	while (currentIndex != l)
	{
		copy /= 10;
		currentIndex--;
	}
	int lDigit = copy - (copy / 10) * 10;

	long newNum = 0;
	copy = N;
	long counter = len;

	while (copy > 0)
	{
		if (currentIndex == m)
		{
			newNum = newNum * 10 + lDigit;
		}
		else if (currentIndex == l)
		{
			newNum = newNum * 10 + mDigit;
		}
		else
		{
			newNum = newNum + (copy / 10) * 10;
		}
		copy /= 10;
		counter--;
	}

	long reversed = reverse(newNum);
	return reversed - (reversed / 4) * 4;
}

bool isDigit(char symbol)
{
	return symbol >= LOWER_BOUND_DIGIT && symbol < +UPPER_BOUND_DIGIT;
}

int checkDate(char* input)
{
	if (input == nullptr)
	{
		return -1;
	}
	int strLen = getStrLen(input);
	if (!(strLen > 0
		|| strLen <= 10)
		&& input[2] == POINT
		&& input[5] == POINT
		&& isDigit(input[0])
		&& isDigit(input[1])
		&& isDigit(input[3])
		&& isDigit(input[4])
		&& isDigit(input[6])
		&& isDigit(input[7])
		&& isDigit(input[8])
		&& isDigit(input[9]))
	{
		return 0;
	}

	int year = (input[6] - DIGIT_TO_CHAR) * 1000 + (input[7] - DIGIT_TO_CHAR) * 100 + (input[8] - DIGIT_TO_CHAR) * 10 + input[9] - DIGIT_TO_CHAR;
	int day = (input[0] - DIGIT_TO_CHAR) * 10 + input[1] - DIGIT_TO_CHAR;
	int month = (input[3] - DIGIT_TO_CHAR) * 10 + input[4] - DIGIT_TO_CHAR;
	if (day < 1 || month < 1 || month>12)
	{
		return 0;
	}
	if (month == 2) {
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return day < 29;
		}
		else
		{
			return day < 28;
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return day <= 31;
	}
	return day <= 30;
}


