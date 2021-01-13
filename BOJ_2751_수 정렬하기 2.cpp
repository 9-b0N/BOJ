#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct splitPoint
{
	splitPoint* front;
	splitPoint* left;
	splitPoint* right;
	int headIndex;
	int rearIndex;
};

int dataArray[1000001], tmpdataArray[1000001];

void Func(int size, splitPoint* frontSplitPoint, char flag)
{
	splitPoint* newSplitPoint = new splitPoint;
	newSplitPoint->left = NULL;
	newSplitPoint->right = NULL;
	//--------------------------------------------------------------------------------------------------------------------
	//�ɰ��� ����
	//���� �ϳ��� ������ �ǹ��Ѵ� ����� ���� �����̴�.
	if (size == 1)
	{
		//size�� Ǯ �������̴�.
		if (flag == 'S')
		{
			printf("!!!!!!!!!!����!!!!!!!! ���� �ϳ��� �Խ��ϴ�.\n");
		}

		//size�� ������ �������� �������̴�. ��������, ������� �� size�� ������ ��Ȯ�� ������ size�̴�.
		else if (flag == 'L')
		{
			frontSplitPoint->left = newSplitPoint;

			newSplitPoint->front = frontSplitPoint;
			newSplitPoint->headIndex = frontSplitPoint->headIndex;
			newSplitPoint->rearIndex = frontSplitPoint->headIndex;
		}
		else if (flag == 'R')
		{
			frontSplitPoint->right = newSplitPoint;

			newSplitPoint->front = frontSplitPoint;
			newSplitPoint->headIndex = frontSplitPoint->rearIndex;
			newSplitPoint->rearIndex = frontSplitPoint->rearIndex;
		}
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	//size�� Ǯ �������̴�.
	if (flag == 'S')
	{
		frontSplitPoint->left = newSplitPoint;

		newSplitPoint->front = NULL;
		newSplitPoint->headIndex = 0;
		newSplitPoint->rearIndex = size - 1;
	}

	//size�� ������ �������� �������̴�. ��������, ������� �� size�� ������ ��Ȯ�� ������ size�̴�.
	else if (flag == 'L')
	{
		frontSplitPoint->left = newSplitPoint;

		newSplitPoint->front = frontSplitPoint;
		newSplitPoint->headIndex = frontSplitPoint->headIndex;
		newSplitPoint->rearIndex = (frontSplitPoint->headIndex) + (size - 1);
	}
	else if (flag == 'R')
	{
		frontSplitPoint->right = newSplitPoint;

		newSplitPoint->front = frontSplitPoint;
		newSplitPoint->headIndex = (frontSplitPoint->rearIndex) - (size - 1);
		newSplitPoint->rearIndex = frontSplitPoint->rearIndex;
	}
	//�ɰ��� ����
	//--------------------------------------------------------------------------------------------------------------------
	int sizeHalf, leftPopHead, rightPopHead;
	bool qleftEnd;

	int tmpdataIndex = 0, tmp;//�������� tmpdataArray����
	//--------------------------------------------------------------------------------------------------------------------
	if (size % 2 == 0)//���࿡ �� ������ ������ �������ٸ�, �� ������ ��Ȯ�� ������ �������� POP�Ѵ�.
	{
		sizeHalf = size / 2;
		Func(sizeHalf, newSplitPoint, 'L'); Func(sizeHalf, newSplitPoint, 'R');//��ͽ���
		leftPopHead = newSplitPoint->left->headIndex;//������ ���� ����
		rightPopHead = newSplitPoint->right->headIndex;
		while (1)//���� ������ ���߿� �ϳ��� �� ������ ���� ���ѹݺ�
		{
			if (leftPopHead == (newSplitPoint->left->rearIndex) + 1)//������ �� ������ ������ �����ٰ� �˸�
			{
				qleftEnd = true;
				break;
			}
			if (rightPopHead == (newSplitPoint->right->rearIndex) + 1)//�������� �� ������ �������� �����ٰ� �˸�
			{
				qleftEnd = false;
				break;
			}
			if (dataArray[leftPopHead] < dataArray[rightPopHead])
				tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
			else
				tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
		}
		if(qleftEnd)//���࿡ ������ ���ƴٸ� �������� ������� �ִ´�.
			while(rightPopHead != (newSplitPoint->right->rearIndex) + 1)
				tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
		else//���࿡ �������� ���ƴٸ� ������ ������� �ִ´�.
			while (leftPopHead != (newSplitPoint->left->rearIndex) + 1)
				tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];

	}
	else//���࿡ �� ������ ������ �������� �ʴ´ٸ�, �� ������ ������ �������� POP�Ѵ�.
	{
		tmp = dataArray[newSplitPoint->rearIndex];//�ϳ��� ���� ������ �̿��� ����.
		bool qtmpEmpty = false;//���� �� ���� ��� �Ǿ����� �˷��ش�. ����� ������ �ʾҴ�.
		sizeHalf = (size - 1) / 2;


		(newSplitPoint->rearIndex)--; //rear�� size�� 1 �����Ѵ�.�� ������ ���� ���־��� �����̴�.
		Func(sizeHalf, newSplitPoint, 'L'); Func(sizeHalf, newSplitPoint, 'R');//��ͽ���

		leftPopHead = newSplitPoint->left->headIndex;//������ ���� ����
		rightPopHead = newSplitPoint->right->headIndex;
		//--------------------------------------------------------------------------------------------------------------------
		while (1)//���� ������ ���߿� �ϳ��� �� ������ ���� ���ѹݺ�
		{
			if (leftPopHead == (newSplitPoint->left->rearIndex) + 1)//������ �� ������ ������ �����ٰ� �˸�
			{
				qleftEnd = true;
				break;
			}
			if (rightPopHead == (newSplitPoint->right->rearIndex) + 1)//�������� �� ������ �������� �����ٰ� �˸�
			{
				qleftEnd = false;
				break;
			}

			//���࿡ ���� �� ��(tmp)�� ���� �����ִٸ�
			if (!qtmpEmpty)
			{
				if (dataArray[leftPopHead] < dataArray[rightPopHead])
				{
					if (dataArray[leftPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
				{
					if (dataArray[rightPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
			}

			//���� �� ���� �������� �ʴٸ�
			else
			{
				if (dataArray[leftPopHead] < dataArray[rightPopHead])
					tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
				else
					tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
			}
		}
		//--------------------------------------------------------------------------------------------------------------------
		//�� ������
		//1. tmp�� �Һ� �Ǿ� �״�� ������ �Һ� ���ָ� �Ǵ°��
		//2. tmp�� �Һ� ���� �ʾ� ��� ���ϸ� tmp�Һ� ���� ���� �ڴʰ� ������ �Һ� ���ִ� ���
		//3. tmp�� �Һ� ���� �ʾ� ��� ���ϸ� ������ �Һ� ���� ���� tmp�� �������� �Һ���� �ִ� ���
		//��θ� ����Ѵ�.
 		if (qleftEnd)//���࿡ ������ ���ƴٸ� �������� ������� �ִ´�.
		{
			while (rightPopHead != (newSplitPoint->right->rearIndex) + 1)
			{
				//2���� ���
				if (!qtmpEmpty)
				{
					if (dataArray[rightPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
					tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
			}
		}
		else//���࿡ �������� ���ƴٸ� ������ ������� �ִ´�.
		{
			while (leftPopHead != (newSplitPoint->left->rearIndex) + 1)
			{
				//2���� ���
				if (!qtmpEmpty)
				{
					if (dataArray[leftPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
					tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
			}
				
		}
		//3���� ���
		if (!qtmpEmpty)
		{
			tmpdataArray[tmpdataIndex++] = tmp;
			qtmpEmpty = true;
		}
		//--------------------------------------------------------------------------------------------------------------------
		(newSplitPoint->rearIndex)++; //rear�� �ٽ� ������Ų��. �� ������ ���� ��Ʈ�� ���� ���� ��Ʈ�� �ٽ� ���Ʊ� �����̴�.
	}

	//tmpdataArray�� ä��� �۾��� ��������, tmpdataArray�� ���� ������ �����Ͽ� ������.
	for (int i = 0; i < tmpdataIndex; i++)
		dataArray[(newSplitPoint->headIndex) + i] = tmpdataArray[i];

	delete newSplitPoint->left;//���� ���� �ʿ����.
	delete newSplitPoint->right;
	return;
}

int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		scanf(" %d", &dataArray[i]);
	if (size == 1)
	{
		printf("%d\n", dataArray[0]);
	}
	else
	{
		splitPoint* newSplitPoint = new splitPoint;
		Func(size, newSplitPoint, 'S');
		for (int i = 0; i < size; i++)
			printf("%d\n", dataArray[i]);
		delete newSplitPoint->left;
		delete newSplitPoint;
	}
	return 0;
}