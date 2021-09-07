#include <iostream> //std::cout/cin
#include <cstdlib> //rand() 
#include <ctime> //time
#include <fstream>//Saving Highscores

int randomfive();
int randomten();
int randomthirty();

void Menu();
void EasyMode();
void MediumMode();
void HardMode();
void HighScore();

int main() {
	std::srand(std::time(nullptr));

	Menu();
	return 0;
}
void Menu() {
	std::cout << "| The number guessing game |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "|Please choose a difficulty|" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "|   Press A: Easy (1-5)    |" << std::endl;
	std::cout << "|  Press B: Medium (1-10)  |" << std::endl;
	std::cout << "|   Press C: Hard (1-30)   |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| Press H to see Highscore |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	char Input;
	std::cout << "              "; 
	std::cin >> Input;
	switch (Input) {
	case 'A': case 'a':
		EasyMode();
		break;
	case 'B':case 'b':
		MediumMode();
		break;
	case 'C': case 'c':
		HardMode();
		break;
	case 'H': case'h':
		HighScore();
		break;
	default:
		break;
	}


}
void EasyMode() {
	int EasyGuess{};
	int Randomonetofive = randomfive();
	int count{};
	std::cout << "Please guess a number between 1 and 5: " << std::endl;
	do {
		std::cin >> EasyGuess;
		count++;
		
	
		if (EasyGuess == Randomonetofive) {
			std::cout << "YOU WON!!"<< std::endl;
			std::cout << "Your attempt count: " << count << std::endl;
			
			std::ifstream input("Best_Score_1_5.txt");
			int Best_Score_1_5; 
			input >> Best_Score_1_5;

			std::ofstream output("Best_Score_1_5.txt");
			if (count < Best_Score_1_5) {
				output << count;
				std::cout << "You broke the highscore!" << std::endl;
				std::cout << "The new highscore is: " << count<<"!";
			}
			else {
				output << Best_Score_1_5;
				std::cout << "The Highscore is: " << Best_Score_1_5;
			}
			

		}
		else if (EasyGuess < Randomonetofive) {
			std::cout << "Oops, wrong answer go higher"<< std::endl;
			

		}
		else if (EasyGuess > Randomonetofive) {
			std::cout << "Oops, wrong answer go lower"<< std::endl;
			
		}
	} while (EasyGuess != Randomonetofive);
}
void MediumMode() {
	int MediumGuess{};
	int Randomonetoten = randomten();
	int count{};
	std::cout << "Please guess a number between 1 and 10: " << std::endl;
	do {
		std::cin >> MediumGuess;
		count++;

		if (MediumGuess == Randomonetoten) {
			std::cout << "YOU WON!!" << std::endl;
			std::cout << "Your attempt count: " << count << std::endl;

			std::ifstream Input("Best_Score_1_10.txt");
			int Best_Score_1_10;
			Input >> Best_Score_1_10;

			std::ofstream Output("Best_Score_1_10.txt");
			if (count < Best_Score_1_10) {
				Output << count;
				std::cout << "You broke the high score!" << std::endl;
				std::cout << "The new highscore is: " << count<<"!"<<std::endl;

			}
			else {
				Output << Best_Score_1_10;
				std::cout << "The high score is: " << Best_Score_1_10 << std::endl;
			}
		}
		else if(MediumGuess < Randomonetoten){
			std::cout << "Oops, wrong answer go higher" << std::endl;

		}
		else if (MediumGuess > Randomonetoten) {
			std::cout << "oops, wrong answer go lower" << std::endl;
		}
	} while(MediumGuess != Randomonetoten);
}
void HardMode() {
	int HardGuess{};
	int Randomonetothirty = randomten();
	int count{};
	std::cout << "Please enter a number between 1 and 30: " << std::endl;
	do {
		std::cin >> HardGuess;
		count++;

		if (HardGuess == Randomonetothirty) {
			std::cout << "YOU WON!" << std::endl;
			std::cout << "Your attempt count: " << count << std::endl;

			std::ifstream Input("Best_Score_1_30.txt");
			int Best_Score_1_30;
			Input >> Best_Score_1_30;

			std::ofstream Output("Best_Score_1_30.txt");
			if (count < Best_Score_1_30) {
				Output << count;
				std::cout << "You broke the high score!" << std::endl;
				std::cout << "The new highscore is: " << count << "!" << std::endl;
			}
			else {
				Output << Best_Score_1_30;
				std::cout << "The high score is: " << Best_Score_1_30 << std::endl;
			}
		}
		else if (HardGuess < Randomonetothirty) {
			std::cout << "Oops, wrong answer go higher" << std::endl;
		}
		else if (HardGuess > Randomonetothirty) {
			std::cout << "Oops, wrong answer go lower" << std::endl;
		}


	} while (HardGuess != Randomonetothirty);
}
void HighScore() {
	std::ifstream ScoreA("Best_Score_1_5.txt");
	int Best_Score_1_5;
	ScoreA >> Best_Score_1_5;

	std::ifstream ScoreB("Best_Score_1_10.txt");
	int Best_Score_1_10;
	ScoreB >> Best_Score_1_10;

	std::ifstream ScoreC("Best_Score_1_10.txt");
	int Best_Score_1_30;
	ScoreC >> Best_Score_1_30;

	std::cout << "|        Highscores        |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "| Best score for Easy:" << Best_Score_1_5 << "----|" << std::endl;
	std::cout << "| Best score for Medium:" << Best_Score_1_10 << "--|" << std::endl;
	std::cout << "| Best score for Hard:" << Best_Score_1_30 << "----|" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
}

int randomfive() {
	
	int random = std::rand() % 5+1;
	return random;
}
int randomten() {
	int random = std::rand() % 10 + 1;
	return random;
}
int randomthirty() {
	int random = std::rand() % 30 + 1;
	return random;
}