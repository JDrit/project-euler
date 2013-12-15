from calendar import weekday                                                                                                                         
s = 0;                                                                                                                                               
for year in range(1901, 2001):                                                                                                                       
	for month in range(1, 13):                                                                                                                       
		if weekday(year, month, 1) == 6:                                                                                                             
			s += 1                                                                                                                                   
 print s  
