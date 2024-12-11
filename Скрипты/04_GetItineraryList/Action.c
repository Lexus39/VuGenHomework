Action()
{
	lr_start_transaction("04_GetItineraryList");
	openStartPage();
	lr_think_time(5);
	login();
	lr_think_time(5);
	getItineraryList();
	lr_think_time(5);
	logout();
	lr_end_transaction("04_GetItineraryList", LR_AUTO);
	return 0;
}
