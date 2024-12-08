Action()
{
	lr_start_transaction("02_SearchFlight");
	openStartPage();
	login();
	openSearchFlightsPage();
	chooseFlight();
	lr_end_transaction("02_SearchFlight",LR_AUTO);
	return 0;
}
