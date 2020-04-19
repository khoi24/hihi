#include "Func.h"
#define BUF 100
void COPY(char * N_fileS, char* N_fileD)
{
	fstream fileS;
	fileS.open(N_fileS, ios::binary);
	fstream fileD;
	fileD.open(N_fileD, ios::binary);
	char a[BUF];
	
	if (fileS.is_open() && fileD.is_open())
	{

		while (fileS.eof())
		{
			fileS.read(a, BUF);
			fileD.write(a, BUF);

		}
		fileS.close();
		fileD.close();
	}
	else
	{
		cout << "error" << endl;
	}
	

	
}
void COPYS(char* N_fileS, char* N_fileD)
{
	fstream fileS;
	fileS.open(N_fileS, ios::binary);
	fstream fileD;
	fileD.open(N_fileD, ios::binary);
	char a[BUF];

}