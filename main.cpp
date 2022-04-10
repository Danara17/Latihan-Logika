#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

bool guessAnswer(char[30]);
int counter = 0;
void cluePicker(int, char[30]);

int main(){
	char tebakan[30];
	int x,y;
	
	cout << "Input Kata : ";
	scanf(" %[^\n]s", &tebakan);
	strupr(tebakan);
	system("cls");
	
	int life = 5;
	while(life != 0){
		system("cls");
		cout << "================" << endl << "Life : ";
		for(int x = 1; x <= life; x++){
			cout <<  (char)3 << " ";
		}
		cout << "\n================" << endl;
		bool compare =  guessAnswer(tebakan);
		if(compare == true){
			system("cls");
			cout << "Benar! Jawabannya adalah " << tebakan << endl;
			break;
		}else{
			if(counter == 5){
				cout << "Anda Kalah!" << endl;
			}else{
				cout << "Coba Lagi!" << endl;
				getch();
			}
		}
		life--;
	}
	
}

bool guessAnswer(char tebakan[30]){
	char ans[30];
	
	counter++;
	cluePicker(counter, tebakan);
	cout << "Tebak -" << counter << " : ";
	scanf(" %[^\n]s", &ans);
	strupr(ans);
	
	if(strcmp(ans, tebakan) == 0){
		return true;		
	}else{
		return false;
	}
}

void cluePicker(int x, char jawab[30]){
	int temp = strlen(jawab);
	int mid = (temp/2);
	if(x == 1){
		cout << "Huruf Pertama = " << jawab[0] << endl; 
	}else if(x == 2){
		cout << "Huruf Terakhir = " << jawab[temp-1] << endl;
	}else if(x == 3){
		cout << "Kalimat Memiliki " << temp << " huruf" << endl;
		cout << "================" << endl;
		{
			cout << jawab[0];
			for(int k = 1; k <= (temp-2); k++){
				cout << " _ ";
			}
			cout << jawab[temp-1] << endl;
		}
		cout << "================" << endl;
	}else if(x == 4){
		cout << "Huruf Tengah = " << jawab[mid] << endl;
		cout << "================" << endl;
		{
			cout << jawab[0];
			for(int k = 1; k <= (temp-2); k++){
				if(k != mid){
					 cout << " _ ";
				}else{
					cout << jawab[mid];
				}
			}
			cout << jawab[temp-1] << endl;
		}
		cout << "================" << endl;
		
	}else if(x == 5){
		int huruf;
		cout << "Ingin Melihat Huruf Keberapa ? ans : "; cin >> huruf;
		cout << "================" << endl;
		int h = huruf-1;
		cout << "Huruf yang anda request adalah huruf : " << jawab[h] << endl;
		{
			cout << jawab[0];
			for(int k = 1; k <= (temp-2); k++){
				if(k == h){
					 cout << jawab[h];
				}else if(k == mid){
					cout << jawab[mid];
				}else {
					cout << " _ ";
				}
			}
			cout << jawab[temp-1] << endl;
		}
		cout << "================" << endl;
	}
}
