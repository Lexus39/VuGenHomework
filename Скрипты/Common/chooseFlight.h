chooseFlight()
{
	lr_start_transaction("Choose flight");
		
	lr_save_param_regexp(
		lr_eval_string("{departureList}"),
		strlen(lr_eval_string("{departureList}")),
        "RegExp=\<option .*>(.*?)</option>",
        "Ordinal=ALL",
        "ResultParam=departureCities",
        LAST);
        
    	lr_save_param_regexp(
		lr_eval_string("{arriveList}"),
		strlen(lr_eval_string("{arriveList}")),
        "RegExp=\<option .*>(.*?)</option>",
        "Ordinal=ALL",
        "ResultParam=arriveCities",
        LAST);
	
	lr_save_string(lr_paramarr_random("departureCities"), "departureCity");
	
	do{
		lr_save_string(lr_paramarr_random("arriveCities"), "arriveCity");
	}while(strcmp(lr_eval_string("{departureCity}"),lr_eval_string("{arriveCity}")) == 0);
	
	lr_save_string(lr_paramarr_random("seatPrefs"), "seatPref");
	lr_save_string(lr_paramarr_random("seatTypes"), "seatType");
	
	web_add_auto_header("Origin", 
		"http://127.0.0.1:8090");
	
	web_reg_save_param_regexp(
		"ParamName=outboundFlights",
        "Regexp=name\=outboundFlight value\=(.*?)>",
        "Ordinal=ALL",
        LAST);
	
	web_reg_find("Text=Flight departing from <B>{departureCity}</B> to <B>{arriveCity}</B>", LAST);

	web_submit_data("reservations.pl",
		"Action=http://127.0.0.1:8090/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:8090/WebTours/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departureCity}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arriveCity}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=30", ENDITEM,
		"Name=findFlights.y", "Value=6", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);
	
	lr_end_transaction("Choose flight", LR_PASS);
}