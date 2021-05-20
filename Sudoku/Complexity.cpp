#include "header.h"
void Sudoku::Complexity() {
	char temp;
	srand(time(NULL));
	cout << "What complexity do you want?\n\te - for easy\n\tm - for medium\n\th - for hard\n";	
	while(true) {
		cin >> temp;
		if (temp == 'e' || temp == 'E') {
			complexity = 0;
			missingCells = rand() % 5 + 40;
			cout << "You chose easy mode!\n";
			break;
		}
		else if (temp == 'm' || temp == 'M') {
			complexity = 1;
			missingCells = rand() % 5 + 50;
			cout << "You chose medium mode!\n";
			break;
		}
		else if (temp == 'h' || temp == 'H') {
			complexity = 2;
			missingCells = rand() % 5 + 60;
			cout << "You chose hard mode!\n";
			break;
		}
		cout << "Wrong input!\n";
	}
}