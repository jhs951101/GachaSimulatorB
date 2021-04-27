#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

/*
	Made by: SharPing - Sharp Coder
	Date of Modification: 2020-10-24
*/

struct GaChaInfo {
	int rare;
	int probability;
};

int maxMaterial;
int minMaterial;

int GaChaArray[200];
int GCArrSize = 200;

void setMinMaterial() {
	minMaterial = maxMaterial / 10 + 1;
}

int randomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int convertOneToTen(int material) {
	return (material * 10 / maxMaterial);
}

void shakeGaChaArray()
{
	for (int n = 1; n <= 100; n++) {
		int a = randomNumber(0, GCArrSize-1);
		int b = randomNumber(0, GCArrSize-1);
		int swap;

		if(a != b){
			swap = GaChaArray[a];
			GaChaArray[a] = GaChaArray[b];
			GaChaArray[b] = swap;
		}
	}
}

void setGaCha(GaChaInfo* pros, int numOfPros, int material)
{
	int rare;
	int realProbability;
	int index = 0;

	int convertedValue = convertOneToTen(material);

	for (int i = numOfPros-1; i >= 1; i--) {
		rare = pros[i].rare;
		realProbability = pros[i].probability * convertedValue;

		int j = 0;
		while (j < realProbability) {
			GaChaArray[index] = rare;
			j++;
			index++;
		}
	}

	rare = pros[0].rare;

	while (index < GCArrSize) {
		GaChaArray[index] = rare;
		index++;
	}
}

int getCharacterFromGaCha()
{
	int random = randomNumber(0, GCArrSize-1);
	int rare = GaChaArray[random];

	cout << "Rare " << rare << " ";

	for (int a = 1; a <= rare; a++) {
		cout << "¡Ú";
	}

	cout << " Get!" << endl;
	cout << endl;

	return rare;
}

int startGaCha(GaChaInfo* pros, int numOfPros, int material) {
	setGaCha(pros, numOfPros, material);
	shakeGaChaArray();
	int result = getCharacterFromGaCha();

	return result;
	return 0;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << "Welcome to the GaCha Simulation!" << endl;

	while (true) {

		char start;
		cout << "Will you try? (y/n): ";
		cin >> start;
		cout << endl;

		if (start == 'n') {
			break;
		}
		else if (start == 'y') {
			GaChaInfo layerPros[5] = { {1, -1}, {2, 4}, {3, 3}, {4, 2}, {5, 1} };

			cout << "Input max material value for GaCha: ";
			cin >> maxMaterial;
			cout << endl;

			setMinMaterial();

			int tryNum;
			cout << "Input a number to start GaCha: ";
			cin >> tryNum;
			cout << endl;

			for (int i = 1; i <= tryNum; i++) {
				int material;

				while (true) {
					cout << "Input a material value to use for GaCha (" << minMaterial << " ~ " << maxMaterial << "): ";
					cin >> material;

					if (material >= minMaterial && material <= maxMaterial) {
						cout << endl;
						break;
					}

					cout << "Error: Input the number between " << minMaterial << " ~ " << maxMaterial << endl << endl;
				}

				int result = startGaCha(layerPros, 5, material);
				
				/*
				cout << result << endl;
				*/
			}
		}
		else {
			cout << "Error: Input the character y or n" << endl << endl;
		}
	}

	cout << "Good Bye~" << endl << endl;

	return 0;
}