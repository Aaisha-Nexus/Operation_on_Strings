#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//FUNCTION FOR FINDING()
void wordfound(string& s)
{
		string word;
    cout<< "Enter the word you want to find: ";
    getline(cin,word);
    
    int found = s.find(word);

    		if (found != string::npos)
			 {
        // Word found!
        cout <<  "WORD " << word << " FOUND AT INDEX " << found << endl;
    	} 
		else 
		{
	        // Word not found
	        cout << "Word '" << word << "' not found in the line." << endl;
	    }
	    cout << endl;
		
}
//FUNCTION FOR REPLACING
void replaceword( string s2)
{
	string repword;
    cout<< "enter the word you want to replace: ";
    getline(cin,repword);
    string repwith;
    cout<< "enter with what you want to replace with: ";
    getline(cin,repwith);
    int repfound = s2.find(repword);

    if (repfound != string::npos)
	 { 
        s2.replace(repfound, repword.length(), repwith);
        cout << "REPLACED LINE: " << s2 << endl << "\n";
    } 
	else {
        cout << "Word not found " << endl;
    }
}
//FUNCTION TO FIND TOTAL SPACES
	int spacecount(string s3)
	{
	   
    int space=0;
    for(int i=0;i<s3.length();i++)
    {
    	if (s3[i]==' ')
        {
            ++space;
        }
	}
	 cout << "The total spaces are: " << space << endl;		
	}
	
	//FUNCTION TO COUNT WORDS
	void wordcounter(string s4)
			{
	
	   int count = 0;
	if (!s4.empty())
	 {
	    count = 1; // At least one word if the string is not empty
	    for (int i = 0; i < s4.length(); i++)
		 {
	        if (s4[i] == ' ' || s4[i] == '\n' || s4[i] == '\t')
			 {
	            if (s4[i + 1] != ' ' && s4[i + 1] != '\n' && s4[i + 1] != '\t')
				 {
	                count++;
	            }
	        }
	    }
	}
	cout << "TOTAL WORD COUNT IS: " << count;
	}
	
	
	//FUNCTION TO COUNT SENTENCES
	void sentencecounter(string s5)
			{
	
	   int count = 0;
	if (!s5.empty())
	 {
	    count = 1; // At least one word if the string is not empty
	    for (int i = 0; i < s5.length(); i++)
		 {
	        if (s5[i] == '.' || s5[i] == '?' || s5[i] == '!')
			 {
                if (i + 1 < s5.length() && s5[i + 1] != '.' && s5[i + 1] != '?' && s5[i + 1] != '!')
				 {
	                count++;
	            }
	        }
	    }
	}
	cout << "TOTAL SENTENCE COUNT IS: " << count;
	}
	
	void articlecount(const string& s6)
	 {
    string articles[3] = {"a ", "an ", "the "};
    int articleCount[3] = {0}; 
    
    for (int i = 0; i < 3; ++i)
	 {
        int found = s6.find(articles[i]);
        while (found != string::npos) 
		{
            ++articleCount[i];
            found = s6.find(articles[i], found + 1); 
        }
    }

    // Output the count of each article
    for (int i = 0; i < 3; ++i) {
        cout << "Count of " << articles[i] << " : " << articleCount[i] << endl;
    }
}

int main()
{
	string str;
	cout << "Enter the line or paragraph: " << endl;
	getline(cin,str);
	
		int option;
	do{
	cout<< "\nCHOOSE THE NUMBER OPTION FROM THE GIVEN MENU: ";
	cout<< "\n 1) FIND \n 2)REPLACE \n 3)WORD COUNTER \n 4)SENTENCE COUNTER \n 5) SPACE COUNTER \n 6)ARTICLE FINDER \n";
	cin>> option;
	cin.ignore(); 
	
	if(option==1)
	{
		wordfound(str);
	}
	else if(option==2)
	{
			replaceword(str);
	}
	else if(option==3)
	{
		wordcounter(str);
	}
	else if(option==4)
	{
		sentencecounter(str);
	}
	else if(option==5)
	{
		 spacecount(str);
	}
		else if(option==6)
	{
		articlecount(str);
	}
	else
	{
		cout<< "INVALID OPTION!" << endl;
	}
}
	while (option!=7);
	return 0;
}





