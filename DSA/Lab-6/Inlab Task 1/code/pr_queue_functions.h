#ifndef PR_QUEUE_FUNCTIONS_H
#define PR_QUEUE_FUNCTIONS_H

#include "node.h"

struct node *pr_dequeue(struct node **qfront);
void pr_enqueue(struct node **qrear, struct node **qfront, struct element new_data, int priority);
int pr_isEmpty(struct node **qfront);

#endif
