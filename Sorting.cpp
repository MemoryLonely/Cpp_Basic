/*
	�����㷨�ļ�ʵ��
*/

//ð������
void UBU() {
	int n = 5;
	int arr[5], i, j;
	
		for (j = 0; j < n - i - 1; j++) { 
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	
}