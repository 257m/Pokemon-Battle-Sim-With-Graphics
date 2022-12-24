#include "../include/definitions.h"

int CheckIfAllDead(bool eop)
{
	if (Parties[eop].Member[0]->CurrentHp <= 0 &&
		Parties[eop].Member[1]->CurrentHp <= 0 &&
		Parties[eop].Member[2]->CurrentHp <= 0 &&
		Parties[eop].Member[3]->CurrentHp <= 0 &&
		Parties[eop].Member[4]->CurrentHp <= 0 &&
		Parties[eop].Member[5]->CurrentHp <= 0) {
		if (eop) {
			printf("The Player has won\n");
		}
		else {
			printf("The Enemy has won\n");
		}
		printf("%d-%d\n",
			(Parties[0].Member[0]->CurrentHp > 0) +
				(Parties[0].Member[1]->CurrentHp > 0) +
				(Parties[0].Member[2]->CurrentHp > 0) +
				(Parties[0].Member[3]->CurrentHp > 0) +
				(Parties[0].Member[4]->CurrentHp > 0) +
				(Parties[0].Member[5]->CurrentHp > 0),
			(Parties[1].Member[0]->CurrentHp > 0) +
				(Parties[1].Member[1]->CurrentHp > 0) +
				(Parties[1].Member[2]->CurrentHp > 0) +
				(Parties[1].Member[3]->CurrentHp > 0) +
				(Parties[1].Member[4]->CurrentHp > 0) +
				(Parties[1].Member[5]->CurrentHp > 0));
		printf("The seed for this game was %lu (just in case you want to "
			   "recreate the game)\n",
			randseed);
		printf("Do you want to play again? (Playing again probably has some "
			   "bugs) (y/n): ");
		(void)fgets(TextBuffer, 31, stdin);
		TextBuffer[strcspn(TextBuffer, "\n")] = 0;
		if (strcmp(TextBuffer, "y") == 0) {
			StatCalc = 1;
			BattleMode = 0;
			Retrieve = 0;
			Execute = 0;
			Parties[0].Member[0]->CurrentHp = Parties[0].Member[0]->Hp;
			Parties[0].Member[1]->CurrentHp = Parties[0].Member[1]->Hp;
			Parties[0].Member[2]->CurrentHp = Parties[0].Member[2]->Hp;
			Parties[0].Member[3]->CurrentHp = Parties[0].Member[3]->Hp;
			Parties[0].Member[4]->CurrentHp = Parties[0].Member[4]->Hp;
			Parties[0].Member[5]->CurrentHp = Parties[0].Member[5]->Hp;

			Parties[1].Member[0]->CurrentHp = Parties[1].Member[0]->Hp;
			Parties[1].Member[1]->CurrentHp = Parties[1].Member[1]->Hp;
			Parties[1].Member[2]->CurrentHp = Parties[1].Member[2]->Hp;
			Parties[1].Member[3]->CurrentHp = Parties[1].Member[3]->Hp;
			Parties[1].Member[4]->CurrentHp = Parties[1].Member[4]->Hp;
			Parties[1].Member[5]->CurrentHp = Parties[1].Member[5]->Hp;

			Parties[0].Member[0]->Non_Volatile_Status = 0;
			Parties[0].Member[1]->Non_Volatile_Status = 0;
			Parties[0].Member[2]->Non_Volatile_Status = 0;
			Parties[0].Member[3]->Non_Volatile_Status = 0;
			Parties[0].Member[4]->Non_Volatile_Status = 0;
			Parties[0].Member[5]->Non_Volatile_Status = 0;

			Parties[1].Member[0]->Non_Volatile_Status = 0;
			Parties[1].Member[1]->Non_Volatile_Status = 0;
			Parties[1].Member[2]->Non_Volatile_Status = 0;
			Parties[1].Member[3]->Non_Volatile_Status = 0;
			Parties[1].Member[4]->Non_Volatile_Status = 0;
			Parties[1].Member[5]->Non_Volatile_Status = 0;

			Parties[0].Member[0]->ItemUsable = 1;
			Parties[0].Member[1]->ItemUsable = 1;
			Parties[0].Member[2]->ItemUsable = 1;
			Parties[0].Member[3]->ItemUsable = 1;
			Parties[0].Member[4]->ItemUsable = 1;
			Parties[0].Member[5]->ItemUsable = 1;

			Parties[1].Member[0]->ItemUsable = 1;
			Parties[1].Member[1]->ItemUsable = 1;
			Parties[1].Member[2]->ItemUsable = 1;
			Parties[1].Member[3]->ItemUsable = 1;
			Parties[1].Member[4]->ItemUsable = 1;
			Parties[0].AI_MODE = 0;
			Parties[1].AI_MODE = 0;

			HideMove = 0;
			TurnCounter = 0;

			// malloc_stats();
		}
		else {
			exit(0);
		}
		return 0;
	}
	return 1;
}