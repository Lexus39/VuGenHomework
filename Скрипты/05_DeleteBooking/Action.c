Action()
{
	int flightsCount;
	int indexToDelete;
	int i;
	
	lr_start_transaction("05_DeleteBooking");
	openStartPage();
	login();
	getItineraryList();
	
	flightsCount = atoi(lr_eval_string("{flightIDs_count}"));
	indexToDelete = rand() % flightsCount;
	lr_save_string(lr_paramarr_idx("flightIDs", indexToDelete + 1), "flightId");
	lr_save_string("","buffer");
	for(i = 1; i <= flightsCount; i++)
	{
		if (i == indexToDelete + 1)
		{
			lr_param_sprintf(
				"buffer", 
				"%s%d=on&", 
				lr_eval_string("{buffer}"), 
				i);
		}
		lr_param_sprintf(
			"buffer", 
			"%sflightID=%s&", 
			lr_eval_string("{buffer}"),
			lr_paramarr_idx("flightIDs", i)
		);
	}
	
	for(i = 1; i <= flightsCount; i++)
	{
		lr_param_sprintf(
			"buffer", 
			"%s.cgifields=%s&", 
			lr_eval_string("{buffer}"),
			lr_paramarr_idx("c_cgifields", i)
		);
	}
	
	lr_save_string(lr_eval_string("{buffer}removeFlights.x=79&removeFlights.y=7"), "requestBody");
	
	lr_start_transaction("Delete booking");

	web_reg_find("Text=name\=\"flightID\" value\=\"{flightID}\"", "Fail=Found", LAST);
	web_reg_find("Text=Unfortunately, we could not delete your entire itinerary because of a database synchronization error. ", "Fail=Found", LAST); 
	
	web_custom_request("itinerary.pl", 
		"URL=http://127.0.0.1:8090/WebTours/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/itinerary.pl", 
		"Snapshot=t14.inf", 
		"Mode=HTML",
		"Body={requestBody}",
		LAST);
	
	lr_end_transaction("Delete booking", LR_PASS);
	
	lr_end_transaction("05_DeleteBooking", LR_AUTO);
	
	return 0;
}
