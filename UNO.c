#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

//REVERSE = 10
//SKIP = 20
//DRAWTWO = 30
//WILD = 40
//PLUS4 = 50

//=====================================================
typedef struct card
{
    int number;
    char* colour;
    int used;
    struct card* next;
}CARD;

typedef struct player
{
    CARD* handCard;
}PLAYER;


typedef struct stackOfCards
{
    CARD* top;
}STACK;

void init_screen(STACK* discard, CARD* deck);
void printScreen(int playerNumber);
void clear(void);


void printCard(CARD card);
void putACard(PLAYER* player,STACK* discard,int number, char* colour);
CARD drawACard(PLAYER* player ,int cardNum, CARD* deck);
int drawCardNum(int number);
int specialFunctions(int number);


void makeUsed1(CARD*deck, int n);
void makeUsed0(CARD*deck);
CARD pop(CARD* deck);

int play(PLAYER* player, STACK* discard, CARD* deck,CARD stackTop);
void computerPlay(PLAYER* player, STACK* discard, CARD* deck, CARD stackTop);

void insertNode(PLAYER* player, int number, char* colour);
int deleteNode(PLAYER* player, int number, char* colour, int computer);
void create7(PLAYER* player, CARD* deck);
void printLinkedList(PLAYER* player);


void push(STACK* stack,int number, char* colour);
void swap (CARD *a, CARD *b);
void randomize ( CARD arr[], int n );



int main()
 {
    CARD deck[108] = {
        { 0, "RED" },
        { 1, "RED" },
        { 1, "RED" },
        { 2, "RED" },
        { 2, "RED" },
        { 3, "RED" },
        { 3, "RED" },
        { 4, "RED" },
        { 4, "RED" },
        { 5, "RED" },
        { 5, "RED" },
        { 6, "RED" },
        { 6, "RED" },
        { 7, "RED" },
        { 7, "RED" },
        { 8, "RED" },
        { 8, "RED" },
        { 9, "RED" },
        { 9, "RED" },
        { 10, "RED" },
        { 10, "RED" },
        { 20, "RED" },
        { 20, "RED" },
        { 30, "RED" },
        { 30, "RED" },
        { 0, "BLUE" },
        { 1, "BLUE" },
        { 1, "BLUE" },
        { 2, "BLUE" },
        { 2, "BLUE" },
        { 3, "BLUE" },
        { 3, "BLUE" },
        { 4, "BLUE" },
        { 4, "BLUE" },
        { 5, "BLUE" },
        { 5, "BLUE" },
        { 6, "BLUE" },
        { 6, "BLUE" },
        { 7, "BLUE" },
        { 7, "BLUE" },
        { 8, "BLUE" },
        { 8, "BLUE" },
        { 9, "BLUE" },
        { 9, "BLUE" },
        { 10, "BLUE" },
        { 10, "BLUE" },
        { 20, "BLUE" },
        { 20, "BLUE" },
        { 30, "BLUE" },
        { 30, "BLUE" },
        { 0, "GREEN" },
        { 1, "GREEN" },
        { 1, "GREEN" },
        { 2, "GREEN" },
        { 2, "GREEN" },
        { 3, "GREEN" },
        { 3, "GREEN" },
        { 4, "GREEN" },
        { 4, "GREEN" },
        { 5, "GREEN" },
        { 5, "GREEN" },
        { 6, "GREEN" },
        { 6, "GREEN" },
        { 7, "GREEN" },
        { 7, "GREEN" },
        { 8, "GREEN" },
        { 8, "GREEN" },
        { 9, "GREEN" },
        { 9, "GREEN" },
        { 10, "GREEN" },
        { 10, "GREEN" },
        { 20, "GREEN" },
        { 20, "GREEN" },
        { 30, "GREEN" },
        { 30, "GREEN" },
        { 0, "YELLOW" },
        { 1, "YELLOW" },
        { 1, "YELLOW" },
        { 2, "YELLOW" },
        { 2, "YELLOW" },
        { 3, "YELLOW" },
        { 3, "YELLOW" },
        { 4, "YELLOW" },
        { 4, "YELLOW" },
        { 5, "YELLOW" },
        { 5, "YELLOW" },
        { 6, "YELLOW" },
        { 6, "YELLOW" },
        { 7, "YELLOW" },
        { 7, "YELLOW" },
        { 8, "YELLOW" },
        { 8, "YELLOW" },
        { 9, "YELLOW" },
        { 9, "YELLOW" },
        { 10, "YELLOW" },
        { 10, "YELLOW" },
        { 20, "YELLOW" },
        { 20, "YELLOW" },
        { 30, "YELLOW" },
        { 30, "YELLOW" },
        { 40, "WHITE" },
        { 40, "WHITE" },
        { 40, "WHITE" },
        { 40, "WHITE" },
        { 50, "WHITE" },
        { 50, "WHITE" },
        { 50, "WHITE" },
        { 50, "WHITE" }
    };
    STACK discard;
    randomize(deck,108);
    init_screen(&discard,deck);
    makeUsed0(deck);

    PLAYER player1;
    PLAYER player2;
    player1.handCard=NULL;
    player2.handCard=NULL;

    create7(&player1,deck);
    printf("\nPlayer 1\n");
    printLinkedList(&player1);
    printf("\n");

    //printf("\nPlayer 2\n");
    create7(&player2,deck);
    //printLinkedList(&player2);
    printf("\n\n");

    int i=0;
    while(player1.handCard!=NULL && player2.handCard!=NULL)
    {
    	int x;
        x = play(&player1,&discard,deck,*(discard.top));
        printf("\n\ntop of pile:\n");
        printCard(*(discard.top));
        if(x) //returns 1
        {
        	play(&player1,&discard,deck,*(discard.top));
	        printf("\n\ntop of pile:\n");
	        printCard(*(discard.top));
    	}
    	 //returns 0
    	
	        computerPlay(&player2,&discard,deck,*(discard.top));
	        printf("\n\ntop of pile:\n");
	        printCard(*(discard.top));
		
    }
    if(player1.handCard==NULL)
    {
    	printf("YOU WIN!!!!");
	}
	else if(player2.handCard==NULL)
	{
		printf("TRY AGAIN NEXT TIME :(");
	}
    /*for(i=0;i<108;i++)
    {
        printf("%d %d %d %s",i,deck[i].used,deck[i].number,deck[i].colour);
        printf("\n");
    }*/
    printf("\n");
    printLinkedList(&player1);
    printf("\n");
}

//=============================================================================

//clears the screen hand cards to the two players, puts a card to discard pile from the main pile

void init_screen(STACK* discard, CARD* deck)
{
    printf("Game Starts Now : \n\n");
    push(discard,deck[14].number,deck[14].colour);
    printCard(deck[14]);
}

void printScreen(int playerNumber)
{
    printf("PLAYER %d's TURN\n\n",playerNumber);

}
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

//=============================================================================

//CARD FUNCTIONS
void printCard(CARD card)
{
    printf("================\n");
    printf("(%d , %s)\n",card.number, card.colour);
    printf("================\n");

}
void putACard(PLAYER* player,STACK* discard,int number, char* colour)
{
	int del;
    del=deleteNode(player,number,colour,0);
    if(del)
    push(discard,number,colour);
    else
    return;
}

CARD drawACard(PLAYER* player ,int cardNum, CARD* deck)
{
    int i=0;
    for(i=0;i<cardNum;i++)
    {
        CARD temp = pop(deck);
//        printf("\n\nThe drawn card is: \n");
//        printCard(temp);
        insertNode(player,temp.number,temp.colour);
        return temp;
    }
}

int drawCardNum(int number)
{
    switch (number) {
        case 30:
        	printf("Draw 2");
            return 2;
            break;
        case 50:
        	printf("Draw 4");
            return 4;
        default:
        	printf("Draw 1");
            return 1;
            break;
    }
}

int specialFunctions(int number)
{
    switch(number)
    {
    case 10:
        //reverse
        printf("The REVERSE card was put!\n");
        return 1;
        //break;
    case 20:
        //skip
        printf("Your opponent's turn has been skipped, play again!\n ");
        return 1;
        //break;
    default:
    	return 0;

    }
}

//=============================================================================
//DECK FUNCTIONS

//used=1
void makeUsed1(CARD*deck, int n)
{
    deck[n].used =1;
}
//used =0
void makeUsed0(CARD*deck)
{
    int i;
    for(i=0;i<108;i++)
    {
        deck[i].used=0;
    }
}
CARD pop(CARD* deck)
{
    static int i = 15;
    deck[i].used=1;
    i++;
    return deck[i-1];
}


//=============================================================================


//Does what a player should do when it is her move
void computerPlay(PLAYER* player, STACK* discard, CARD* deck, CARD stackTop)
{
    //printf("1 ");
    CARD* nodePtr= player->handCard;
    while((nodePtr != NULL) && strcmp(nodePtr->colour,stackTop.colour)!=0 && nodePtr->number!=stackTop.number)
    {
        nodePtr = nodePtr->next;
        //printf("2 ");
    }
    if(nodePtr==NULL)
    {
    	printf("=========================\n");
    	printf("Computer Drew a card\n");
    	printf("=========================\n");
        drawACard(player,drawCardNum(stackTop.number),deck);
        CARD* head=player->handCard;
        if(head->number == stackTop.number || strcmp(head->colour,stackTop.colour)==0)
        {
       	printf("=========================\n");
    	printf("Computer put the Drawn card\n");
    	printf("=========================\n");
        putACard(player,discard,head->number,head->colour);
       
	    	if(specialFunctions(head->number))
	        {
	        	//printf("ok");
		       return;  	
			}
			if(nodePtr->number==30)
			{
				drawACard(player,2,deck);
			}
			if(nodePtr->number ==50)
			{
				drawACard(player,4,deck);
			}
        }
        else
        {
            //printf("7 ");
            return;
        }
        //printf("3 ");

    }
    else
    {
    		printf("=========================\n");
        	printf("Computer put a card\n");
        	printf("=========================\n");
        	putACard(player,discard,nodePtr->number,nodePtr->colour);
            if(specialFunctions(nodePtr->number))
	        {
	        	//printf("ok2");
		      	return; 	
			}
			if(nodePtr->number==30)
			{
				drawACard(player,2,deck);
			}
			if(nodePtr->number ==50)
			{
				drawACard(player,4,deck);
			}

        //printf("4 ");
    }

}

int play(PLAYER* player, STACK* discard, CARD* deck, CARD stackTop)
{
    
    CARD* nodePtr= player->handCard;
	while((nodePtr != NULL) && strcmp(nodePtr->colour,stackTop.colour)!=0 && nodePtr->number!=stackTop.number)
   	{
       	nodePtr = nodePtr->next;
   	}
	if(nodePtr==NULL)
    {
    	printf("=========================\n");
    	printf("You have to DRAW a card\n");
    	printf("=========================\n");
        CARD temp = drawACard(player,drawCardNum(stackTop.number),deck);
        printf("\n\nThe drawn card is: \n");
        printCard(temp);
        printLinkedList(player);
   	    CARD* head=player->handCard;
   	    if(head->number == stackTop.number || strcmp(head->colour,stackTop.colour)==0)
       	{
       		printf("\n=========================\n");
    		printf("You have put the DRAWN a card\n");
    		printf("=========================\n");
       	    putACard(player,discard,head->number,head->colour);
       	    
       	    if(specialFunctions(head->number))
       	    {
       	    	//printf("g1");
       	    	printLinkedList(player);
       	    	return 1;
			}
			if(nodePtr->number==30)
			{
				drawACard(player,2,deck);
			}
			if(nodePtr->number ==50)
			{
				drawACard(player,4,deck);
			}
			printLinkedList(player);
			return 0;


       	}
       	else
       	{
           	return 0;
    	}
   	}
   	else
   	{
   		printf("=========================\n");
   		printf("You have to PUT a card\n");
   		printf("=========================\n");
    	int number;
    	char colour[10];
    	fflush(stdin);
    	printf("\nEnter the number: ");
	    scanf("%d",&number);
        printf("Enter the colour: ");
      	scanf("%s",colour);
       	putACard(player,discard,number,colour);
       	
        if(specialFunctions(number))
        {
        	//printf("g2");
        	printLinkedList(player);
        	return 1;
	        
		}
		if(nodePtr->number==30)
			{
				drawACard(player,2,deck);
			}
			if(nodePtr->number ==50)
			{
				drawACard(player,4,deck);
			}
        printLinkedList(player);
        return 0;
	}

}



/*void computerPlay(PLAYER player, CARD* topOfStack,STACK* discard)
 {
 int number= topOfStack->number;
 char colour[10];
 strcpy(colour,topOfStack->colour);

 deleteNode(player,number,colour,1);
 push(discard,number,colour);
 }*/
//=============================================================================
//LINKED LIST

//deletes a node using the info given
int deleteNode(PLAYER* player, int number, char* colour, int computer)
{
    CARD *current = player->handCard, *previous;
    CARD *head = player->handCard;
    if (head == NULL) {
        printf("Error : Invalid node pointer !!!\n");
        return 0;
    }

    if ((current->number == number)&& strcmp(current->colour,colour)==0 )
    {
        CARD* t =current;
        player->handCard = current->next;
        free(t);
        return 1;
    }

    if(computer)
    {
        while ((current != NULL )&& (current->number != number) && (strcmp(current->colour,colour)))
        {
            previous = current;
            current = current->next;
        }
    }
    else
    {
        while ((current != NULL )&& (current->number != number || strcmp(current->colour,colour)))
        {
            previous = current;
            current = current->next;
        }
    }

    if (current == NULL){
        printf("not found in Linked List\n");
        return 0;
    }

    CARD* t =current;
    previous->next = current->next;
    free(t);
}

//adds a node with the given info to the end
void insertNode(PLAYER* player, int number, char* colour)
{
    CARD* head = player->handCard;
    CARD* newNode = (CARD*) malloc(sizeof(CARD));
    newNode->number  = number;
    newNode->colour=(char*)malloc(100*sizeof(char));
    strcpy(newNode->colour,colour);
    newNode->next = head;
    player->handCard = newNode;
}
void create7(PLAYER* player, CARD* deck)
{
    int i,count=0;
    for(i=0;count<7;i++)
    {
        if(deck[i].used==0)
        {
            insertNode(player,deck[i].number,deck[i].colour);
            makeUsed1(deck,i);
            count++;
        }
    }
}
//Prints the list
void printLinkedList(PLAYER* player) {
    CARD* nodePtr= player->handCard;
    printf("\n");
    while (nodePtr != NULL)
    {
        printf("%d, %s", nodePtr->number, nodePtr->colour);
        nodePtr = nodePtr->next;
        if(nodePtr != NULL)
        { printf("\n");}
    }
}

//=============================================================================
//Adds to the stack checks for duplicates. if duplicates are present it is invalid
void push(STACK* stack,int number, char colour[])
{
    CARD* temp = stack->top;
    CARD* newCard = (CARD*)malloc(sizeof(CARD));
    newCard->number=number;
    newCard->colour = (char*)malloc(100*sizeof(char));
    strcpy(newCard->colour,colour);
    newCard->used=1;

    if(temp==NULL)
    {
        stack->top=newCard;
        newCard->next=NULL;
    }
    else
    {
        newCard->next=stack->top;
        stack->top=newCard;
    }
    //printCard(*newCard);
    printf("\n");
}
//=============================================================================
//SHUFFLE FUNCTIONS
// A utility function to swap to integers
void swap (CARD *a, CARD *b)
{
    CARD temp = *a;
    *a = *b;
    *b = temp;
}

// A function to generate a random permutation of arr[]
void randomize ( CARD arr[], int n )
{
    int i;
    srand ( time(NULL) );
    for ( i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);

        swap(&arr[i], &arr[j]);
    }
}

//=============================================================================

