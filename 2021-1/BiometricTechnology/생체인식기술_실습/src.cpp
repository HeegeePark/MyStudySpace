#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

// 2���� �迭 �����Ҵ� ����
unsigned char** imageMatrix;
// �������󿡼� 
unsigned char blankPixel = 255, imagePixel = 0;

typedef struct {
	int row, col;
}pixel;

int getBlackNeighbours(int row, int col) {

	int i, j, sum = 0;

	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (i != 0 || j != 0)
				sum += (imageMatrix[row + i][col + j] == imagePixel);
		}
	}

	return sum;
}

int getBWTransitions(int row, int col) {
	return 	((imageMatrix[row - 1][col] == blankPixel && imageMatrix[row - 1][col + 1] == imagePixel)
		+ (imageMatrix[row - 1][col + 1] == blankPixel && imageMatrix[row][col + 1] == imagePixel)
		+ (imageMatrix[row][col + 1] == blankPixel && imageMatrix[row + 1][col + 1] == imagePixel)
		+ (imageMatrix[row + 1][col + 1] == blankPixel && imageMatrix[row + 1][col] == imagePixel)
		+ (imageMatrix[row + 1][col] == blankPixel && imageMatrix[row + 1][col - 1] == imagePixel)
		+ (imageMatrix[row + 1][col - 1] == blankPixel && imageMatrix[row][col - 1] == imagePixel)
		+ (imageMatrix[row][col - 1] == blankPixel && imageMatrix[row - 1][col - 1] == imagePixel)
		+ (imageMatrix[row - 1][col - 1] == blankPixel && imageMatrix[row - 1][col] == imagePixel));
}

int zhangSuenTest1(int row, int col) {
	int neighbours = getBlackNeighbours(row, col);

	return ((neighbours >= 2 && neighbours <= 6)
		&& (getBWTransitions(row, col) == 1)
		&& (imageMatrix[row - 1][col] == blankPixel || imageMatrix[row][col + 1] == blankPixel || imageMatrix[row + 1][col] == blankPixel)
		&& (imageMatrix[row][col + 1] == blankPixel || imageMatrix[row + 1][col] == blankPixel || imageMatrix[row][col - 1] == blankPixel));
}

int zhangSuenTest2(int row, int col) {
	int neighbours = getBlackNeighbours(row, col);

	return ((neighbours >= 2 && neighbours <= 6)
		&& (getBWTransitions(row, col) == 1)
		&& (imageMatrix[row - 1][col] == blankPixel || imageMatrix[row][col + 1] == blankPixel || imageMatrix[row][col - 1] == blankPixel)
		&& (imageMatrix[row - 1][col] == blankPixel || imageMatrix[row + 1][col] == blankPixel || imageMatrix[row][col + 1] == blankPixel));
}

void zhangSuen(unsigned char* image, unsigned char* output, int rows, int cols) {

	int startRow = 1, startCol = 1, endRow, endCol, i, j, count, processed;

	pixel* markers;

	imageMatrix = (unsigned char**)malloc(rows * sizeof(unsigned char*));

	for (i = 0; i < rows; i++) {
		imageMatrix[i] = (unsigned char*)malloc((cols + 1) * sizeof(unsigned char));
		for (int k = 0; k < cols; k++) imageMatrix[i][k] = image[i * cols + k];
	}

	endRow = rows - 2;
	endCol = cols - 2;
	do {
		markers = (pixel*)malloc((endRow - startRow + 1) * (endCol - startCol + 1) * sizeof(pixel));
		count = 0;

		for (i = startRow; i <= endRow; i++) {
			for (j = startCol; j <= endCol; j++) {
				if (imageMatrix[i][j] == imagePixel && zhangSuenTest1(i, j) == 1) {
					markers[count].row = i;
					markers[count].col = j;
					count++;
				}
			}
		}

		processed = (count > 0);

		for (i = 0; i < count; i++) {
			imageMatrix[markers[i].row][markers[i].col] = blankPixel;
		}

		free(markers);
		markers = (pixel*)malloc((endRow - startRow + 1) * (endCol - startCol + 1) * sizeof(pixel));
		count = 0;

		for (i = startRow; i <= endRow; i++) {
			for (j = startCol; j <= endCol; j++) {
				if (imageMatrix[i][j] == imagePixel && zhangSuenTest2(i, j) == 1) {
					markers[count].row = i;
					markers[count].col = j;
					count++;
				}
			}
		}

		if (processed == 0)
			processed = (count > 0);

		for (i = 0; i < count; i++) {
			imageMatrix[markers[i].row][markers[i].col] = blankPixel;
		}

		free(markers);
	} while (processed == 1);


	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			output[i * cols + j] = imageMatrix[i][j];
		}
	}
}

void InverseImage(BYTE* Img, BYTE* Out, int W, int H)
{
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		Out[i] = 255 - Img[i];
	}
}
void BrightnessAdj(BYTE* Img, BYTE* Out, int W, int H, int Val)
{
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		if (Img[i] + Val > 255)
		{
			Out[i] = 255;
		}
		else if (Img[i] + Val < 0)
		{
			Out[i] = 0;
		}
		else 	Out[i] = Img[i] + Val;
	}
}
void ContrastAdj(BYTE* Img, BYTE* Out, int W, int H, double Val)
{
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		if (Img[i] * Val > 255.0)
		{
			Out[i] = 255;
		}
		else 	Out[i] = (BYTE)(Img[i] * Val);
	}
}

void ObtainHistogram(BYTE* Img, int* Histo, int W, int H)
{
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++) {
		Histo[Img[i]]++;
	}
}

void ObtainAHistogram(int* Histo, int* AHisto)
{
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j <= i; j++) {
			AHisto[i] += Histo[j];
		}
	}
}

void HistogramStretching(BYTE* Img, BYTE* Out, int* Histo, int W, int H)
{
	int ImgSize = W * H;
	BYTE Low, High;
	for (int i = 0; i < 256; i++) {
		if (Histo[i] != 0) {
			Low = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--) {
		if (Histo[i] != 0) {
			High = i;
			break;
		}
	}
	for (int i = 0; i < ImgSize; i++) {
		Out[i] = (BYTE)((Img[i] - Low) / (double)(High - Low) * 255.0);
	}
}
void HistogramEqualization(BYTE* Img, BYTE* Out, int* AHisto, int W, int H)
{
	int ImgSize = W * H;
	int Nt = W * H, Gmax = 255;
	double Ratio = Gmax / (double)Nt;
	BYTE NormSum[256];
	for (int i = 0; i < 256; i++) {
		NormSum[i] = (BYTE)(Ratio * AHisto[i]);
	}
	for (int i = 0; i < ImgSize; i++)
	{
		Out[i] = NormSum[Img[i]];
	}
}

void Binarization(BYTE* Img, BYTE* Out, int W, int H, BYTE Threshold)
{
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++) {
		if (Img[i] < Threshold) Out[i] = 0;
		else Out[i] = 255;
	}
}

//int GozalezBinThresh()
//{
//
//}

void AverageConv(BYTE* Img, BYTE* Out, int W, int H) // �ڽ���Ȱȭ
{
	double Kernel[3][3] = { 0.11111, 0.11111, 0.11111,
										0.11111, 0.11111, 0.11111,
										0.11111, 0.11111, 0.11111 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			Out[i * W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}

void GaussAvrConv(BYTE* Img, BYTE* Out, int W, int H) // ����þ���Ȱȭ
{
	double Kernel[3][3] = { 0.0625, 0.125, 0.0625,
										0.125, 0.25, 0.125,
										0.0625, 0.125, 0.0625 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			Out[i * W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}

void Prewitt_X_Conv(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, 0.0, 1.0,
										-1.0, 0.0, 1.0,
										-1.0, 0.0, 1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			// 0 ~ 765  =====> 0 ~ 255
			Out[i * W + j] = abs((long)SumProduct) / 3;
			SumProduct = 0.0;
		}
	}
}

void Prewitt_Y_Conv(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, -1.0, -1.0,
										0.0, 0.0, 0.0,
										1.0, 1.0, 1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			// 0 ~ 765  =====> 0 ~ 255
			Out[i * W + j] = abs((long)SumProduct) / 3;
			SumProduct = 0.0;
		}
	}
}

void Sobel_X_Conv(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, 0.0, 1.0,
										-2.0, 0.0, 2.0,
										-1.0, 0.0, 1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			// 0 ~ 1020  =====> 0 ~ 255
			Out[i * W + j] = abs((long)SumProduct) / 4;
			SumProduct = 0.0;
		}
	}
}

void Sobel_Y_Conv(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, -2.0, -1.0,
										0.0, 0.0, 0.0,
										1.0, 2.0, 1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			// 0 ~ 765  =====> 0 ~ 255
			Out[i * W + j] = abs((long)SumProduct) / 4;
			SumProduct = 0.0;
		}
	}
}

void Laplace_Conv(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, -1.0, -1.0,
										-1.0, 8.0, -1.0,
										-1.0, -1.0, -1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			// 0 ~ 2040  =====> 0 ~ 255
			Out[i * W + j] = abs((long)SumProduct) / 8;
			SumProduct = 0.0;
		}
	}
}

void Laplace_Conv_DC(BYTE* Img, BYTE* Out, int W, int H) // Prewitt ����ũ X
{
	double Kernel[3][3] = { -1.0, -1.0, -1.0,
										-1.0, 9.0, -1.0,
										-1.0, -1.0, -1.0 };
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) { // Y��ǥ (��)
		for (int j = 1; j < W - 1; j++) { // X��ǥ (��)
			for (int m = -1; m <= 1; m++) { // Kernel ��
				for (int n = -1; n <= 1; n++) { // Kernel ��
					SumProduct += Img[(i + m) * W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			//Out[i * W + j] = abs((long)SumProduct) / 8;
			if (SumProduct > 255.0) Out[i * W + j] = 255;
			else if (SumProduct < 0.0) Out[i * W + j] = 0;
			else Out[i * W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}

void SaveBMPFile(BITMAPFILEHEADER hf, BITMAPINFOHEADER hInfo,
	RGBQUAD* hRGB, BYTE* Output, int W, int H, const char* FileName)
{
	FILE* fp = fopen(FileName, "wb");
	if (hInfo.biBitCount == 24) {
		fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
		fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
		fwrite(Output, sizeof(BYTE), W * H * 3, fp);
	}
	else if (hInfo.biBitCount == 8) {
		fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
		fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
		fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
		fwrite(Output, sizeof(BYTE), W * H, fp);
	}
	fclose(fp);
}

void swap(BYTE* a, BYTE* b)
{
	BYTE temp = *a;
	*a = *b;
	*b = temp;
}

BYTE Median(BYTE* arr, int size)
{
	// �������� ����
	const int S = size;
	for (int i = 0; i < size - 1; i++) // pivot index
	{
		for (int j = i + 1; j < size; j++) // �񱳴�� index
		{
			if (arr[i] > arr[j]) 	swap(&arr[i], &arr[j]);
		}
	}
	return arr[S / 2];
}

BYTE MaxPooling(BYTE* arr, int size)
{
	// �������� ����
	const int S = size;
	for (int i = 0; i < size - 1; i++) // pivot index
	{
		for (int j = i + 1; j < size; j++) // �񱳴�� index
		{
			if (arr[i] > arr[j]) 	swap(&arr[i], &arr[j]);
		}
	}
	return arr[S - 1];
}

BYTE MinPooling(BYTE* arr, int size)
{
	// �������� ����
	const int S = size;
	for (int i = 0; i < size - 1; i++) // pivot index
	{
		for (int j = i + 1; j < size; j++) // �񱳴�� index
		{
			if (arr[i] > arr[j]) 	swap(&arr[i], &arr[j]);
		}
	}
	return arr[0];
}

int push(short* stackx, short* stacky, int arr_size, short vx, short vy, int* top)
{
	if (*top >= arr_size) return(-1);
	(*top)++;
	stackx[*top] = vx;
	stacky[*top] = vy;
	return(1);
}

int pop(short* stackx, short* stacky, short* vx, short* vy, int* top)
{
	if (*top == 0) return(-1);
	*vx = stackx[*top];
	*vy = stacky[*top];
	(*top)--;
	return(1);
}


// GlassFire �˰����� �̿��� �󺧸� �Լ�
void m_BlobColoring(BYTE* CutImage, int height, int width)
{
	int i, j, m, n, top, area, Out_Area, index, BlobArea[1000];
	long k;
	short curColor = 0, r, c;
	//	BYTE** CutImage2;
	Out_Area = 1;

	// �������� ����� �޸� �Ҵ�
	short* stackx = new short[height * width];
	short* stacky = new short[height * width];
	short* coloring = new short[height * width];

	int arr_size = height * width;

	// �󺧸��� �ȼ��� �����ϱ� ���� �޸� �Ҵ�

	for (k = 0; k < height * width; k++) coloring[k] = 0;  // �޸� �ʱ�ȭ

	for (i = 0; i < height; i++)
	{
		index = i * width;
		for (j = 0; j < width; j++)
		{
			// �̹� �湮�� ���̰ų� �ȼ����� 255�� �ƴ϶�� ó�� ����
			if (coloring[index + j] != 0 || CutImage[index + j] != 255) continue;
			r = i; c = j; top = 0; area = 1;
			curColor++;

			while (1)
			{
			GRASSFIRE:
				for (m = r - 1; m <= r + 1; m++)
				{
					index = m * width;
					for (n = c - 1; n <= c + 1; n++)
					{
						//���� �ȼ��� �����踦 ����� ó�� ����
						if (m < 0 || m >= height || n < 0 || n >= width) continue;

						if ((int)CutImage[index + n] == 255 && coloring[index + n] == 0)
						{
							coloring[index + n] = curColor; // ���� �󺧷� ��ũ
							if (push(stackx, stacky, arr_size, (short)m, (short)n, &top) == -1) continue;
							r = m; c = n; area++;
							goto GRASSFIRE;
						}
					}
				}
				if (pop(stackx, stacky, &r, &c, &top) == -1) break;
			}
			if (curColor < 1000) BlobArea[curColor] = area;
		}
	}

	float grayGap = 255.0f / (float)curColor;

	// ���� ������ ���� ������ ã�Ƴ��� ���� 
	for (i = 1; i <= curColor; i++)
	{
		if (BlobArea[i] >= BlobArea[Out_Area]) Out_Area = i;
	}
	// CutImage �迭 Ŭ����~
	for (k = 0; k < width * height; k++) CutImage[k] = 255;

	// coloring�� ����� �󺧸� ����� (Out_Area�� �����) ������ ���� ū �͸� CutImage�� ����
	/*
	for (k = 0; k < width * height; k++)
	{
		if (coloring[k] == Out_Area) CutImage[k] = 0;  // ���� ū �͸� ���� (size filtering)
		//if (BlobArea[coloring[k]] > 500) CutImage[k] = 0;  // Ư�� �����̻�Ǵ� ������ ���
		//CutImage[k] = (unsigned char)(coloring[k] * grayGap);
	}
	*/

	// coloring�� ����� �󺧸� ����� (Out_Area�� �����) ������ ���� ũ�� �̻��� �͸� CutImage�� ����
	for (k = 0; k < width * height; k++)
	{
		if (BlobArea[coloring[k]] > 50) CutImage[k] = 0;  // ���� ū �͸� ���� (size filtering)
		//if (BlobArea[coloring[k]] > 500) CutImage[k] = 0;  // Ư�� �����̻�Ǵ� ������ ���
		//CutImage[k] = (unsigned char)(coloring[k] * grayGap);
	}

	delete[] coloring;
	delete[] stackx;
	delete[] stacky;
}
// �󺧸� �� ���� ���� ������ ���ؼ��� �̾Ƴ��� �ڵ� ����

void BinaryImageEdgeDetection(BYTE* Bin, BYTE* Out, int W, int H)
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (Bin[i * W + j] == 0) // ����ȭ�Ҷ��
			{
				if (!(Bin[(i - 1) * W + j] == 0 && Bin[(i + 1) * W + j] == 0 &&
					Bin[i * W + j - 1] == 0 && Bin[i * W + j + 1] == 0)) // 4���� ȭ�� �� �ϳ��� ������ �ƴ϶��
					Out[i * W + j] = 255;
			}
		}
	}
}

BYTE DetermThGonzalez(int* H)
{
	BYTE ep = 3;
	BYTE Low, High;
	BYTE Th, NewTh;
	int G1 = 0, G2 = 0, cnt1 = 0, cnt2 = 0, mu1, mu2;

	for (int i = 0; i < 256; i++) {
		if (H[i] != 0) {
			Low = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--) {
		if (H[i] != 0) {
			High = i;
			break;
		}
	}

	Th = (Low + High) / 2;

	//printf("%d\n", Th);
	while (1)
	{
		for (int i = Th + 1; i <= High; i++) {
			G1 += (H[i] * i);
			cnt1 += H[i];
		}
		for (int i = Low; i <= Th; i++) {
			G2 += (H[i] * i);
			cnt2 += H[i];
		}
		if (cnt1 == 0) cnt1 = 1;
		if (cnt2 == 0) cnt2 = 1;

		mu1 = G1 / cnt1;
		mu2 = G2 / cnt2;

		NewTh = (mu1 + mu2) / 2;

		if (abs(NewTh - Th) < ep)
		{
			Th = NewTh;
			break;
		}
		else
		{
			Th = NewTh;
		}
		G1 = G2 = cnt1 = cnt2 = 0;
		//printf("%d\n", Th);
	}
	return Th;
}

void VerticalFlip(BYTE* Img, int W, int H)
{
	for (int i = 0; i < H / 2; i++) { // y��ǥ
		for (int j = 0; j < W; j++) { // x��ǥ
			swap(&Img[i * W + j], &Img[(H - 1 - i) * W + j]);
		}
	}
}

void HorizontalFlip(BYTE* Img, int W, int H)
{
	for (int i = 0; i < W / 2; i++) { // x��ǥ
		for (int j = 0; j < H; j++) { // y��ǥ
			swap(&Img[j * W + i], &Img[j * W + (W - 1 - i)]);
		}
	}
}

void Translation(BYTE* Image, BYTE* Output, int W, int H, int Tx, int Ty)
{
	// Translation
	Ty *= -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((i + Ty < H && i + Ty >= 0) && (j + Tx < W && j + Tx >= 0))
				Output[(i + Ty) * W + (j + Tx)] = Image[i * W + j];
		}
	}
}

void Scaling(BYTE* Image, BYTE* Output, int W, int H, double SF_X, double SF_Y)
{
	// Scaling
	int tmpX, tmpY;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			tmpX = (int)(j / SF_X);
			tmpY = (int)(i / SF_Y);
			if (tmpY < H && tmpX < W)
				Output[i * W + j] = Image[tmpY * W + tmpX];
		}
	}

}

void Rotation(BYTE* Image, BYTE* Output, int W, int H, int Angle)
{
	int tmpX, tmpY;
	double Radian = Angle * 3.141592 / 180.0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			tmpX = (int)(cos(Radian) * j + sin(Radian) * i);
			tmpY = (int)(-sin(Radian) * j + cos(Radian) * i);
			if ((tmpY < H && tmpY >= 0) && (tmpX < W && tmpX >= 0))
				Output[i * W + j] = Image[tmpY * W + tmpX];
		}
	}
}

void MedianFiltering(BYTE* Image, BYTE* Output, int W, int H, int size)
{
	int Length = size;  // ����ũ�� �� ���� ����
	int Margin = Length / 2;
	int WSize = Length * Length;
	BYTE* temp = (BYTE*)malloc(sizeof(BYTE) * WSize);
	int i, j, m, n;
	for (i = Margin; i < H - Margin; i++) {
		for (j = Margin; j < W - Margin; j++) {
			for (m = -Margin; m <= Margin; m++) {
				for (n = -Margin; n <= Margin; n++) {
					temp[(m + Margin) * Length + (n + Margin)] = Image[(i + m) * W + j + n];
				}
			}
			Output[i * W + j] = Median(temp, WSize);
		}
	}
	free(temp);
}

// Img: �簢���� �׸� �̹����迭, W: ���� ���λ�����, H: ���� ���λ�����,
// LU_X: �簢���� ������� X��ǥ, LU_Y: �簢���� ������� Y��ǥ,
// RD_X: �簢���� �����ϴ� X��ǥ, LU_Y: �簢���� �����ϴ� Y��ǥ.
void DrawRectOutline(BYTE* Img, int W, int H, int LU_X, int LU_Y, int RD_X, int RD_Y)
{
	for (int i = LU_X; i < RD_X; i++) 	Img[LU_Y * W + i] = 255;
	for (int i = LU_X; i < RD_X; i++) 	Img[RD_Y * W + i] = 255;
	for (int i = LU_Y; i < RD_Y; i++) 	Img[i * W + LU_X] = 255;
	for (int i = LU_Y; i < RD_Y; i++) 	Img[i * W + RD_X] = 255;
}

// Img: ����/���� ������ �׸� �̹����迭, W: ���� ���λ�����, H: ���� ���λ�����,
// Cx: ����/���� ������ �����Ǵ� ������ X��ǥ
// Cy: ����/���� ������ �����Ǵ� ������ Y��ǥ
void DrawCrossLine(BYTE* Img, int W, int H, int Cx, int Cy)
{
	for (int i = 0; i < W - 1; i++) // horizontal line
		Img[Cy * W + i] = 255;
	for (int i = 0; i < H - 1; i++) // vertical line
		Img[i * W + Cx] = 255;
}

void Obtain2DCenter(BYTE* Image, int W, int H, int* Cx, int* Cy)
{
	int SumX = 0, SumY = 0;
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (Image[i * W + j] == 0) // ���������̸�
			{
				SumX += j;
				SumY += i;
				cnt++;
			}
		}
	}
	if (cnt == 0) 	cnt = 1;
	*Cx = SumX / cnt;
	*Cy = SumY / cnt;
	//printf("%d    %d\n", Cx, Cy);
}

void Obtain2DBoundingBox(BYTE* Image, int W, int H, int* LUX, int* LUY, int* RDX, int* RDY)
{
	int flag = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (Image[i * W + j] == 0) {
				*LUY = i;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	flag = 0;
	for (int i = H - 1; i >= 0; i--) {
		for (int j = 0; j < W; j++) {
			if (Image[i * W + j] == 0) {
				*RDY = i;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	flag = 0;

	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			if (Image[i * W + j] == 0) {
				*LUX = j;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	flag = 0;
	for (int j = W - 1; j >= 0; j--) {
		for (int i = 0; i < H; i++) {
			if (Image[i * W + j] == 0) {
				*RDX = j;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
}

void FillColor(BYTE* Image, int X, int Y, int W, int H, BYTE R, BYTE G, BYTE B)
{
	Image[Y * W * 3 + X * 3] = B; // Blue ����
	Image[Y * W * 3 + X * 3 + 1] = G; // Green ����
	Image[Y * W * 3 + X * 3 + 2] = R; // Red ����
}

void RGB2YCbCr(BYTE* Image, BYTE* Y, BYTE* Cb, BYTE* Cr, int W, int H)
{
	for (int i = 0; i < H; i++) { // Y��ǥ
		for (int j = 0; j < W; j++) { // X��ǥ
			Y[i * W + j] = (BYTE)(0.299 * Image[i * W * 3 + j * 3 + 2] + 0.587 * Image[i * W * 3 + j * 3 + 1] + 0.114 * Image[i * W * 3 + j * 3]);
			Cb[i * W + j] = (BYTE)(-0.16874 * Image[i * W * 3 + j * 3 + 2] - 0.3313 * Image[i * W * 3 + j * 3 + 1] + 0.5 * Image[i * W * 3 + j * 3] + 128.0);
			Cr[i * W + j] = (BYTE)(0.5 * Image[i * W * 3 + j * 3 + 2] - 0.4187 * Image[i * W * 3 + j * 3 + 1] - 0.0813 * Image[i * W * 3 + j * 3] + 128.0);
		}
	}
}
void Erosion(BYTE* Image, BYTE* Output, int W, int H)
{
	for (int i = 1; i < H - 1; i++) {
		for (int j = 1; j < W - 1; j++) {
			if (Image[i * W + j] == 255) // ����ȭ�Ҷ��
			{
				if (!(Image[(i - 1) * W + j] == 255 &&
					Image[(i + 1) * W + j] == 255 &&
					Image[i * W + j - 1] == 255 &&
					Image[i * W + j + 1] == 255)) // 4�ֺ�ȭ�Ұ� ��� ����ȭ�Ұ� �ƴ϶��
					Output[i * W + j] = 0;
				else Output[i * W + j] = 255;
			}
			else Output[i * W + j] = 0;
		}
	}
}

void Dilation(BYTE* Image, BYTE* Output, int W, int H)
{
	for (int i = 1; i < H - 1; i++) {
		for (int j = 1; j < W - 1; j++) {
			if (Image[i * W + j] == 0) // ���ȭ�Ҷ��
			{
				if (!(Image[(i - 1) * W + j] == 0 &&
					Image[(i + 1) * W + j] == 0 &&
					Image[i * W + j - 1] == 0 &&
					Image[i * W + j + 1] == 0)) // 4�ֺ�ȭ�Ұ� ��� ���ȭ�Ұ� �ƴ϶��
					Output[i * W + j] = 255;
				else Output[i * W + j] = 0;
			}
			else Output[i * W + j] = 255;
		}
	}
}

void FeatureExtractThinImage(BYTE* Image, BYTE* Output, int W, int H, char * FileName)
{
	//for (int i = 0; i < W * H; i++) Output[i] = Image[i];
	int featureCnt = 0;		// Ư¡�� ���� count
	int cnt = 0;		// �ֺ�ȭ�� ���� count
	char FFileName[20] = "Result\\";
	FILE* fp = fopen("temp.txt", "wt");
	strcat(FileName, ".txt");		//1_6.txt
	strcat(FFileName, FileName);		// FFileName = "Result\\1_6.txt"
	FILE* fp2 = fopen(FFileName, "wt");
	for (int i = 3; i < H - 3; i++) {		// y��ǥ 
		for (int j = 3; j < W - 3; j++) {		// x��ǥ 
			if (Image[i * W + j] == 0) { // �ֺ�ȭ�� �ð�������� ���鼭 ��->�� ����Ǹ� cnt++
				if (Image[(i - 1) * W + j - 1] == 0 && Image[(i - 1) * W + j] == 255) cnt++;
				if (Image[(i - 1) * W + j] == 0 && Image[(i - 1) * W + j + 1] == 255) cnt++;
				if (Image[(i - 1) * W + j + 1] == 0 && Image[i  * W + j + 1] == 255) cnt++;
				if (Image[i * W + j + 1] == 0 && Image[(i+1) * W + j + 1] == 255) cnt++;
				if (Image[(i + 1) * W + j + 1] == 0 && Image[(i+1)  * W + j] == 255) cnt++;
				if (Image[(i + 1) * W + j] == 0 && Image[(i + 1) * W + j - 1] == 255) cnt++;
				if (Image[(i + 1) * W + j - 1] == 0 && Image[i  * W + j - 1] == 255) cnt++;
				if (Image[i * W + j - 1] == 0 && Image[(i-1) * W + j - 1] == 255) cnt++;
			}
			if (cnt == 1) // ����
			{
				//printf("e");
				featureCnt++;
				Output[i * W + j] = 128;
				fprintf(fp, "%d\t%d\n", j, i);
			}
			else if (cnt  == 3) // �б���
			{
				//printf("b");
				featureCnt++;
				Output[i * W + j] = 128;
				fprintf(fp, "%d\t%d\n", j, i);
			}
			cnt = 0;
		}
	}
	fclose(fp);
	fp = fopen("temp.txt", "rt");
	int tempX, tempY;
	fprintf(fp2, "%d\n", featureCnt);
	for (int i = 0; i < featureCnt; i++)
	{
		fscanf(fp, "%d\t%d\n", &tempX, &tempY);
		fprintf(fp2, "%d\t%d\n", tempX, tempY);
	}
	
	fclose(fp2);
}
void FileNameGenerator(int SubNo, int ImgNo, char* FileName)
{
	//char SubNum[3]; 
	char ImgNum[2];		// �ι��� �����ؼ� 2 size
	itoa(SubNo, FileName, 10);		// (sub) int -> char
	itoa(ImgNo, ImgNum, 10);		// (img) int -> char
	strcat(FileName, "_");		// 1_
	strcat(FileName, ImgNum);		// 1_6
}

//void DrawFeaturesInImage(BYTE* Image, BYTE* Output, int W, int H, char* FileName) {
//	int featureCnt = 0;	// Ư¡�� ���� 
//	char buffer[20];	//	���� 
//	FILE* fp = NULL;	// ���� ������
//	int** features;		// Ư¡�� ��ǥ�� 
//	bool isFirst = true;
//	int temp_x = 0;
//	int temp_y = 0;
//
//	// 1. Ư¡�� txt ���� �ҷ����� 
//	char FFileName[20] = "Result\\";
//	//FILE* fp = fopen("temp.txt", "rt");
//	strcat(FileName, ".txt");		//1_6.txt
//	strcat(FFileName, FileName);		// FFileName = "Result\\1_6.txt"
//	fp = fopen(FFileName, "rt");
//
//	// 2. �������� ������ Ư¡�� �ڸ��� ȭ�Ұ� 128��
//	int i = 0;
//	while (fscanf(fp, "%s", buffer) != EOF) {
//		if (isFirst) {
//			featureCnt = atoi(buffer);
//			isFirst = false;
//		}
//		else if (i % 2 != 0) {
//			features[i] = (int*)malloc(2 * sizeof(int));
//			temp_x = atoi(buffer);
//			//features[i][0] = temp_x;
//
//		}
//		else {
//			temp_y = atoi(buffer);
//			Image[temp_x][temp_y] = 128;
//			//features[i][1] = temp_y;
//		}
//		i++;
//	}
//	
//	
//	// 2. �������� ������ Ư¡�� �ڸ��� ȭ�Ұ� 128��
//	for (int i = 0; i < H; i++) {		// y��ǥ 
//		for (int j = 0; j < W; j++) {		// x��ǥ 
//			if (Image[i][j] == featu) { // �ֺ�ȭ�� �ð�������� ���鼭 ��->�� ����Ǹ� cnt++
//				
//			}
//		}
//	}
//	
//
//	fclose(fp);
//
//}
int main()
{
	BITMAPFILEHEADER hf; // 14����Ʈ
	BITMAPINFOHEADER hInfo; // 40����Ʈ
	RGBQUAD hRGB[256]; // 1024����Ʈ

	FILE* fp;
	char FileName[20] = "fingerDB\\";
	char temp[20];

	for (int i = 1; i <= 1; i++) {		// Subject No
		if (i >= 41 && i <= 48) continue;
		for (int j = 1; j <= 6; j++) {		// Image No
			FileNameGenerator(i, j, temp);		// temp = "1_6"
			strcat(FileName, temp);		// FileName = FingerDB\\1_6
			strcat(FileName, ".bmp");		// FileName = FingerDB\\1_6.bmp
			fp = fopen(FileName, "rb");
			printf("%s\n", FileName);
			if (fp == NULL) {
				printf("%s not found!\n", FileName);
			}
			BYTE* Image;
			BYTE* Output;
			fread(&hf, sizeof(BITMAPFILEHEADER), 1, fp);
			fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, fp);
			int ImgSize = hInfo.biWidth * hInfo.biHeight;
			int H = hInfo.biHeight, W = hInfo.biWidth;
			if (hInfo.biBitCount == 24) { // Ʈ���÷�
				Image = (BYTE*)malloc(ImgSize * 3);
				Output = (BYTE*)malloc(ImgSize * 3);
				fread(Image, sizeof(BYTE), ImgSize * 3, fp);
			}
			else { // �ε���(�׷���)
				fread(hRGB, sizeof(RGBQUAD), 256, fp);
				Image = (BYTE*)malloc(ImgSize);
				Output = (BYTE*)malloc(ImgSize);
				fread(Image, sizeof(BYTE), ImgSize, fp);
			}
			fclose(fp);

			int Histo[256] = { 0 };
			int AHisto[256] = { 0 };



			Binarization(Image, Output, W, H, 250); // ����: 0, ���: 255
			InverseImage(Output, Output, W, H); // ����: 255, ���: 0
			m_BlobColoring(Output, H, W); // ����: 255, ���: 0
			InverseImage(Output, Output, W, H); // ����: 255, ���: 0
			Erosion(Output, Image, W, H);
			Dilation(Image, Output, W, H);
			Dilation(Output, Image, W, H);
			Erosion(Image, Output, W, H);
			InverseImage(Output, Image, W, H);
			zhangSuen(Image, Output, H, W);
			FeatureExtractThinImage(Output, Image, W, H, temp);
			//DrawFeaturesInImage(Image, Output, W, H, temp);

			SaveBMPFile(hf, hInfo, hRGB, Image, hInfo.biWidth, hInfo.biHeight, strcat(temp, ".bmp"));
			
			strcpy(FileName, "fingerDB\\");

			free(Image);
			free(Output);
		}
	}
	
	//free(Temp);
	return 0;
}