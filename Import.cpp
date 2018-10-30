#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>

using namespace std;


struct table
{

	string tconst_table;
	string title_table;
	string averageRating_table;
	string numVotes_table;
	string seasonNumber_table;
	string episodeNumber_table;
	int rank;
};

bool compareByLength(const table &a, const table &b)
{
    return a.rank < b.rank;
}

int main(int argc,char* argv[])
{

	vector <table> table_vector;
	
	vector <string> tconst;
	vector <string> parentTconst;
	vector <string> seasonNumber;
	vector <string> episodeNumber;
	vector <string> averageRating;
	vector <string> numVotes;
	
	string tconst_temp;
	string parentTconst_temp;
	string seasonNumber_temp;
	string episodeNumber_temp;
	
	vector <string> filtered_tconst;
	vector <string>	filtered_seasonNumber;
	vector <string> filtered_episodeNumber;

	vector <string> title;

	string filtered_tconst_temp;
	
	ifstream title_episodes_file;
	title_episodes_file.open("../title.episode.tsv");

	ifstream title_basics_file;
	title_basics_file.open("../title.basics.tsv");
	
	ifstream title_ratings_file;
	title_ratings_file.open("../title.ratings.tsv");

	ifstream title_akas_file;
	title_akas_file.open("../title.akas.tsv");

	string temp1,temp2,temp3;
	
	cout<<argc<<"\t"<<argv[1]<<endl;

	cout<<"Reading Akas File"<<endl;
	
	string titleId;
	string region;
	string titleMain;
	
	while(getline(title_akas_file,temp1,'\n'))
	{
		
		vector<string> elems;
		
		std::stringstream ss;
		ss.str(temp1);
		std::string item;
    			
    		std::getline(ss, item, '\t');titleId = item;
		std::getline(ss, item, '\t');
		std::getline(ss, item, '\t');titleMain = item;
		std::getline(ss, item, '\t');region = item;
				
		int compare_title = strcmp(argv[1],titleId.c_str());
		int compare_region = strcmp("\\N",region.c_str());
		
			
		if(compare_title==0&&compare_region==0)
		{
			//cout<<titleId.c_str()<<"\t"<<region.c_str()<<"\t"<<titleMain.c_str()<<endl;
			//getchar();
			ofstream output_name;
			output_name.open("Name.txt");
			output_name<<"\'"<<titleMain.c_str()<<"\'";
			output_name.close();
			break;
			
		}
	}
	
	cout<<"Finished Akas File"<<endl;

	tconst.clear();


	cout<<"Reading Episode File"<<endl;
	while(getline(title_episodes_file,temp1,'\n'))
	{
		
		vector<string> elems;
		
		std::stringstream ss;
		ss.str(temp1);
		std::string item;
    			
    		std::getline(ss, item, '\t');tconst.push_back(item);
		std::getline(ss, item, '\t');parentTconst.push_back(item);
		std::getline(ss, item, '\t');seasonNumber.push_back(item);
		std::getline(ss, item, '\t');episodeNumber.push_back(item);

		//"tt0412142"
		
		int compare = strcmp(argv[1],parentTconst.back().c_str());
		if(compare==0)
		{
			filtered_tconst.push_back(tconst.back());
			table table_data = {tconst.back(),"\t","\t","\t",seasonNumber.back(),episodeNumber.back(),0};
			table_vector.push_back(table_data);
		}
	}
	cout<<"Finished Episode File"<<endl;

	tconst.clear();

	cout<<"Reading Ratings File"<<endl;
	
	int rating_count=0;
	while(getline(title_ratings_file,temp3,'\n'))
	{
		
		vector<string> elems;
		
		std::stringstream ss;
		ss.str(temp3);
		std::string item;
    			
    		std::getline(ss, item, '\t');tconst.push_back(item);
		
		int i=0;
		while(i<filtered_tconst.size())
		{

			if(rating_count>=table_vector.size())
				break;
			else
			{
				int compare = strcmp(filtered_tconst[i].c_str(),tconst.back().c_str());
				if(compare==0)
				{
					std::getline(ss, item, '\t');averageRating.push_back(item);
					std::getline(ss, item, '\t');numVotes.push_back(item);
					
					table_vector[i].averageRating_table = averageRating.back();			
					table_vector[i].numVotes_table = numVotes.back();
					rating_count++;				
				}
			}
			i++;
		}		
	}
	cout<<"Finished Ratings File"<<endl;

	tconst.clear();
	
	cout<<"Reading title File"<<endl;

	int title_count=0;
	while(getline(title_basics_file,temp2,'\n'))
	{
		
		vector<string> elems;		
		std::stringstream ss;
		ss.str(temp2);

		std::string item;
		
		int i=0;	
		while (std::getline(ss, item, '\t')) 
		{	
			
			if(i==0)
				tconst.push_back(item);
			else if(i==2)
				title.push_back(item);
			i++;

    		}
		
		i=0;
		while(i<filtered_tconst.size())
		{
			if(title_count>=table_vector.size())
				break;
			else
			{

				int compare = strcmp(filtered_tconst[i].c_str(),tconst.back().c_str());
				if(compare==0)
				{
					table_vector[i].title_table = title.back();
					title_count++;			
				}
				i++;
			}
		}

	}
    	cout<<"Finished title File"<<endl;
	//cout<<table_vector.size()<<endl;
	
	cout<<"Create ranks"<<endl;
	
	ofstream output;
	output.open("IMDB.csv");
	
	
	for(int i=0;i<table_vector.size();i++)
	{
		string s = table_vector[i].episodeNumber_table.c_str();
		stringstream ss(s);
		int epi=0;
		ss>>epi;
		
		s = table_vector[i].seasonNumber_table.c_str();
		stringstream ss1(s);
		int sea=0;
		ss1>>sea;

		table_vector[i].rank = sea*100+epi;
		//cout<<table_vector[i].rank<<endl;
			
	}

	cout<<"Sort Table"<<endl;
	sort(table_vector.begin(),table_vector.end(),compareByLength);

	for(int i=0;i<table_vector.size();i++)
	{
		cout<<table_vector[i].tconst_table<<"\t"<<setw(40)<<std::left<<table_vector[i].title_table.substr(0,40)<<"\t"<<table_vector[i].averageRating_table<<"\t"
			<<table_vector[i].numVotes_table<<"\t"<<table_vector[i].seasonNumber_table<<"\t"<<table_vector[i].episodeNumber_table<<"\t"<<table_vector[i].rank<<endl;
		output<<table_vector[i].tconst_table<<";"<<setw(40)<<std::left<<table_vector[i].title_table.substr(0,40)<<";"<<table_vector[i].averageRating_table<<";"
			<<table_vector[i].numVotes_table<<";"<<table_vector[i].seasonNumber_table<<";"<<table_vector[i].episodeNumber_table<<";"<<table_vector[i].rank<<endl;
	}
	//cout<<setw(40)<<std::left<<titleMain.substr(0,40)<<endl;
	//cout<<endl<<parentTconst.size()<<endl;
	//string mypath="TITLE_MAIN=" + titleMain;
	//char *cstr = new char[mypath.length() + 1];
	//strcpy(cstr, mypath.c_str());
	//putenv(cstr);
	//cout<<setenv("TITLE",titleMain.c_str(),true)<<endl;
	//const char* env_p = getenv("TITLE");
	//cout<<"TITLE="<<env_p;
	//delete [] cstr;	
	
	//ofstream output_name;
	//output_name.open("Name.txt");
	//output_name<<"\""<<titleMain.c_str()<<"\"";
	
	return 0;
}
