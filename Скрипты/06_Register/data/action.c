Action()
{

	web_add_cookie("MSO=SID&1733453728&MSO_Comments&on&MSO_ServerErrorsProb&50&MSO_ServerLoadProb&50; DOMAIN=127.0.0.1");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("login.pl", 
		"URL=http://127.0.0.1:8090/WebTours/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://127.0.0.1:8090");

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=login", ENDITEM, 
		"Name=password", "Value=password", ENDITEM, 
		"Name=passwordConfirm", "Value=password", ENDITEM, 
		"Name=firstName", "Value=first", ENDITEM, 
		"Name=lastName", "Value=last", ENDITEM, 
		"Name=address1", "Value=address", ENDITEM, 
		"Name=address2", "Value=zip", ENDITEM, 
		"Name=register.x", "Value=58", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(7);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}