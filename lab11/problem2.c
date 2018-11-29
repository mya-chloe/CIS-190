
#define MAX_NAME_LEN 25

typedef struct peg{
	color[MAX_NAME_LEN];
    sides;
    pegNum;
	next hole;
}PEG;

typedef struct hole{
    color[MAX_NAME_LEN];
    sides;
    holeNum;
    next hole;
}HOLE;

int main(void){

	PEG *pegList = malloc(sizeof(PEG));
    HOLE *holeList = malloc(sizeof(HOLE));
    int holeNum = 0;
    int pegNum = 0;

	while the user has not entered "ENOUGH"{
        ++pegNum;
		addPeg(pegList, color to add, number of sides, pegNum)
	}

	add all holes from a file to holeList
        ++holeNum;
        addHole(holeList, color to add, number of sides, holeNum)
	while the user has not chosen option 5{
		print their options

		retrieve their choice

		switch(choice)
			case 1:
				retrieve color and sides of peg to search for
				printPeg(pegList, color to search for)
				break;
			case 2:
				retrieve color and num sides of peg to add
				++pegNum
				addPeg(pegList, name to add, num sides, pegNum)
				break;
			case 3:
                retrieve color and sides of peg to remove
				removePeg(pegList, name to remove, num of sides)
				break;
			case 4:
				retrieve name of file to write to
				printList(pegList, holeList, name of file)
				break;
			case 5:
				terminate program
	}
}

void printPeg(pegList, color to search, num sides to search){
	create temp peg pointing to pegList
	while(temp peg != NULL && we have not found the correct peg){
		advance our temp peg along the list
	}

	if(the peg was found)
		print the peg's details
	else
		print no peg by that name

}

void addpeg(pegList, color to add, num sides to add, penNum){
    create temp peg pointing to pegList
    while(temp peg does not point to NULL){
        advance our temp peg along the list
    }

	store the color, sides, pegNum

	create a new valid element location
	set that new element's next location to null

}

void removepeg(pegList, name to remove){
	create temp peg currentPeg pointing to pegList
	create temp peg previousPeg pointer set to null
	while(currentPeg does not equal NULL){
		if(we found the peg)
			if(it's the first element)
				set pegList = the next element of current peg
			else
				set the previous peg's next peg to the current peg's next peg

			free the current peg
			return;
		}
		previous peg = current peg
		current peg = the next element in the list

	}
		advance our temp peg along the list
	}

void exportFile(pegList, holeList name of file){
	create temp peg pointing to pegList
	open file with write permissions

	while(there is another element in the peg list){
        while(there is another element in the hole list){
            if( peg matches hole)
                print out this peg and hole
                move down the line of holes
        }
        move down the list of pegs
    }
	}

}
