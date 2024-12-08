Action()
{
	user_data data;
	generate_user(&data);
	
	lr_save_string(data.login, "login");
	lr_save_string(data.password, "password");
	lr_save_string(data.first_name, "first_name");
	lr_save_string(data.last_name, "last_name");
	lr_save_string(data.street, "street");
	lr_save_string(data.zip_code, "post_code");
	
	lr_start_transaction("06_Register");
	
	openStartPage();
	
	lr_start_transaction("Register");
	
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
	
	web_reg_find("Text=First time registering? Please complete the form below", LAST);

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
	
	web_reg_find("Text=Click below when you're ready to plan your dream trip", LAST);

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={first_name}", ENDITEM, 
		"Name=lastName", "Value={last_name}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={post_code}", ENDITEM, 
		"Name=register.x", "Value=58", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");
	
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.", LAST);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Register", LR_PASS);
	
	logout();

	lr_end_transaction("06_Register", LR_AUTO);
	
	return 0;
}