Action()
{
	lr_start_transaction("03_BuyTicket");
	openStartPage();
	lr_think_time(5);
	login();
	lr_think_time(5);
	openSearchFlightsPage();
	lr_start_transaction("Fill out fields");
	lr_think_time(5);
	lr_end_transaction("Fill out fields", LR_PASS);
	chooseFlight();
	lr_think_time(5);
	lr_start_transaction("Buy ticket");
	lr_save_string(lr_paramarr_random("outboundFlights"), "outboundFlight");
	
	web_reg_find("Text=name\=\"outboundFlight\" value\=\"{outboundFlight}\"", LAST);
	web_reg_find("Text=name\=\"pass1\" value\=\"{first_name} {last_name}", LAST);
	
	web_submit_data("reservations.pl_2",
		"Action=http://127.0.0.1:8090/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:8090/WebTours/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=29", ENDITEM,
		"Name=reserveFlights.y", "Value=5", ENDITEM,
		LAST);
	
	lr_think_time(15);

	web_reg_find("Text=Thank you for booking through Web Tours.", LAST);
	web_reg_find("Text=A {seatType} Class ticket", LAST);
	web_reg_find("Text=from {departureCity} to {arriveCity}", LAST);
	
	web_submit_data("reservations.pl_3",
		"Action=http://127.0.0.1:8090/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:8090/WebTours/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={first_name}", ENDITEM,
		"Name=lastName", "Value={last_name}", ENDITEM,
		"Name=address1", "Value={street}", ENDITEM,
		"Name=address2", "Value={post_code}", ENDITEM,
		"Name=pass1", "Value={first_name} {last_name}", ENDITEM,
		"Name=creditCard", "Value={credit_card}", ENDITEM,
		"Name=expDate", "Value={exp_date}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=63", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
	
	lr_end_transaction("Buy ticket", LR_PASS);
	//lr_think_time(5);
	logout();
	lr_end_transaction("03_BuyTicket", LR_AUTO);
	return 0;
}
