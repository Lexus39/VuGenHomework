openSearchFlightsPage()
{
	lr_start_transaction("Open search flights page");

/*Correlation comment - Do not change!  Original value='12/01/2024' Name ='departDate' Type ='RecordReplay'*/
	web_reg_save_param_attrib(
		"ParamName=departDate",
		"TagName=input",
		"Extract=value",
		"Name=departDate",
		"Type=text",
		SEARCH_FILTERS,
		"RequestUrl=*/reservations.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='12/02/2024' Name ='returnDate' Type ='RecordReplay'*/
	web_reg_save_param_attrib(
		"ParamName=returnDate",
		"TagName=input",
		"Extract=value",
		"Name=returnDate",
		"Type=text",
		SEARCH_FILTERS,
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=departureList",
        "Regexp=\<select name\=\"depart\" >([\\s\\S]*?)</select>",
        LAST);
        
    web_reg_save_param_regexp(
		"ParamName=arriveList",
        "Regexp=\<select name\=\"arrive\" >([\\s\\S]*?)</select>",
        LAST);
        
    web_reg_save_param_regexp(
		"ParamName=seatPrefs",
        "Regexp=name\=\"seatPref\" value\=\"(.*?)\"",
        "Ordinal=ALL",
        LAST);
        
    web_reg_save_param_regexp(
		"ParamName=seatTypes",
        "Regexp=name\=\"seatType\" value\=\"(.*?)\"",
        "Ordinal=ALL",
        LAST);
    
	web_reg_find(
		"Text=\<form method\=\"post\" action\=\"reservations.pl\" enctype\=\"application/x-www-form-urlencoded\" onsubmit\=\"\" name\=\"DestForm\">",
        LAST);
    
	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("Open search flights page", LR_PASS);
}