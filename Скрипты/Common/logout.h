logout()
{
	lr_start_transaction("Logout");

	web_reg_find("Text=If you haven't registered yet,", LAST);

	web_url("SignOff Button",
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=flights",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);
	
	lr_end_transaction("Logout", LR_PASS);
	return 0;
}