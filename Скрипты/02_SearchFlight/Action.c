Action()
{
	lr_start_transaction("02_SearchFlight");
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
	getItineraryList();
	lr_think_time(5);
	openSearchFlightsPage();
	lr_start_transaction("Fill out fields");
	lr_think_time(5);
	lr_end_transaction("Fill out fields", LR_PASS);
	chooseFlight();
	lr_think_time(5);
	getItineraryList();
	lr_think_time(5);
	logout();
	lr_end_transaction("02_SearchFlight",LR_AUTO);
	return 0;
}
