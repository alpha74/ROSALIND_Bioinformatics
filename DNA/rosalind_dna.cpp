// Count the occurence of A, G, T and C

#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
	ifstream fp ;
	
	fp.open( "rosalind_dna.txt", ios :: in ) ;
	
	char c ;
	long int countA = 0, countG = 0, countT= 0, countC = 0 ;

	
	while( !fp.eof() )
	{
		fp >> c ;

		if( fp.eof() )
			break ;
		
		if( c == 'A' )
			countA++ ;
			
		else if( c == 'G')
			countG++ ;
			
		else if( c == 'C' )
			countC++ ;
		
		else if( c == 'T')
			countT++ ;
		
		else;

		
	}
	
	cout << countA << " " << countC << " " << countG << " " << countT  ;
	
	return 0 ;
}
