Action()
{
	lr_start_transaction("04_GetItineraryList");
	openStartPage();
	login();
	getItineraryList();
	lr_end_transaction("04_GetItineraryList", LR_AUTO);
	return 0;
}
