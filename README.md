# IMDB-Series-Trend

## Procedure:
1. Import the IMDB datasets from the following URL:
https://datasets.imdbws.com/
 
2. Unzip the files (use gunzip)

3. Create a folder called IMDB_Data

4. Clone this repository into this folder

5. Find the title code of the series . This can be found on the IMDB URL of the series you are intrested in:
	Example: The URL for Game of thrones is :https://www.imdb.com/title/tt0944947/
	The title code is **tt0944947**
	
6. Run the executable (./Import tt0944947). 

7. The data will be saved in IMDB.csv. The values are semicolon delimited (;).

8. You can plot the line chart of the data using gnuplot (gnuplot 'gnuscript.p')  
