// Computing GC content

#include <bits/stdc++.h>

using namespace std ;

class FASTA
{
	public:
			string ID ;			// FASTA ID
			string dnastr ;		// DNA string
			double gcc ;		// GC content percentage
			
			FASTA() 
			{
				ID = "" ;
				dnastr = "" ;
				gcc = 0.0 ;
			}
} ;

// Reads file and loads the class FASTA with data
void get_fasta_from_file( vector<FASTA> &, string ) ;

// Iterates in FASTA data and returns id with highest GC content
int get_id_of_high_gcc( vector<FASTA> & ) ; 

int main()
{
	string filename = "rosalind_gc.txt" ;
	
	vector<FASTA> fasta ;
	
	// Read file and store as FASTA format
	get_fasta_from_file( fasta, filename ) ;
	
	int hi_gcc = get_id_of_high_gcc( fasta ) ;
	
	cout << "\n\n" ;

	// Print ID and gcc of hi_gc content
	cout << fasta[ hi_gcc ].ID << "\n" ;
	cout << fasta[ hi_gcc ].gcc ;
	
	return 0 ;
}

// Reads file and loads the class FASTA with data
void get_fasta_from_file( vector<FASTA> &fasta, string file ) 
{
	// Read from input file
	ifstream fp ;
	fp.open( file, ios :: in ) ;
	
	char c ;
	int counter = -1 ;		// Number of records of FASTA
	int line = 0 ;			// Denotes input format line number
	
	string id = "" ;
	string dna = "" ;
	int countG = 0, countC = 0 ;
	
	bool eof = false ;
	
	while( !fp.eof() )
	{
		fp >> c ;		// Read char from file
		
		// If EOF is reached, change c to '>' for adding last record to list
		if( fp.eof() )
		{
			c = '>' ;
			eof = true ;
		}
		
		if( c == '>' )
		{
			// Counts number of records
			cout << "\n counter: "<< ++counter ;
			
			if( line != 0 )
			{
				// Store new FASTA
				FASTA newfasta ;
				
				double gccp = 0.0 ;
				
				// Calculate GCC content
				if( countC + countG > 0 )
					gccp = 1.0 * ( countC + countG ) * 100 / dna.length() ;
				else
					gccp = 0 ;
				
				//[cout << "\n countC: " << countC << "  countG: " << countG ; 
				cout << "\n gccp: " << gccp << "  dnalen: " << dna.length() ;
				
								
				newfasta.ID = id ;
				newfasta.dnastr = dna ;
				newfasta.gcc = gccp ;
				
				// Push into list
				fasta.push_back( newfasta ) ;
				
				
				// Reset the variables
				id = "" ;
				dna = "" ;
				countG = 0 ;
				countC = 0 ;
				
				// Check if eof is reached
				if( eof )
					break ;
			}
			
			line = 1 ;
		}
		
		// End of line1. Change to line2
		if( id.length() == 13 )
			line = 2 ;
			
		// Reading line 1 of input format
		if( line == 1 )
		{
			if( c != '>' )
				id += c ;
			//cout << "\n id: " << id ;
		}
		
		// Reading line2 of input format
		if( line == 2 )
		{
			dna += c ;
			//cout << "\n dna: " << dna ;	
			
			if( c == 'C' )
				countC++ ;
			
			if( c == 'G' )
				countG++ ;
				
			//cout << "\n countC: " << countC << "  countG: " << countG ;
		}	
		
	}
	
	fp.close() ;
}

// Iterates in FASTA data and returns id with highest GC content
int get_id_of_high_gcc( vector<FASTA> &fasta )
{
	cout << "\n Number of records: " << fasta.size() ;
	
	int id_max_gcc = -1 ;
	int val_max_gcc = -1 ;
	
	// Iterate and get ID of highest GCC.
	for( int i = 0 ; i < fasta.size() ; i++ )
	{
		if( fasta[ i ].gcc > val_max_gcc )
		{
			val_max_gcc = fasta[ i ].gcc ;
			id_max_gcc = i ;
		}
	}
	
	return id_max_gcc ;
}
