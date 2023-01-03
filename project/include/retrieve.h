#ifndef RETRIEVE_H
#define RETRIEVE_H

#include <stdbool.h>

void RetrieveAIMove(bool eop);
enum {
ACTION_SELECTION,
MOVE_SELECTION,
};
void RetrieveUserMove(bool eop);

#endif // RETRIEVE_H //