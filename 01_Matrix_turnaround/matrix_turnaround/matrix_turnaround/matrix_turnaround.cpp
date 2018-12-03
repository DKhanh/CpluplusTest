#include <stdio.h>
#include <string.h>



void print_matrix(int *matrix, int height, int width)
{
	int w, h = 0;
	
	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
		{
			if (matrix[h*width + w] <= 9)
				printf("%d   ", matrix[h*width + w]);
			else if (matrix[h*width + w] <= 99)
				printf("%d  ", matrix[h*width + w]);
			else if (matrix[h*width + w] <= 990)
				printf("%d ", matrix[h*width + w]);
		}
		printf("\n");
	}
}

void swap_number(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void matrix_turnaround(int *matrix, int _width, int _height)
{
	int width, height = 0;
	int w, h, index = 0;
	int tmp[4] = { 0 };

	width  = _width;
	height = _height;

	int *tmp_matrix = new int[_width*_height];

	memset(tmp_matrix, 0, sizeof(int) * width * height);

	while ((index <= (height/2 - 1)) || (index <= (width/2 - 1)))
	{
		for (h = index; h < height - index; h++)
		{
			for (w = index; w < width - index; w++)
			{
				if (h == index)
				{
					if (w == index)
						tmp_matrix[h*width + w] = matrix[(h + 1)*width + w];
					else if (w == width - index - 1)
						tmp_matrix[h*width + w] = matrix[h*width + (w - 1)];
					else
						tmp_matrix[h*width + w] = matrix[h*width + (w - 1)];
				}
				else if (w == index)
				{
					if (h == index)
						tmp_matrix[h*width + w] = matrix[(h + 1)*width + w];
					else if (h == height - index - 1)
						tmp_matrix[h*width + w] = matrix[h*width + (w + 1)];
					else
						tmp_matrix[h*width + w] = matrix[(h + 1)*width + w];
				}
				else if (h == height - index - 1)
				{
					if (w == index)
						tmp_matrix[h*width + w] = matrix[h*width + (w + 1)];
					else if (w == width - index - 1)
						tmp_matrix[h*width + w] = matrix[(h - 1)*width + w];
					else
						tmp_matrix[h*width + w] = matrix[h*width + (w + 1)];
				}
				else if (w == width - index - 1)
				{
					if (h == index)
						tmp_matrix[h*width + w] = matrix[h*width + (w - 1)];
					else if (h == height - index - 1)
						tmp_matrix[h*width + w] = matrix[(h - 1)*width + w];
					else
						tmp_matrix[h*width + w] = matrix[(h - 1)*width + w];
				}
			}
		}

		index++;
	}

	print_matrix(tmp_matrix, _height, _width);
	delete tmp_matrix;
}

int main(void)
{

	int matrixA[4*4] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};

	int matrixB[6 * 6] = {
		1,	2,	3,	4,	5,	6,
		7,	8,	9,	10,	11,	12,
		13,	14,	15,	16,	17,	18,
		19,	20,	21,	22,	23,	24,
		25,	26,	27,	28,	29,	30,
		31,	32,	33,	34,	35,	36
	};

	//print_matrix(matrixA, 4, 4);

	matrix_turnaround(matrixB, 6, 6);

	while (1);

	return 0;
}