//Tacuma Solomon
//Computer Science 3 

//This assignment asks you to write a program that 
//	(1) reads a data file named infile.txt and constructs the adjacency list above and 
//	(2) finds if there is any two-legged path (route) between the two cities.
//YOU DONOT HAVE THE USE A STACK. A NESTED LOOP IS ADEQUATE FOR TWO-LEGGED PATHS
//Next, the program should prompt the user be enter the names of two cities 
//between which a path is requested. The program should then locate any path 
//between the two cities and compute the distance of the path.


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct edgeNodeType   // Represents an edge in the graph
{
     int index_no;
     int weight;
     edgeNodeType* nextCity;
};


struct vertixType    // Represents a vertex
{
     string city_name;
     edgeNodeType* firstCity;
};


void addedgeNodeType(edgeNodeType*&, ifstream&);			 // Adds an edgeNodeType to the linked list
int findCity(string, vertixType[]);							 //function that returns index of city 
bool connectingCity(int, int, vertixType[], int&);			 // function that returns whether there is a path between city at these indices
void Print_Result(int, int, bool, vertixType[], int&);       // Prints the result and the distance
void Footer();


int main()
{
	cout << "Tacuma Solomon"     << endl;
	cout << "Computer Science 3" << endl;
	cout << endl;

	ifstream infile;				//file input
	infile.open("infile.txt");
	bool found;						//Variable indicating whether the destination was found
	int distance = 0;					//Initialized variable for the distance travelled
	int counter, index, index2;
	string city1, city2;			//Holds the index value of the city
	vertixType graph[7];			// Array of vertixTypes

	for (int i=0; i<7; i++)			// Builds an adjacency list from the text file		
	{	
		infile >> graph[i].city_name;		// Inputs the the city name from the file
		cout << graph[i].city_name;		
		graph[i].firstCity=NULL;			// Sets the Array pointer to null
		infile >> counter;					// Reads the count of the number of nodes per array space
		for (int j=1;j<=counter;j++)
			addedgeNodeType(graph[i].firstCity,infile);
		cout << endl;
	}
			
	cout << endl << endl << "Enter two cities that you wish to find a path: "; // prompts the user for the names of the cities
	cin >> city1 >> city2;

	index=findCity(city1, graph);	// Generates the index value for city1
	index2=findCity(city2, graph);	// Generates the index value for city2

	found=connectingCity(index, index2, graph, distance); // Locates the path between city1 and city2

	Print_Result(index, index2, found, graph, distance); //Prints the result
	Footer();
	system("pause");
	return 0;
}




 // function that returns whether there is a path between city at these indices
bool connectingCity(int start_city, int end_city, vertixType graph[], int& distance)
{
	bool found=false;
	edgeNodeType *head, *head2;		//Pointers
	if ((start_city==-1)||(end_city==-1))
		return 0;
	head=graph[start_city].firstCity;
	while(head!=NULL)
	{
		if (head->index_no == end_city) // This looks at the first node. If it is the correct index, the city is found.
		{
			found=true;
			distance=head->weight; // Records the distance of this leg of the journey
			return found;
		}
		else // If the previous city was not the destination, this nested loop looks at the connecting flights from this one to see
			// if there may be some other flight that may get to the distination via some second leg
		{
			head2=graph[head->index_no].firstCity;
			while(head2!= NULL)
			{
				if(head2->index_no == end_city)
				{
					found=true;
					distance=head->weight+head2->weight; // Records the distance of this leg of the journey
					return found;
				}
				head2=head2->nextCity;
			}
		}
		head = head->nextCity;
	}
	return found;				
}


// Prints the result of the search
void Print_Result(int start, int end, bool result,vertixType graph[], int& distance) 
{
	if (result==true)
	{
		cout << "A path exists between " << graph[start].city_name << " and " <<graph[end].city_name << " ." << endl;
		cout << "Distance of Path: " << distance << endl << endl;
	}
	else
		cout << "A path does not exist between those two elements" << endl << endl;
}


// Returns the array position of the city
int findCity(string cty, vertixType thisgraph[]) 
 {
	 for(int i = 0; i<7; i++)
	 {
		 if (thisgraph[i].city_name == cty)
			 return i;
	 }
	 cout << "City not found " << endl;
	 return -1;
 }


// Adds an edgeNodeType to the linked list
void addedgeNodeType(edgeNodeType*& head, ifstream& infile)
{
	edgeNodeType *temp, *temp2;
    temp = new edgeNodeType;		// Creates a node and takes its information
	infile >> temp->index_no;
	cout << " " << temp->index_no;
	infile >> temp->weight;
	cout << " " << temp->weight;
	temp->nextCity = NULL;
	if (head == NULL)              // Links the new edgeNodeType to the rest of the adjacency list
		head = temp;
	else {
		temp2 = head;
		while (temp2->nextCity != NULL)
		{
			temp2 = temp2->nextCity;
		}
		temp2->nextCity = temp;
	}	
}

void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}


/*
Tacuma Solomon
Computer Science 3

Atlanta 5 800 6 600
Austin 3 200 5 160
Chicago 4 1000
Dallas 1 200 2 900 4 780
Denver 0 1400 2 1000
Houston 0 800
Washington 0 600 3 1300


Enter two cities that you wish to find a path: Austin Chicago
A path exists between Austin and Chicago .
Distance of Path: 1100



() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/