//Fei-exe 1.8.1
//Create a struct Article and a Print() function that gets the address of the structure as a parameter

#include <stdio.h>

//create a struct Article
struct Article
	{
	int Num;			//Article number
	int Quant;			//Quantity
	char Desc[21];		//Description with max 20 characters
	};

//create a function Print() that prints struct Article
//create a pointer 'each' that gets the address of 'Article' struct
void Print(struct Article* each){
	
	//access members of 'each' and print corresponding outputs
	printf("Article number: %d\n", (*each).Num);
	printf("Quantity: %d\n", (*each).Quant);
	printf("Description: %s\n", (*each).Desc);
	}

//Print() function declaration
void Print(struct Article art);

void main(){
	//initialize contents of Article
	struct Article entry[] = {
		{1, 20, "Hello world"},
		{2, 5, "It is fun"}
	};

	//print the second element of entry array
	Print(&entry[1]);


	/*
	struct Article article; // An instance of the "Article" structure.

	// Print the contents of an instance of the "Article" structure.
	// p_article - a pointer to an instance of the "Article" structure.
	void Print(struct Article* p_article);

	// Initialize the contents of article.
	article.number = 1;
	article.quantity = 10;
	strcpy_s(article.description, "An article on MATLAB");

	// Print the contents of article.
	Print(&article);
	*/
}