getItineraryList()
{
	lr_start_transaction("Get itinerary list");
	
	web_reg_save_param_regexp(
		"ParamName=flightIDs",
        "Regexp=name\=\"flightID\" value\=\"(.*?)\"",
        "Ordinal=ALL",
        LAST);
	
	web_reg_save_param("c_cgifields",
    	"LB=<input type=\"hidden\" name=\".cgifields\" value=\"",
    	"RB=\"  />",
    	"Ordinal=ALL",
    	LAST);
	
	web_reg_find("Text=<title>Flights List</title>", LAST);
	
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Get itinerary list", LR_PASS);
}