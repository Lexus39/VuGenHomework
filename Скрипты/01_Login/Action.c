Action()
{
	lr_start_transaction("01_Login");
	openStartPage();
	lr_think_time(5);
	login();
	lr_think_time(5);
	openSearchFlightsPage();
	lr_think_time(5);
	logout();
	lr_end_transaction("01_Login", LR_AUTO);
	return 0;
}
