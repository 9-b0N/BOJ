#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAXSIZE 55 


using namespace std;

int dqOK[MAXSIZE], dqSize, dqClearCount;
int want[MAXSIZE], wantSize;
int tmpCounter1, tmpCounter2, moveCounter, nowIndex, tmpIndex1, tmpIndex2;

bool findQ;

int main()
{

	//!!!!!!!!!!!�ε����� 1���� �����!!!!!!!!!!!!!!!!!

	scanf("%d %d", &dqSize, &wantSize);
	for (int i = 1; i <= wantSize; i++)
		scanf(" %d", &want[i]);
	for (int i = 1; i <= dqSize; i++)//1���� size������ �迭�� �����.
		dqOK[i] = true;

	nowIndex = 1;//������ġ�� ó��
	for (int i = 1; i <= wantSize; i++)
	{

		if (nowIndex == want[i])//������ �����Ͱ� ���ϴ� �����ΰ�?
		{
			dqOK[nowIndex] = false;
			
			nowIndex++;
			while (!dqOK[nowIndex] && nowIndex < dqSize) //���ڰ� ����������, ������ ���ڱ��� ���������� ������.
				nowIndex++;
			if (!dqOK[nowIndex])//�׷��� �������� �ʾҴٸ�
			{
				nowIndex = 1; //���� ù��°�� ���ƿ´�.
				while (!dqOK[nowIndex])//ó������ ���ڰ� ���ö����� ã�´�.
					nowIndex++;
			}
			
		}

		else//ù��°�� �ƴ϶�� ã�� �����Ѵ�.
		{
			tmpCounter1 = 0, tmpCounter2 = 0;

			findQ = false;
			tmpIndex1 = nowIndex;
			while (!findQ && tmpIndex1 > 1)//������������ �������� �����ִٸ� ������ �˾ƺ��ڴ�.
			{
				tmpIndex1--;

				if (!dqOK[tmpIndex1])//���ڰ� ���� ĭ�̸� �״��� ĭ���� ������.
					continue;
				else
				{
					tmpCounter1++;
					if (tmpIndex1 == want[i])//ã�Ҵ°�?
						findQ = true;
				}
			}	

			if (!findQ)//���� ������ ������ �� ã�Ҵٸ� 
			{
				tmpIndex1 = dqSize + 1;//������ �����ͷ� �̵��ϰ�
				while (!findQ)//ã�������� �������� �̵��Ѵ�.
				{					
					if (!dqOK[tmpIndex1])
					{
						tmpIndex1--;
						continue;
					}
					else
					{
						if (tmpIndex1 == want[i])//ã�Ҵ°�?
							findQ = true;
						tmpIndex1--;
						tmpCounter1++;
					}
				}
			}

			findQ = false;
			tmpIndex2 = nowIndex;

			while (!findQ && tmpIndex2 < dqSize) //���������� �� �� �ִٸ� ���������� ���ڴ�.
			{
				tmpIndex2++;//������ ���� ���������� ����

				if (!dqOK[tmpIndex2])//���ڰ� ������ �Ѿ��.
					continue;

				else
				{				
					tmpCounter2++;//������ Ƚ���� �����Ѵ�.

					if (tmpCounter1 <= tmpCounter2)//���࿡ �������� ���� ������ ���ų� Ŀ���ٸ� �������� ��Ų��.
					{
						findQ = true;
						break;
					}

					if (tmpIndex2 == want[i])//ã�Ҵ°�?
						findQ = true;
				}
			}
			if (!findQ)//������ ������ ������ �� ã�Ҵٸ� 
			{
				tmpIndex2 = 1;//���� �����ͷ� �̵��ϰ�
				while (!findQ)//ã�������� ���������� �̵��Ѵ�.
				{
					if (!dqOK[tmpIndex2])
					{
						tmpIndex2++;
						continue;
					}
					else
					{
						if (tmpCounter1 <= tmpCounter2)//���࿡ �������� ���� ������ ���ų� Ŀ���ٸ� �������� ��Ų��.
						{
							findQ = true;
							break;
						}

						if (tmpIndex2 == want[i])//ã�Ҵ°�?
							findQ = true;

						tmpCounter2++;
						tmpIndex2++;
					}
				}
			}

			dqOK[want[i]] = false;
			if (want[i] + 1 > dqSize)
				nowIndex = 1;
			else
				nowIndex = want[i] + 1;

			if (!dqOK[nowIndex] && i != wantSize)
			{
				while (!dqOK[nowIndex])
				{
					nowIndex++;
					if (nowIndex > dqSize)
						nowIndex = 1;
				}
			}

			if (tmpCounter1 < tmpCounter2)
				moveCounter += tmpCounter1;
			else
				moveCounter += tmpCounter2;
		}
	}
	printf("%d\n", moveCounter);

	return 0;
}