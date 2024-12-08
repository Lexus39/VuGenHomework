Action()
{
	lr_start_transaction("01_Login");
	openStartPage();
	login();
	logout();
	lr_end_transaction("01_Login", LR_AUTO);
	return 0;
}
